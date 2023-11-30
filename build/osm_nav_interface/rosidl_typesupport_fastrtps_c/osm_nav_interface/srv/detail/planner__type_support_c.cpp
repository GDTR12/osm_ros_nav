// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from osm_nav_interface:srv/Planner.idl
// generated code does not contain a copyright notice
#include "osm_nav_interface/srv/detail/planner__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "osm_nav_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "osm_nav_interface/srv/detail/planner__struct.h"
#include "osm_nav_interface/srv/detail/planner__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Planner_Request__ros_msg_type = osm_nav_interface__srv__Planner_Request;

static bool _Planner_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Planner_Request__ros_msg_type * ros_message = static_cast<const _Planner_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: current_lon
  {
    cdr << ros_message->current_lon;
  }

  // Field name: current_lat
  {
    cdr << ros_message->current_lat;
  }

  // Field name: target_lon
  {
    cdr << ros_message->target_lon;
  }

  // Field name: target_lat
  {
    cdr << ros_message->target_lat;
  }

  return true;
}

static bool _Planner_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Planner_Request__ros_msg_type * ros_message = static_cast<_Planner_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: current_lon
  {
    cdr >> ros_message->current_lon;
  }

  // Field name: current_lat
  {
    cdr >> ros_message->current_lat;
  }

  // Field name: target_lon
  {
    cdr >> ros_message->target_lon;
  }

  // Field name: target_lat
  {
    cdr >> ros_message->target_lat;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osm_nav_interface
size_t get_serialized_size_osm_nav_interface__srv__Planner_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Planner_Request__ros_msg_type * ros_message = static_cast<const _Planner_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name current_lon
  {
    size_t item_size = sizeof(ros_message->current_lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_lat
  {
    size_t item_size = sizeof(ros_message->current_lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_lon
  {
    size_t item_size = sizeof(ros_message->target_lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_lat
  {
    size_t item_size = sizeof(ros_message->target_lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Planner_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_osm_nav_interface__srv__Planner_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osm_nav_interface
size_t max_serialized_size_osm_nav_interface__srv__Planner_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: current_lon
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: current_lat
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: target_lon
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: target_lat
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Planner_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_osm_nav_interface__srv__Planner_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Planner_Request = {
  "osm_nav_interface::srv",
  "Planner_Request",
  _Planner_Request__cdr_serialize,
  _Planner_Request__cdr_deserialize,
  _Planner_Request__get_serialized_size,
  _Planner_Request__max_serialized_size
};

static rosidl_message_type_support_t _Planner_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Planner_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, osm_nav_interface, srv, Planner_Request)() {
  return &_Planner_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "osm_nav_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "osm_nav_interface/srv/detail/planner__struct.h"
// already included above
// #include "osm_nav_interface/srv/detail/planner__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Planner_Response__ros_msg_type = osm_nav_interface__srv__Planner_Response;

static bool _Planner_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Planner_Response__ros_msg_type * ros_message = static_cast<const _Planner_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: next_lon
  {
    cdr << ros_message->next_lon;
  }

  // Field name: next_lat
  {
    cdr << ros_message->next_lat;
  }

  return true;
}

static bool _Planner_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Planner_Response__ros_msg_type * ros_message = static_cast<_Planner_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: next_lon
  {
    cdr >> ros_message->next_lon;
  }

  // Field name: next_lat
  {
    cdr >> ros_message->next_lat;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osm_nav_interface
size_t get_serialized_size_osm_nav_interface__srv__Planner_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Planner_Response__ros_msg_type * ros_message = static_cast<const _Planner_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name next_lon
  {
    size_t item_size = sizeof(ros_message->next_lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name next_lat
  {
    size_t item_size = sizeof(ros_message->next_lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Planner_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_osm_nav_interface__srv__Planner_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_osm_nav_interface
size_t max_serialized_size_osm_nav_interface__srv__Planner_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: next_lon
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: next_lat
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _Planner_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_osm_nav_interface__srv__Planner_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Planner_Response = {
  "osm_nav_interface::srv",
  "Planner_Response",
  _Planner_Response__cdr_serialize,
  _Planner_Response__cdr_deserialize,
  _Planner_Response__get_serialized_size,
  _Planner_Response__max_serialized_size
};

static rosidl_message_type_support_t _Planner_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Planner_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, osm_nav_interface, srv, Planner_Response)() {
  return &_Planner_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "osm_nav_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "osm_nav_interface/srv/planner.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Planner__callbacks = {
  "osm_nav_interface::srv",
  "Planner",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, osm_nav_interface, srv, Planner_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, osm_nav_interface, srv, Planner_Response)(),
};

static rosidl_service_type_support_t Planner__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Planner__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, osm_nav_interface, srv, Planner)() {
  return &Planner__handle;
}

#if defined(__cplusplus)
}
#endif
