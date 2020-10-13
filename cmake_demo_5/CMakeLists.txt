#cmake 最低版本需求
cmake_minimum_required(VERSION 3.0.2)

#工程
project(LinkLists)

#编译标准
#add_compile_options(-std=c++11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#添加头文件路径
include_directories(.)
include_directories(lib)

#添加子目录，到子目录中寻找CMakelists.txt
add_subdirectory(lib)

#设置源文件路径
set(SRC_LIST 
	src/main.cpp
	lib/LinkLists.cpp

)

#生成可执行文件
add_executable(main ${SRC_LIST})

