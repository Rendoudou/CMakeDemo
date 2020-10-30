#设置cmake版本要求
cmake_minimum_required(VERSION 3.0.2)

#设置编译器要求
add_compile_options(-std=c++11)

#设置项目名字
project(demo)

#查找opencv包
find_package(OpenCV REQUIRED)

#包含opencv头文件
include_directories(${OpenCV_INCLUDE_DIRS})

#生成可执行文件
add_executable(demo demo.cpp)

#可执行文件链接库文件
target_link_libraries(demo ${OpenCV_LIBS})
