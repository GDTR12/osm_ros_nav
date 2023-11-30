// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from osm_nav_interface:srv/Planner.idl
// generated code does not contain a copyright notice

#ifndef OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__STRUCT_H_
#define OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Planner in the package osm_nav_interface.
typedef struct osm_nav_interface__srv__Planner_Request
{
  double current_lon;
  double current_lat;
  double target_lon;
  double target_lat;
} osm_nav_interface__srv__Planner_Request;

// Struct for a sequence of osm_nav_interface__srv__Planner_Request.
typedef struct osm_nav_interface__srv__Planner_Request__Sequence
{
  osm_nav_interface__srv__Planner_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} osm_nav_interface__srv__Planner_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Planner in the package osm_nav_interface.
typedef struct osm_nav_interface__srv__Planner_Response
{
  double next_lon;
  double next_lat;
} osm_nav_interface__srv__Planner_Response;

// Struct for a sequence of osm_nav_interface__srv__Planner_Response.
typedef struct osm_nav_interface__srv__Planner_Response__Sequence
{
  osm_nav_interface__srv__Planner_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} osm_nav_interface__srv__Planner_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__STRUCT_H_
