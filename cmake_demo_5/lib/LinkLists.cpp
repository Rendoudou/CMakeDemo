#include"LinkLists.h"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

using HW3::CompareRes;
using HW3::LINKNODES;
using HW3::MYLIST;

/* @func  ģ����MYLIST ��ʼ���ȽϽ��
 * @param result(CompareRes<Ty>&)
 * @get   bool ��ʼ���ɹ�Ϊtrue
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
 * @ģ����MYLISTĬ�Ϲ��캯�� ��ʼ����β�ͱ�ͷָ�� ��սڵ����
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
 * @ģ����MYLIST���캯�� 
 * ��ʼ����β�ͱ�ͷָ�룬
 * ��սڵ������
 * ����������Ϊ��������������
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
		ListInsertLast(inputInfoArray[i]);//�൱�ڲ��ϲ����β
	}
#ifdef DEBUG
	cout << "func : MYLIST, Array Initialize construct." << endl;
#endif // DEBUG
}

/*
 * @ģ����MYLIST��������
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
 * @ģ����MYLIST����ģ������Ҫ����
 */
template<typename Ty>//����ʹ��
bool HW3::MYLIST <Ty>::ListResetPointCount()
{
	headP = nullptr;
	lastP = nullptr;
	ListNodeCount = 0;
	return true;
}

/* @func  ģ����MYLIST ��ʾ��������������Ԫ��
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

/* @func  ģ����MYLIST �ж������Ƿ�Ϊ��
 * @param void
 * @get   bool  ��Ϊ�ǿգ���Ϊ��
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

/* @func  ģ����MYLIST �õ�������
 * @param void
 * @get   TestBack(unsigned int) ���ز��Խ��(������)
 */
template<typename Ty>
TestBack HW3::MYLIST <Ty>::ListLength(void) const
{
#ifdef DEBUG
	cout << "func : ListLength, return list length." << endl;
#endif // DEBUG
	return ListNodeCount;
}

/* @func  ģ����MYLIST ɾ��ĳ���ڵ� ����λ�� 
 * @param tpos(const unsigned int) ɾ������λ��
 * @get   TestBack(unsigned int) ���ز��Խ��
 * @tip   ���ܵ�����λ�ü��䴦��
 *        1.���λ��С�� 1 ��������Ϊ�գ���ôɾ��ʧ��
 *        2.���ֻ��һ���ڵ�
 *        3.�������һ���ڵ���ɾ��ͷ��
 *        4.�������һ���ڵ���ɾ��β��
 *        5.ɾ�������������������ͨ�ڵ�
 */
template<typename Ty>
TestBack HW3::MYLIST <Ty>::ListDeleteNode(const unsigned int tpos)
{
	LINKNODES<Ty>* tempP = nullptr;
	unsigned int tempPos = 0x01;
	unsigned int pos = tpos;

	if (pos > ListNodeCount) pos = ListNodeCount;//�������� ֻ������������

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
		if (pos == ListNodeCount && ListNodeCount == 1)//ֻ��һ���ڵ�
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
		else if (pos == 1)//����һ���ڵ� ��ͷ
		{
			tempP = headP->NodeNextP;
			delete headP;
			headP = tempP;
#ifdef DOUBLELIST
			headP->NodePreP = nullptr;//˫������
#endif
			ListNodeCount--;
#ifdef DEBUG
			cout << "func : ListDeleteNode, delete head node. Now capacity is "\
				<< ListNodeCount << endl;
#endif // DEBUG
			return 2;
		}
		else if (pos == ListNodeCount)//����һ���ڵ� ��β
		{
			tempP = headP;
			while (tempPos < pos - 1)//�ҵ���β��ǰһ��ָ��
			{
				tempP = tempP->NodeNextP;
				tempPos++;
			}
			delete lastP;
			lastP = tempP;
			lastP->NodeNextP = nullptr;//��βָ���ָ��
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
			while (tempPos < pos - 1)//�ҵ�Ѱ��λ�õ�ǰһ��
			{
				tempP = tempP->NodeNextP;
				tempPos++;
			}
			aimP = tempP->NodeNextP;//Ŀ��λ��
			tempP->NodeNextP = aimP->NodeNextP;//ǰһ��λ�õ�ָ��ָ��Ŀ��λ�õ�ָ��
#ifdef DOUBLELIST
			(aimP->NodeNextP)->NodePreP = tempP;//Ŀ��λ�õĺ�һ���ڵ��ǰָ��ָ��Ŀ��λ��ǰһ��
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

/* @func  ģ����MYLIST �����ƻ���������ʼ������ȫ�����delete
 * @param void
 * @get   bool true : �ɹ�ɾ����ձ�
 */
template<typename Ty>
bool HW3::MYLIST <Ty>::ListDestory(void)
{
	LINKNODES<Ty>* tempP = nullptr;//��ʱ�ڵ�ָ��
	if (headP == nullptr)
	{	
#ifdef DEBUG
		cout << "func : ListDestory, list is nullptr. " \
			<< "Delete Finish!" << endl;
#endif // DEBUG
		return false;
	}
	while (headP != nullptr)//ͷָ�벻�Ϻ���
	{
		tempP = headP;
		headP = headP->NodeNextP;
		delete tempP;
	}
#ifdef DEBUG
		cout << "func : ListDestory, list is not nullptr." << endl;
#endif // DEBUG
	lastP = headP;//��ʼ����βָ��
	ListNodeCount = 0;
#ifdef DEBUG
	cout << "Delete Finish! Now, List is nullptr!" << endl << endl;
#endif // DEBUG
	return true;
}

/* @func  ģ����MYLIST ��ʼ����������ʼ������ȫ�����delete
 * @param void
 * @get   void
 * @tip   ����ListDestory��
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

/* @func  ģ����MYLIST �ڱ�ͷ����ڵ�
 * @param insertinfo(const Ty&) ����ڵ�ľ�����Ϣ
 * @get   TestBack(unsigned int) ���ز��Խ��
 * @tip   ��һЩ������������
 *		  1.�����ʼ����Ϊ�գ���ô�����ڵ㣬������Ϣ��
 */
template<typename Ty>
TestBack HW3::MYLIST <Ty>::ListInsertHead(const Ty& insertinfo)
{
	if (headP == nullptr && lastP == nullptr && ListNodeCount == ZERO)
	{
		headP = new LINKNODES<Ty>;
		headP->Info = insertinfo;
		lastP = headP;
		headP->NodeNextP = nullptr;//��βָ���
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

/* @func  ģ����MYLIST �ڱ�β����ڵ�
 * @param insertinfo(const Ty&) ����ڵ�ľ�����Ϣ
 * @get   TestBack(unsigned int) ���ز��Խ��
 * @tip   ��һЩ������������
 *		  1.�����ʼ����Ϊ�գ���ô�����ڵ㣬������Ϣ��
 */
template<typename Ty>
TestBack HW3::MYLIST <Ty>::ListInsertLast(const Ty& insertinfo)
{
	LINKNODES<Ty>* const tempP = new LINKNODES<Ty>;//��ָ��ָ��������
	tempP->Info = insertinfo;
	tempP->NodeNextP = nullptr;
#ifdef DOUBLELIST
	tempP->NodePreP = nullptr;
#endif
	if (lastP == nullptr)//��û�����ݵĶ������
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
		lastP->NodeNextP = tempP;//ԭ����β�������ڱ�β
#ifdef DOUBLELIST
		tempP->NodePreP = lastP;//���ڱ�β����ǰ��
#endif
		lastP = tempP;//������β���
		ListNodeCount++;
#ifdef DEBUG
		cout << "func : ListInsertLast, list is not nullptr." << endl;
#endif // DEBUG
	}
	return 1;
}

/* @func  ģ����MYLIST �ھ���λ�ò������ڵ�
 * @param pos(const unsigned int&) ����ڵ�ľ���λ��
 * @param insertinfo(const Ty&) ����ڵ����Ϣ
 * @get   TestBack(unsigned int) ���ز��Խ��
 * @tip   ��һЩ������������
 *		  1.���posС��1���ߵ���1����ô�ͻ����������ͷ��
 *        2.���pos���ڻ���ڵ�ǰ�����ȣ���ô�Ͳ��뵽����β��
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
		while (temppos < pos - 1)//�ҵ�����λ��ǰһ��
		{
			tempP = tempP->NodeNextP;
			temppos++;
		}
		LINKNODES<Ty>* const NodeIn = new LINKNODES<Ty>;//��ָ��ָ��������
		NodeIn->Info = insertinfo;//������Ϣ
		NodeIn->NodeNextP = tempP->NodeNextP;//���ڵĺ���ָ��ԭ���ĺ���
#ifdef DOUBLELIST
		NodeIn->NodePreP = tempP;//���ڵĺ���ָ��ԭ����ǰ��
#endif	
		tempP->NodeNextP = NodeIn;//ǰ��ָ�����ڵĺ���
		ListNodeCount++;
#ifdef DEBUG
		cout << "func : ListInsertNode, insert list normal." << endl;
#endif // DEBUG
	}
	return 2;
}

/* @func  ģ����MYLIST �����������ֻ���ؽڵ���Ϣ
 * @param serchitem(const Ty&) ����������
 * @get   TestBack(unsigned int) ����
 * @tip   ��һЩ���󱻲���
 *		  1.����Ϊ��ʱ
 *		  2.�Ҳ�����Ӧ������
 *        3.�Ҳ���ʱ����0
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
		if (tempP && tempP->Info == serchitem)//��ֹtemp�ǿ�ָ�룬���Խ�temp ���������жϵ�ǰ��
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
			return 0;//Ӧ������ɾ��Ϊ0
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

/* @func  ģ����MYLIST ���ڽ����������ڽڵ�
 * @param pos(const unsigned int&) ��������λ��
 * @param ChangeDir(enum DIR) �����ķ��� NEXTONE �����һ�������� BEFOREONE ����ǰһ���ڵ㽻����
 * @get   TestBack(unsigned int) ���ز��Խ��
 * @tip   ��һЩ�������󱻲���
 *		  1.���������ڵ������󽻻�
 *		  2.��һ���ڵ�����ǰһ������
 *		  3.���һ���ڵ����һ������
 *        4.��������ڵ㣿����
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
		if (ListNodeCount == 2)//ֻ�������ڵ�
		{
			tempP = headP;
			headP = lastP;
			lastP = tempP;
			headP->NodeNextP = lastP;//important
			lastP->NodeNextP = nullptr;
#ifdef DOUBLELIST
			headP->NodePreP = nullptr;//��ͷǰָָ���
			lastP->NodePreP = headP;//��βָ���ͷ
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
			headP->NodePreP = nullptr;//ͬ��
			tempP->NodePreP = headP;//ͬ��
#endif
			return 6;
		}
		else if (ChangeDir == BEFOREONE)//����ڵ� ����ǰ��
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
			aimbefore = tempP->NodeNextP;//ǰһ����Ҫ�����Ľڵ�
			aim = aimbefore->NodeNextP;//pos����Ҫ�����Ľڵ�
			aimorgP = aim->NodeNextP;//pos���ָ��

			tempP->NodeNextP = aim;//�����ڵ�ǰ�Ľڵ� ָ��pos��
			aim->NodeNextP = aimbefore;//pos�� ָ��ǰһ����Ҫ�����Ľڵ�
			aimbefore->NodeNextP = aimorgP;//ָ��ǰһ����Ҫ�����Ľڵ� ָ�� ԭ��pos��ָ��
#ifdef DOUBLELIST
			if (aimorgP != nullptr)
				aimorgP->NodePreP = aimbefore; //pos���ǰָ�� ָ������aim ����Ϊ��
			aimbefore->NodePreP = aim;//ͬ��
			aim->NodePreP = tempP;//ͬ��
#endif
#ifdef DEBUG
			cout << "func : ListExchangeNodeAD, change before one, exchange success." << endl;
#endif // DEBUG
			return 4;
		}
		else if (ChangeDir == NEXTONE)//����ڵ� ��������
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
			aim = tempP->NodeNextP;//pos �ڵ�
			aimnext = aim->NodeNextP;//��Ҫ��������һ���ڵ�
			aimnextorgP = aimnext->NodeNextP;//��Ҫ��������һ���ڵ��ԭ��ָ��

			tempP->NodeNextP = aimnext;//�����ڵ�ǰ�Ľڵ� ָ����һ����Ҫ�����Ľڵ�
			aimnext->NodeNextP = aim;//��һ����Ҫ�����Ľڵ� ָ��pos�ڵ�
			aim->NodeNextP = aimnextorgP;//pos�ڵ�ָ�� ��һ����Ҫ�����Ľڵ��ԭָ��
#ifdef DOUBLELIST
			if(aimnextorgP != nullptr)
				aimnextorgP->NodePreP = aim; //pos���ǰָ�� ָ������aim ����Ϊ��
			aim->NodePreP = aimnext;//ͬ��
			aimnext->NodePreP = tempP;//ͬ��
#endif
#ifdef DEBUG
		cout << "func : ListExchangeNodeAD, change next one, exchange success." << endl;
#endif // DEBUG
		}
	}
	return 5;
}

/* @func  ģ����MYLIST ���ڷ���ĳ������Ľڵ�
 * @param pos(const unsigned int&) ����λ��
 * @get   LINKNODES<Ty>& ���ؽڵ������
 * @tip   ��һЩ�������� 
 * const ���ÿ��Խ���const���ݺͷ�const���ݡ� ���ǣ���const����ֻ�ܽ��շ�const���ݡ�
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
		if (tempP == lastP) break;//�����β
	}
	return (*tempP);//������ ��������
}

/* @func  ģ����MYLIST �Ƚ����������ؽ���
 * @param compare(MYLIST<Ty>&) ��Ҫ�ȽϵĶ���
 * @param result(CompareRes<Ty>&) �ȽϽ��
 * @param compare(CompareRes<Ty>&) �Ƚ���ʱ���
 * @get   CompareRes<Ty>& �ȽϽ��
 * @tip   ���������õݹ� ���ԱȽϳ�����Ӽ�
 */
template<typename Ty>//�˴���������ββ���Ϊconst
CompareRes<Ty>& HW3::MYLIST <Ty>::ListCompareList(MYLIST<Ty>& outlist,\
	CompareRes<Ty>& result, CompareRes<Ty>& compare)
{
	(this->*InitCompareResPfunc)(result);//��ʼ����� imporant
	const LINKNODES<Ty>* localP = this->headP;
	const LINKNODES<Ty>* outliP = outlist.ListGetHead();
	ListCompareListfunc(localP, outliP, result, compare);
	return result;
}

/* @func  ģ����MYLIST �ݹ������󽻼�
 * @param localstart(const LINKNODES<Ty>*) �Ƚϱ��ض�����ʼλ��
 * @param outstart(const LINKNODES<Ty>*) �Ƚ����ڶ�����ʼλ��
 * @param result(CompareRes<Ty>&) ���űȽϽ��
 * @param compare(CompareRes<Ty>&) �˴αȽϽ��
 * @get   void
 * @tip   ������������Ӽ�
 */
template<typename Ty>//�˴���������ββ���Ϊconst
void HW3::MYLIST <Ty>::ListCompareListfunc(const LINKNODES<Ty>* localstart, const LINKNODES<Ty>* outstart,\
	CompareRes<Ty>& result, CompareRes<Ty>& compare)
{
	if (localstart == nullptr || outstart == nullptr)
		return;//�ݹ����

	(this->*InitCompareResPfunc)(compare);//��ʼ��
	unsigned int i = 1, j = 1;
	unsigned int samecount = 0;
	const LINKNODES<Ty>* localP = localstart;
	const LINKNODES<Ty>* outliP = outstart;
	bool flag = false;
	bool second = false;

	for (; localP;)//��Ѱ���
	{
		outliP = outstart;
		for (; outliP;)
		{
			if (outliP->Info == localP->Info)
			{
				flag = true;
				compare.samepart.ListInsertLast(outliP->Info);//������Ϣ
				samecount++;
				break;
			}
			outliP = outliP->NodeNextP;
		}
		if (flag) break;
		localP = localP->NodeNextP;
	}
	if (flag)//������
	{
		compare.StartNodelocal = localP;//��¼��ʼ��ָ��
		compare.StartNodeout = outliP;//��¼��ʼ��ָ��
		for (; localP && outliP;)
		{
			if (outliP->Info != localP->Info) break;
			if (second) {
				compare.samepart.ListInsertLast(outliP->Info);//������Ϣ
				samecount++;
			}	
			if(!second)
				second = true;
			outliP = outliP->NodeNextP;;
			localP = localP->NodeNextP;
		}
		compare.samelength = samecount;
		compare.EndNodelocal = localP;//��¼��ʼ��ָ�� ����Ϊ��
		compare.EndNodeout = outliP;//��¼��ʼ��ָ��
	}
	if (compare.samelength > result.samelength)//����Ҫ���������ʱ��
	{
		result.samepart.ListInitialize();//��ʱɾ���Ĳ���Ϊresult
		result = compare;
		compare.samepart.ListResetPointCount();//�Ͽ�compare������������� ���ø�result
	}
	else
	{
		compare.samepart.ListInitialize();//���û�б�ԭ���� �ͳ�ʼ������
	}
	ListCompareListfunc(compare.EndNodelocal, outstart, result, compare);

	return;
}

/* @func  ģ����MYLIST �����󽻼��������ǽڵ�λ�ö�Ӧ˳���Ӧ
 * @param outlist(MYLIST<Ty>&) ��Ҫ�Ƚϵ��ⲿ����
 * @param result(CompareRes<Ty>&) ���űȽϽ��
 * @get   CompareRes<Ty>& ���
 */
template<typename Ty>//�˴���������ββ���Ϊconst
CompareRes<Ty>& HW3::MYLIST <Ty>::ListCompareNpos(MYLIST<Ty>& outlist, CompareRes<Ty>& result)
{
	(this->*InitCompareResPfunc)(result);//��ʼ��
	unsigned int i = 1, j = 1;
	unsigned int samecount = 0;
	const LINKNODES<Ty>* localP = this->headP;
	const LINKNODES<Ty>* outliP = outlist.ListGetHead();

	for (i = 1; localP && i <= this->ListNodeCount; i++)
	{
		outliP = outlist.ListGetHead();//�ⲿ�Ƚϻص�ͷ�ڵ�
		for (j = 1; outliP && j <= outlist.ListLength(); j++)
		{
			if (outliP->Info == localP->Info)
			{
				if (result.samepart.ListSearchPos(localP->Info) == ZERO)//����ͬ�ҵ�һ�γ���
				{
					result.samepart.ListInsertLast(outliP->Info);//������Ϣ
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