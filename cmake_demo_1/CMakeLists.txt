#最低版本需求
cmake_minimum_required (VERSION 3.1)
#工程名称
project(P94)

add_compile_options(-std=c++11)

MESSAGE(STATUS "This is BINARY dir " ${P94_BINARY_DIR})

MESSAGE(STATUS "This is SOURCE dir "${P94_SOURCE_DIR})

set(SRC_LIST P94.cpp)

add_executable(P94 ${SRC_LIST})
