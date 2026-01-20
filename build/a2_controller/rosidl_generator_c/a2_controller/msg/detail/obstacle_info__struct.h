// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from a2_controller:msg/ObstacleInfo.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__STRUCT_H_
#define A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'direction'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ObstacleInfo in the package a2_controller.
typedef struct a2_controller__msg__ObstacleInfo
{
  float min_distance;
  rosidl_runtime_c__String direction;
  float current_threshold;
} a2_controller__msg__ObstacleInfo;

// Struct for a sequence of a2_controller__msg__ObstacleInfo.
typedef struct a2_controller__msg__ObstacleInfo__Sequence
{
  a2_controller__msg__ObstacleInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} a2_controller__msg__ObstacleInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__STRUCT_H_
