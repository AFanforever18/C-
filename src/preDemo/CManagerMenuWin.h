#ifndef CMANAGERMENUWIN_H
#define CMANAGERMENUWIN_H
#include "CWindow.h"
class CManagerMenuWin:public CWindow
{
public:
	CManagerMenuWin();//Ĭ�Ϲ���
	CManagerMenuWin(int x,int y,int width,int height);//Ĭ�Ϲ���//���ι���
	~CManagerMenuWin();//Ĭ������
	void doAction();//���ڵĲ��� ÿ������һ�� ���� ����������д

	//��ǩ
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;
	//��ť
	CButton* find_Btn;
	CButton* import_Btn;
	CButton* input_Btn;
	CButton* output_Btn;
	CButton* orderCheck_Btn;
	CButton* myexit;
};

#endif
