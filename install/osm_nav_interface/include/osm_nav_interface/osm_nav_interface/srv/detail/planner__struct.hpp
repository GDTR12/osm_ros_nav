// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from osm_nav_interface:srv/Planner.idl
// generated code does not contain a copyright notice

#ifndef OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__STRUCT_HPP_
#define OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__osm_nav_interface__srv__Planner_Request __attribute__((deprecated))
#else
# define DEPRECATED__osm_nav_interface__srv__Planner_Request __declspec(deprecated)
#endif

namespace osm_nav_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Planner_Request_
{
  using Type = Planner_Request_<ContainerAllocator>;

  explicit Planner_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_lon = 0.0;
      this->current_lat = 0.0;
      this->target_lon = 0.0;
      this->target_lat = 0.0;
    }
  }

  explicit Planner_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_lon = 0.0;
      this->current_lat = 0.0;
      this->target_lon = 0.0;
      this->target_lat = 0.0;
    }
  }

  // field types and members
  using _current_lon_type =
    double;
  _current_lon_type current_lon;
  using _current_lat_type =
    double;
  _current_lat_type current_lat;
  using _target_lon_type =
    double;
  _target_lon_type target_lon;
  using _target_lat_type =
    double;
  _target_lat_type target_lat;

  // setters for named parameter idiom
  Type & set__current_lon(
    const double & _arg)
  {
    this->current_lon = _arg;
    return *this;
  }
  Type & set__current_lat(
    const double & _arg)
  {
    this->current_lat = _arg;
    return *this;
  }
  Type & set__target_lon(
    const double & _arg)
  {
    this->target_lon = _arg;
    return *this;
  }
  Type & set__target_lat(
    const double & _arg)
  {
    this->target_lat = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    osm_nav_interface::srv::Planner_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const osm_nav_interface::srv::Planner_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<osm_nav_interface::srv::Planner_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<osm_nav_interface::srv::Planner_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      osm_nav_interface::srv::Planner_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<osm_nav_interface::srv::Planner_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      osm_nav_interface::srv::Planner_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<osm_nav_interface::srv::Planner_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<osm_nav_interface::srv::Planner_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<osm_nav_interface::srv::Planner_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__osm_nav_interface__srv__Planner_Request
    std::shared_ptr<osm_nav_interface::srv::Planner_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__osm_nav_interface__srv__Planner_Request
    std::shared_ptr<osm_nav_interface::srv::Planner_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Planner_Request_ & other) const
  {
    if (this->current_lon != other.current_lon) {
      return false;
    }
    if (this->current_lat != other.current_lat) {
      return false;
    }
    if (this->target_lon != other.target_lon) {
      return false;
    }
    if (this->target_lat != other.target_lat) {
      return false;
    }
    return true;
  }
  bool operator!=(const Planner_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Planner_Request_

// alias to use template instance with default allocator
using Planner_Request =
  osm_nav_interface::srv::Planner_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace osm_nav_interface


#ifndef _WIN32
# define DEPRECATED__osm_nav_interface__srv__Planner_Response __attribute__((deprecated))
#else
# define DEPRECATED__osm_nav_interface__srv__Planner_Response __declspec(deprecated)
#endif

namespace osm_nav_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Planner_Response_
{
  using Type = Planner_Response_<ContainerAllocator>;

  explicit Planner_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->next_lon = 0.0;
      this->next_lat = 0.0;
    }
  }

  explicit Planner_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->next_lon = 0.0;
      this->next_lat = 0.0;
    }
  }

  // field types and members
  using _next_lon_type =
    double;
  _next_lon_type next_lon;
  using _next_lat_type =
    double;
  _next_lat_type next_lat;

  // setters for named parameter idiom
  Type & set__next_lon(
    const double & _arg)
  {
    this->next_lon = _arg;
    return *this;
  }
  Type & set__next_lat(
    const double & _arg)
  {
    this->next_lat = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    osm_nav_interface::srv::Planner_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const osm_nav_interface::srv::Planner_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<osm_nav_interface::srv::Planner_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<osm_nav_interface::srv::Planner_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      osm_nav_interface::srv::Planner_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<osm_nav_interface::srv::Planner_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      osm_nav_interface::srv::Planner_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<osm_nav_interface::srv::Planner_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<osm_nav_interface::srv::Planner_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<osm_nav_interface::srv::Planner_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__osm_nav_interface__srv__Planner_Response
    std::shared_ptr<osm_nav_interface::srv::Planner_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__osm_nav_interface__srv__Planner_Response
    std::shared_ptr<osm_nav_interface::srv::Planner_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Planner_Response_ & other) const
  {
    if (this->next_lon != other.next_lon) {
      return false;
    }
    if (this->next_lat != other.next_lat) {
      return false;
    }
    return true;
  }
  bool operator!=(const Planner_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Planner_Response_

// alias to use template instance with default allocator
using Planner_Response =
  osm_nav_interface::srv::Planner_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace osm_nav_interface

namespace osm_nav_interface
{

namespace srv
{

struct Planner
{
  using Request = osm_nav_interface::srv::Planner_Request;
  using Response = osm_nav_interface::srv::Planner_Response;
};

}  // namespace srv

}  // namespace osm_nav_interface

#endif  // OSM_NAV_INTERFACE__SRV__DETAIL__PLANNER__STRUCT_HPP_
