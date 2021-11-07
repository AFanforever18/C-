#ifndef CORDERCHECKWIN_H
#define CORDERCHECKWIN_H
#include "CWindow.h"
class COrderCheckWin:public CWindow
{
public:
	COrderCheckWin(int x,int y,int width,int height);//带参构造
	void doAction();//重写父类纯虚函数
	void enter_Check(int Btn_num);//进入详细数据
	void change_check_state();//改变冲正状态 

	//按钮
	CLabel* Btn_1;//Btn_1->Btn_7用于选择数据
	CLabel* Btn_2;
	CLabel* Btn_3;
	CLabel* Btn_4;
	CLabel* Btn_5;
	CLabel* Btn_6;
	CLabel* Btn_7;
	CButton* exit_Button;//返回

	//标签
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;
	CLabel* jiantou;
	CLabel* order_num;
	CLabel* order_state;
	CTable_3* table;
};
#endif