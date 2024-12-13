cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)

project(cloud_viewer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## ------------------------------------------------------ 项目配置 -----------------------------------------------------

aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)

add_executable(test.out
    ${SRC_SUB}
    ${SRC_CUR}
)

target_include_directories(test.out PRIVATE
    include
)

# pcl 库配置
find_package(PCL 1.14 REQUIRED)

target_include_directories(test.out PRIVATE
    ${PCL_INCLUDE_DIRS}
)
target_link_libraries (test.out
    ${PCL_LIBRARIES}
)