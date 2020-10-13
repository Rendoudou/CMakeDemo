#include <iostream>
#include "LinkLists.h"
constexpr auto CAP = 0x05;
constexpr auto TCAP = 0X0B;

using namespace std;
using HW3::CompareRes;
using HW3::LINKNODES;
using HW3::MYLIST;
CompareRes<int> Res;
CompareRes<int> hRes;	
int Marray[CAP] = { 11,2,3,5,4 };
int Tarray[TCAP] = { 2,1,3,4,6,5,8,11,21,15,23 };

int main(int argc, char* argv[])
{
	//具体实现请查看 "LinkLists.cpp" 
	//打开 LinkLists.h 中的 DEBUG 宏来显示测试信息
	//打开 LinkLists.h 中的 DOUBLELIST 宏来切换为双向链表
	CompareRes<int>& result = Res;
	CompareRes<int>& hresult = hRes;
	MYLIST<int> test(Marray, CAP);		                       //模板类创建对象
	MYLIST<int> testb(Tarray, TCAP);

	cout << "Before exchange listnode : " << endl;
	test.ListShowAllElements();                                //显示链表内容
	testb.ListShowAllElements();

	result = test.ListCompareList(testb, result, hresult);     //得出交集(考虑节点位置)
	cout << "Before exchange same part : " << endl;
	result.samepart.ListShowAllElements();
	testb.ListCompareNpos(test, result);
	cout << "Before exchange same part(think about position) : " << endl;
	result.samepart.ListShowAllElements();                     //得出交集(不考虑位置)

	//交换
	test.ListExchangeNodeAD(test.ListSearchPos(4), BEFOREONE);  //交换相邻的节点 找第一个4和前者交换
	testb.ListExchangeNodeAD(testb.ListSearchPos(1), BEFOREONE);//交换相邻的节点 找第一个1和前者交换
	//testb.ListExchangeNodeAD(2, BEFOREONE);                   //第二个位置向前交换
	testb.ListExchangeNodeAD(testb.ListSearchPos(6), NEXTONE);  //交换相邻的节点 找到第一个6和前者交换
	//testb.ListExchangeNodeAD(5, NEXTONE);                     //第五个位置向后交换
	
	cout << "==========================depart line=============================" << endl << endl;

	cout << "After exchange : " << endl;
	test.ListShowAllElements();
	testb.ListShowAllElements();

	result = test.ListCompareList(testb, result, hresult);      //得出交集
	cout << "After exchange same part : " << endl;
	result.samepart.ListShowAllElements();
	testb.ListCompareNpos(test, result);
	cout << "After exchange same part(think about positon) : " << endl;
	result.samepart.ListShowAllElements();                      //得出交集(不考虑位置)

	cin.get();
	return 0;
}