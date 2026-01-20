# generated from rosidl_generator_py/resource/_idl.py.em
# with input from a2_controller:srv/GetVelocityStats.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetVelocityStats_Request(type):
    """Metaclass of message 'GetVelocityStats_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('a2_controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'a2_controller.srv.GetVelocityStats_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_velocity_stats__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_velocity_stats__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_velocity_stats__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_velocity_stats__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_velocity_stats__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetVelocityStats_Request(metaclass=Metaclass_GetVelocityStats_Request):
    """Message class 'GetVelocityStats_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_GetVelocityStats_Response(type):
    """Metaclass of message 'GetVelocityStats_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('a2_controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'a2_controller.srv.GetVelocityStats_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_velocity_stats__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_velocity_stats__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_velocity_stats__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_velocity_stats__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_velocity_stats__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetVelocityStats_Response(metaclass=Metaclass_GetVelocityStats_Response):
    """Message class 'GetVelocityStats_Response'."""

    __slots__ = [
        '_avg_linear_vel',
        '_avg_angular_vel',
    ]

    _fields_and_field_types = {
        'avg_linear_vel': 'float',
        'avg_angular_vel': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.avg_linear_vel = kwargs.get('avg_linear_vel', float())
        self.avg_angular_vel = kwargs.get('avg_angular_vel', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.avg_linear_vel != other.avg_linear_vel:
            return False
        if self.avg_angular_vel != other.avg_angular_vel:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def avg_linear_vel(self):
        """Message field 'avg_linear_vel'."""
        return self._avg_linear_vel

    @avg_linear_vel.setter
    def avg_linear_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'avg_linear_vel' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'avg_linear_vel' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._avg_linear_vel = value

    @builtins.property
    def avg_angular_vel(self):
        """Message field 'avg_angular_vel'."""
        return self._avg_angular_vel

    @avg_angular_vel.setter
    def avg_angular_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'avg_angular_vel' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'avg_angular_vel' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._avg_angular_vel = value


class Metaclass_GetVelocityStats(type):
    """Metaclass of service 'GetVelocityStats'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('a2_controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'a2_controller.srv.GetVelocityStats')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_velocity_stats

            from a2_controller.srv import _get_velocity_stats
            if _get_velocity_stats.Metaclass_GetVelocityStats_Request._TYPE_SUPPORT is None:
                _get_velocity_stats.Metaclass_GetVelocityStats_Request.__import_type_support__()
            if _get_velocity_stats.Metaclass_GetVelocityStats_Response._TYPE_SUPPORT is None:
                _get_velocity_stats.Metaclass_GetVelocityStats_Response.__import_type_support__()


class GetVelocityStats(metaclass=Metaclass_GetVelocityStats):
    from a2_controller.srv._get_velocity_stats import GetVelocityStats_Request as Request
    from a2_controller.srv._get_velocity_stats import GetVelocityStats_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
