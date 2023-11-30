#pragma once
#include <osmium/osm/node.hpp>
#include <osmium/io/xml_input.hpp>
#include <osmium/handler.hpp>
#include <osmium/handler/node_locations_for_ways.hpp>
#include <osmium/visitor.hpp>
#include <osmium/geom/factory.hpp>
#include <osmium/geom/wkt.hpp>
#include <osmium/index/map.hpp>
#include <osmium/index/map/sparse_mem_array.hpp>
#include <osmium/geom/wkb.hpp>
#include "nav_msgs/msg/path.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "unordered_map"
#include <functional>
#include "visualization_msgs/msg/marker_array.hpp"
#include "math.h"
#include "osm_nav_interface/srv/planner.hpp"

namespace osm_map = osmium::index::map;

namespace osm_nav
{


typedef struct
{
    osmium::object_id_type id;
    std::vector<std::pair<std::string, std::string>> tags;
    std::vector<osmium::object_id_type> node_ref;
}Way_t;

typedef struct
{
    osmium::object_id_type id;
    double lon, lat;
    std::vector<osmium::object_id_type> way_ref;
    osmium::object_id_type first_nav_node = -1, second_nav_node = -1;
}Node_t;

typedef struct 
{
    double x,y,z;
}Enu_t;

typedef struct
{
    typedef struct
    {
        osmium::object_id_type id;
        std::deque<osmium::object_id_type> inner_nodes;
        double cost; //距离
    }ReachableNode_t;
    std::vector<ReachableNode_t> reachable_nodes;
}NavNode_t;

// typedef struct TmpNode{
//     osmium::object_id_type id;
//     double cost; 
// }TmpNode_t;

typedef struct Path: public std::enable_shared_from_this<Path>{
    std::list<std::shared_ptr<struct Path>> subs;
    std::shared_ptr<struct Path> parent;
    std::vector<osmium::object_id_type> node_to_parent;
    osmium::object_id_type id;
    double g_cost = 0, h_cost = 0;
    bool visual_able = true;
    Path(){}
    Path(osmium::object_id_type id_):id(id_){}
    Path(osmium::object_id_type id_, double cost_):id(id_), g_cost(cost_){}
    Path(osmium::object_id_type id_, double g_cost_,double h_cost_):id(id_), g_cost(g_cost_), h_cost(h_cost_){}

    void add_sub(osmium::object_id_type id_, double g_cost_, double h_cost_){
        auto sub = std::make_shared<struct Path>();
        sub->id = id_;
        sub->g_cost = g_cost_;
        sub->h_cost = h_cost_;
        sub->parent = shared_from_this();
        subs.push_back(sub);
    }
    void add_sub(std::shared_ptr<struct Path> sub){
        sub->parent = shared_from_this();
        subs.push_back(sub);
    }
    double get_f_cost(){return g_cost + h_cost;} 
    bool operator != (const struct Path& n1){
        return n1.id == id;
    }
}Path_t;


Enu_t gnss2enu(double lon,double lat, double alt);

class OsmHandler:public osmium::handler::Handler{
public:
    OsmHandler(std::vector<std::pair<std::string, std::string>> tags)
    :tags_(tags)
    {
        way_map = std::make_shared<std::unordered_map<osmium::object_id_type, Way_t>>();    
        node_map = std::make_shared<std::unordered_map<osmium::object_id_type, Node_t>>(); 
        node_in_way_map = std::make_shared<std::unordered_map<osmium::object_id_type, Node_t>>(); 
    }
    OsmHandler(){}
    std::string way_has_tag(const osmium::Way& way, std::string key)
    {
        for (auto &t : way.tags()){
            if (0 == strcmp(t.key(), key.c_str())){
                return std::string(t.value());
            }
        }
        return "";
    }

    bool way_has_node(const osmium::Way& way, osmium::object_id_type id)
    {
        for (auto& node: way.nodes()){
            if (id == node.ref())
                return true;
        }
        return false;
    }

    void way(const osmium::Way& way) 
    {
        Way_t w;
        w.id = way.id();
        for (auto& tag : tags_){
            std::string v = way_has_tag(way, tag.first);
            if(tag.second == "*"){
                w.tags.push_back(tag);        
                for(auto &node : way.nodes()){
                    if((*node_map).find(node.ref()) != (*node_map).end()){
                        (*node_in_way_map)[node.ref()] = (*node_map)[node.ref()];
                        (*node_in_way_map)[node.ref()].way_ref.push_back(w.id);
                        // (*node_map)[node.ref()].way_ref.push_back(w.id);
                        w.node_ref.push_back(node.ref());
                        (*way_map)[way.id()] = w;
                    }else{
                        std::cout << "Error: node didn't existed in way!" << way.id() << " " << node.ref() << std::endl; 
                    }
                }
            }else if(tag.second == v){
                w.tags.push_back(tag);
                for(auto &node : way.nodes()){
                    if((*node_map).find(node.ref()) != (*node_map).end()){
                        (*node_in_way_map)[node.ref()] = (*node_map)[node.ref()];
                        (*node_in_way_map)[node.ref()].way_ref.push_back(w.id);
                        // (*node_map)[node.ref()].way_ref.push_back(w.id);
                        w.node_ref.push_back(node.ref());
                        (*way_map)[way.id()] = w;
                    }else{
                        std::cout << "Error: node didn't existed in way!" << way.id() << " " << node.ref() << std::endl; 
                    }
                }
            }
        }

    }

    void node(const osmium::Node& node)
    {
        Node_t node_;
        node_.id = node.id();
        node_.lat = node.location().lat();
        node_.lon = node.location().lon();
        (*node_map)[node.id()] = node_;
    }

    osmium::object_id_type get_node_size(){
        return (*node_in_way_map).size();
    }
    osmium::object_id_type get_way_size(){
        return (*way_map).size();
    }


    auto get_matched_nodes()
    {
        return node_in_way_map;
    }

    auto get_matched_ways()
    {
        return way_map;
    }
private: 
    int64_t node_size = 0;
    std::vector<std::pair<std::string, std::string>> tags_;
    std::shared_ptr<std::unordered_map<osmium::object_id_type, Node_t>> node_map;
    std::shared_ptr<std::unordered_map<osmium::object_id_type, Node_t>> node_in_way_map;
    std::shared_ptr<std::unordered_map<osmium::object_id_type, Way_t>> way_map;
};

class OsmParser: public rclcpp::Node
{
public:
    OsmParser():Node("osm_parser")
    {
        this->declare_parameter("osm_file", rclcpp::PARAMETER_STRING);
        this->declare_parameter("osm_match_tags", rclcpp::PARAMETER_STRING_ARRAY);
        this->get_parameter("osm_file", osm_file);
        this->get_parameter("osm_match_tags", way_match);
        RCLCPP_DEBUG(this->get_logger(), "oms_file:%s way_match size:%ld", osm_file.c_str(), way_match.size());

        std::vector<std::string>::iterator it;
        for(it = way_match.begin(); it != way_match.end(); it++){
            if ( !(way_match.size() % 2) ){
                std::string key = *it;
                std::string value = *(++it);
                match_tags.push_back(std::pair<std::string, std::string>(key, value));
            }else{
                std::cout << "Error: Wrong param!" << std::endl;
            }
        }
        
        RCLCPP_DEBUG(this->get_logger(), "match_tags size:%ld", match_tags.size());

        t_process_osm = std::thread(&OsmParser::parse_osm, this);
        t_process_osm.join();
        RCLCPP_DEBUG(this->get_logger(), "size node: %ld, size way: %ld", node_in_way_map->size(), way_map->size());
        visual_node = this->create_publisher<visualization_msgs::msg::MarkerArray>("/osm_parser/nodes", 1);
        visual_nav_node_dis_pub = this->create_publisher<visualization_msgs::msg::MarkerArray>("/osm_parser/nodes_dis", 1);
        planner_srv = this->create_service<osm_nav_interface::srv::Planner>(
            "/osm_parser/service",
            std::bind(&OsmParser::planner_request_cb, this, std::placeholders::_1, std::placeholders::_2));
        // visualiz_node();
        visual_way = rclcpp::create_publisher<nav_msgs::msg::Path>(this, "/osm_parser/ways", 1);
        visual_path = rclcpp::create_publisher<nav_msgs::msg::Path>(this, "/osm_parser/path", 1);
        visualiz_way();
        visualiz_nav_node();
        osm_nav_interface::srv::Planner::Request::SharedPtr req = std::make_shared<osm_nav_interface::srv::Planner::Request>();
        osm_nav_interface::srv::Planner::Response::SharedPtr rsp = std::make_shared<osm_nav_interface::srv::Planner::Response>();
    //     req->current_lon = 117.1801534;
    //     req->current_lat = 31.7652315;
    //     req->target_lon = 117.1813790;
    //    req->target_lat = 31.7681149;
        // req->target_lon = 0;
        // req->target_lat = 0;
        // req->current_lon = 117.1813790;
        // req->current_lat = 31.7681149;
        // req->current_lon = 0;
        // req->current_lat = 0;
        // req->target_lon = 117.1813790;
        req->target_lon = 117.1884469;
        req->target_lat = 31.7624620;
        req->current_lon = 117.1297055;
        req->current_lat = 31.8652168;       // req->target_lat = 31.7681149;
        planner_request_cb(req, rsp);
   }
    ~OsmParser(){}

private:
    bool waypoint_inited = false;
    bool target_arrived = false;
    void planner_request_cb(const osm_nav_interface::srv::Planner::Request::SharedPtr req, const osm_nav_interface::srv::Planner::Response::SharedPtr res)
    {
        auto f = [&](std::deque<osmium::object_id_type> obj){
            std::cout << "inner: ";
            for (auto& id : obj){
                std::cout << id << " ";
            }
            std::cout << std::endl;
        };
        osmium::object_id_type start_id, end_id;
        double min_start_distance = INFINITY;
        double min_end_distance = INFINITY;
        for (auto& n : *node_in_way_map){
            auto tmp = distance_in_two_node(n.second.lon, n.second.lat, req->current_lon, req->current_lat);
            if (min_start_distance > tmp){
                min_start_distance = tmp;
                start_id = n.first;
            }
            tmp = distance_in_two_node(n.second.lon, n.second.lat, req->target_lon, req->target_lat);
            if (min_end_distance > tmp){
                min_end_distance = tmp;
                end_id = n.first;
            }
        }

        // start_id = 4789602551;
        // end_id = 4839927663;

        RCLCPP_DEBUG(this->get_logger(), "start_id: %ld, end_id:%ld", start_id, end_id);
        osmium::object_id_type start1,start2,end1,end2;
        double s1_cost, s2_cost, e1_cost, e2_cost;
        std::deque<osmium::object_id_type> s1_inner, s2_inner, e1_inner, e2_inner;
        bool complete_s = false, complete_e = false;

        // for (auto& n : nav_nodes){
        //     std::cout << n.first << " ";
        //     // for (auto& n_re : n.second.reachable_nodes){
        //     //     f(n_re.inner_nodes);
        //     // }
        // }
        // std::cout << std::endl;

        for (auto& n : nav_nodes){
            for (auto& n_re : n.second.reachable_nodes){
                // f(n_re.inner_nodes);
                double tmp_cost = 0;
                osmium::object_id_type last_id = n_re.inner_nodes.front();
                NavNode_t tmp_nav_node;
                std::deque<osmium::object_id_type> reach_tmp;
                bool mark_found = false;

                double tmp_cost_ = 0;
                NavNode_t tmp_nav_node_;
                std::deque<osmium::object_id_type> reach_tmp_;
                bool mark_found_ = false;
                for (auto& n_in : n_re.inner_nodes){
                    tmp_cost += distance_in_two_node(n_in, last_id);
                    tmp_cost_ += distance_in_two_node(n_in, last_id);
                    if (mark_found == false){
                        reach_tmp.push_front(n_in);
                    }else{
                        reach_tmp.push_back(n_in);
                    }
                    if (mark_found_ == false){
                        reach_tmp_.push_back(n_in);
                    }else{
                        reach_tmp_.push_front(n_in);
                    }

                    if(complete_s == false){
                        if (n_in == start_id && mark_found == false){
                            start1 = n.first;
                            start2 = n_re.id;
                            s1_cost = tmp_cost; 
                            s1_inner = reach_tmp;
                            reach_tmp.clear();
                            reach_tmp.push_back(n_in);
                            tmp_cost = 0;
                            mark_found = true;
                            f(n_re.inner_nodes);
                            std::cout << std::endl;
                        }if (n_in == n_re.inner_nodes.back() && mark_found == true){
                            s2_cost = tmp_cost;
                            s2_inner = reach_tmp;  
                            complete_s = true;
                        }
                    }

                    if (complete_e == false){
                        if (n_in == end_id && mark_found_ == false){
                            end1 = n.first;
                            end2 = n_re.id;
                            e1_cost = tmp_cost_; 
                            e1_inner = reach_tmp_;
                            reach_tmp_.clear();
                            reach_tmp_.push_back(n_in);
                            tmp_cost_ = 0;
                            mark_found_ = true;
                            f(n_re.inner_nodes);
                            std::cout << std::endl;
                        }
                        if (n_in == n_re.inner_nodes.back() && mark_found_ == true){
                            e2_cost = tmp_cost_;
                            e2_inner = reach_tmp_;   
                            complete_e = true;
                        }
                    }
                    if (complete_e && complete_s) {
                        goto find_complete;
                    }
                    last_id = n_in;
                }
            }
        }    
find_complete:
        std::cout << std::endl;
        
        RCLCPP_DEBUG(this->get_logger(), "id: %ld %ld %ld %ld", start1, start2, end1, end2);
        RCLCPP_DEBUG(this->get_logger(), "cost: %f %f %f %f", s1_cost, s2_cost, e1_cost, e2_cost);
        f(s1_inner); f(s2_inner); f(e1_inner); f(e2_inner);
        
        NavNode_t::ReachableNode_t reach_node;
        reach_node.id = end_id;
        reach_node.inner_nodes = e1_inner;
        reach_node.cost = e1_cost;
        nav_nodes[end1].reachable_nodes.push_back(reach_node);
        reach_node.inner_nodes = e2_inner;
        reach_node.cost = e2_cost;
        nav_nodes[end2].reachable_nodes.push_back(reach_node);
        // NavNode_t nav;
        // reach_node.id = end1;
        // reach_node.cost = e1_cost;
        // reach_node.inner_nodes = e1_inner;
        // nav.reachable_nodes.push_back(reach_node);
        // reach_node.id = end2;
        // reach_node.cost = e2_cost;
        // reach_node.inner_nodes = e2_inner;
        // nav.reachable_nodes.push_back(reach_node);
        // nav_nodes[end_id] = nav;

        // 找到到 end_id 的最短路径
        double dist_start1 = s1_cost + distance_in_two_node(start1, end_id);
        double dist_start2 = s2_cost + distance_in_two_node(start2, end_id);

        std::shared_ptr<Path_t> path_rule = std::make_shared<Path_t>(start_id,0, distance_in_two_node(start_id, end1));
        path_rule->parent = path_rule;

        std::unordered_map<osmium::object_id_type, std::shared_ptr<Path_t>> open_id;
        auto f_min = [&open_id](){
                std::shared_ptr<Path_t> min;
                double cost_tmp = INFINITY;
                for (auto& n : open_id){
                    if (n.second->h_cost + n.second->g_cost < cost_tmp && n.second->visual_able == true){
                        min = n.second;
                        cost_tmp = n.second->h_cost + n.second->g_cost;
                    }
                }
                return min;
            };
        auto n1 = std::make_shared<struct Path>(start1, s1_cost, dist_start1 - s1_cost);
        auto n2 = std::make_shared<struct Path>(start2, s2_cost, dist_start2 - s2_cost);
        path_rule->add_sub(n1);
        path_rule->add_sub(n2);
        open_id[n1->id] = n1;
        open_id[n2->id] = n2;
        std::shared_ptr<Path_t> current_path = path_rule;
        current_path->visual_able = false;
        if (dist_start1 < dist_start2){
            current_path = n1;
        }else{
            current_path = n2;
        }
        rclcpp::Rate rate(0.5);
        for (; current_path->id != end_id;){
            std::shared_ptr<struct Path> next;
            double tmp_cost = current_path->get_f_cost();
            for (auto& n : nav_nodes[current_path->id].reachable_nodes){
                double cost_g_tmp = n.cost + current_path->g_cost;
                double cost_h_tmp = distance_in_two_node(n.id, end1);
                if (open_id.find(n.id) != open_id.end()){
                    if (open_id[n.id]->get_f_cost() < cost_g_tmp + cost_h_tmp){
                        continue;
                    }
                    if (open_id[n.id]->visual_able == false){
                        continue;
                    }
                }
                open_id[n.id] = std::make_shared<struct Path>(n.id, cost_g_tmp, cost_h_tmp);    
                current_path->add_sub(open_id[n.id]);
                if (cost_g_tmp + cost_h_tmp < tmp_cost){
                    next = open_id[n.id];
                    tmp_cost = cost_g_tmp + cost_h_tmp;
                }
            } 
            if (next.get() != nullptr){
                current_path->visual_able = false;
                current_path = next;
            }else{
                std::shared_ptr<Path_t> tmp_id = f_min();
                
                RCLCPP_DEBUG(this->get_logger(),"open_id");
                for (auto& n : open_id){
                    if (n.first == 4839986907 || n.first == 4791764855 ||  n.first == 4839986910)
                    RCLCPP_DEBUG(this->get_logger(),"open_id:%ld, cost: %f, vis: %d", n.second->id, n.second->get_f_cost(), n.second->visual_able);
                }
                current_path->visual_able = false;
                current_path = tmp_id;
            }
        }
        
        std::deque<osmium::object_id_type> path_node_list;
        RCLCPP_DEBUG(this->get_logger(), "===============================================");
        std::cout << "id: " << current_path->id << " cost: " << current_path->g_cost << " " << current_path->h_cost << 
             " True cost:" << current_path->get_f_cost() + e1_cost << std::endl;

        for ( ;current_path->id != path_rule->id; ){
            std::cout << "current id:" << current_path->id << " " << std::endl;

            std::find_if(nav_nodes[current_path->id].reachable_nodes.begin(), nav_nodes[current_path->id].reachable_nodes.end(),
                [&](osm_nav::NavNode_t::ReachableNode_t& node){
                    if (node.id == current_path->parent->id){
                        for (auto& n : node.inner_nodes){
                            path_node_list.push_front(n);
                        }
                        return true;
                    }
                    // if(current_path->id == start1){
                    //     for (auto& n : s1_inner){
                    //         path_node_list.push_back(n);
                    //     }
                    // }
                    // else if(current_path->id == start2){
                    //     for (auto& n : s2_inner){
                    //         path_node_list.push_back(n);
                    //     }
                    // }
                    // else if (current_path->id == end1){
                    //     for (auto& n : e1_inner){
                    //         path_node_list.push_back(n);
                    //     }
                    // }
                    // else if(current_path->id == end2){
                    //     for (auto& n : e2_inner){
                    //         path_node_list.push_back(n);
                    //     }
                    // }
                    return false;
                });
            current_path = current_path->parent;
        }

        for(auto& n : path_node_list){
            RCLCPP_DEBUG(this->get_logger(), "%ld", n);
        }

        RCLCPP_DEBUG(this->get_logger(), "Length path node:%ld", path_node_list.size());

        nav_nodes[end1].reachable_nodes.pop_back();
        nav_nodes[end2].reachable_nodes.pop_back();
        
        nav_msgs::msg::Path path;
        path.header.frame_id = "world";
        path.header.stamp = this->now();
        geometry_msgs::msg::PoseStamped pose1;
        for (auto& node_id : path_node_list){
            pose1.header.frame_id = "world";
            pose1.header.stamp = this->now();
            Enu_t enu = gnss2enu((*node_in_way_map)[node_id].lon - 117.2, (*node_in_way_map)[node_id].lat - 31.7, 0);
            pose1.pose.position.x = enu.x;
            pose1.pose.position.y = enu.y;
            pose1.pose.position.z = 0.0;
            path.poses.push_back(pose1);
        }
        visual_path->publish(path);

        RCLCPP_DEBUG(this->get_logger(), "id: 4791764855");
        for (auto& n : nav_nodes[4791764855].reachable_nodes){
            RCLCPP_DEBUG(this->get_logger(), "reach: %ld cost: %f", n.id, n.cost);
        }
        RCLCPP_DEBUG(this->get_logger(), "id: 4839986907");
        for (auto& n : nav_nodes[4839986907].reachable_nodes){
            RCLCPP_DEBUG(this->get_logger(), "reach: %ld cost: %f", n.id, n.cost);
        }
    }

    void visualiz_way()
    {
        nav_msgs::msg::Path path;
        path.header.frame_id = "world";
        path.header.stamp = this->now();
        for (auto& way : *way_map){
            path.poses.clear();
            for(auto& node_id : way.second.node_ref){
                geometry_msgs::msg::PoseStamped pose1;
                pose1.header.frame_id = "world";
                pose1.header.stamp = this->now();
                Enu_t enu = gnss2enu((*node_in_way_map)[node_id].lon - 117.2, (*node_in_way_map)[node_id].lat - 31.7, 0);
                pose1.pose.position.x = enu.x;
                pose1.pose.position.y = enu.y;
                pose1.pose.position.z = 0.0;
                path.poses.push_back(pose1);
            }
            visual_way->publish(path);
        }
        
    }

    void visualiz_node()
    {
        visualization_msgs::msg::Marker marker;
        marker.header.frame_id = "world";
        marker.pose.position.z = 0;
        marker.scale.x = 5;
        marker.scale.y = 5;
        marker.scale.z = 5;
        marker.color.r = 0.3;
        marker.color.g = 0.3;
        marker.color.b = 0.3;
        marker.color.a = 0.8;
        marker.type = visualization_msgs::msg::Marker::CUBE;
        int i = 0;
        for(auto& node : *node_in_way_map){
            marker.id  = i;
            i++; 
            marker.header.stamp = this->now();
            Enu_t enu = gnss2enu(node.second.lon - 117.2, node.second.lat - 31.7, 0);
            marker.pose.position.x = enu.x;
            marker.pose.position.y = enu.y;
            visual_node_data.markers.push_back(marker);
        }
        visual_node->publish(visual_node_data);
    }

    inline bool ways_has_node(const std::pair<const osmium::object_id_type, osm_nav::Way_t> &way, osmium::object_id_type nid)
    {
        for(auto id : way.second.node_ref){
            if (id == nid){
                return true;
            }
        }
        return false;
    }

    double distance_in_two_node(osmium::object_id_type n1, osmium::object_id_type n2)
    {
        Enu_t enu1 = gnss2enu((*node_in_way_map)[n1].lon, (*node_in_way_map)[n1].lat, 0);
        Enu_t enu2 = gnss2enu((*node_in_way_map)[n2].lon, (*node_in_way_map)[n2].lat, 0);
        return sqrt(pow(enu1.x - enu2.x, 2) + pow(enu1.y - enu2.y, 2)); 
    }

    double distance_in_two_node(double lon1, double lat1, double lon2, double lat2)
    {
        Enu_t enu1 = gnss2enu(lon1, lat1, 0);
        Enu_t enu2 = gnss2enu(lon2, lat2, 0);
        return sqrt(pow(enu1.x - enu2.x, 2) + pow(enu1.y - enu2.y, 2)); 
    }

    void visualiz_nav_node()
    {
        std::unordered_set<osmium::object_id_type> tmp;
        for(auto& way : *way_map){
            for(auto id : way.second.node_ref){
                if(id == way.second.node_ref.front() || id == way.second.node_ref.back()){
                    nav_nodes.insert(std::pair(id, osm_nav::NavNode_t{}));
                    continue;
                }
                if(tmp.find(id) != tmp.end()){
                    nav_nodes.insert(std::pair(id, osm_nav::NavNode_t{}));
                }else{
                    tmp.insert(id);
                }
            }
        }
        for (const auto& way : *way_map){ 
            // last_ref 上一个在 way 的 ndf 找到的 node
            // pre_id 是在 way 中 current_id 的上一个 ndf
            // reachable_node 是 nav_nodes 的 node
            osmium::object_id_type last_ref = way.second.node_ref.front();
            osmium::object_id_type pre_id = way.second.node_ref.front();
            osm_nav::NavNode_t::ReachableNode_t reachable_node;
            osm_nav::NavNode_t::ReachableNode_t reachable_node_;
            double tmp_distance = 0;
            int i = 0;
            for(const auto current_id : way.second.node_ref){ 
                i++;
                tmp_distance += distance_in_two_node(pre_id, current_id);    
                reachable_node.inner_nodes.push_back(current_id);
                reachable_node_.inner_nodes.push_front(current_id);
                if ( nav_nodes.find(current_id) != nav_nodes.end()){
                    // 在way中找到了路口

                    if(pre_id == current_id){
                        continue;
                    }
                    reachable_node.id = current_id;
                    reachable_node.cost = tmp_distance;
                    nav_nodes[last_ref].reachable_nodes.push_back(reachable_node);
                    reachable_node_.id = last_ref;
                    reachable_node_.cost = tmp_distance;
                    nav_nodes[current_id].reachable_nodes.push_back(reachable_node_);
                    // if(reachable_node.inner_nodes.size() == 1){
                    //     RCLCPP_DEBUG(this->get_logger(), "size of way's node: %ld %d", way.second.node_ref.size(), i);
                    // } 
                    reachable_node.inner_nodes.clear();
                    reachable_node_.inner_nodes.clear();
                    tmp_distance = 0;
                    last_ref = current_id;
                    reachable_node.inner_nodes.push_back(current_id);
                    reachable_node_.inner_nodes.push_front(current_id);
                } 
       
                pre_id = current_id;
            }
        }

        visualization_msgs::msg::Marker marker;
        visualization_msgs::msg::Marker text;
        marker.header.frame_id = text.header.frame_id = "world";
        marker.pose.position.z = marker.pose.position.z = 0;
        // marker.scale.x = text.scale.x = 10;
        // marker.scale.y = text.scale.y = 10;
        // marker.scale.z = text.scale.z = 10;
        marker.scale.x = 10;
        marker.scale.y = 10;
        marker.scale.z = 10;
        text.scale.x = text.scale.y = text.scale.z = 10;
        marker.color.r = text.color.b = 0.5;
        marker.color.g = text.color.g = 0.0;
        marker.color.b = text.color.r = 0.0;
        marker.color.a = text.color.a = 0.9;
        // marker.type = visualization_msgs::msg::Marker::CUBE;
        marker.type = visualization_msgs::msg::Marker::TEXT_VIEW_FACING;
        text.type = visualization_msgs::msg::Marker::TEXT_VIEW_FACING;
        int i_node = 0;
        int i_text = 0;
        for(auto& nid : nav_nodes){
            const auto node = (*node_in_way_map)[nid.first];
            marker.id = i_node;
            i_node++; 
            marker.header.stamp = text.header.stamp = this->now();
            Enu_t enu = gnss2enu(node.lon - 117.2, node.lat - 31.7, 0);
            for(auto reachable : nav_nodes[nid.first].reachable_nodes){
                text.id = i_text;
                i_text++;
                text.text = std::to_string((int)reachable.cost);
                
                // RCLCPP_DEBUG(this->get_logger(), "sizeof inner_nodes: %ld", reachable.inner_nodes.size());
                // if(reachable.inner_nodes.size() != 2){
                //     auto texted_node = (*node_in_way_map)[reachable.inner_nodes[reachable.inner_nodes.size()/2]];
                //     auto texted_loc = gnss2enu(texted_node.lon - 117.2, texted_node.lat - 31.7, 0);    
                //     text.pose.position.x = texted_loc.x;
                //     text.pose.position.y = texted_loc.y;
                // }else{
                    auto reach_node = (*node_in_way_map)[reachable.id];
                    Enu_t enu_reach = gnss2enu(reach_node.lon - 117.2, reach_node.lat - 31.7, 0); 
                    text.pose.position.x = (enu.x + enu_reach.x) / 2;
                    text.pose.position.y = (enu.y + enu_reach.y) / 2;
                // }
                visual_nav_node_distance.markers.push_back(text);
            }
            marker.pose.position.x = enu.x;
            marker.pose.position.y = enu.y;
            marker.text = std::to_string(nid.first);
            visual_node_data.markers.push_back(marker);
        }
        visual_node->publish(visual_node_data);
        visual_nav_node_dis_pub->publish(visual_nav_node_distance);
    }

    double get_cost_in_node(osmium::object_id_type n1, osmium::object_id_type n2)
    {
        for(const auto& n : nav_nodes[n1].reachable_nodes){
            if( n.id == n2 ){
                return n.cost;
            }
        }
        return -1;
    }

    void parse_osm(){
        osmium::io::Reader reader(osm_file, osmium::osm_entity_bits::all);
        OsmHandler handler(match_tags);
        for(auto& tag : match_tags){
            RCLCPP_DEBUG(this->get_logger(), "Match tags: k=%s, v=%s", tag.first.c_str(), tag.second.c_str());
        }
        IndexType index;
        LocationHandler location_handler{index};
        auto t = this->now();
        osmium::apply(reader, location_handler, handler);
        RCLCPP_DEBUG(this->get_logger(), "Parse cost time: %f ms", (this->now().nanoseconds() - t.nanoseconds()) / 10e6) ;
        node_in_way_map = handler.get_matched_nodes();
        way_map = handler.get_matched_ways();
        reader.close();
    }
    using IndexType = osm_map::SparseMemArray<osmium::unsigned_object_id_type, osmium::Location>;
    using LocationHandler = osmium::handler::NodeLocationsForWays<IndexType>;
    std::string osm_file;
    std::vector<std::pair<std::string, std::string>> match_tags;
    std::vector<std::string> way_match;
    std::thread t_process_osm;
    std::shared_ptr<std::unordered_map<osmium::object_id_type, Node_t>> node_in_way_map;
    std::shared_ptr<std::unordered_map<osmium::object_id_type, Way_t>> way_map;   
    std::unordered_map<osmium::object_id_type, NavNode_t> nav_nodes;
    visualization_msgs::msg::MarkerArray visual_node_data;
    visualization_msgs::msg::MarkerArray visual_nav_node_distance;
    nav_msgs::msg::Path visual_way_data;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr visual_node;
    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr visual_nav_node_dis_pub;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr visual_way;
    rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr visual_path;
    rclcpp::Service<osm_nav_interface::srv::Planner>::SharedPtr planner_srv;

};   

} // namespace osm_nav






