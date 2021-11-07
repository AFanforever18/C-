#ifndef CGOODSSEARCH_H
#define CGOODSSEARCH_H
#pragma   warning (disable: 4786)
#include "CWindow.h"
#include <sstream>
#include <string>
class CGoodsSearchWin:public CWindow
{
public:
	CGoodsSearchWin();//默认构造
	CGoodsSearchWin(int x,int y,int width,int height);//默认构造//带参构造
	~CGoodsSearchWin();//默认析构
	void doAction();//窗口的操作 每个都不一样 纯虚 所有子类重写
	int accurateQuery();//精确查询
	int fuzzyQuery();//模糊查询
	void input_goods_data();//导出商品信息
	//标签
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;
	CLabel* inputNum_label;
	CLabel* tableNum_label;
	//编辑框
	CEdit* inputNum_edit;
	//按钮
	CButton* find_Btn;//商品查询
	CButton* import_Btn;//导入商品
	CButton* myexit;//退出
	//表格
	CTable* table;
};
#endif
