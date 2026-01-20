// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from a2_controller:msg/ObstacleInfo.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__TRAITS_HPP_
#define A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "a2_controller/msg/detail/obstacle_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace a2_controller
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObstacleInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: min_distance
  {
    out << "min_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.min_distance, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << ", ";
  }

  // member: current_threshold
  {
    out << "current_threshold: ";
    rosidl_generator_traits::value_to_yaml(msg.current_threshold, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObstacleInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: min_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.min_distance, out);
    out << "\n";
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }

  // member: current_threshold
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_threshold: ";
    rosidl_generator_traits::value_to_yaml(msg.current_threshold, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObstacleInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace a2_controller

namespace rosidl_generator_traits
{

[[deprecated("use a2_controller::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const a2_controller::msg::ObstacleInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  a2_controller::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use a2_controller::msg::to_yaml() instead")]]
inline std::string to_yaml(const a2_controller::msg::ObstacleInfo & msg)
{
  return a2_controller::msg::to_yaml(msg);
}

template<>
inline const char * data_type<a2_controller::msg::ObstacleInfo>()
{
  return "a2_controller::msg::ObstacleInfo";
}

template<>
inline const char * name<a2_controller::msg::ObstacleInfo>()
{
  return "a2_controller/msg/ObstacleInfo";
}

template<>
struct has_fixed_size<a2_controller::msg::ObstacleInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<a2_controller::msg::ObstacleInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<a2_controller::msg::ObstacleInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__TRAITS_HPP_
