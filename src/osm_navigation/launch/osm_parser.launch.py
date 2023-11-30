from launch import LaunchDescription as ld
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

from pkg_resources import declare_namespace
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.actions import ExecuteProcess, RegisterEventHandler,LogInfo
from launch.event_handlers import OnProcessExit,OnProcessStart
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import GroupAction


def generate_launch_description():
    logger = DeclareLaunchArgument(
        "log_level",
        default_value=["debug"],
        description="Logging level",
    )
    parser_param = os.path.join(
        get_package_share_directory('osm_nav'),
        'config',
        'osm_parser.yaml'
    )
    # osm_file = DeclareLaunchArgument("osm_file", default_value="/root/slam/slam/osm/osm-nav/src/osm_navigation/osm_file/map.osm")
    osm_parser = Node(
        package="osm_nav",
        executable="osm_navigation",
        parameters=[parser_param],
        output='screen',
        arguments=['--ros-args', '--log-level', LaunchConfiguration("log_level")]
    )

    return ld(
        [
            logger,
            osm_parser
        ]
    )

