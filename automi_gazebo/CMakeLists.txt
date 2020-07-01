cmake_minimum_required(VERSION 2.8.3)
project(automi_gazebo)

# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED COMPONENTS 
  rospy
  roscpp
  std_msgs
  geometry_msgs
  sensor_msgs
  gazebo_ros  
  trajectory_msgs
)

find_package(Boost REQUIRED COMPONENTS system)
find_package(gazebo REQUIRED)

catkin_python_setup()

catkin_package(
  CATKIN_DEPENDS 
    sensor_msgs
    gazebo_ros 
    hector_gazebo_plugins
    roscpp
  DEPENDS 
    gazebo
)
include_directories(${catkin_INCLUDE_DIRS})

add_executable(checkcontroller_node src/checkcontroller.cpp)
target_link_libraries(checkcontroller_node ${catkin_LIBRARIES})
