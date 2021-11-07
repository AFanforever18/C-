#ifndef CWINDOW_H
#define CWINDOW_H
#include <iostream>
#include <string>
#include "CTool.h"
#include "CControl.h"
#include "CEdit.h"
#include "CButton.h"
#include "CLabel.h"
#include "CTable.h"
#include "CTable_2.h"
#include "CTable_3.h"
#include <list>
#include <ctime>
#include <fstream>
using namespace std;
class CWindow//窗口类
{
private:
	int x;//x坐标
	int y;//y坐标
	int width;//宽度
	int height;//高度
	int count;//控件数
	int focus;//保存enter操作下标
	CControl* arr[20];//控件数组
	int num;//用于账号生成
	string type;//窗口类型
public:
	CWindow();//默认构造
	CWindow(int x,int y,int width,int height);//带参构造函数
	~CWindow();//析构函数
	int getX();//获取x坐标
	int getY();//获取y坐标
	int getWidth();//获取宽
	int getHeight();//获取高
	int getFocus();//获取enter操作下标
	int getCount();//获取控件数
	int getNum();//获取num
	CControl* getArr(int x);//获取控件数组
	void addControl(CControl *con);//添加控件
	virtual void doAction()=0;//窗口的操作 每个都不一样 纯虚 所有子类重写
	virtual	void search(string word);//查询打印商品信息--1.出库窗口  2.盘点窗口
	virtual string get_Search_word();//获取输入的商品编码--出库窗口,盘点窗口
	virtual string get_makeOrder_Num();//获取盘点编号--盘点报表
	virtual string get_Order_num();//获取输入的盘点数量--盘点窗口
	virtual int get_input_Goods_Num();//获取输入的出库数量--出库窗口
	virtual string get_search_null();//获取输入的未查到的商品编码--新增商品
	virtual string getTitleType();//获取提示窗口类型--提示窗口
	virtual void setTitleType(string word);//设置提示窗口类型--提示窗口
	virtual int fuzzyQuery();//模糊查询-6.12test
	


	void CWindow_Show();//画窗口
	void CWindow_Table_Show();//画窗口--模糊查询
	void CWindow_Show_Select();//画窗口--选择用户类型窗口
	void winRun();//窗口交互
	void change(CControl* con,int i);//换控件

};
#endif
extern CWindow * winArr2[15];//存窗口
extern CWindow * winArr[30];//存窗口
extern string fuzzy_word;//模糊查询

extern list<string>order_goods_record;//存商品盘点记录
extern string data;//时间
extern map<int,CUser>mymap;//存用户信息
extern map<string,CGoods>mymap_goods;//存商品信息
extern gbl_accountNum;//生成账号用的
extern current_Account;//当前登入者账号
extern  string user_name;//用户名
extern list<CGoods> temp_list;//盘点报表
extern page_current;//当前页数--盘点报表
extern page_current_2;//当前页数--冲正
extern page_current_3;//当前页数--冲正中
extern string gbl_selectNUM;//冲正--盘点编号
extern string gbl_goods_selectNUM;//冲正--7个属性--选择商品编号
extern map<string,CGoods> map_check;//冲正信息容器--7个属性