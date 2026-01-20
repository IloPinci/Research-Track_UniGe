// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from a2_controller:srv/GetVelocityStats.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__STRUCT_H_
#define A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetVelocityStats in the package a2_controller.
typedef struct a2_controller__srv__GetVelocityStats_Request
{
  uint8_t structure_needs_at_least_one_member;
} a2_controller__srv__GetVelocityStats_Request;

// Struct for a sequence of a2_controller__srv__GetVelocityStats_Request.
typedef struct a2_controller__srv__GetVelocityStats_Request__Sequence
{
  a2_controller__srv__GetVelocityStats_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} a2_controller__srv__GetVelocityStats_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/GetVelocityStats in the package a2_controller.
typedef struct a2_controller__srv__GetVelocityStats_Response
{
  float avg_linear_vel;
  float avg_angular_vel;
} a2_controller__srv__GetVelocityStats_Response;

// Struct for a sequence of a2_controller__srv__GetVelocityStats_Response.
typedef struct a2_controller__srv__GetVelocityStats_Response__Sequence
{
  a2_controller__srv__GetVelocityStats_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} a2_controller__srv__GetVelocityStats_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // A2_CONTROLLER__SRV__DETAIL__GET_VELOCITY_STATS__STRUCT_H_
