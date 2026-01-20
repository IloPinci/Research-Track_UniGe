// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from a2_controller:srv/SetSafetyThreshold.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__SRV__DETAIL__SET_SAFETY_THRESHOLD__TRAITS_HPP_
#define A2_CONTROLLER__SRV__DETAIL__SET_SAFETY_THRESHOLD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "a2_controller/srv/detail/set_safety_threshold__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace a2_controller
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetSafetyThreshold_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: new_threshold
  {
    out << "new_threshold: ";
    rosidl_generator_traits::value_to_yaml(msg.new_threshold, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetSafetyThreshold_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: new_threshold
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "new_threshold: ";
    rosidl_generator_traits::value_to_yaml(msg.new_threshold, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetSafetyThreshold_Request & msg, bool use_flow_style = false)
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
  const a2_controller::srv::SetSafetyThreshold_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  a2_controller::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use a2_controller::srv::to_yaml() instead")]]
inline std::string to_yaml(const a2_controller::srv::SetSafetyThreshold_Request & msg)
{
  return a2_controller::srv::to_yaml(msg);
}

template<>
inline const char * data_type<a2_controller::srv::SetSafetyThreshold_Request>()
{
  return "a2_controller::srv::SetSafetyThreshold_Request";
}

template<>
inline const char * name<a2_controller::srv::SetSafetyThreshold_Request>()
{
  return "a2_controller/srv/SetSafetyThreshold_Request";
}

template<>
struct has_fixed_size<a2_controller::srv::SetSafetyThreshold_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<a2_controller::srv::SetSafetyThreshold_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<a2_controller::srv::SetSafetyThreshold_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace a2_controller
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetSafetyThreshold_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetSafetyThreshold_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetSafetyThreshold_Response & msg, bool use_flow_style = false)
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
  const a2_controller::srv::SetSafetyThreshold_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  a2_controller::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use a2_controller::srv::to_yaml() instead")]]
inline std::string to_yaml(const a2_controller::srv::SetSafetyThreshold_Response & msg)
{
  return a2_controller::srv::to_yaml(msg);
}

template<>
inline const char * data_type<a2_controller::srv::SetSafetyThreshold_Response>()
{
  return "a2_controller::srv::SetSafetyThreshold_Response";
}

template<>
inline const char * name<a2_controller::srv::SetSafetyThreshold_Response>()
{
  return "a2_controller/srv/SetSafetyThreshold_Response";
}

template<>
struct has_fixed_size<a2_controller::srv::SetSafetyThreshold_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<a2_controller::srv::SetSafetyThreshold_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<a2_controller::srv::SetSafetyThreshold_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<a2_controller::srv::SetSafetyThreshold>()
{
  return "a2_controller::srv::SetSafetyThreshold";
}

template<>
inline const char * name<a2_controller::srv::SetSafetyThreshold>()
{
  return "a2_controller/srv/SetSafetyThreshold";
}

template<>
struct has_fixed_size<a2_controller::srv::SetSafetyThreshold>
  : std::integral_constant<
    bool,
    has_fixed_size<a2_controller::srv::SetSafetyThreshold_Request>::value &&
    has_fixed_size<a2_controller::srv::SetSafetyThreshold_Response>::value
  >
{
};

template<>
struct has_bounded_size<a2_controller::srv::SetSafetyThreshold>
  : std::integral_constant<
    bool,
    has_bounded_size<a2_controller::srv::SetSafetyThreshold_Request>::value &&
    has_bounded_size<a2_controller::srv::SetSafetyThreshold_Response>::value
  >
{
};

template<>
struct is_service<a2_controller::srv::SetSafetyThreshold>
  : std::true_type
{
};

template<>
struct is_service_request<a2_controller::srv::SetSafetyThreshold_Request>
  : std::true_type
{
};

template<>
struct is_service_response<a2_controller::srv::SetSafetyThreshold_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // A2_CONTROLLER__SRV__DETAIL__SET_SAFETY_THRESHOLD__TRAITS_HPP_
