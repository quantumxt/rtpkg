# rtpkg

A ROS2 example package that contains the publisher and subscriber example of both C++ & Python.

## Setup

Git clone the repository into the workspace:

```bash
$ git clone https://github.com/1487quantum/rtpkg.git
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
