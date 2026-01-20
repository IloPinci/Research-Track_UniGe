// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from a2_controller:srv/SetSafetyThreshold.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__SRV__DETAIL__SET_SAFETY_THRESHOLD__BUILDER_HPP_
#define A2_CONTROLLER__SRV__DETAIL__SET_SAFETY_THRESHOLD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "a2_controller/srv/detail/set_safety_threshold__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace a2_controller
{

namespace srv
{

namespace builder
{

class Init_SetSafetyThreshold_Request_new_threshold
{
public:
  Init_SetSafetyThreshold_Request_new_threshold()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::a2_controller::srv::SetSafetyThreshold_Request new_threshold(::a2_controller::srv::SetSafetyThreshold_Request::_new_threshold_type arg)
  {
    msg_.new_threshold = std::move(arg);
    return std::move(msg_);
  }

private:
  ::a2_controller::srv::SetSafetyThreshold_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::a2_controller::srv::SetSafetyThreshold_Request>()
{
  return a2_controller::srv::builder::Init_SetSafetyThreshold_Request_new_threshold();
}

}  // namespace a2_controller


namespace a2_controller
{

namespace srv
{

namespace builder
{

class Init_SetSafetyThreshold_Response_success
{
public:
  Init_SetSafetyThreshold_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::a2_controller::srv::SetSafetyThreshold_Response success(::a2_controller::srv::SetSafetyThreshold_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::a2_controller::srv::SetSafetyThreshold_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::a2_controller::srv::SetSafetyThreshold_Response>()
{
  return a2_controller::srv::builder::Init_SetSafetyThreshold_Response_success();
}

}  // namespace a2_controller

#endif  // A2_CONTROLLER__SRV__DETAIL__SET_SAFETY_THRESHOLD__BUILDER_HPP_
