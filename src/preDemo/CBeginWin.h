#ifndef CBEGINWIN_H
#define CBEGINWIN_H
#include "CWindow.h"
class CBeginWin:public CWindow
{
public:
	CBeginWin();//默认构造
	CBeginWin(int x,int y,int width,int height);//带参构造
	~CBeginWin();//析构函数
	void doAction();//重写父类纯虚函数

	//按钮
	CButton* login_Button;//登入
	CButton* reg_Button;//注册
	CButton* exit_Button;//退出

	//标签
	CLabel* title;
	CLabel* stu_num;
};
#endif