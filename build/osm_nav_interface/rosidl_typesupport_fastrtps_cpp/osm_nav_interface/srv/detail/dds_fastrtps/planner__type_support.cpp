// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from osm_nav_interface:srv/Planner.idl
// generated code does not contain a copyright notice
#include "osm_nav_interface/srv/detail/planner__rosidl_typesupport_fastrtps_cpp.hpp"
#include "osm_nav_interface/srv/detail/planner__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace osm_nav_interface
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osm_nav_interface
cdr_serialize(
  const osm_nav_interface::srv::Planner_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: current_lon
  cdr << ros_message.current_lon;
  // Member: current_lat
  cdr << ros_message.current_lat;
  // Member: target_lon
  cdr << ros_message.target_lon;
  // Member: target_lat
  cdr << ros_message.target_lat;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osm_nav_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  osm_nav_interface::srv::Planner_Request & ros_message)
{
  // Member: current_lon
  cdr >> ros_message.current_lon;

  // Member: current_lat
  cdr >> ros_message.current_lat;

  // Member: target_lon
  cdr >> ros_message.target_lon;

  // Member: target_lat
  cdr >> ros_message.target_lat;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osm_nav_interface
get_serialized_size(
  const osm_nav_interface::srv::Planner_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: current_lon
  {
    size_t item_size = sizeof(ros_message.current_lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_lat
  {
    size_t item_size = sizeof(ros_message.current_lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: target_lon
  {
    size_t item_size = sizeof(ros_message.target_lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: target_lat
  {
    size_t item_size = sizeof(ros_message.target_lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osm_nav_interface
max_serialized_size_Planner_Request(
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


  // Member: current_lon
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: current_lat
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: target_lon
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: target_lat
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Planner_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const osm_nav_interface::srv::Planner_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Planner_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<osm_nav_interface::srv::Planner_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Planner_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const osm_nav_interface::srv::Planner_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Planner_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Planner_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Planner_Request__callbacks = {
  "osm_nav_interface::srv",
  "Planner_Request",
  _Planner_Request__cdr_serialize,
  _Planner_Request__cdr_deserialize,
  _Planner_Request__get_serialized_size,
  _Planner_Request__max_serialized_size
};

static rosidl_message_type_support_t _Planner_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Planner_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace osm_nav_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_osm_nav_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<osm_nav_interface::srv::Planner_Request>()
{
  return &osm_nav_interface::srv::typesupport_fastrtps_cpp::_Planner_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, osm_nav_interface, srv, Planner_Request)() {
  return &osm_nav_interface::srv::typesupport_fastrtps_cpp::_Planner_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace osm_nav_interface
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osm_nav_interface
cdr_serialize(
  const osm_nav_interface::srv::Planner_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: next_lon
  cdr << ros_message.next_lon;
  // Member: next_lat
  cdr << ros_message.next_lat;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osm_nav_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  osm_nav_interface::srv::Planner_Response & ros_message)
{
  // Member: next_lon
  cdr >> ros_message.next_lon;

  // Member: next_lat
  cdr >> ros_message.next_lat;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osm_nav_interface
get_serialized_size(
  const osm_nav_interface::srv::Planner_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: next_lon
  {
    size_t item_size = sizeof(ros_message.next_lon);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: next_lat
  {
    size_t item_size = sizeof(ros_message.next_lat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_osm_nav_interface
max_serialized_size_Planner_Response(
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


  // Member: next_lon
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: next_lat
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Planner_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const osm_nav_interface::srv::Planner_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Planner_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<osm_nav_interface::srv::Planner_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Planner_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const osm_nav_interface::srv::Planner_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Planner_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Planner_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Planner_Response__callbacks = {
  "osm_nav_interface::srv",
  "Planner_Response",
  _Planner_Response__cdr_serialize,
  _Planner_Response__cdr_deserialize,
  _Planner_Response__get_serialized_size,
  _Planner_Response__max_serialized_size
};

static rosidl_message_type_support_t _Planner_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Planner_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace osm_nav_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_osm_nav_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<osm_nav_interface::srv::Planner_Response>()
{
  return &osm_nav_interface::srv::typesupport_fastrtps_cpp::_Planner_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, osm_nav_interface, srv, Planner_Response)() {
  return &osm_nav_interface::srv::typesupport_fastrtps_cpp::_Planner_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace osm_nav_interface
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _Planner__callbacks = {
  "osm_nav_interface::srv",
  "Planner",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, osm_nav_interface, srv, Planner_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, osm_nav_interface, srv, Planner_Response)(),
};

static rosidl_service_type_support_t _Planner__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Planner__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace osm_nav_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_osm_nav_interface
const rosidl_service_type_support_t *
get_service_type_support_handle<osm_nav_interface::srv::Planner>()
{
  return &osm_nav_interface::srv::typesupport_fastrtps_cpp::_Planner__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, osm_nav_interface, srv, Planner)() {
  return &osm_nav_interface::srv::typesupport_fastrtps_cpp::_Planner__handle;
}

#ifdef __cplusplus
}
#endif
