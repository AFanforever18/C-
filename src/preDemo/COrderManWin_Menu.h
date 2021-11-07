#ifndef CORDERMANWIN_MENU_H
#define CORDERMANWIN_MENU_H
#include "CWindow.h"
class COrderManWin_Menu:public CWindow
{
public:
	COrderManWin_Menu(int x,int y,int width,int height);//带参构造
	void doAction();//窗口的操作 每个都不一样 纯虚 所有子类重写

	//标签
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;
	//按钮
	CButton* newOrder_Btn;//商品查询
	CButton* orderRecord_Btn;//盘点商品
	CButton* myexit;//返回
};
#endif
