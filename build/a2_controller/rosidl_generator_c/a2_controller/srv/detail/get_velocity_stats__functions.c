// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from a2_controller:srv/GetVelocityStats.idl
// generated code does not contain a copyright notice
#include "a2_controller/srv/detail/get_velocity_stats__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
a2_controller__srv__GetVelocityStats_Request__init(a2_controller__srv__GetVelocityStats_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
a2_controller__srv__GetVelocityStats_Request__fini(a2_controller__srv__GetVelocityStats_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
a2_controller__srv__GetVelocityStats_Request__are_equal(const a2_controller__srv__GetVelocityStats_Request * lhs, const a2_controller__srv__GetVelocityStats_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
a2_controller__srv__GetVelocityStats_Request__copy(
  const a2_controller__srv__GetVelocityStats_Request * input,
  a2_controller__srv__GetVelocityStats_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

a2_controller__srv__GetVelocityStats_Request *
a2_controller__srv__GetVelocityStats_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  a2_controller__srv__GetVelocityStats_Request * msg = (a2_controller__srv__GetVelocityStats_Request *)allocator.allocate(sizeof(a2_controller__srv__GetVelocityStats_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(a2_controller__srv__GetVelocityStats_Request));
  bool success = a2_controller__srv__GetVelocityStats_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
a2_controller__srv__GetVelocityStats_Request__destroy(a2_controller__srv__GetVelocityStats_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    a2_controller__srv__GetVelocityStats_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
a2_controller__srv__GetVelocityStats_Request__Sequence__init(a2_controller__srv__GetVelocityStats_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  a2_controller__srv__GetVelocityStats_Request * data = NULL;

  if (size) {
    data = (a2_controller__srv__GetVelocityStats_Request *)allocator.zero_allocate(size, sizeof(a2_controller__srv__GetVelocityStats_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = a2_controller__srv__GetVelocityStats_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        a2_controller__srv__GetVelocityStats_Request__fini(&data[i - 1]);
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
a2_controller__srv__GetVelocityStats_Request__Sequence__fini(a2_controller__srv__GetVelocityStats_Request__Sequence * array)
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
      a2_controller__srv__GetVelocityStats_Request__fini(&array->data[i]);
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

a2_controller__srv__GetVelocityStats_Request__Sequence *
a2_controller__srv__GetVelocityStats_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  a2_controller__srv__GetVelocityStats_Request__Sequence * array = (a2_controller__srv__GetVelocityStats_Request__Sequence *)allocator.allocate(sizeof(a2_controller__srv__GetVelocityStats_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = a2_controller__srv__GetVelocityStats_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
a2_controller__srv__GetVelocityStats_Request__Sequence__destroy(a2_controller__srv__GetVelocityStats_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    a2_controller__srv__GetVelocityStats_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
a2_controller__srv__GetVelocityStats_Request__Sequence__are_equal(const a2_controller__srv__GetVelocityStats_Request__Sequence * lhs, const a2_controller__srv__GetVelocityStats_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!a2_controller__srv__GetVelocityStats_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
a2_controller__srv__GetVelocityStats_Request__Sequence__copy(
  const a2_controller__srv__GetVelocityStats_Request__Sequence * input,
  a2_controller__srv__GetVelocityStats_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(a2_controller__srv__GetVelocityStats_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    a2_controller__srv__GetVelocityStats_Request * data =
      (a2_controller__srv__GetVelocityStats_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!a2_controller__srv__GetVelocityStats_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          a2_controller__srv__GetVelocityStats_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!a2_controller__srv__GetVelocityStats_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
a2_controller__srv__GetVelocityStats_Response__init(a2_controller__srv__GetVelocityStats_Response * msg)
{
  if (!msg) {
    return false;
  }
  // avg_linear_vel
  // avg_angular_vel
  return true;
}

void
a2_controller__srv__GetVelocityStats_Response__fini(a2_controller__srv__GetVelocityStats_Response * msg)
{
  if (!msg) {
    return;
  }
  // avg_linear_vel
  // avg_angular_vel
}

bool
a2_controller__srv__GetVelocityStats_Response__are_equal(const a2_controller__srv__GetVelocityStats_Response * lhs, const a2_controller__srv__GetVelocityStats_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // avg_linear_vel
  if (lhs->avg_linear_vel != rhs->avg_linear_vel) {
    return false;
  }
  // avg_angular_vel
  if (lhs->avg_angular_vel != rhs->avg_angular_vel) {
    return false;
  }
  return true;
}

bool
a2_controller__srv__GetVelocityStats_Response__copy(
  const a2_controller__srv__GetVelocityStats_Response * input,
  a2_controller__srv__GetVelocityStats_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // avg_linear_vel
  output->avg_linear_vel = input->avg_linear_vel;
  // avg_angular_vel
  output->avg_angular_vel = input->avg_angular_vel;
  return true;
}

a2_controller__srv__GetVelocityStats_Response *
a2_controller__srv__GetVelocityStats_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  a2_controller__srv__GetVelocityStats_Response * msg = (a2_controller__srv__GetVelocityStats_Response *)allocator.allocate(sizeof(a2_controller__srv__GetVelocityStats_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(a2_controller__srv__GetVelocityStats_Response));
  bool success = a2_controller__srv__GetVelocityStats_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
a2_controller__srv__GetVelocityStats_Response__destroy(a2_controller__srv__GetVelocityStats_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    a2_controller__srv__GetVelocityStats_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
a2_controller__srv__GetVelocityStats_Response__Sequence__init(a2_controller__srv__GetVelocityStats_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  a2_controller__srv__GetVelocityStats_Response * data = NULL;

  if (size) {
    data = (a2_controller__srv__GetVelocityStats_Response *)allocator.zero_allocate(size, sizeof(a2_controller__srv__GetVelocityStats_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = a2_controller__srv__GetVelocityStats_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        a2_controller__srv__GetVelocityStats_Response__fini(&data[i - 1]);
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
a2_controller__srv__GetVelocityStats_Response__Sequence__fini(a2_controller__srv__GetVelocityStats_Response__Sequence * array)
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
      a2_controller__srv__GetVelocityStats_Response__fini(&array->data[i]);
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

a2_controller__srv__GetVelocityStats_Response__Sequence *
a2_controller__srv__GetVelocityStats_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  a2_controller__srv__GetVelocityStats_Response__Sequence * array = (a2_controller__srv__GetVelocityStats_Response__Sequence *)allocator.allocate(sizeof(a2_controller__srv__GetVelocityStats_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = a2_controller__srv__GetVelocityStats_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
a2_controller__srv__GetVelocityStats_Response__Sequence__destroy(a2_controller__srv__GetVelocityStats_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    a2_controller__srv__GetVelocityStats_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
a2_controller__srv__GetVelocityStats_Response__Sequence__are_equal(const a2_controller__srv__GetVelocityStats_Response__Sequence * lhs, const a2_controller__srv__GetVelocityStats_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!a2_controller__srv__GetVelocityStats_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
a2_controller__srv__GetVelocityStats_Response__Sequence__copy(
  const a2_controller__srv__GetVelocityStats_Response__Sequence * input,
  a2_controller__srv__GetVelocityStats_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(a2_controller__srv__GetVelocityStats_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    a2_controller__srv__GetVelocityStats_Response * data =
      (a2_controller__srv__GetVelocityStats_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!a2_controller__srv__GetVelocityStats_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          a2_controller__srv__GetVelocityStats_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!a2_controller__srv__GetVelocityStats_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
