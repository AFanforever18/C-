#ifndef CORDERMANWIN_MENU_H
#define CORDERMANWIN_MENU_H
#include "CWindow.h"
class COrderManWin_Menu:public CWindow
{
public:
	COrderManWin_Menu(int x,int y,int width,int height);//���ι���
	void doAction();//���ڵĲ��� ÿ������һ�� ���� ����������д

	//��ǩ
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;
	//��ť
	CButton* newOrder_Btn;//��Ʒ��ѯ
	CButton* orderRecord_Btn;//�̵���Ʒ
	CButton* myexit;//����
};
#endif
