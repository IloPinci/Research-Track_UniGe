// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from a2_controller:srv/GetVelocityStats.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__STRUCT_HPP_
#define A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__a2_controller__srv__GetVelocityStats_Request __attribute__((deprecated))
#else
# define DEPRECATED__a2_controller__srv__GetVelocityStats_Request __declspec(deprecated)
#endif

namespace a2_controller
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetVelocityStats_Request_
{
  using Type = GetVelocityStats_Request_<ContainerAllocator>;

  explicit GetVelocityStats_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetVelocityStats_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__a2_controller__srv__GetVelocityStats_Request
    std::shared_ptr<a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__a2_controller__srv__GetVelocityStats_Request
    std::shared_ptr<a2_controller::srv::GetVelocityStats_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetVelocityStats_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetVelocityStats_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetVelocityStats_Request_

// alias to use template instance with default allocator
using GetVelocityStats_Request =
  a2_controller::srv::GetVelocityStats_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace a2_controller


#ifndef _WIN32
# define DEPRECATED__a2_controller__srv__GetVelocityStats_Response __attribute__((deprecated))
#else
# define DEPRECATED__a2_controller__srv__GetVelocityStats_Response __declspec(deprecated)
#endif

namespace a2_controller
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetVelocityStats_Response_
{
  using Type = GetVelocityStats_Response_<ContainerAllocator>;

  explicit GetVelocityStats_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->avg_linear_vel = 0.0f;
      this->avg_angular_vel = 0.0f;
    }
  }

  explicit GetVelocityStats_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->avg_linear_vel = 0.0f;
      this->avg_angular_vel = 0.0f;
    }
  }

  // field types and members
  using _avg_linear_vel_type =
    float;
  _avg_linear_vel_type avg_linear_vel;
  using _avg_angular_vel_type =
    float;
  _avg_angular_vel_type avg_angular_vel;

  // setters for named parameter idiom
  Type & set__avg_linear_vel(
    const float & _arg)
  {
    this->avg_linear_vel = _arg;
    return *this;
  }
  Type & set__avg_angular_vel(
    const float & _arg)
  {
    this->avg_angular_vel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__a2_controller__srv__GetVelocityStats_Response
    std::shared_ptr<a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__a2_controller__srv__GetVelocityStats_Response
    std::shared_ptr<a2_controller::srv::GetVelocityStats_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetVelocityStats_Response_ & other) const
  {
    if (this->avg_linear_vel != other.avg_linear_vel) {
      return false;
    }
    if (this->avg_angular_vel != other.avg_angular_vel) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetVelocityStats_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetVelocityStats_Response_

// alias to use template instance with default allocator
using GetVelocityStats_Response =
  a2_controller::srv::GetVelocityStats_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace a2_controller

namespace a2_controller
{

namespace srv
{

struct GetVelocityStats
{
  using Request = a2_controller::srv::GetVelocityStats_Request;
  using Response = a2_controller::srv::GetVelocityStats_Response;
};

}  // namespace srv

}  // namespace a2_controller

#endif  // A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__STRUCT_HPP_
