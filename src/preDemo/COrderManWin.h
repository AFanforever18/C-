#ifndef CORDERMANWIN_H
#define CORDERMANWIN_H
#include "CWindow.h"
class COrderManWin:public CWindow
{
public:
	COrderManWin();//Ĭ�Ϲ���
	COrderManWin(int x,int y,int width,int height);//Ĭ�Ϲ���//���ι���
	~COrderManWin();//Ĭ������
	void doAction();//���ڵĲ��� ÿ������һ�� ���� ����������д

	//��ǩ
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;
	//��ť
	CButton* find_Btn;//��Ʒ��ѯ
	CButton* order_Btn;//�̵���Ʒ
	CButton* myexit;//�˳�
};
#endif

