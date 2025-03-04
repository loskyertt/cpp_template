cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)

project(PCL_PROJECT)


## ------------------------------------------ basic-settings ----------------------------------------------
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


## ------------------------------------------ files-settings ----------------------------------------------
# 查找源文件
file(GLOB PROJECT_SRC
    "src/*.cpp",
    "main.cpp"
)

set(PROJECT_INCLUDE
    "include"
)

add_executable(test
    ${PROJECT_SRC}
)

# 包含头文件
target_include_directories(test PRIVATE
    ${PROJECT_INCLUDE}
)


## ------------------------------------------ pkgs-settings ----------------------------------------------
# pcl 库配置
find_package(PCL 1.14 REQUIRED)

target_include_directories(test PRIVATE
    ${PCL_INCLUDE_DIRS}
)
target_link_libraries(test
    ${PCL_LIBRARIES}
)
