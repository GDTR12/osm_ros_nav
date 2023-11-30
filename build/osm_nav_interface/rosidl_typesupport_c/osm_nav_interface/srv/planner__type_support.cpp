// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from osm_nav_interface:srv/Planner.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "osm_nav_interface/srv/detail/planner__struct.h"
#include "osm_nav_interface/srv/detail/planner__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace osm_nav_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Planner_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Planner_Request_type_support_ids_t;

static const _Planner_Request_type_support_ids_t _Planner_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Planner_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Planner_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Planner_Request_type_support_symbol_names_t _Planner_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, osm_nav_interface, srv, Planner_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, osm_nav_interface, srv, Planner_Request)),
  }
};

typedef struct _Planner_Request_type_support_data_t
{
  void * data[2];
} _Planner_Request_type_support_data_t;

static _Planner_Request_type_support_data_t _Planner_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Planner_Request_message_typesupport_map = {
  2,
  "osm_nav_interface",
  &_Planner_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Planner_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Planner_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Planner_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Planner_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace osm_nav_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, osm_nav_interface, srv, Planner_Request)() {
  return &::osm_nav_interface::srv::rosidl_typesupport_c::Planner_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "osm_nav_interface/srv/detail/planner__struct.h"
// already included above
// #include "osm_nav_interface/srv/detail/planner__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace osm_nav_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Planner_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Planner_Response_type_support_ids_t;

static const _Planner_Response_type_support_ids_t _Planner_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Planner_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Planner_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Planner_Response_type_support_symbol_names_t _Planner_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, osm_nav_interface, srv, Planner_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, osm_nav_interface, srv, Planner_Response)),
  }
};

typedef struct _Planner_Response_type_support_data_t
{
  void * data[2];
} _Planner_Response_type_support_data_t;

static _Planner_Response_type_support_data_t _Planner_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Planner_Response_message_typesupport_map = {
  2,
  "osm_nav_interface",
  &_Planner_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Planner_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Planner_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Planner_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Planner_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace osm_nav_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, osm_nav_interface, srv, Planner_Response)() {
  return &::osm_nav_interface::srv::rosidl_typesupport_c::Planner_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "osm_nav_interface/srv/detail/planner__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace osm_nav_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Planner_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Planner_type_support_ids_t;

static const _Planner_type_support_ids_t _Planner_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Planner_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Planner_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Planner_type_support_symbol_names_t _Planner_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, osm_nav_interface, srv, Planner)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, osm_nav_interface, srv, Planner)),
  }
};

typedef struct _Planner_type_support_data_t
{
  void * data[2];
} _Planner_type_support_data_t;

static _Planner_type_support_data_t _Planner_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Planner_service_typesupport_map = {
  2,
  "osm_nav_interface",
  &_Planner_service_typesupport_ids.typesupport_identifier[0],
  &_Planner_service_typesupport_symbol_names.symbol_name[0],
  &_Planner_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Planner_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Planner_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace osm_nav_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, osm_nav_interface, srv, Planner)() {
  return &::osm_nav_interface::srv::rosidl_typesupport_c::Planner_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
