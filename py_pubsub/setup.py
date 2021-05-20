import os
from glob import glob
from setuptools import setup

package_name = 'py_pubsub'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
	#Include all launchfile(s)
        (os.path.join('share', package_name), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Photon',
    maintainer_email='1487quantum@users.noreply.github.com',
    description='ROS2 Pub-Sub example, Python',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'pub = py_pubsub.publisher_member_function:main',
                'sub = py_pubsub.subscriber_member_function:main',
        ],
    },
)
