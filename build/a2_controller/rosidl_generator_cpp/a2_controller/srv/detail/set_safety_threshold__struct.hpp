// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from a2_controller:srv/SetSafetyThreshold.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__SRV__DETAIL__SET_SAFETY_THRESHOLD__STRUCT_HPP_
#define A2_CONTROLLER__SRV__DETAIL__SET_SAFETY_THRESHOLD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__a2_controller__srv__SetSafetyThreshold_Request __attribute__((deprecated))
#else
# define DEPRECATED__a2_controller__srv__SetSafetyThreshold_Request __declspec(deprecated)
#endif

namespace a2_controller
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetSafetyThreshold_Request_
{
  using Type = SetSafetyThreshold_Request_<ContainerAllocator>;

  explicit SetSafetyThreshold_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->new_threshold = 0.0f;
    }
  }

  explicit SetSafetyThreshold_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->new_threshold = 0.0f;
    }
  }

  // field types and members
  using _new_threshold_type =
    float;
  _new_threshold_type new_threshold;

  // setters for named parameter idiom
  Type & set__new_threshold(
    const float & _arg)
  {
    this->new_threshold = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__a2_controller__srv__SetSafetyThreshold_Request
    std::shared_ptr<a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__a2_controller__srv__SetSafetyThreshold_Request
    std::shared_ptr<a2_controller::srv::SetSafetyThreshold_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetSafetyThreshold_Request_ & other) const
  {
    if (this->new_threshold != other.new_threshold) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetSafetyThreshold_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetSafetyThreshold_Request_

// alias to use template instance with default allocator
using SetSafetyThreshold_Request =
  a2_controller::srv::SetSafetyThreshold_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace a2_controller


#ifndef _WIN32
# define DEPRECATED__a2_controller__srv__SetSafetyThreshold_Response __attribute__((deprecated))
#else
# define DEPRECATED__a2_controller__srv__SetSafetyThreshold_Response __declspec(deprecated)
#endif

namespace a2_controller
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetSafetyThreshold_Response_
{
  using Type = SetSafetyThreshold_Response_<ContainerAllocator>;

  explicit SetSafetyThreshold_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SetSafetyThreshold_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__a2_controller__srv__SetSafetyThreshold_Response
    std::shared_ptr<a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__a2_controller__srv__SetSafetyThreshold_Response
    std::shared_ptr<a2_controller::srv::SetSafetyThreshold_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetSafetyThreshold_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetSafetyThreshold_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetSafetyThreshold_Response_

// alias to use template instance with default allocator
using SetSafetyThreshold_Response =
  a2_controller::srv::SetSafetyThreshold_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace a2_controller

namespace a2_controller
{

namespace srv
{

struct SetSafetyThreshold
{
  using Request = a2_controller::srv::SetSafetyThreshold_Request;
  using Response = a2_controller::srv::SetSafetyThreshold_Response;
};

}  // namespace srv

}  // namespace a2_controller

#endif  // A2_CONTROLLER__SRV__DETAIL__SET_SAFETY_THRESHOLD__STRUCT_HPP_
