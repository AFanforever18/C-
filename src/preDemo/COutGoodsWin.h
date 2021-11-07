#ifndef COUTGOODSWIN_H
#define COUTGOODSWIN_H
#pragma   warning (disable: 4786)
#include "CWindow.h"
#include <sstream>
#include <string>
class COutGoodsWin:public CWindow
{
private:
	string search_word;//存输入的商品编码
	int input_Goods_Num;//输入的出库数量
public:
	COutGoodsWin();//默认构造
	COutGoodsWin(int x,int y,int width,int height);//默认构造//带参构造
	~COutGoodsWin();//默认析构
	void doAction();//窗口的操作 每个都不一样 纯虚 所有子类重写
	void search(string word);//查询打印商品信息
	void goodsOut();//商品出库
	string get_Search_word();//获取输入的商品编码
	int get_input_Goods_Num();//获取输入的出库数量
	//标签
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;//日期
	CLabel* inputNum_label;//查询商品编号
	CLabel* outGoods_label;//出库数量
	CLabel* goods_Name;//商品名称
	CLabel* goods_Type;//"商品类型:");
	CLabel* goods_Price;//商品价格
	CLabel* goods_NUm;//库存数量
	CLabel* goods_WarehouseNum;//仓位编号
	//编辑框
	CEdit* inputNum_edit;//输入商品编号
	CEdit* inputoutGoods_edit;//输入出库数量
	//按钮
	CButton* find_Btn;//商品查询
	CButton* import_Btn;//确定出库按钮
	CButton* myexit;//退出
	//表格
	CTable* table;
};
#endif
