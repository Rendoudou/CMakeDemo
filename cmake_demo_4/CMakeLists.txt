#cmake 最低版本需求
cmake_minimum_required(VERSION 3.0.2)

#工程
project(LinkLists)

#编译标准
add_compile_options(-std=c++11)

#添加子目录，到子目录中寻找CMakelists.txt
add_subdirectory(lib)

