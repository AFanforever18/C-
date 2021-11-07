#include "CGoods.h"
//默认构造
CGoods::CGoods()
{
	
}
//带参构造
CGoods::CGoods(string goodsNum,string goodsName,string goodsType,string goodsPrice,string inventory,string warehouseNum)
{
	this->goodsNum=goodsNum;
	this->goodsName=goodsName;
	this->goodsType=goodsType;
	this->goodsPrice=goodsPrice;
	this->inventory=inventory;
	this->warehouseNum=warehouseNum;
}
//析构
CGoods::~CGoods()
{
	
}
//获取商品编号
string CGoods::getGoodsNum()
{
	return this->goodsNum;
}
//获取商品名称
string CGoods::getGoodsName()
{
	return this->goodsName;
}
//获取商品类型
string CGoods::getGoodsType()
{
	return this->goodsType;
}
//获取商品价格
string CGoods::getGoodsPrice()
{
	return this->goodsPrice;
}
//获取库存数量
string CGoods::getInventory()
{
	return this->inventory;
}
//获取仓位编号
string CGoods::getWarehouseNum()
{
	return this->warehouseNum;
}