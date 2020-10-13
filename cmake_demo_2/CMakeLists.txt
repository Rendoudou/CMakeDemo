#cmake 最低版本需求
cmake_minimum_required(VERSION 3.0.2)

#工程
project(LinkLists)

#编译标准
add_compile_options(-std=c++11)

#src
set(SRC_LIST main.cpp LinkLists.cpp)

#添加克可以执行的文件
add_executable(list ${SRC_LIST})
