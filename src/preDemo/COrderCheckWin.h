#ifndef CORDERCHECKWIN_H
#define CORDERCHECKWIN_H
#include "CWindow.h"
class COrderCheckWin:public CWindow
{
public:
	COrderCheckWin(int x,int y,int width,int height);//���ι���
	void doAction();//��д���ി�麯��
	void enter_Check(int Btn_num);//������ϸ����
	void change_check_state();//�ı����״̬ 

	//��ť
	CLabel* Btn_1;//Btn_1->Btn_7����ѡ������
	CLabel* Btn_2;
	CLabel* Btn_3;
	CLabel* Btn_4;
	CLabel* Btn_5;
	CLabel* Btn_6;
	CLabel* Btn_7;
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