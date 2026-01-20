// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from a2_controller:srv/GetVelocityStats.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "a2_controller/srv/detail/get_velocity_stats__struct.h"
#include "a2_controller/srv/detail/get_velocity_stats__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool a2_controller__srv__get_velocity_stats__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[63];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("a2_controller.srv._get_velocity_stats.GetVelocityStats_Request", full_classname_dest, 62) == 0);
  }
  a2_controller__srv__GetVelocityStats_Request * ros_message = _ros_message;
  ros_message->structure_needs_at_least_one_member = 0;

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * a2_controller__srv__get_velocity_stats__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GetVelocityStats_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("a2_controller.srv._get_velocity_stats");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GetVelocityStats_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  (void)raw_ros_message;

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "a2_controller/srv/detail/get_velocity_stats__struct.h"
// already included above
// #include "a2_controller/srv/detail/get_velocity_stats__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool a2_controller__srv__get_velocity_stats__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("a2_controller.srv._get_velocity_stats.GetVelocityStats_Response", full_classname_dest, 63) == 0);
  }
  a2_controller__srv__GetVelocityStats_Response * ros_message = _ros_message;
  {  // avg_linear_vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "avg_linear_vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->avg_linear_vel = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // avg_angular_vel
    PyObject * field = PyObject_GetAttrString(_pymsg, "avg_angular_vel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->avg_angular_vel = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * a2_controller__srv__get_velocity_stats__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GetVelocityStats_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("a2_controller.srv._get_velocity_stats");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GetVelocityStats_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  a2_controller__srv__GetVelocityStats_Response * ros_message = (a2_controller__srv__GetVelocityStats_Response *)raw_ros_message;
  {  // avg_linear_vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->avg_linear_vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "avg_linear_vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // avg_angular_vel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->avg_angular_vel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "avg_angular_vel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
