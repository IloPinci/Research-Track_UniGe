// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from a2_controller:msg/ObstacleInfo.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__STRUCT_HPP_
#define A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__a2_controller__msg__ObstacleInfo __attribute__((deprecated))
#else
# define DEPRECATED__a2_controller__msg__ObstacleInfo __declspec(deprecated)
#endif

namespace a2_controller
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObstacleInfo_
{
  using Type = ObstacleInfo_<ContainerAllocator>;

  explicit ObstacleInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min_distance = 0.0f;
      this->direction = "";
      this->current_threshold = 0.0f;
    }
  }

  explicit ObstacleInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : direction(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->min_distance = 0.0f;
      this->direction = "";
      this->current_threshold = 0.0f;
    }
  }

  // field types and members
  using _min_distance_type =
    float;
  _min_distance_type min_distance;
  using _direction_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _direction_type direction;
  using _current_threshold_type =
    float;
  _current_threshold_type current_threshold;

  // setters for named parameter idiom
  Type & set__min_distance(
    const float & _arg)
  {
    this->min_distance = _arg;
    return *this;
  }
  Type & set__direction(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->direction = _arg;
    return *this;
  }
  Type & set__current_threshold(
    const float & _arg)
  {
    this->current_threshold = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    a2_controller::msg::ObstacleInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const a2_controller::msg::ObstacleInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<a2_controller::msg::ObstacleInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<a2_controller::msg::ObstacleInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      a2_controller::msg::ObstacleInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<a2_controller::msg::ObstacleInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      a2_controller::msg::ObstacleInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<a2_controller::msg::ObstacleInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<a2_controller::msg::ObstacleInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<a2_controller::msg::ObstacleInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__a2_controller__msg__ObstacleInfo
    std::shared_ptr<a2_controller::msg::ObstacleInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__a2_controller__msg__ObstacleInfo
    std::shared_ptr<a2_controller::msg::ObstacleInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObstacleInfo_ & other) const
  {
    if (this->min_distance != other.min_distance) {
      return false;
    }
    if (this->direction != other.direction) {
      return false;
    }
    if (this->current_threshold != other.current_threshold) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObstacleInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObstacleInfo_

// alias to use template instance with default allocator
using ObstacleInfo =
  a2_controller::msg::ObstacleInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace a2_controller

#endif  // A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__STRUCT_HPP_
