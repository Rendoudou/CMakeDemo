#pragma once
//#define DEBUG      //开启测试 出现信息提示
//#define DOUBLELIST //开启双向链表
#define ZERO 0
typedef	 unsigned int TestBack;
enum DIR {
	NEXTONE = 100,
	BEFOREONE
};

namespace HW3 {
#ifdef DOUBLELIST 
	template<typename Ty>//双向链表节点模板
	struct LINKNODES {
		LINKNODES* NodePreP;
		Ty Info;
		LINKNODES* NodeNextP;
	};
#else
	template<typename Ty>//单向链表节点模板
	struct LINKNODES {
		LINKNODES* NodeNextP;
		Ty Info;
	};
#endif

	template <typename Ty> //声明模板类
	class MYLIST;

	template<typename Ty>
	struct CompareRes
	{
		const LINKNODES<Ty>* StartNodelocal;
		const LINKNODES<Ty>* EndNodelocal;
		const LINKNODES<Ty>* StartNodeout;
		const LINKNODES<Ty>* EndNodeout;
		unsigned int samelength;
		MYLIST<Ty> samepart;
	};

	template <typename Ty>
	class MYLIST {
	public: 
		MYLIST();//默认构造函数

		~MYLIST();//析构函数

		//第一个参数为一个数组，第二个参数为数组长度，将数组按照次序变成链表
		MYLIST(Ty* inputInfoArray, unsigned int length);

		//返回链表的头指针 inline
		LINKNODES<Ty>* ListGetHead(void) const { return headP; }

		//返回链表的尾指针 inline
		LINKNODES<Ty>* ListGetLast(void) const { return lastP; }

		//初始化对象的链表头尾指针和计数，慎重使用
		bool ListResetPointCount(void);

		//显示一个链表的所有成员信息
		void ListShowAllElements(void) const;
		
		//判断一个链表是否为空
		bool ListIsEmpty(void) const;

		//返回链表长度
		TestBack ListLength(void) const;
		
		//删除某个节点 参数为该节点在链表中的位置 例如 1 2 3 4 5
		TestBack ListDeleteNode(const unsigned int pos);
		
		//毁坏链表，初始化链表，删除链表
		bool ListDestory(void);

		//链表初始化
		void ListInitialize(void);

		//具体位置插入具体节点，第一个参数是插入的位置 如 1 2 3 4 5，第二个参数是插入链表的信息
		TestBack ListInsertNode(const unsigned int& pos, const Ty& insertinfo);	
		
		//在链表的头部加入一个节点，参数是插入的信息
		TestBack ListInsertHead(const Ty& insertinfo);//插在最前

		//在链表的尾部加入一个节点，参数是插入的信息
		TestBack ListInsertLast(const Ty& insertinfo);//插在最后

		//搜索具体节点，返回该节点的位置，参数是搜索的节点所对应的信息
		TestBack ListSearchPos(const Ty& serchitem) const;

		//交换两个相邻节点，第一个参数是交换的起始位置,第二个参数是交换方向 可选 NEXTONE,BEFOREONE
		TestBack ListExchangeNodeAD(const unsigned int& pos, DIR ChangeDir);
		
		//返回具体节点的引用，参数是位置
		const LINKNODES<Ty>& ListGetNode(const unsigned int& pos);

		//比较两个链表对象，返回交集(考虑节点位置)
		CompareRes<Ty>& ListCompareList(MYLIST<Ty>&, CompareRes<Ty>&, CompareRes<Ty>&);
		
		//类内指向成员函数的函数指针 imporant
		bool (MYLIST::*InitCompareResPfunc)(CompareRes<Ty>&);

		//比较两个链表对象，返回交集(不考虑节点位置)
		CompareRes<Ty>& ListCompareNpos(MYLIST<Ty>&, CompareRes<Ty>&);

	private:
		bool ListInitCompare(CompareRes<Ty>&);//初始化CompareRes
		void ListCompareListfunc(const LINKNODES<Ty>* , const LINKNODES<Ty>* , \
			CompareRes<Ty>& , CompareRes<Ty>& );//返回最长交集(考虑节点位置)
		LINKNODES<Ty>* headP;//头指针
		LINKNODES<Ty>* lastP;//尾指针
		unsigned int ListNodeCount;
	};
}