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
	//����ʵ����鿴 "LinkLists.cpp" 
	//�� LinkLists.h �е� DEBUG ������ʾ������Ϣ
	//�� LinkLists.h �е� DOUBLELIST �����л�Ϊ˫������
	CompareRes<int>& result = Res;
	CompareRes<int>& hresult = hRes;
	MYLIST<int> test(Marray, CAP);		                       //ģ���ഴ������
	MYLIST<int> testb(Tarray, TCAP);

	cout << "Before exchange listnode : " << endl;
	test.ListShowAllElements();                                //��ʾ��������
	testb.ListShowAllElements();

	result = test.ListCompareList(testb, result, hresult);     //�ó�����(���ǽڵ�λ��)
	cout << "Before exchange same part : " << endl;
	result.samepart.ListShowAllElements();
	testb.ListCompareNpos(test, result);
	cout << "Before exchange same part(think about position) : " << endl;
	result.samepart.ListShowAllElements();                     //�ó�����(������λ��)

	//����
	test.ListExchangeNodeAD(test.ListSearchPos(4), BEFOREONE);  //�������ڵĽڵ� �ҵ�һ��4��ǰ�߽���
	testb.ListExchangeNodeAD(testb.ListSearchPos(1), BEFOREONE);//�������ڵĽڵ� �ҵ�һ��1��ǰ�߽���
	//testb.ListExchangeNodeAD(2, BEFOREONE);                   //�ڶ���λ����ǰ����
	testb.ListExchangeNodeAD(testb.ListSearchPos(6), NEXTONE);  //�������ڵĽڵ� �ҵ���һ��6��ǰ�߽���
	//testb.ListExchangeNodeAD(5, NEXTONE);                     //�����λ����󽻻�
	
	cout << "==========================depart line=============================" << endl << endl;

	cout << "After exchange : " << endl;
	test.ListShowAllElements();
	testb.ListShowAllElements();

	result = test.ListCompareList(testb, result, hresult);      //�ó�����
	cout << "After exchange same part : " << endl;
	result.samepart.ListShowAllElements();
	testb.ListCompareNpos(test, result);
	cout << "After exchange same part(think about positon) : " << endl;
	result.samepart.ListShowAllElements();                      //�ó�����(������λ��)

	cin.get();
	return 0;
}