# rtpkg

[![Industrial-CI](https://img.shields.io/github/actions/workflow/status/quantumxt/rtpkg/gh-action.yml?logo=github&style=flat-square)](https://github.com/quantumxt/rtpkg/actions/workflows/gh-action.yml)
[![Documentation](https://img.shields.io/github/actions/workflow/status/quantumxt/rtpkg/doxy.yml?logo=readthedocs&label=docs&style=flat-square
)](https://github.com/quantumxt/rtpkg/actions/workflows/doxy.yml)

A ROS2 example package that contains the publisher and subscriber example of both C++ & Python, with the use of custom message. 

The C++ subscriber node also subscribes to the topic `topic_py` published by the Python publisher. Additionally, it also utilises the `rtpkg` helper class to generate random number, which is then published as `rnd_num` with the custom message structure `rtpkg_msg`.

> API documentation of the `rtpkg` package is available here: https://quantumxt.github.io/rtpkg/

## Setup

Git clone the repository into the workspace:

```bash
$ git clone https://github.com/quantumxt/rtpkg.git
```

Compile the package with `colcon build`:

```bash
$ colcon build --packages-select rtpkg cpp_pubsub py_pubsub
```

After that, run `colcon test` to test the package:

```bash
$ colcon test --packages-select rtpkg cpp_pubsub py_pubsub
```

> If there's error during the build, more details on the test could be viewed via `$ colcon test-result --verbose`.

### Script

Alternatively, a bash script is available to run the compilation & testing of the packages:

```bash
$ sudo chmod +x buildpkg.sh
$ ./buildpkg  #Alternatively, -v flag could be used to export the verbose output of the test result
```



## Usage

There are 3 available launch files that could be used:

- `cpp_topic.launch.py`: Launches both the publisher & subscriber nodes written in C++.
- `py_topic.launch.py`: Launches both the publisher & subscriber nodes written in Python.
- `alltop.launch.py`: Launches both the `cpp_topic.launch.py` & `py_topic.launch.py` launch file.

Ensure that the workspace is sourced beforehand:

```bash
$ . install/setup.bash
```

To launch the launch file, use the `ros2 launch [packageName] [launchFile]` command:

```bash
$ ros2 launch rtpkg alltop.launch.py
```



## Packages

- `cpp_pubsub`: C++ publisher/subscriber example. (Subscriber node also publishes random number with `rtpkg_msg`.)
- `py_pubsub`: Python publisher/subscriber example.
- `rtpkg`: Contains the `rtpkg` helper class for random number generation & the launch file to launch both the C++ and Python publisher/subscriber example simulataneously. 
- `rtpkg_msg`: Custom ROS2 message structure for the `rtpkg` package, used for random number topic publication/subscription. More information could be found [here](rtpkg_msg/README.md).
