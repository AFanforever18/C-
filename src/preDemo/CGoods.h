#ifndef CGOODS_H
#define CGOODS_H
#pragma   warning (disable: 4786)
#include <iostream>
#include <map>
using namespace std;
class CGoods
{
public:
	CGoods();//默认构造
	CGoods(	string goodsNum,string goodsName,string goodsType,string goodsPrice,string inventory,string warehouseNum);//带参构造
	~CGoods();//析构
	string getGoodsNum();//获取商品编号
	string getGoodsName();//获取商品名称
	string getGoodsType();//获取商品类型
	string getGoodsPrice();//获取商品价格
	string getInventory();//获取库存数量
	string getWarehouseNum();//获取仓位编号

private:
	string goodsNum;//商品编号
	string goodsName;//商品名称
	string goodsType;//商品类型
	string goodsPrice;//商品价格
	string inventory;//库存数量
	string warehouseNum;//仓位编号
};
#endif