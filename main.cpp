#include "iostream"
#include <osmium/osm/node.hpp>
#include <osmium/io/xml_input.hpp>
#include <osmium/handler.hpp>
#include <osmium/handler/node_locations_for_ways.hpp>
#include <osmium/visitor.hpp>
#include <osmium/geom/factory.hpp>
#include <osmium/geom/wkt.hpp>
#include <osmium/index/map.hpp>
#include <osmium/index/map/sparse_mem_array.hpp>
#include <matplot/matplot.h>
#include <osmium/geom/wkb.hpp>
#include "osm/osm_parser.hpp"
class MyHandler : public osmium::handler::Handler {
public:
    MyHandler(){
        
    }
    void way(const osmium::Way& way) {
        // std::string str = wkt.create_linestring(way,osmium::geom::use_nodes::all);

        // std::cout << str << std::endl;

        std::shared_ptr<std::vector<double>> way_node_lon_ptr = std::make_shared<std::vector<double>>();
        std::shared_ptr<std::vector<double>> way_node_lat_ptr = std::make_shared<std::vector<double>>();
        auto aa = way.nodes().begin();
        for(auto& node : way.nodes())
        {
            (*way_node_lon_ptr).push_back(node.location().lon());
            (*way_node_lat_ptr).push_back(node.location().lat());
            ways.push_back(*std::make_shared<std::pair<std::vector<double>, std::vector<double>>>());
        }
        matplot::plot(*way_node_lon_ptr, *way_node_lat_ptr);
        sleep(1);
        matplot::hold(matplot::on);
    }
    
    void search_path()
    {

    }

    // void node(const osmium::Node& node) {
    //     nodes_lon.push_back(node.location().lon() * M_PI / 180.0);
    //     nodes_lat.push_back(node.location().lat() * M_PI / 180.0);
    // }

    void plot(){
        auto scatter = matplot::scatter(nodes_lon, nodes_lat);
        matplot::show();
    }
    const double EARTH_RADIUS = 6371000;
    std::vector<double> nodes_lon;
    std::vector<double> nodes_lat;
    std::vector<std::pair<std::vector<double>, std::vector<double>>> ways;
    osmium::geom::WKTFactory<> wkt;
};


class NodeWay
{
private:
    /* data */
public:
    NodeWay
    ();
    ~NodeWay
    ();
};

NodeWay
::NodeWay
(/* args */)
{
}

NodeWay
::~NodeWay
()
{
}


int main(int argc, char* argv[])
{
    // osmium::io::Reader reader("/root/slam/slam/osm/osm-nav/osm_file/map.osm", osmium::osm_entity_bits::all);
    // osmium::io::Header header = reader.header();
    // std::string key, value;
    // header.get(key, value);
    // std::cout << "header(key, value): " << std:: endl << key << " " << value << std::endl;

    // namespace map = osmium::index::map;
    // using index_type = map::SparseMemArray<osmium::unsigned_object_id_type, osmium::Location>;
    // using location_handler_type = osmium::handler::NodeLocationsForWays<index_type>;
    // index_type index;
    // location_handler_type location_handler{index};
    // // location_handler.ignore_errors();

    // MyHandler handler;
    // osmium::apply(reader, location_handler, handler);
    // handler.plot();
    // reader.close();
    rclcpp::init(argc, argv);
    
    rclcpp::Node::SharedPtr parser = std::make_shared<osm_nav::OsmPraser>();
    rclcpp::spin(parser);
    rclcpp::shutdown();
}
