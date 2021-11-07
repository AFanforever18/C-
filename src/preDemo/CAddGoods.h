#ifndef CADDGOODS_H
#define CADDGOODS_H
#include "CWindow.h"
class CAddGoods:public CWindow
{
public:
	CAddGoods(int x,int y,int width,int height);//带参构造
	void doAction();//重写父类纯虚函数
	void addGoods();//商品添加函数

	//按钮
	CButton* enter_Button;//确定
	CButton* esc_Button;//取消

	//编辑框
	CEdit* Name;//商品名称
	CEdit* Type;//商品类型
	CEdit* Price;//商品价格
	CEdit* warehouseNum;//仓位编号
	//标签
	CLabel* managername;//用户名
	CLabel* mydate;//日期
	CLabel* title;//标题
	CLabel* goods_Num;//商品编号
	CLabel* goods_Num_content;//编号内容
	CLabel* goods_Name;//商品名称
	CLabel* goods_Type;//商品类型
	CLabel* goods_Price;//商品价格
	CLabel* goods_warehouseNum;//仓位编号
};
#endif
