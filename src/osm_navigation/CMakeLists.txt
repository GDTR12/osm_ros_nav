# cmake_minimum_required(VERSION 3.22.1)

# project(osm-nav)

# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# find_package(Osmium REQUIRED COMPONENTS io gdal xml pbf lz4)
# if(NOT OSMIUM_FOUND)
#     message(WARNING "Libosmium not found!\n")
# endif()

# file(GLOB_RECURSE SRC_SRCS "./*.cpp")
# file(GLOB_RECURSE EXE_SRCS "./app/*.cpp")
# list(REMOVE_ITEM SRC_SRCS ${EXE_SRCS})

# add_subdirectory(third_party/matplotplusplus)
# set(CMAKE_BUILD_TYPE Debug)

# add_executable(osm_nav src/app/main.cpp)
# target_include_directories(osm_nav PUBLIC ${OSMIUM_INCLUDE_DIR})
# target_link_libraries(osm_nav PUBLIC ${OSMIUM_XML_LIBRARIES} matplot)


cmake_minimum_required(VERSION 3.22.1)

project(osm_nav)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(Osmium REQUIRED COMPONENTS io xml lz4)
if(NOT OSMIUM_FOUND)
    message("CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}\n")
    message(FATAL_ERROR "Libosmium not found!\n")
endif()

find_package(Eigen3 REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(osm_nav_interface REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(PCL REQUIRED)
find_package(tf2_ros REQUIRED)


file(GLOB_RECURSE LIBRARY_SRCS "./*.cpp")
file(GLOB_RECURSE NODE_SRCS "./app/*_node.cpp")
file(GLOB_RECURSE THIRD_PARTY_SRCS "./third_party/*.cpp")
list(REMOVE_ITEM LIBRARY_SRCS ${NODE_SRCS})
list(REMOVE_ITEM LIBRARY_SRCS ${THIRD_PARTY_SRCS})
message("LIBRARY_SRCS: ${LIBRARY_SRCS}\n")

set(INCLUDE_PATH "./include")


add_executable(osm_navigation ${LIBRARY_SRCS} ${NODE_SRCS})
target_include_directories(osm_navigation PUBLIC 
  ${OSMIUM_INCLUDE_DIR} ${INCLUDE_PATH}
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_link_libraries(osm_navigation
    ${OSMIUM_XML_LIBRARIES}
    # ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES} ${PCL_LIBRARIES}
    )

ament_target_dependencies(
  osm_navigation
  "rclcpp"
  "geometry_msgs"
  "visualization_msgs"
  "nav_msgs"
  "osm_nav_interface"
#   "Eigen3"
#   "tf2_ros"
#   "PCL"
#   "pcl_conversions"
)





set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")
target_compile_features(osm_navigation PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS osm_navigation
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch config  DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


ament_package()
