// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from a2_controller:srv/GetVelocityStats.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__TRAITS_HPP_
#define A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "a2_controller/srv/detail/get_velocity_stats__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace a2_controller
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetVelocityStats_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetVelocityStats_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetVelocityStats_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace a2_controller

namespace rosidl_generator_traits
{

[[deprecated("use a2_controller::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const a2_controller::srv::GetVelocityStats_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  a2_controller::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use a2_controller::srv::to_yaml() instead")]]
inline std::string to_yaml(const a2_controller::srv::GetVelocityStats_Request & msg)
{
  return a2_controller::srv::to_yaml(msg);
}

template<>
inline const char * data_type<a2_controller::srv::GetVelocityStats_Request>()
{
  return "a2_controller::srv::GetVelocityStats_Request";
}

template<>
inline const char * name<a2_controller::srv::GetVelocityStats_Request>()
{
  return "a2_controller/srv/GetVelocityStats_Request";
}

template<>
struct has_fixed_size<a2_controller::srv::GetVelocityStats_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<a2_controller::srv::GetVelocityStats_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<a2_controller::srv::GetVelocityStats_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace a2_controller
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetVelocityStats_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: avg_linear_vel
  {
    out << "avg_linear_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_linear_vel, out);
    out << ", ";
  }

  // member: avg_angular_vel
  {
    out << "avg_angular_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_angular_vel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetVelocityStats_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: avg_linear_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "avg_linear_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_linear_vel, out);
    out << "\n";
  }

  // member: avg_angular_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "avg_angular_vel: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_angular_vel, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetVelocityStats_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace a2_controller

namespace rosidl_generator_traits
{

[[deprecated("use a2_controller::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const a2_controller::srv::GetVelocityStats_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  a2_controller::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use a2_controller::srv::to_yaml() instead")]]
inline std::string to_yaml(const a2_controller::srv::GetVelocityStats_Response & msg)
{
  return a2_controller::srv::to_yaml(msg);
}

template<>
inline const char * data_type<a2_controller::srv::GetVelocityStats_Response>()
{
  return "a2_controller::srv::GetVelocityStats_Response";
}

template<>
inline const char * name<a2_controller::srv::GetVelocityStats_Response>()
{
  return "a2_controller/srv/GetVelocityStats_Response";
}

template<>
struct has_fixed_size<a2_controller::srv::GetVelocityStats_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<a2_controller::srv::GetVelocityStats_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<a2_controller::srv::GetVelocityStats_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<a2_controller::srv::GetVelocityStats>()
{
  return "a2_controller::srv::GetVelocityStats";
}

template<>
inline const char * name<a2_controller::srv::GetVelocityStats>()
{
  return "a2_controller/srv/GetVelocityStats";
}

template<>
struct has_fixed_size<a2_controller::srv::GetVelocityStats>
  : std::integral_constant<
    bool,
    has_fixed_size<a2_controller::srv::GetVelocityStats_Request>::value &&
    has_fixed_size<a2_controller::srv::GetVelocityStats_Response>::value
  >
{
};

template<>
struct has_bounded_size<a2_controller::srv::GetVelocityStats>
  : std::integral_constant<
    bool,
    has_bounded_size<a2_controller::srv::GetVelocityStats_Request>::value &&
    has_bounded_size<a2_controller::srv::GetVelocityStats_Response>::value
  >
{
};

template<>
struct is_service<a2_controller::srv::GetVelocityStats>
  : std::true_type
{
};

template<>
struct is_service_request<a2_controller::srv::GetVelocityStats_Request>
  : std::true_type
{
};

template<>
struct is_service_response<a2_controller::srv::GetVelocityStats_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__TRAITS_HPP_
