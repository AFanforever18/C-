#ifndef CTOOL_H
#define CTOOL_H
#pragma   warning (disable: 4786)
#include <iostream>
#include <string>
#include <windows.h>//光标定位需要
#include "Control.h"
#include "CUser.h"
#include "CGoods.h"
#include <sstream>
#include "CGoods.h"
#include <map>
#include <list>
#include <fstream>
#include <conio.h>//
#include <io.h>

#define KEY_ESC 27
#define KEY_ENTER 13
#define KEY_UP -1
#define KEY_DOWN -2
#define KEY_LEFT -3
#define KEY_RIGHT -4

using namespace std;
class CTool
{
public:
	//光标切换
	static void gotoxy(int x,int y);
	//画框
	static void paintBorder(int startX, int startY,int width,int height);
	//获取键值
	static int Key();
	//
	static void show();
	static void prtinf_Table_Content(list<CGoods> goods_list);//盘点报表--数据打印
	static void printf_Table_Order();//盘点编号和冲正状态--数据打印
	static void printf_Table_Order_All();//盘点冲正信息--数据打印
	static string strtoInt(int val);//int->string
	static void clear(int x,int y,int width,int height);//局部清空
	static void file_opear();//遍历文件
	
};
#endif
extern page_current;//当前页数--盘点报表
extern page_current_2;//当前页数--冲正
extern page_current_3;//当前页数--冲正中
extern page_current_4;////当前页数--冲正--7个属性
extern map<string,string>mymap_order_num;//存盘点编号和冲正状态
extern string gbl_selectNUM;//冲正--盘点编号
extern string gbl_orderNUM;//data下最新盘点编号
extern map<string,CGoods> map_check;//冲正信息容器
