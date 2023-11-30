# generated from rosidl_generator_py/resource/_idl.py.em
# with input from osm_nav_interface:srv/Planner.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Planner_Request(type):
    """Metaclass of message 'Planner_Request'."""

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
            module = import_type_support('osm_nav_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'osm_nav_interface.srv.Planner_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__planner__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__planner__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__planner__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__planner__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__planner__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Planner_Request(metaclass=Metaclass_Planner_Request):
    """Message class 'Planner_Request'."""

    __slots__ = [
        '_current_lon',
        '_current_lat',
        '_target_lon',
        '_target_lat',
    ]

    _fields_and_field_types = {
        'current_lon': 'double',
        'current_lat': 'double',
        'target_lon': 'double',
        'target_lat': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.current_lon = kwargs.get('current_lon', float())
        self.current_lat = kwargs.get('current_lat', float())
        self.target_lon = kwargs.get('target_lon', float())
        self.target_lat = kwargs.get('target_lat', float())

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
        if self.current_lon != other.current_lon:
            return False
        if self.current_lat != other.current_lat:
            return False
        if self.target_lon != other.target_lon:
            return False
        if self.target_lat != other.target_lat:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def current_lon(self):
        """Message field 'current_lon'."""
        return self._current_lon

    @current_lon.setter
    def current_lon(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_lon' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'current_lon' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._current_lon = value

    @builtins.property
    def current_lat(self):
        """Message field 'current_lat'."""
        return self._current_lat

    @current_lat.setter
    def current_lat(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_lat' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'current_lat' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._current_lat = value

    @builtins.property
    def target_lon(self):
        """Message field 'target_lon'."""
        return self._target_lon

    @target_lon.setter
    def target_lon(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_lon' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'target_lon' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._target_lon = value

    @builtins.property
    def target_lat(self):
        """Message field 'target_lat'."""
        return self._target_lat

    @target_lat.setter
    def target_lat(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_lat' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'target_lat' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._target_lat = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_Planner_Response(type):
    """Metaclass of message 'Planner_Response'."""

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
            module = import_type_support('osm_nav_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'osm_nav_interface.srv.Planner_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__planner__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__planner__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__planner__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__planner__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__planner__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Planner_Response(metaclass=Metaclass_Planner_Response):
    """Message class 'Planner_Response'."""

    __slots__ = [
        '_next_lon',
        '_next_lat',
    ]

    _fields_and_field_types = {
        'next_lon': 'double',
        'next_lat': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.next_lon = kwargs.get('next_lon', float())
        self.next_lat = kwargs.get('next_lat', float())

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
        if self.next_lon != other.next_lon:
            return False
        if self.next_lat != other.next_lat:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def next_lon(self):
        """Message field 'next_lon'."""
        return self._next_lon

    @next_lon.setter
    def next_lon(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'next_lon' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'next_lon' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._next_lon = value

    @builtins.property
    def next_lat(self):
        """Message field 'next_lat'."""
        return self._next_lat

    @next_lat.setter
    def next_lat(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'next_lat' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'next_lat' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._next_lat = value


class Metaclass_Planner(type):
    """Metaclass of service 'Planner'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('osm_nav_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'osm_nav_interface.srv.Planner')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__planner

            from osm_nav_interface.srv import _planner
            if _planner.Metaclass_Planner_Request._TYPE_SUPPORT is None:
                _planner.Metaclass_Planner_Request.__import_type_support__()
            if _planner.Metaclass_Planner_Response._TYPE_SUPPORT is None:
                _planner.Metaclass_Planner_Response.__import_type_support__()


class Planner(metaclass=Metaclass_Planner):
    from osm_nav_interface.srv._planner import Planner_Request as Request
    from osm_nav_interface.srv._planner import Planner_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
