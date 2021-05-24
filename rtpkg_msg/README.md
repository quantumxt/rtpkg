# rtpkg_msg
A custom ROS2 message for the rtpkg package.



## Usage

To use  `rtpkg_msg` , ensure that the package build dependency is included in the `CMakeLists.txt` & the `package.xml` of the package (that would be using this message structure). 

**`CMakeLists.txt`**

```cmake
find_package(rtpkg_msg REQUIRED)
```

**`package.xml`**

```xml
<build_depend>rtpkg_msg</build_depend>
```



## Topic Structure

- `data`: Value of the randomly generated number.
- `data_min`: Minimum value number generated within the current session.
- `data_max`: Maximum value number generated within the current session.
