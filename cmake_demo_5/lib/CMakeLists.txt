##设置LIB_SRC_LIST变量
set(LIB_SRC_LIST LinkLists.cpp)
##添加库文件
#添加动态库，利用LIB_SRC_LIST
add_library(linklist SHARED ${LIB_SRC_LIST})
#添加静态库
add_library(linklist_static STATIC ${LIB_SRC_LIST})
#重新设置静态库目标文件名称
set_target_properties(linklist_static PROPERTIES OUTPUT_NAME "linklist")
