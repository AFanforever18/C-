#ifndef CORDERTABLEWIN_H
#define CORDERTABLEWIN_H
#pragma   warning (disable: 4786)
#include "CWindow.h"
#include <sstream>
#include <string>
class COrderTableWin:public CWindow
{
public:
	COrderTableWin();//Ĭ�Ϲ���
	COrderTableWin(int x,int y,int width,int height);//���ι���
	~COrderTableWin();//Ĭ������
	void doAction();//���ڵĲ��� ÿ������һ�� ���� ����������д
	void printf_Content();//��ӡ��Ʒ��Ϣ

	//��ǩ
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;//����
	CLabel* orderNum;//�̵���
	CLabel* order_state;//�̵�״̬
	CLabel* jiantou;//��ͷ
	CLabel* page_num;//ҳ��
	//��ť
	CButton* myexit;//ȡ��
	CButton* over_order;//�����̵�
	//���
	CTable_2* table;
};
#endif

