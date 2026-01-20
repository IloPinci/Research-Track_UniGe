// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from a2_controller:srv/GetVelocityStats.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__BUILDER_HPP_
#define A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "a2_controller/srv/detail/get_velocity_stats__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace a2_controller
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::a2_controller::srv::GetVelocityStats_Request>()
{
  return ::a2_controller::srv::GetVelocityStats_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace a2_controller


namespace a2_controller
{

namespace srv
{

namespace builder
{

class Init_GetVelocityStats_Response_avg_angular_vel
{
public:
  explicit Init_GetVelocityStats_Response_avg_angular_vel(::a2_controller::srv::GetVelocityStats_Response & msg)
  : msg_(msg)
  {}
  ::a2_controller::srv::GetVelocityStats_Response avg_angular_vel(::a2_controller::srv::GetVelocityStats_Response::_avg_angular_vel_type arg)
  {
    msg_.avg_angular_vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::a2_controller::srv::GetVelocityStats_Response msg_;
};

class Init_GetVelocityStats_Response_avg_linear_vel
{
public:
  Init_GetVelocityStats_Response_avg_linear_vel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetVelocityStats_Response_avg_angular_vel avg_linear_vel(::a2_controller::srv::GetVelocityStats_Response::_avg_linear_vel_type arg)
  {
    msg_.avg_linear_vel = std::move(arg);
    return Init_GetVelocityStats_Response_avg_angular_vel(msg_);
  }

private:
  ::a2_controller::srv::GetVelocityStats_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::a2_controller::srv::GetVelocityStats_Response>()
{
  return a2_controller::srv::builder::Init_GetVelocityStats_Response_avg_linear_vel();
}

}  // namespace a2_controller

#endif  // A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__BUILDER_HPP_
