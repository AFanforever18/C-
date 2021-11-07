#ifndef CADDGODDSMENUWIN_H
#define CADDGODDSMENUWIN_H
#include "CWindow.h"
class CAddGoodsMenuWin:public CWindow
{
public:
	CAddGoodsMenuWin();//默认构造
	CAddGoodsMenuWin(int x,int y,int width,int height);//带参构造
	~CAddGoodsMenuWin();//析构函数
	void doAction();//重写父类纯虚函数

	//按钮
	CButton* add_Button;//登入
	CButton* record_Button;//注册
	CButton* exit_Button;//退出

	//标签
	CLabel* title;//标题
	CLabel* managername;//用户名
	CLabel* mydate;//日期
};
#endif