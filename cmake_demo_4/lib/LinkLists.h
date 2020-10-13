#pragma once
//#define DEBUG      //�������� ������Ϣ��ʾ
//#define DOUBLELIST //����˫������
#define ZERO 0
typedef	 unsigned int TestBack;
enum DIR {
	NEXTONE = 100,
	BEFOREONE
};

namespace HW3 {
#ifdef DOUBLELIST 
	template<typename Ty>//˫������ڵ�ģ��
	struct LINKNODES {
		LINKNODES* NodePreP;
		Ty Info;
		LINKNODES* NodeNextP;
	};
#else
	template<typename Ty>//��������ڵ�ģ��
	struct LINKNODES {
		LINKNODES* NodeNextP;
		Ty Info;
	};
#endif

	template <typename Ty> //����ģ����
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
		MYLIST();//Ĭ�Ϲ��캯��

		~MYLIST();//��������

		//��һ������Ϊһ�����飬�ڶ�������Ϊ���鳤�ȣ������鰴�մ���������
		MYLIST(Ty* inputInfoArray, unsigned int length);

		//���������ͷָ�� inline
		LINKNODES<Ty>* ListGetHead(void) const { return headP; }

		//���������βָ�� inline
		LINKNODES<Ty>* ListGetLast(void) const { return lastP; }

		//��ʼ�����������ͷβָ��ͼ���������ʹ��
		bool ListResetPointCount(void);

		//��ʾһ����������г�Ա��Ϣ
		void ListShowAllElements(void) const;
		
		//�ж�һ�������Ƿ�Ϊ��
		bool ListIsEmpty(void) const;

		//����������
		TestBack ListLength(void) const;
		
		//ɾ��ĳ���ڵ� ����Ϊ�ýڵ��������е�λ�� ���� 1 2 3 4 5
		TestBack ListDeleteNode(const unsigned int pos);
		
		//�ٻ�������ʼ������ɾ������
		bool ListDestory(void);

		//�����ʼ��
		void ListInitialize(void);

		//����λ�ò������ڵ㣬��һ�������ǲ����λ�� �� 1 2 3 4 5���ڶ��������ǲ����������Ϣ
		TestBack ListInsertNode(const unsigned int& pos, const Ty& insertinfo);	
		
		//�������ͷ������һ���ڵ㣬�����ǲ������Ϣ
		TestBack ListInsertHead(const Ty& insertinfo);//������ǰ

		//�������β������һ���ڵ㣬�����ǲ������Ϣ
		TestBack ListInsertLast(const Ty& insertinfo);//�������

		//��������ڵ㣬���ظýڵ��λ�ã������������Ľڵ�����Ӧ����Ϣ
		TestBack ListSearchPos(const Ty& serchitem) const;

		//�����������ڽڵ㣬��һ�������ǽ�������ʼλ��,�ڶ��������ǽ������� ��ѡ NEXTONE,BEFOREONE
		TestBack ListExchangeNodeAD(const unsigned int& pos, DIR ChangeDir);
		
		//���ؾ���ڵ�����ã�������λ��
		const LINKNODES<Ty>& ListGetNode(const unsigned int& pos);

		//�Ƚ�����������󣬷��ؽ���(���ǽڵ�λ��)
		CompareRes<Ty>& ListCompareList(MYLIST<Ty>&, CompareRes<Ty>&, CompareRes<Ty>&);
		
		//����ָ���Ա�����ĺ���ָ�� imporant
		bool (MYLIST::*InitCompareResPfunc)(CompareRes<Ty>&);

		//�Ƚ�����������󣬷��ؽ���(�����ǽڵ�λ��)
		CompareRes<Ty>& ListCompareNpos(MYLIST<Ty>&, CompareRes<Ty>&);

	private:
		bool ListInitCompare(CompareRes<Ty>&);//��ʼ��CompareRes
		void ListCompareListfunc(const LINKNODES<Ty>* , const LINKNODES<Ty>* , \
			CompareRes<Ty>& , CompareRes<Ty>& );//���������(���ǽڵ�λ��)
		LINKNODES<Ty>* headP;//ͷָ��
		LINKNODES<Ty>* lastP;//βָ��
		unsigned int ListNodeCount;
	};
}