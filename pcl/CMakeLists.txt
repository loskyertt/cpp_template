cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)

project(cloud_viewer)


## ------------------------------------------ basic-settings ----------------------------------------------
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


## ------------------------------------------ files-settings ----------------------------------------------
aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)

add_executable(test.out
    ${SRC_SUB}
    ${SRC_CUR}
)

target_include_directories(test.out PRIVATE
    include
)


## ------------------------------------------ pkgs-settings ----------------------------------------------
# pcl 库配置
find_package(PCL 1.14 REQUIRED)

target_include_directories(test.out PRIVATE
    ${PCL_INCLUDE_DIRS}
)
target_link_libraries (test.out
    ${PCL_LIBRARIES}
)