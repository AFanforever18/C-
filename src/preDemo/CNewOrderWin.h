#ifndef CNEWOREDERWIN_H
#define CNEWOREDERWIN_H
#pragma   warning (disable: 4786)
#include "CWindow.h"
#include <sstream>
#include <string>
#include <ctime>
class CNewOrderWin:public CWindow
{
private:
	string search_word;//���������Ʒ����
	string order_num;//��������̵�����
	int num;//�̵� 001 002 003 ������
	string orderNUM;//�̵���
	int count;//��Ż�ȥ
public:
	CNewOrderWin();//Ĭ�Ϲ���
	CNewOrderWin(int x,int y,int width,int height);//Ĭ�Ϲ���//���ι���
	~CNewOrderWin();//Ĭ������
	void doAction();//���ڵĲ��� ÿ������һ�� ���� ����������д
	void search(string word);//��ӡ��Ʒ��Ϣ
	string get_Search_word();//��ȡ�������Ʒ����	
	string get_Order_num();//��ȡ������̵�����
	void record();//��¼�̵��
	string makeOrder_Num();//�����̵���
	string get_makeOrder_Num();//��ȡ�̵���--�̵㱨��

	//��ǩ
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;//����
	CLabel* inputNum_label;//��ѯ��Ʒ���
	CLabel* orderNum;//�̵���
	CLabel* outGoods_label;//��������
	CLabel* goods_Name;//��Ʒ����
	CLabel* goods_Type;//"��Ʒ����:");
	CLabel* goods_Price;//��Ʒ�۸�
	CLabel* goods_WarehouseNum;//��λ���
	//�༭��
	CEdit* inputNum_edit;//������Ʒ���
	CEdit* inputoutGoods_edit;//�����������
	//��ť
	CButton* find_Btn;//��Ʒ��ѯ
	CButton* import_Btn;//ȷ�����ⰴť
	CButton* myexit;//ȡ��
	CButton* orderTable;//�����̵㱨��
	//���
	CTable* table;
};
#endif
