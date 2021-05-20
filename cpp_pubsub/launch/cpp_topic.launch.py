from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
            
    pub_node = Node(
        package='cpp_pubsub',
        executable='pub',
        output='screen',
        name=['nodecpp_pub'])
    
    sub_node = Node(
        package='cpp_pubsub',
        executable='sub',
        output='screen',
        name=['nodecpp_sub'])
        
    ld.add_action(pub_node)
    ld.add_action(sub_node)
    
    return ld
