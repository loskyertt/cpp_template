cmake_minimum_required(VERSION 3.10)

# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)

project(OPENGL_PROJECT)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 查找源文件
aux_source_directory(src SRC_SUB)
aux_source_directory(. SRC_CUR)

add_executable(test.out ${SRC_SUB} ${SRC_CUR})

# 包含头文件
target_include_directories(test.out PRIVATE include)

# 配置 opengl
set(OpenGL_GL_PREFERENCE "GLVND")

# 添加 OpenGL 和 FreeGLUT 的查找和链接
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)  # FreeGLUT 包含在这里

target_include_directories(test.out PRIVATE ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(test.out ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

# # 查找 GLFW 库
# find_package(glfw3 3.3 REQUIRED)
# target_link_libraries(test.out glfw)
# # 查找 GLEW 库
# find_package(GLEW REQUIRED)
# target_link_libraries(test.out GLEW::GLEW)

# 输出信息以确保库和头文件路径正确
message(STATUS "OpenGL include dirs: ${OPENGL_INCLUDE_DIRS}")
message(STATUS "GLUT include dirs: ${GLUT_INCLUDE_DIRS}")
message(STATUS "OpenGL libraries: ${OPENGL_LIBRARIES}")
message(STATUS "GLUT libraries: ${GLUT_LIBRARIES}")