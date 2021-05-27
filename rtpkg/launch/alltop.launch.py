import os
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import (GroupAction, IncludeLaunchDescription)
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
    ld = LaunchDescription()

    # Specify the actions
    bringup_cmd_group = GroupAction(
        [IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(
                get_package_share_directory('cpp_pubsub'),
                'launch',
                'cpp_topic.launch.py'))),
         IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(
                get_package_share_directory('py_pubsub'),
                'py_topic.launch.py'))),    # launch file for py in main share dir
         ]
    )
    # Add the actions to launch all of the navigation nodes
    ld.add_action(bringup_cmd_group)

    return ld
