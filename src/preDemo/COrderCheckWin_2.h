#ifndef CORDERCHECKWIN_2_H
#define CORDERCHECKWIN_2_H
#include "CWindow.h"
class COrderCheckWin_2:public CWindow
{
public:
	COrderCheckWin_2(int x,int y,int width,int height);//���ι���
	void doAction();//��д���ി�麯��
	void beg_Check(int Btn_num);//��ʼ����
	

	//��ť
	CLabel* Btn_1;//Btn_1->Btn_7����ѡ������
	CLabel* Btn_2;
	CLabel* Btn_3;
	CLabel* Btn_4;
	CLabel* Btn_5;
	CLabel* Btn_6;
	CButton* over_Button;
	CButton* exit_Button;//����

	//��ǩ
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;
	CLabel* jiantou;
	CLabel* order_num;
	CLabel* order_state;
	CTable_3* table;
};
#endif