#include"LinkLists.h"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

using HW3::CompareRes;
using HW3::LINKNODES;
using HW3::MYLIST;

/* @func  模板类MYLIST 初始化比较结果
 * @param result(CompareRes<Ty>&)
 * @get   bool 初始化成功为true
 */
template<typename Ty>
bool HW3::MYLIST <Ty>::ListInitCompare(CompareRes<Ty>& result)
{
	result.EndNodelocal = nullptr;
	result.EndNodeout = nullptr;
	result.samelength = ZERO;
	result.samepart.ListDestory();
	result.StartNodelocal = nullptr;
	result.StartNodeout = nullptr;
	return true;
}

/* 
 * @模板类MYLIST默认构造函数 初始化表尾和表头指针 清空节点计数
 */
template<typename Ty>
HW3::MYLIST <Ty>::MYLIST()
{
	headP = nullptr;
	lastP = nullptr;
	ListNodeCount = ZERO;
	InitCompareResPfunc = &MYLIST::ListInitCompare;//imporant
#ifdef DEBUG
	cout << "func : MYLIST, Initialize construct." << endl;
#endif // DEBUG
}

/*
 * @模板类MYLIST构造函数 
 * 初始化表尾和表头指针，
 * 清空节点计数，
 * 创造以数组为样本的有序链表
 */
template<typename Ty>
HW3::MYLIST <Ty>::MYLIST(Ty* inputInfoArray, unsigned int length)
{
	headP = nullptr;
	lastP = nullptr;
	ListNodeCount = ZERO;
	InitCompareResPfunc = &MYLIST::ListInitCompare;//imporant
	for (unsigned int i = 0; i < length; i++)
	{
		ListInsertLast(inputInfoArray[i]);//相当于不断插入表尾
	}
#ifdef DEBUG
	cout << "func : MYLIST, Array Initialize construct." << endl;
#endif // DEBUG
}

/*
 * @模板类MYLIST析构函数
 */
template<typename Ty>
HW3::MYLIST <Ty>::~MYLIST()
{
	ListDestory();
#ifdef DEBUG
	cout << "func : ~MYLIST, destory construct." << endl;
#endif // DEBUG
}

/*
 * @模板类MYLIST重置模板中重要变量
 */
template<typename Ty>//谨慎使用
bool HW3::MYLIST <Ty>::ListResetPointCount()
{
	headP = nullptr;
	lastP = nullptr;
	ListNodeCount = 0;
	return true;
}

/* @func  模板类MYLIST 显示对象内链表所有元素
 * @param void
 * @get   void
 */
template<typename Ty>
void HW3::MYLIST <Ty>::ListShowAllElements(void) const
{
	if (nullptr == headP || ListNodeCount == 0)
	{
		cout << "LIST :" << endl;
		cout << "	There is no elements." << endl << endl;
	}
	else
	{
		LINKNODES<Ty>* tempP = nullptr;
		unsigned int temppos = 1;
		tempP = headP;
		cout << "LIST :" << endl;
		while (tempP != nullptr)
		{
			cout << "  pos : " << temppos << "  info : " << tempP->Info << endl;
			tempP = tempP->NodeNextP;
			temppos++;
		}
		cout << endl;
	}
	return;
}

/* @func  模板类MYLIST 判断链表是否为空
 * @param void
 * @get   bool  真为非空，假为空
 */
template<typename Ty>
bool HW3::MYLIST <Ty>::ListIsEmpty(void) const
{
	if (headP != nullptr && ListNodeCount && lastP != nullptr)
	{
#ifdef DEBUG
		cout << "func : ListIsEmpty, judge list capacity. "\
		<< "It is not an empty list. The capacity is " << \
			ListLength() << endl;
#endif // DEBUG
		return true;
	}
	else
	{
		//cout << "It is an empty list." << endl;
#ifdef DEBUG
		cout << "func : ListIsEmpty, nullptr." << endl;
#endif // DEBUG
		return false;
	}
}

/* @func  模板类MYLIST 得到链表长度
 * @param void
 * @get   TestBack(unsigned int) 返回测试结果(链表长度)
 */
template<typename Ty>
TestBack HW3::MYLIST <Ty>::ListLength(void) const
{
#ifdef DEBUG
	cout << "func : ListLength, return list length." << endl;
#endif // DEBUG
	return ListNodeCount;
}

/* @func  模板类MYLIST 删除某个节点 根据位置 
 * @param tpos(const unsigned int) 删除具体位置
 * @get   TestBack(unsigned int) 返回测试结果
 * @tip   可能的输入位置及其处理
 *        1.如果位置小于 1 或者链表为空，那么删除失败
 *        2.如果只有一个节点
 *        3.如果多于一个节点且删除头部
 *        4.如果多于一个节点且删除尾部
 *        5.删除不属于上述情况的普通节点
 */
template<typename Ty>
TestBack HW3::MYLIST <Ty>::ListDeleteNode(const unsigned int tpos)
{
	LINKNODES<Ty>* tempP = nullptr;
	unsigned int tempPos = 0x01;
	unsigned int pos = tpos;

	if (pos > ListNodeCount) pos = ListNodeCount;//输入修正 只修正超出部分

	if (pos < 1 || !ListIsEmpty() )
	{		
#ifdef DEBUG
		cout << "func : ListDeleteNode, list is nullptr or pos out range. " \
			<< "Delete fail." << endl;
#endif // DEBUG
		return 0;
	}
	else
	{
		if (pos == ListNodeCount && ListNodeCount == 1)//只有一个节点
		{
			delete headP;
			headP = nullptr;
			lastP = nullptr;
			ListNodeCount--;
#ifdef DEBUG
			cout << "func : ListDeleteNode, only one node, delete it. Now capacity is "\
				<< ListNodeCount <<endl;
#endif // DEBUG
			return 1;
		}
		else if (pos == 1)//多于一个节点 表头
		{
			tempP = headP->NodeNextP;
			delete headP;
			headP = tempP;
#ifdef DOUBLELIST
			headP->NodePreP = nullptr;//双向链表
#endif
			ListNodeCount--;
#ifdef DEBUG
			cout << "func : ListDeleteNode, delete head node. Now capacity is "\
				<< ListNodeCount << endl;
#endif // DEBUG
			return 2;
		}
		else if (pos == ListNodeCount)//多于一个节点 表尾
		{
			tempP = headP;
			while (tempPos < pos - 1)//找到表尾的前一个指针
			{
				tempP = tempP->NodeNextP;
				tempPos++;
			}
			delete lastP;
			lastP = tempP;
			lastP->NodeNextP = nullptr;//表尾指向空指针
			ListNodeCount--;
#ifdef DEBUG
			cout << "func : ListDeleteNode, delete last node. Now capacity is "\
				<< ListNodeCount << endl;
#endif // DEBUG
			return 3;
		}
		else
		{
			LINKNODES<Ty>* aimP = nullptr;
			tempP = headP;
			while (tempPos < pos - 1)//找到寻找位置的前一个
			{
				tempP = tempP->NodeNextP;
				tempPos++;
			}
			aimP = tempP->NodeNextP;//目标位置
			tempP->NodeNextP = aimP->NodeNextP;//前一个位置的指针指向目标位置的指向
#ifdef DOUBLELIST
			(aimP->NodeNextP)->NodePreP = tempP;//目标位置的后一个节点的前指针指向目标位置前一个
#endif
			delete aimP;
			ListNodeCount--;
#ifdef DEBUG
			cout << "func : ListDeleteNode, delete node Now capacity is "\
				<< ListNodeCount << endl;
#endif // DEBUG
		}
	}
	return 4;
}

/* @func  模板类MYLIST 链表破坏函数，初始化链表，全部清空delete
 * @param void
 * @get   bool true : 成功删除清空表
 */
template<typename Ty>
bool HW3::MYLIST <Ty>::ListDestory(void)
{
	LINKNODES<Ty>* tempP = nullptr;//临时节点指针
	if (headP == nullptr)
	{	
#ifdef DEBUG
		cout << "func : ListDestory, list is nullptr. " \
			<< "Delete Finish!" << endl;
#endif // DEBUG
		return false;
	}
	while (headP != nullptr)//头指针不断后移
	{
		tempP = headP;
		headP = headP->NodeNextP;
		delete tempP;
	}
#ifdef DEBUG
		cout << "func : ListDestory, list is not nullptr." << endl;
#endif // DEBUG
	lastP = headP;//初始化表尾指针
	ListNodeCount = 0;
#ifdef DEBUG
	cout << "Delete Finish! Now, List is nullptr!" << endl << endl;
#endif // DEBUG
	return true;
}

/* @func  模板类MYLIST 初始化函数，初始化链表，全部清空delete
 * @param void
 * @get   void
 * @tip   调用ListDestory。
 */
template<typename Ty>
void HW3::MYLIST <Ty>::ListInitialize(void)
{
	ListDestory();
#ifdef DEBUG
	cout << "func : ListInitialize, list destory." << endl;
#endif // DEBUG
	return;
}

/* @func  模板类MYLIST 在表头插入节点
 * @param insertinfo(const Ty&) 插入节点的具体信息
 * @get   TestBack(unsigned int) 返回测试结果
 * @tip   有一些插入请求被修正
 *		  1.如果起始链表为空，那么创建节点，插入信息。
 */
template<typename Ty>
TestBack HW3::MYLIST <Ty>::ListInsertHead(const Ty& insertinfo)
{
	if (headP == nullptr && lastP == nullptr && ListNodeCount == ZERO)
	{
		headP = new LINKNODES<Ty>;
		headP->Info = insertinfo;
		lastP = headP;
		headP->NodeNextP = nullptr;//表尾指向空
#ifdef DOUBLELIST
		headP->NodePreP = nullptr;
#endif
		ListNodeCount++;
#ifdef DEBUG
		cout << "func : ListInsertHead, list is nullptr." << endl;
#endif // DEBUG
		return 0;
	}
	else
	{
		LINKNODES<Ty>* const tempP = new LINKNODES<Ty>;
		tempP->Info = insertinfo;
		tempP->NodeNextP = headP;
#ifdef DOUBLELIST
		tempP->NodePreP = nullptr;
#endif
		headP = tempP;
		ListNodeCount++;
#ifdef DEBUG
		cout << "func : ListInsertHead, list is not nullptr." << endl;
#endif // DEBUG
	}
	return 1;
}

/* @func  模板类MYLIST 在表尾插入节点
 * @param insertinfo(const Ty&) 插入节点的具体信息
 * @get   TestBack(unsigned int) 返回测试结果
 * @tip   有一些插入请求被修正
 *		  1.如果起始链表为空，那么创建节点，插入信息。
 */
template<typename Ty>
TestBack HW3::MYLIST <Ty>::ListInsertLast(const Ty& insertinfo)
{
	LINKNODES<Ty>* const tempP = new LINKNODES<Ty>;//常指针指向分配对象
	tempP->Info = insertinfo;
	tempP->NodeNextP = nullptr;
#ifdef DOUBLELIST
	tempP->NodePreP = nullptr;
#endif
	if (lastP == nullptr)//在没有内容的对象插入
	{
		lastP = headP = tempP;
		ListNodeCount++;
#ifdef DEBUG
		cout << "func : ListInsertLast, list is nullptr." << endl;
#endif // DEBUG
		return 0;
	}
	else
	{
		lastP->NodeNextP = tempP;//原来表尾连接现在表尾
#ifdef DOUBLELIST
		tempP->NodePreP = lastP;//现在表尾连接前者
#endif
		lastP = tempP;//更换表尾身份
		ListNodeCount++;
#ifdef DEBUG
		cout << "func : ListInsertLast, list is not nullptr." << endl;
#endif // DEBUG
	}
	return 1;
}

/* @func  模板类MYLIST 在具体位置插入具体节点
 * @param pos(const unsigned int&) 插入节点的具体位置
 * @param insertinfo(const Ty&) 插入节点的信息
 * @get   TestBack(unsigned int) 返回测试结果
 * @tip   有一些插入请求被修正
 *		  1.如果pos小于1或者等于1，那么就会插入在链表头部
 *        2.如果pos大于或等于当前链表长度，那么就插入到链表尾部
 */
template<typename Ty>
TestBack HW3::MYLIST <Ty>::ListInsertNode(const unsigned int& pos, const Ty& insertinfo)
{
	if (pos == 1 || pos < 1)
	{
		ListInsertHead(insertinfo);
#ifdef DEBUG
		cout << "func : ListInsertNode, insert list head." << endl;
#endif // DEBUG
		return 0;
	}
	else if (pos > ListNodeCount)
	{
		ListInsertLast(insertinfo);
#ifdef DEBUG
		cout << "func : ListInsertNode, insert list last." << endl;
#endif // DEBUG
		return 1;
	}
	else
	{
		unsigned int temppos = 1;
		LINKNODES<Ty>* tempP = nullptr;
		tempP = headP;
		while (temppos < pos - 1)//找到插入位置前一个
		{
			tempP = tempP->NodeNextP;
			temppos++;
		}
		LINKNODES<Ty>* const NodeIn = new LINKNODES<Ty>;//常指针指向分配对象
		NodeIn->Info = insertinfo;//分配信息
		NodeIn->NodeNextP = tempP->NodeNextP;//现在的后者指向原来的后者
#ifdef DOUBLELIST
		NodeIn->NodePreP = tempP;//现在的后者指向原来的前者
#endif	
		tempP->NodeNextP = NodeIn;//前者指向现在的后者
		ListNodeCount++;
#ifdef DEBUG
		cout << "func : ListInsertNode, insert list normal." << endl;
#endif // DEBUG
	}
	return 2;
}

/* @func  模板类MYLIST 搜索具体对象，只返回节点信息
 * @param serchitem(const Ty&) 搜索的数据
 * @get   TestBack(unsigned int) 返回
 * @tip   有一些请求被驳回
 *		  1.链表为空时
 *		  2.找不到对应的数据
 *        3.找不到时返回0
 */
template<typename Ty>
TestBack HW3::MYLIST <Ty>::ListSearchPos(const Ty& serchitem) const 
{
	LINKNODES<Ty>* tempP = nullptr;
	unsigned int temppos = 1;
	if (headP != nullptr)
	{
		tempP = headP;
		while (tempP && tempP->Info != serchitem)
		{
			tempP = tempP->NodeNextP;
			temppos++;
		}
		if (tempP && tempP->Info == serchitem)//防止temp是空指针，所以将temp 放在条件判断的前面
		{
#ifdef DEBUG
			cout << "func : ListSearch, finded node." << endl;
#endif // DEBUG
			return temppos;
		}
		else
		{ 
#ifdef DEBUG
			cout << "func : ListSearch, can't find it." << endl;
#endif // DEBUG
			return 0;//应当不可删除为0
		}
	}
	else
	{
#ifdef DEBUG
		cout << "func : ListSearch, list is nullptr, can't find it." << endl;
#endif // DEBUG
		return 0;
	}
}

/* @func  模板类MYLIST 用于交换两个相邻节点
 * @param pos(const unsigned int&) 交换出发位置
 * @param ChangeDir(enum DIR) 交换的方向 NEXTONE ：与后一个交换； BEFOREONE ：与前一个节点交换；
 * @get   TestBack(unsigned int) 返回测试结果
 * @tip   有一些交换请求被驳回
 *		  1.少于两个节点下请求交换
 *		  2.第一个节点与与前一个交换
 *		  3.最后一个节点与后一个交换
 *        4.交换任意节点？？？
 */
template<typename Ty>
TestBack HW3::MYLIST <Ty>::ListExchangeNodeAD(const unsigned int& pos, DIR ChangeDir)
{
	if (ListNodeCount < 2 || headP == nullptr)
	{
#ifdef DEBUG
		cout << "func : ListExchangeNodeAD, have no enough node to change, exchange fail" << endl;
#endif // DEBUG
		return 0;
	}
	else if ((pos == 1 && ChangeDir == BEFOREONE) || (pos == ListNodeCount && ChangeDir == NEXTONE))
	{
#ifdef DEBUG
		cout << "func : ListExchangeNodeAD, this direct have no node to change, exchange fail." << endl;
#endif // DEBUG
		return 1;
	}
	else if (pos < 1 || pos >  ListNodeCount)
	{
#ifdef DEBUG
		cout << "func : ListExchangeNodeAD, pos wrong, exchange fail." << endl;
#endif // DEBUG
		return 2;
	}
	else
	{
		LINKNODES<Ty>* tempP = nullptr;
		unsigned int temppos = 1;
		if (ListNodeCount == 2)//只有两个节点
		{
			tempP = headP;
			headP = lastP;
			lastP = tempP;
			headP->NodeNextP = lastP;//important
			lastP->NodeNextP = nullptr;
#ifdef DOUBLELIST
			headP->NodePreP = nullptr;//表头前指指向空
			lastP->NodePreP = headP;//表尾指向表头
#endif

#ifdef DEBUG
			cout << "func : ListExchangeNodeAD, only two nodes, exchange success." << endl;
#endif // DEBUG
			return 3;
		}
		else if ((pos == 2 && ChangeDir == BEFOREONE)||(pos == 1 && ChangeDir == NEXTONE))
		{
			LINKNODES<Ty>* orgP = nullptr;
			tempP = headP;
			headP = headP->NodeNextP;
			tempP->NodeNextP = headP->NodeNextP;
			orgP = tempP->NodeNextP;
			headP->NodeNextP = tempP;
#ifdef DOUBLELIST
			if (orgP)
				orgP->NodePreP = tempP;
			headP->NodePreP = nullptr;//同理
			tempP->NodePreP = headP;//同理
#endif
			return 6;
		}
		else if (ChangeDir == BEFOREONE)//多个节点 交换前者
		{
			LINKNODES<Ty>* aim = nullptr;
			LINKNODES<Ty>* aimbefore = nullptr;
			LINKNODES<Ty>* aimorgP = nullptr;
			tempP = headP;
			while (temppos < pos - 2)
			{
				tempP = tempP->NodeNextP;
				temppos++;
			}
			aimbefore = tempP->NodeNextP;//前一个需要交换的节点
			aim = aimbefore->NodeNextP;//pos点需要交换的节点
			aimorgP = aim->NodeNextP;//pos点的指向

			tempP->NodeNextP = aim;//交换节点前的节点 指向pos点
			aim->NodeNextP = aimbefore;//pos点 指向前一个需要交换的节点
			aimbefore->NodeNextP = aimorgP;//指向前一个需要交换的节点 指向 原来pos的指向
#ifdef DOUBLELIST
			if (aimorgP != nullptr)
				aimorgP->NodePreP = aimbefore; //pos点的前指向 指向现在aim 可能为空
			aimbefore->NodePreP = aim;//同理
			aim->NodePreP = tempP;//同理
#endif
#ifdef DEBUG
			cout << "func : ListExchangeNodeAD, change before one, exchange success." << endl;
#endif // DEBUG
			return 4;
		}
		else if (ChangeDir == NEXTONE)//多个节点 交换后者
		{
			LINKNODES<Ty>* aim = nullptr;
			LINKNODES<Ty>* aimnext = nullptr;
			LINKNODES<Ty>* aimnextorgP = nullptr;
			tempP = headP;
			while (temppos < pos - 1)
			{
				tempP = tempP->NodeNextP;
				temppos++;
			}
			aim = tempP->NodeNextP;//pos 节点
			aimnext = aim->NodeNextP;//需要交换的下一个节点
			aimnextorgP = aimnext->NodeNextP;//需要交换的下一个节点的原来指向

			tempP->NodeNextP = aimnext;//交换节点前的节点 指向下一个需要交换的节点
			aimnext->NodeNextP = aim;//下一个需要交换的节点 指向pos节点
			aim->NodeNextP = aimnextorgP;//pos节点指向 下一个需要交换的节点的原指向
#ifdef DOUBLELIST
			if(aimnextorgP != nullptr)
				aimnextorgP->NodePreP = aim; //pos点的前指向 指向现在aim 可能为空
			aim->NodePreP = aimnext;//同理
			aimnext->NodePreP = tempP;//同理
#endif
#ifdef DEBUG
		cout << "func : ListExchangeNodeAD, change next one, exchange success." << endl;
#endif // DEBUG
		}
	}
	return 5;
}

/* @func  模板类MYLIST 用于返回某个具体的节点
 * @param pos(const unsigned int&) 返回位置
 * @get   LINKNODES<Ty>& 返回节点的引用
 * @tip   有一些请求被修正 
 * const 引用可以接收const数据和非const数据。 但是，非const引用只能接收非const数据。
 */
template<typename Ty>
const LINKNODES<Ty>& HW3::MYLIST <Ty>::ListGetNode(const unsigned int& pos)
{
	unsigned int temppos = pos;
	unsigned int i = 0x01;
	/*const*/ LINKNODES<Ty> * tempP = nullptr;
	if (temppos < 1)temppos = 1;
	else if (temppos > ListNodeCount) temppos = ListNodeCount;

	tempP = headP;
	
	for (i = 1; i < temppos; i++)
	{
		tempP = tempP->NodeNextP;
		if (tempP == lastP) break;//到达表尾
	}
	return (*tempP);//解引用 返回引用
}

/* @func  模板类MYLIST 比较两个链表返回交集
 * @param compare(MYLIST<Ty>&) 需要比较的对象
 * @param result(CompareRes<Ty>&) 比较结果
 * @param compare(CompareRes<Ty>&) 比较临时结果
 * @get   CompareRes<Ty>& 比较结果
 * @tip   调用区分用递归 可以比较出最大子集
 */
template<typename Ty>//此处传入对象形参不能为const
CompareRes<Ty>& HW3::MYLIST <Ty>::ListCompareList(MYLIST<Ty>& outlist,\
	CompareRes<Ty>& result, CompareRes<Ty>& compare)
{
	(this->*InitCompareResPfunc)(result);//初始化结果 imporant
	const LINKNODES<Ty>* localP = this->headP;
	const LINKNODES<Ty>* outliP = outlist.ListGetHead();
	ListCompareListfunc(localP, outliP, result, compare);
	return result;
}

/* @func  模板类MYLIST 递归求得最大交集
 * @param localstart(const LINKNODES<Ty>*) 比较本地对象起始位置
 * @param outstart(const LINKNODES<Ty>*) 比较外在对象起始位置
 * @param result(CompareRes<Ty>&) 最优比较结果
 * @param compare(CompareRes<Ty>&) 此次比较结果
 * @get   void
 * @tip   可以区别最大子集
 */
template<typename Ty>//此处传入对象形参不能为const
void HW3::MYLIST <Ty>::ListCompareListfunc(const LINKNODES<Ty>* localstart, const LINKNODES<Ty>* outstart,\
	CompareRes<Ty>& result, CompareRes<Ty>& compare)
{
	if (localstart == nullptr || outstart == nullptr)
		return;//递归出口

	(this->*InitCompareResPfunc)(compare);//初始化
	unsigned int i = 1, j = 1;
	unsigned int samecount = 0;
	const LINKNODES<Ty>* localP = localstart;
	const LINKNODES<Ty>* outliP = outstart;
	bool flag = false;
	bool second = false;

	for (; localP;)//找寻起点
	{
		outliP = outstart;
		for (; outliP;)
		{
			if (outliP->Info == localP->Info)
			{
				flag = true;
				compare.samepart.ListInsertLast(outliP->Info);//存入信息
				samecount++;
				break;
			}
			outliP = outliP->NodeNextP;
		}
		if (flag) break;
		localP = localP->NodeNextP;
	}
	if (flag)//起点存在
	{
		compare.StartNodelocal = localP;//记录起始内指针
		compare.StartNodeout = outliP;//记录起始外指针
		for (; localP && outliP;)
		{
			if (outliP->Info != localP->Info) break;
			if (second) {
				compare.samepart.ListInsertLast(outliP->Info);//存入信息
				samecount++;
			}	
			if(!second)
				second = true;
			outliP = outliP->NodeNextP;;
			localP = localP->NodeNextP;
		}
		compare.samelength = samecount;
		compare.EndNodelocal = localP;//记录起始内指针 可能为空
		compare.EndNodeout = outliP;//记录起始外指针
	}
	if (compare.samelength > result.samelength)//当需要交换链表的时候
	{
		result.samepart.ListInitialize();//此时删除的部分为result
		result = compare;
		compare.samepart.ListResetPointCount();//断开compare与其链表的链接 传让给result
	}
	else
	{
		compare.samepart.ListInitialize();//如果没有比原来大 就初始化链表
	}
	ListCompareListfunc(compare.EndNodelocal, outstart, result, compare);

	return;
}

/* @func  模板类MYLIST 求得最大交集，不考虑节点位置对应顺序对应
 * @param outlist(MYLIST<Ty>&) 需要比较的外部链表
 * @param result(CompareRes<Ty>&) 最优比较结果
 * @get   CompareRes<Ty>& 结果
 */
template<typename Ty>//此处传入对象形参不能为const
CompareRes<Ty>& HW3::MYLIST <Ty>::ListCompareNpos(MYLIST<Ty>& outlist, CompareRes<Ty>& result)
{
	(this->*InitCompareResPfunc)(result);//初始化
	unsigned int i = 1, j = 1;
	unsigned int samecount = 0;
	const LINKNODES<Ty>* localP = this->headP;
	const LINKNODES<Ty>* outliP = outlist.ListGetHead();

	for (i = 1; localP && i <= this->ListNodeCount; i++)
	{
		outliP = outlist.ListGetHead();//外部比较回到头节点
		for (j = 1; outliP && j <= outlist.ListLength(); j++)
		{
			if (outliP->Info == localP->Info)
			{
				if (result.samepart.ListSearchPos(localP->Info) == ZERO)//当相同且第一次出现
				{
					result.samepart.ListInsertLast(outliP->Info);//存入信息
					samecount++;
				}
			}
			outliP = outliP->NodeNextP;
		}
		localP = localP->NodeNextP;
	}
	result.samelength = samecount;
	return  result;
}

template struct LINKNODES<int>;

template struct CompareRes<int>;

template class MYLIST<int>;