#ifndef CORDERCHECKWIN_2_H
#define CORDERCHECKWIN_2_H
#include "CWindow.h"
class COrderCheckWin_2:public CWindow
{
public:
	COrderCheckWin_2(int x,int y,int width,int height);//带参构造
	void doAction();//重写父类纯虚函数
	void beg_Check(int Btn_num);//开始冲正
	

	//按钮
	CLabel* Btn_1;//Btn_1->Btn_7用于选择数据
	CLabel* Btn_2;
	CLabel* Btn_3;
	CLabel* Btn_4;
	CLabel* Btn_5;
	CLabel* Btn_6;
	CButton* over_Button;
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