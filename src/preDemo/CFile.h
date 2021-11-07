#ifndef CFILE_H
#define CFILE_H
#pragma   warning (disable: 4786)
#include <iostream>
#include <fstream>
#include <string>
#include "CUser.h"
#include "CGoods.h"
#include "CTool.h"
#include <ctime>
#include <list>
using namespace std;
class CFile
{
public:
	CFile();//构造
	~CFile();//析构
	static void userFileRead();//用户文件读取--读取用户类
	static void goodsFileRead();//文件读取--读取仓库商品
	static void userWrite(string ID,string name,string pwd,int role);//用户写入文件--注册可用
	static void goodsWrite(string goodsNum,string goodsName,string goodsType,string goodsPrice,string inventory,string warehouseNum);//商品写入文件
	static void goods_Record_Write(string goodsNum,string goodsName,string inventory,string orderNum,string errorNum,int num);//盘点编号写入文件	
	static void goods_Order_Read(list<CGoods> &order_list,string src);//读取盘点编号     参数:盘点容器 和 文件路径
	static void ALL_Check_Write(string order_num,string goodsNum,string goodsName,string inventory,string orderNum,string errorNum,string check,string seaon);//冲正信息
	static void order_check_read();//冲正选择的盘点编号读到容器
	static void num_and_state_read();//读取文件中盘点编号和冲正状态写入mymap_order_num容器
	static void num_and_state_write(string num,string state);//盘点编号和冲正的容器mymap_order_num写入文件
	static void new_Check_Data_Write();//冲正后的商品信息写入文件
};
#endif
extern map<int,CUser>mymap;//存用户信息
extern map<string,CGoods>mymap_goods;//存商品信息
extern string data;//时间
extern string gbl_orderNUM;
extern string gbl_orderNUM;//data下最新盘点编号
extern map<string,CGoods> map_check;//冲正信息容器
extern map<string,string>mymap_order_num;//存盘点编号和冲正状态的容器

