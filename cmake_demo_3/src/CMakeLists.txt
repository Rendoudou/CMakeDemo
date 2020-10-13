#最低版本需求
cmake_minimum_required (VERSION 3.1)
#编译器版本要求
add_compile_options(-std=c++11)
#新建变量
set(SRC_LIST P94.cpp)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#用变量SRC_LIST生成可执行文件P94
add_executable(P94 ${SRC_LIST})

