cmake_minimum_required(VERSION 3.10)

# 指定默认编译器（clang）
# 这两条命令应该放在文件的开始位置（cmake_minimum_required 之下，其他命令之上），否则可能无效
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# 项目信息
project(Qt_Window)


## ------------------------------------------ basic-settings ----------------------------------------------
# 设置默认构建类型为 Debug
set(CMAKE_BUILD_TYPE Debug)

# 生成 compile_commands.json 文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 禁用可能导致问题的编译器选项
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # 移除不兼容的编译器标志
    string(REPLACE "-mno-direct-extern-access" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string(REPLACE "-fno-direct-access-external-data" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

# # 启用自动添加当前目录到编译器搜索路径
# set(CMAKE_INCLUDE_CURRENT_DIR ON)

## qt auto call uic, moc, rcc compilers
set(CMAKE_AUTOUIC ON) # auto call uic compiler to process qt ui files.
set(CMAKE_AUTOMOC ON) # auto call moc compiler to process qt signal-slot source files.
set(CMAKE_AUTORCC ON) # auto call rcc complier to process qt resource files.


## ------------------------------------------ files-settings ----------------------------------------------
# 中大型项目建议显示列出源文件、头文件
# # source files
# set(PROJECT_SOURCES
#     ./main.cpp
#     src/mainwindow.cpp
# )

# # header files
# set(PROJECT_HEADERS
#     include/mainwindow.hpp
# )

# 把 GLOB 改为 GLOB_RECURSE 可以实现递归查找
file(GLOB PROJECT_SOURCES
    "src/*.cpp"
    "./main.cpp"
)

file(GLOB PROJECT_HEADERS
    "include/*.hpp"
)

# # qt ui files
# set(PROJECT_QUIS
#     MainWindow.ui
# )

# # qt resource files
# set(PROJECT_QRCS
#     icons.qrc
# )

# build target
add_executable(test
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
    # ${PROJECT_QUIS}
    # ${PROJECT_QRCS}
)

# 包含头文件路径
target_include_directories(test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR} # 重要：添加自动生成文件的目录
)


## ------------------------------------------ pkgs-settings ----------------------------------------------
# 查找 Qt 包
find_package(Qt6 REQUIRED COMPONENTS Core Widgets REQUIRED)

# 链接 Qt6::Widgets Qt6::Core
target_link_libraries(test PRIVATE
    Qt6::Core
    Qt6::Widgets
)

# link other required libraries
# target_link_libraries(test PRIVATE
#     ${Boost_LIBRARIES}
#     ${Protobuf_LIBRARIES}
# )


## ------------------------------------------ command ------------------------------------------------------
# cmake -DCMAKE_C_COMPILER:FILEPATH=clang -DCMAKE_CXX_COMPILER:FILEPATH=clang++ --no-warn-unused-cli -G Ninja -B build
