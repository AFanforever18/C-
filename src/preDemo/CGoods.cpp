#include "CGoods.h"
//Ĭ�Ϲ���
CGoods::CGoods()
{
	
}
//���ι���
CGoods::CGoods(string goodsNum,string goodsName,string goodsType,string goodsPrice,string inventory,string warehouseNum)
{
	this->goodsNum=goodsNum;
	this->goodsName=goodsName;
	this->goodsType=goodsType;
	this->goodsPrice=goodsPrice;
	this->inventory=inventory;
	this->warehouseNum=warehouseNum;
}
//����
CGoods::~CGoods()
{
	
}
//��ȡ��Ʒ���
string CGoods::getGoodsNum()
{
	return this->goodsNum;
}
//��ȡ��Ʒ����
string CGoods::getGoodsName()
{
	return this->goodsName;
}
//��ȡ��Ʒ����
string CGoods::getGoodsType()
{
	return this->goodsType;
}
//��ȡ��Ʒ�۸�
string CGoods::getGoodsPrice()
{
	return this->goodsPrice;
}
//��ȡ�������
string CGoods::getInventory()
{
	return this->inventory;
}
//��ȡ��λ���
string CGoods::getWarehouseNum()
{
	return this->warehouseNum;
}