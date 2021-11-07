#ifndef CORDERMANWIN_H
#define CORDERMANWIN_H
#include "CWindow.h"
class COrderManWin:public CWindow
{
public:
	COrderManWin();//默认构造
	COrderManWin(int x,int y,int width,int height);//默认构造//带参构造
	~COrderManWin();//默认析构
	void doAction();//窗口的操作 每个都不一样 纯虚 所有子类重写

	//标签
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;
	//按钮
	CButton* find_Btn;//商品查询
	CButton* order_Btn;//盘点商品
	CButton* myexit;//退出
};
#endif

