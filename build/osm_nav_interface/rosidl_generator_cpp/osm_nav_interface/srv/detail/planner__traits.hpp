// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from osm_nav_interface:srv/Planner.idl
// generated code does not contain a copyright notice

#ifndef OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__TRAITS_HPP_
#define OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "osm_nav_interface/srv/detail/planner__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace osm_nav_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Planner_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_lon
  {
    out << "current_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.current_lon, out);
    out << ", ";
  }

  // member: current_lat
  {
    out << "current_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.current_lat, out);
    out << ", ";
  }

  // member: target_lon
  {
    out << "target_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.target_lon, out);
    out << ", ";
  }

  // member: target_lat
  {
    out << "target_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.target_lat, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Planner_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_lon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.current_lon, out);
    out << "\n";
  }

  // member: current_lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.current_lat, out);
    out << "\n";
  }

  // member: target_lon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.target_lon, out);
    out << "\n";
  }

  // member: target_lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.target_lat, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Planner_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace osm_nav_interface

namespace rosidl_generator_traits
{

[[deprecated("use osm_nav_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const osm_nav_interface::srv::Planner_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  osm_nav_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use osm_nav_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const osm_nav_interface::srv::Planner_Request & msg)
{
  return osm_nav_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<osm_nav_interface::srv::Planner_Request>()
{
  return "osm_nav_interface::srv::Planner_Request";
}

template<>
inline const char * name<osm_nav_interface::srv::Planner_Request>()
{
  return "osm_nav_interface/srv/Planner_Request";
}

template<>
struct has_fixed_size<osm_nav_interface::srv::Planner_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<osm_nav_interface::srv::Planner_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<osm_nav_interface::srv::Planner_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace osm_nav_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Planner_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: next_lon
  {
    out << "next_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.next_lon, out);
    out << ", ";
  }

  // member: next_lat
  {
    out << "next_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.next_lat, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Planner_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: next_lon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "next_lon: ";
    rosidl_generator_traits::value_to_yaml(msg.next_lon, out);
    out << "\n";
  }

  // member: next_lat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "next_lat: ";
    rosidl_generator_traits::value_to_yaml(msg.next_lat, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Planner_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace osm_nav_interface

namespace rosidl_generator_traits
{

[[deprecated("use osm_nav_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const osm_nav_interface::srv::Planner_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  osm_nav_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use osm_nav_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const osm_nav_interface::srv::Planner_Response & msg)
{
  return osm_nav_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<osm_nav_interface::srv::Planner_Response>()
{
  return "osm_nav_interface::srv::Planner_Response";
}

template<>
inline const char * name<osm_nav_interface::srv::Planner_Response>()
{
  return "osm_nav_interface/srv/Planner_Response";
}

template<>
struct has_fixed_size<osm_nav_interface::srv::Planner_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<osm_nav_interface::srv::Planner_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<osm_nav_interface::srv::Planner_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<osm_nav_interface::srv::Planner>()
{
  return "osm_nav_interface::srv::Planner";
}

template<>
inline const char * name<osm_nav_interface::srv::Planner>()
{
  return "osm_nav_interface/srv/Planner";
}

template<>
struct has_fixed_size<osm_nav_interface::srv::Planner>
  : std::integral_constant<
    bool,
    has_fixed_size<osm_nav_interface::srv::Planner_Request>::value &&
    has_fixed_size<osm_nav_interface::srv::Planner_Response>::value
  >
{
};

template<>
struct has_bounded_size<osm_nav_interface::srv::Planner>
  : std::integral_constant<
    bool,
    has_bounded_size<osm_nav_interface::srv::Planner_Request>::value &&
    has_bounded_size<osm_nav_interface::srv::Planner_Response>::value
  >
{
};

template<>
struct is_service<osm_nav_interface::srv::Planner>
  : std::true_type
{
};

template<>
struct is_service_request<osm_nav_interface::srv::Planner_Request>
  : std::true_type
{
};

template<>
struct is_service_response<osm_nav_interface::srv::Planner_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__TRAITS_HPP_
