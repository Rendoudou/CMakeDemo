#最低版本需求
cmake_minimum_required (VERSION 3.1)
#工程名称
project(P94)
#增加编译选项
add_compile_options(-std=c++11)
#
add_subdirectory(src bin)
