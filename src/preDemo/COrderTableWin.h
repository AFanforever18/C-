#ifndef CORDERTABLEWIN_H
#define CORDERTABLEWIN_H
#pragma   warning (disable: 4786)
#include "CWindow.h"
#include <sstream>
#include <string>
class COrderTableWin:public CWindow
{
public:
	COrderTableWin();//默认构造
	COrderTableWin(int x,int y,int width,int height);//带参构造
	~COrderTableWin();//默认析构
	void doAction();//窗口的操作 每个都不一样 纯虚 所有子类重写
	void printf_Content();//打印商品信息

	//标签
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;//日期
	CLabel* orderNum;//盘点编号
	CLabel* order_state;//盘点状态
	CLabel* jiantou;//箭头
	CLabel* page_num;//页数
	//按钮
	CButton* myexit;//取消
	CButton* over_order;//结束盘点
	//表格
	CTable_2* table;
};
#endif

