// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from a2_controller:msg/ObstacleInfo.idl
// generated code does not contain a copyright notice

#ifndef A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__FUNCTIONS_H_
#define A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "a2_controller/msg/rosidl_generator_c__visibility_control.h"

#include "a2_controller/msg/detail/obstacle_info__struct.h"

/// Initialize msg/ObstacleInfo message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * a2_controller__msg__ObstacleInfo
 * )) before or use
 * a2_controller__msg__ObstacleInfo__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
bool
a2_controller__msg__ObstacleInfo__init(a2_controller__msg__ObstacleInfo * msg);

/// Finalize msg/ObstacleInfo message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
void
a2_controller__msg__ObstacleInfo__fini(a2_controller__msg__ObstacleInfo * msg);

/// Create msg/ObstacleInfo message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * a2_controller__msg__ObstacleInfo__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
a2_controller__msg__ObstacleInfo *
a2_controller__msg__ObstacleInfo__create();

/// Destroy msg/ObstacleInfo message.
/**
 * It calls
 * a2_controller__msg__ObstacleInfo__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
void
a2_controller__msg__ObstacleInfo__destroy(a2_controller__msg__ObstacleInfo * msg);

/// Check for msg/ObstacleInfo message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
bool
a2_controller__msg__ObstacleInfo__are_equal(const a2_controller__msg__ObstacleInfo * lhs, const a2_controller__msg__ObstacleInfo * rhs);

/// Copy a msg/ObstacleInfo message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
bool
a2_controller__msg__ObstacleInfo__copy(
  const a2_controller__msg__ObstacleInfo * input,
  a2_controller__msg__ObstacleInfo * output);

/// Initialize array of msg/ObstacleInfo messages.
/**
 * It allocates the memory for the number of elements and calls
 * a2_controller__msg__ObstacleInfo__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
bool
a2_controller__msg__ObstacleInfo__Sequence__init(a2_controller__msg__ObstacleInfo__Sequence * array, size_t size);

/// Finalize array of msg/ObstacleInfo messages.
/**
 * It calls
 * a2_controller__msg__ObstacleInfo__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
void
a2_controller__msg__ObstacleInfo__Sequence__fini(a2_controller__msg__ObstacleInfo__Sequence * array);

/// Create array of msg/ObstacleInfo messages.
/**
 * It allocates the memory for the array and calls
 * a2_controller__msg__ObstacleInfo__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
a2_controller__msg__ObstacleInfo__Sequence *
a2_controller__msg__ObstacleInfo__Sequence__create(size_t size);

/// Destroy array of msg/ObstacleInfo messages.
/**
 * It calls
 * a2_controller__msg__ObstacleInfo__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
void
a2_controller__msg__ObstacleInfo__Sequence__destroy(a2_controller__msg__ObstacleInfo__Sequence * array);

/// Check for msg/ObstacleInfo message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
bool
a2_controller__msg__ObstacleInfo__Sequence__are_equal(const a2_controller__msg__ObstacleInfo__Sequence * lhs, const a2_controller__msg__ObstacleInfo__Sequence * rhs);

/// Copy an array of msg/ObstacleInfo messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_a2_controller
bool
a2_controller__msg__ObstacleInfo__Sequence__copy(
  const a2_controller__msg__ObstacleInfo__Sequence * input,
  a2_controller__msg__ObstacleInfo__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // A2_CONTROLLER__MSG__DETAIL__OBSTACLE_INFO__FUNCTIONS_H_
