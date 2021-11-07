#ifndef CNEWOREDERWIN_H
#define CNEWOREDERWIN_H
#pragma   warning (disable: 4786)
#include "CWindow.h"
#include <sstream>
#include <string>
#include <ctime>
class CNewOrderWin:public CWindow
{
private:
	string search_word;//存输入的商品编码
	string order_num;//存输入的盘点数量
	int num;//盘点 001 002 003 自增用
	string orderNUM;//盘点编号
	int count;//编号回去
public:
	CNewOrderWin();//默认构造
	CNewOrderWin(int x,int y,int width,int height);//默认构造//带参构造
	~CNewOrderWin();//默认析构
	void doAction();//窗口的操作 每个都不一样 纯虚 所有子类重写
	void search(string word);//打印商品信息
	string get_Search_word();//获取输入的商品编码	
	string get_Order_num();//获取输入的盘点数量
	void record();//记录盘点表
	string makeOrder_Num();//生成盘点编号
	string get_makeOrder_Num();//获取盘点编号--盘点报表

	//标签
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;//日期
	CLabel* inputNum_label;//查询商品编号
	CLabel* orderNum;//盘点编号
	CLabel* outGoods_label;//出库数量
	CLabel* goods_Name;//商品名称
	CLabel* goods_Type;//"商品类型:");
	CLabel* goods_Price;//商品价格
	CLabel* goods_WarehouseNum;//仓位编号
	//编辑框
	CEdit* inputNum_edit;//输入商品编号
	CEdit* inputoutGoods_edit;//输入出库数量
	//按钮
	CButton* find_Btn;//商品查询
	CButton* import_Btn;//确定出库按钮
	CButton* myexit;//取消
	CButton* orderTable;//生成盘点报表
	//表格
	CTable* table;
};
#endif
