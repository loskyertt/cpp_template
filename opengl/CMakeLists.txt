cmake_minimum_required(VERSION 3.10)

# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)

project(OPENGL_PROJECT)


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
# 配置 opengl
set(OpenGL_GL_PREFERENCE "GLVND")

# 添加 OpenGL 和 FreeGLUT 的查找和链接
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_include_directories(test PRIVATE
    ${OPENGL_INCLUDE_DIRS}
    ${GLUT_INCLUDE_DIRS}
)
target_link_libraries(test
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)

# # 查找 GLFW 库
# find_package(glfw3 3.3 REQUIRED)
# target_link_libraries(test glfw)
# # 查找 GLEW 库
# find_package(GLEW REQUIRED)
# target_link_libraries(test GLEW::GLEW)

# 输出信息以确保库和头文件路径正确
message(STATUS "OpenGL include dirs: ${OPENGL_INCLUDE_DIRS}")
message(STATUS "GLUT include dirs: ${GLUT_INCLUDE_DIRS}")
message(STATUS "OpenGL libraries: ${OPENGL_LIBRARIES}")
message(STATUS "GLUT libraries: ${GLUT_LIBRARIES}")
