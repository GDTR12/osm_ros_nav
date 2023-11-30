// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from osm_nav_interface:srv/Planner.idl
// generated code does not contain a copyright notice

#ifndef OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__BUILDER_HPP_
#define OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "osm_nav_interface/srv/detail/planner__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace osm_nav_interface
{

namespace srv
{

namespace builder
{

class Init_Planner_Request_target_lat
{
public:
  explicit Init_Planner_Request_target_lat(::osm_nav_interface::srv::Planner_Request & msg)
  : msg_(msg)
  {}
  ::osm_nav_interface::srv::Planner_Request target_lat(::osm_nav_interface::srv::Planner_Request::_target_lat_type arg)
  {
    msg_.target_lat = std::move(arg);
    return std::move(msg_);
  }

private:
  ::osm_nav_interface::srv::Planner_Request msg_;
};

class Init_Planner_Request_target_lon
{
public:
  explicit Init_Planner_Request_target_lon(::osm_nav_interface::srv::Planner_Request & msg)
  : msg_(msg)
  {}
  Init_Planner_Request_target_lat target_lon(::osm_nav_interface::srv::Planner_Request::_target_lon_type arg)
  {
    msg_.target_lon = std::move(arg);
    return Init_Planner_Request_target_lat(msg_);
  }

private:
  ::osm_nav_interface::srv::Planner_Request msg_;
};

class Init_Planner_Request_current_lat
{
public:
  explicit Init_Planner_Request_current_lat(::osm_nav_interface::srv::Planner_Request & msg)
  : msg_(msg)
  {}
  Init_Planner_Request_target_lon current_lat(::osm_nav_interface::srv::Planner_Request::_current_lat_type arg)
  {
    msg_.current_lat = std::move(arg);
    return Init_Planner_Request_target_lon(msg_);
  }

private:
  ::osm_nav_interface::srv::Planner_Request msg_;
};

class Init_Planner_Request_current_lon
{
public:
  Init_Planner_Request_current_lon()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Planner_Request_current_lat current_lon(::osm_nav_interface::srv::Planner_Request::_current_lon_type arg)
  {
    msg_.current_lon = std::move(arg);
    return Init_Planner_Request_current_lat(msg_);
  }

private:
  ::osm_nav_interface::srv::Planner_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::osm_nav_interface::srv::Planner_Request>()
{
  return osm_nav_interface::srv::builder::Init_Planner_Request_current_lon();
}

}  // namespace osm_nav_interface


namespace osm_nav_interface
{

namespace srv
{

namespace builder
{

class Init_Planner_Response_next_lat
{
public:
  explicit Init_Planner_Response_next_lat(::osm_nav_interface::srv::Planner_Response & msg)
  : msg_(msg)
  {}
  ::osm_nav_interface::srv::Planner_Response next_lat(::osm_nav_interface::srv::Planner_Response::_next_lat_type arg)
  {
    msg_.next_lat = std::move(arg);
    return std::move(msg_);
  }

private:
  ::osm_nav_interface::srv::Planner_Response msg_;
};

class Init_Planner_Response_next_lon
{
public:
  Init_Planner_Response_next_lon()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Planner_Response_next_lat next_lon(::osm_nav_interface::srv::Planner_Response::_next_lon_type arg)
  {
    msg_.next_lon = std::move(arg);
    return Init_Planner_Response_next_lat(msg_);
  }

private:
  ::osm_nav_interface::srv::Planner_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::osm_nav_interface::srv::Planner_Response>()
{
  return osm_nav_interface::srv::builder::Init_Planner_Response_next_lon();
}

}  // namespace osm_nav_interface

#endif  // OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__BUILDER_HPP_
