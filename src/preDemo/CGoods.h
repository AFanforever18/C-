#ifndef CGOODS_H
#define CGOODS_H
#pragma   warning (disable: 4786)
#include <iostream>
#include <map>
using namespace std;
class CGoods
{
public:
	CGoods();//Ĭ�Ϲ���
	CGoods(	string goodsNum,string goodsName,string goodsType,string goodsPrice,string inventory,string warehouseNum);//���ι���
	~CGoods();//����
	string getGoodsNum();//��ȡ��Ʒ���
	string getGoodsName();//��ȡ��Ʒ����
	string getGoodsType();//��ȡ��Ʒ����
	string getGoodsPrice();//��ȡ��Ʒ�۸�
	string getInventory();//��ȡ�������
	string getWarehouseNum();//��ȡ��λ���

private:
	string goodsNum;//��Ʒ���
	string goodsName;//��Ʒ����
	string goodsType;//��Ʒ����
	string goodsPrice;//��Ʒ�۸�
	string inventory;//�������
	string warehouseNum;//��λ���
};
#endif