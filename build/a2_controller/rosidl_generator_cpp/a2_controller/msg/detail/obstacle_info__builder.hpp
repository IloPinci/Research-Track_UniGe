// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from a2_controller:msg/ObstacleInfo.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__BUILDER_HPP_
#define A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "a2_controller/msg/detail/obstacle_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace a2_controller
{

namespace msg
{

namespace builder
{

class Init_ObstacleInfo_current_threshold
{
public:
  explicit Init_ObstacleInfo_current_threshold(::a2_controller::msg::ObstacleInfo & msg)
  : msg_(msg)
  {}
  ::a2_controller::msg::ObstacleInfo current_threshold(::a2_controller::msg::ObstacleInfo::_current_threshold_type arg)
  {
    msg_.current_threshold = std::move(arg);
    return std::move(msg_);
  }

private:
  ::a2_controller::msg::ObstacleInfo msg_;
};

class Init_ObstacleInfo_direction
{
public:
  explicit Init_ObstacleInfo_direction(::a2_controller::msg::ObstacleInfo & msg)
  : msg_(msg)
  {}
  Init_ObstacleInfo_current_threshold direction(::a2_controller::msg::ObstacleInfo::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return Init_ObstacleInfo_current_threshold(msg_);
  }

private:
  ::a2_controller::msg::ObstacleInfo msg_;
};

class Init_ObstacleInfo_min_distance
{
public:
  Init_ObstacleInfo_min_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObstacleInfo_direction min_distance(::a2_controller::msg::ObstacleInfo::_min_distance_type arg)
  {
    msg_.min_distance = std::move(arg);
    return Init_ObstacleInfo_direction(msg_);
  }

private:
  ::a2_controller::msg::ObstacleInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::a2_controller::msg::ObstacleInfo>()
{
  return a2_controller::msg::builder::Init_ObstacleInfo_min_distance();
}

}  // namespace a2_controller

#endif  // A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__BUILDER_HPP_
