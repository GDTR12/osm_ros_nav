// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from osm_nav_interface:srv/Planner.idl
// generated code does not contain a copyright notice
#include "osm_nav_interface/srv/detail/planner__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
osm_nav_interface__srv__Planner_Request__init(osm_nav_interface__srv__Planner_Request * msg)
{
  if (!msg) {
    return false;
  }
  // current_lon
  // current_lat
  // target_lon
  // target_lat
  return true;
}

void
osm_nav_interface__srv__Planner_Request__fini(osm_nav_interface__srv__Planner_Request * msg)
{
  if (!msg) {
    return;
  }
  // current_lon
  // current_lat
  // target_lon
  // target_lat
}

bool
osm_nav_interface__srv__Planner_Request__are_equal(const osm_nav_interface__srv__Planner_Request * lhs, const osm_nav_interface__srv__Planner_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_lon
  if (lhs->current_lon != rhs->current_lon) {
    return false;
  }
  // current_lat
  if (lhs->current_lat != rhs->current_lat) {
    return false;
  }
  // target_lon
  if (lhs->target_lon != rhs->target_lon) {
    return false;
  }
  // target_lat
  if (lhs->target_lat != rhs->target_lat) {
    return false;
  }
  return true;
}

bool
osm_nav_interface__srv__Planner_Request__copy(
  const osm_nav_interface__srv__Planner_Request * input,
  osm_nav_interface__srv__Planner_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // current_lon
  output->current_lon = input->current_lon;
  // current_lat
  output->current_lat = input->current_lat;
  // target_lon
  output->target_lon = input->target_lon;
  // target_lat
  output->target_lat = input->target_lat;
  return true;
}

osm_nav_interface__srv__Planner_Request *
osm_nav_interface__srv__Planner_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osm_nav_interface__srv__Planner_Request * msg = (osm_nav_interface__srv__Planner_Request *)allocator.allocate(sizeof(osm_nav_interface__srv__Planner_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(osm_nav_interface__srv__Planner_Request));
  bool success = osm_nav_interface__srv__Planner_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
osm_nav_interface__srv__Planner_Request__destroy(osm_nav_interface__srv__Planner_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    osm_nav_interface__srv__Planner_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
osm_nav_interface__srv__Planner_Request__Sequence__init(osm_nav_interface__srv__Planner_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osm_nav_interface__srv__Planner_Request * data = NULL;

  if (size) {
    data = (osm_nav_interface__srv__Planner_Request *)allocator.zero_allocate(size, sizeof(osm_nav_interface__srv__Planner_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = osm_nav_interface__srv__Planner_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        osm_nav_interface__srv__Planner_Request__fini(&data[i - 1]);
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
osm_nav_interface__srv__Planner_Request__Sequence__fini(osm_nav_interface__srv__Planner_Request__Sequence * array)
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
      osm_nav_interface__srv__Planner_Request__fini(&array->data[i]);
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

osm_nav_interface__srv__Planner_Request__Sequence *
osm_nav_interface__srv__Planner_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osm_nav_interface__srv__Planner_Request__Sequence * array = (osm_nav_interface__srv__Planner_Request__Sequence *)allocator.allocate(sizeof(osm_nav_interface__srv__Planner_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = osm_nav_interface__srv__Planner_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
osm_nav_interface__srv__Planner_Request__Sequence__destroy(osm_nav_interface__srv__Planner_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    osm_nav_interface__srv__Planner_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
osm_nav_interface__srv__Planner_Request__Sequence__are_equal(const osm_nav_interface__srv__Planner_Request__Sequence * lhs, const osm_nav_interface__srv__Planner_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!osm_nav_interface__srv__Planner_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
osm_nav_interface__srv__Planner_Request__Sequence__copy(
  const osm_nav_interface__srv__Planner_Request__Sequence * input,
  osm_nav_interface__srv__Planner_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(osm_nav_interface__srv__Planner_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    osm_nav_interface__srv__Planner_Request * data =
      (osm_nav_interface__srv__Planner_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!osm_nav_interface__srv__Planner_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          osm_nav_interface__srv__Planner_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!osm_nav_interface__srv__Planner_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
osm_nav_interface__srv__Planner_Response__init(osm_nav_interface__srv__Planner_Response * msg)
{
  if (!msg) {
    return false;
  }
  // next_lon
  // next_lat
  return true;
}

void
osm_nav_interface__srv__Planner_Response__fini(osm_nav_interface__srv__Planner_Response * msg)
{
  if (!msg) {
    return;
  }
  // next_lon
  // next_lat
}

bool
osm_nav_interface__srv__Planner_Response__are_equal(const osm_nav_interface__srv__Planner_Response * lhs, const osm_nav_interface__srv__Planner_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // next_lon
  if (lhs->next_lon != rhs->next_lon) {
    return false;
  }
  // next_lat
  if (lhs->next_lat != rhs->next_lat) {
    return false;
  }
  return true;
}

bool
osm_nav_interface__srv__Planner_Response__copy(
  const osm_nav_interface__srv__Planner_Response * input,
  osm_nav_interface__srv__Planner_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // next_lon
  output->next_lon = input->next_lon;
  // next_lat
  output->next_lat = input->next_lat;
  return true;
}

osm_nav_interface__srv__Planner_Response *
osm_nav_interface__srv__Planner_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osm_nav_interface__srv__Planner_Response * msg = (osm_nav_interface__srv__Planner_Response *)allocator.allocate(sizeof(osm_nav_interface__srv__Planner_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(osm_nav_interface__srv__Planner_Response));
  bool success = osm_nav_interface__srv__Planner_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
osm_nav_interface__srv__Planner_Response__destroy(osm_nav_interface__srv__Planner_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    osm_nav_interface__srv__Planner_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
osm_nav_interface__srv__Planner_Response__Sequence__init(osm_nav_interface__srv__Planner_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osm_nav_interface__srv__Planner_Response * data = NULL;

  if (size) {
    data = (osm_nav_interface__srv__Planner_Response *)allocator.zero_allocate(size, sizeof(osm_nav_interface__srv__Planner_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = osm_nav_interface__srv__Planner_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        osm_nav_interface__srv__Planner_Response__fini(&data[i - 1]);
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
osm_nav_interface__srv__Planner_Response__Sequence__fini(osm_nav_interface__srv__Planner_Response__Sequence * array)
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
      osm_nav_interface__srv__Planner_Response__fini(&array->data[i]);
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

osm_nav_interface__srv__Planner_Response__Sequence *
osm_nav_interface__srv__Planner_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  osm_nav_interface__srv__Planner_Response__Sequence * array = (osm_nav_interface__srv__Planner_Response__Sequence *)allocator.allocate(sizeof(osm_nav_interface__srv__Planner_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = osm_nav_interface__srv__Planner_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
osm_nav_interface__srv__Planner_Response__Sequence__destroy(osm_nav_interface__srv__Planner_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    osm_nav_interface__srv__Planner_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
osm_nav_interface__srv__Planner_Response__Sequence__are_equal(const osm_nav_interface__srv__Planner_Response__Sequence * lhs, const osm_nav_interface__srv__Planner_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!osm_nav_interface__srv__Planner_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
osm_nav_interface__srv__Planner_Response__Sequence__copy(
  const osm_nav_interface__srv__Planner_Response__Sequence * input,
  osm_nav_interface__srv__Planner_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(osm_nav_interface__srv__Planner_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    osm_nav_interface__srv__Planner_Response * data =
      (osm_nav_interface__srv__Planner_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!osm_nav_interface__srv__Planner_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          osm_nav_interface__srv__Planner_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!osm_nav_interface__srv__Planner_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
