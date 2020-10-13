#set 设置SRC_LIST变量
set(SRC_LIST 
	"main.cpp"
	"../lib/LinkLists.cpp"
)

#增加可执行文件
add_executable(main ${SRC_LIST})

