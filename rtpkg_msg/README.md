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



## Message Structure

- `data`: Value of the randomly generated number. [int16]
- `data_min`: Minimum value number generated within the current session. [int16]
- `data_max`: Maximum value number generated within the current session. [int16]
- `is_prime`:  Determine whether the current number is a prime number or not. [bool]
- `prime_ratio`: Ratio of the total number of prime number compared to the total random number generated within the current session. [float32]
