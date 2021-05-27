cmake_minimum_required(VERSION 3.5)
project(rtpkg)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

include_directories(
  include
)

set(LIB_NAME rtpkg_helper)

find_package(ament_cmake REQUIRED)

add_library(${LIB_NAME} SHARED
  src/helper.cpp)

# Gen launch files.
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

install(DIRECTORY include/
  DESTINATION include/
)

# Reference: http://www.robotandchisel.com/2020/08/25/etherbotix/#exporting-libraries
install(
  TARGETS
  ${LIB_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  # gtest c++ unit test
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(${PROJECT_NAME}_utest test/utest.cpp)
  target_link_libraries(${PROJECT_NAME}_utest ${LIB_NAME})

  # Catch2 C++ unit test
  set(Catch2_DIR /home/runner/work/rtpkg/rtpkg/Catch2/tmp/lib/cmake/Catch2/)  # Only for github action, comment out after cloning repo
  find_package(Catch2 REQUIRED)
  find_package(ament_cmake_catch2 REQUIRED)
  ament_add_catch2(${PROJECT_NAME}_catch2 test/main_catch.cpp)
  target_link_libraries(${PROJECT_NAME}_catch2 ${LIB_NAME} Catch2::Catch2)

  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()

endif()

ament_export_include_directories(include)
ament_export_libraries(${LIB_NAME})

ament_package()
