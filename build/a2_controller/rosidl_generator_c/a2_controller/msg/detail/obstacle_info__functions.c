// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from a2_controller:msg/ObstacleInfo.idl
// generated code does not contain a copyright notice
#include "a2_controller/msg/detail/obstacle_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `direction`
#include "rosidl_runtime_c/string_functions.h"

bool
a2_controller__msg__ObstacleInfo__init(a2_controller__msg__ObstacleInfo * msg)
{
  if (!msg) {
    return false;
  }
  // min_distance
  // direction
  if (!rosidl_runtime_c__String__init(&msg->direction)) {
    a2_controller__msg__ObstacleInfo__fini(msg);
    return false;
  }
  // current_threshold
  return true;
}

void
a2_controller__msg__ObstacleInfo__fini(a2_controller__msg__ObstacleInfo * msg)
{
  if (!msg) {
    return;
  }
  // min_distance
  // direction
  rosidl_runtime_c__String__fini(&msg->direction);
  // current_threshold
}

bool
a2_controller__msg__ObstacleInfo__are_equal(const a2_controller__msg__ObstacleInfo * lhs, const a2_controller__msg__ObstacleInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // min_distance
  if (lhs->min_distance != rhs->min_distance) {
    return false;
  }
  // direction
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->direction), &(rhs->direction)))
  {
    return false;
  }
  // current_threshold
  if (lhs->current_threshold != rhs->current_threshold) {
    return false;
  }
  return true;
}

bool
a2_controller__msg__ObstacleInfo__copy(
  const a2_controller__msg__ObstacleInfo * input,
  a2_controller__msg__ObstacleInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // min_distance
  output->min_distance = input->min_distance;
  // direction
  if (!rosidl_runtime_c__String__copy(
      &(input->direction), &(output->direction)))
  {
    return false;
  }
  // current_threshold
  output->current_threshold = input->current_threshold;
  return true;
}

a2_controller__msg__ObstacleInfo *
a2_controller__msg__ObstacleInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  a2_controller__msg__ObstacleInfo * msg = (a2_controller__msg__ObstacleInfo *)allocator.allocate(sizeof(a2_controller__msg__ObstacleInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(a2_controller__msg__ObstacleInfo));
  bool success = a2_controller__msg__ObstacleInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
a2_controller__msg__ObstacleInfo__destroy(a2_controller__msg__ObstacleInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    a2_controller__msg__ObstacleInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
a2_controller__msg__ObstacleInfo__Sequence__init(a2_controller__msg__ObstacleInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  a2_controller__msg__ObstacleInfo * data = NULL;

  if (size) {
    data = (a2_controller__msg__ObstacleInfo *)allocator.zero_allocate(size, sizeof(a2_controller__msg__ObstacleInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = a2_controller__msg__ObstacleInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        a2_controller__msg__ObstacleInfo__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
a2_controller__msg__ObstacleInfo__Sequence__fini(a2_controller__msg__ObstacleInfo__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      a2_controller__msg__ObstacleInfo__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

a2_controller__msg__ObstacleInfo__Sequence *
a2_controller__msg__ObstacleInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  a2_controller__msg__ObstacleInfo__Sequence * array = (a2_controller__msg__ObstacleInfo__Sequence *)allocator.allocate(sizeof(a2_controller__msg__ObstacleInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = a2_controller__msg__ObstacleInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
a2_controller__msg__ObstacleInfo__Sequence__destroy(a2_controller__msg__ObstacleInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    a2_controller__msg__ObstacleInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
a2_controller__msg__ObstacleInfo__Sequence__are_equal(const a2_controller__msg__ObstacleInfo__Sequence * lhs, const a2_controller__msg__ObstacleInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!a2_controller__msg__ObstacleInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
a2_controller__msg__ObstacleInfo__Sequence__copy(
  const a2_controller__msg__ObstacleInfo__Sequence * input,
  a2_controller__msg__ObstacleInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(a2_controller__msg__ObstacleInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    a2_controller__msg__ObstacleInfo * data =
      (a2_controller__msg__ObstacleInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!a2_controller__msg__ObstacleInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          a2_controller__msg__ObstacleInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!a2_controller__msg__ObstacleInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
