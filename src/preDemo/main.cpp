#include <iostream>
#pragma   warning (disable: 4786)
#include "CTool.h"
#include "CButton.h"
#include "CLogin.h"
#include "CBeginWin.h"
#include "CRegisterWin.h"
#include "CManagerMenuWin.h"
#include "COrderManWin.h"
#include "CGoodsSearch.h"
#include "COutGoodsWin.h"//商品出库
#include "CTipsWin.h"//提示窗口
#include "CTipsWin_2.h"//提示窗口--入库
#include "CNewOrderWin.h";//新建盘点
#include "COrderTableWin.h"//盘点表
#include "CAddGoodsMenuWin.h"//商品入库菜单界面
#include "CInputGoodsWin.h"//商品入库界面
#include "CAddGoods.h"//新增商品
#include "COrderCheckWin.h"//冲正
#include "COrderCheckWin_2.h"//冲正2
#include "CTips_Check_Win.h"//冲正--7个属性--提示窗口--冲正
#include "COrderManWin_Menu.h"
#include "CGoods.h"
#include <io.h>
#include <string>
#include <sstream>//int to string
#include <map>
#include <list>
#include <ctime>
using namespace std;
//全局变量
CWindow * winArr[30];//存窗口---跳转
CWindow * winArr2[15];//存窗口--注册
map<int,CUser>mymap;//存用户信息
map<string,CGoods>mymap_goods;//存商品信息
map<string,string>mymap_order_num;//存盘点编号和冲正状态
list<string>order_goods_record;//存商品盘点编号
int gbl_accountNum=0;//生成账号用的
int current_Account=0;//当前登入者账号
string user_name;//用户名
string fuzzy_word;//模糊查询 
string data;//时间数据
list<CGoods> temp_list;//盘点报表
int page_current=1;//当前页数--盘点报表
int page_current_2=1;//当前页数--冲正
int page_current_3=1;//当前页数--冲正中
int page_current_4=1;//当前页数--冲正--7个属性
string gbl_orderNUM;//data下最新盘点编号
string gbl_selectNUM;//冲正--选择盘点编号
string gbl_goods_selectNUM;//冲正--7个属性--选择商品编号
map<string,CGoods> map_check;//冲正信息容器--7个属性
int main()
{   
	//盘点编号和盘点状态存入容器mymap_order_num
	CFile::num_and_state_read();

	//遍历文件夹下的所有文件
	CTool::file_opear();
	
    // 基于当前系统的当前日期/时间
    tm *ltm;
    time_t now = time(0);
    ltm= localtime(&now); 
	data=CTool::strtoInt(ltm->tm_year+1900)+"-"+CTool::strtoInt(ltm->tm_mon+1)+"-"+CTool::strtoInt(ltm->tm_mday);//获取时间
	//一开始就要读文件放入 map容器
	CFile::userFileRead();
	CFile::goodsFileRead();	

	map<int,CUser>::iterator iter;//用迭代器找到最后一个
	iter=mymap.end();
	string nn;//存账号
	if(mymap.begin()!=iter)
	{
		iter--;
		//将字符串变为int型
		string str=iter->second.getID();
		int temp=atoi(str.c_str());
		temp=temp+1;//找到最后一个账号 加1
		gbl_accountNum=temp;
		stringstream ss;
		ss<<temp;
		ss>>nn;
		if(nn=="1" ||nn=="")//无user.txt的情况  user.txt为空的情况
		{
			gbl_accountNum=1001;
			nn="1001";
		}
	}else{
		nn="1001";
		gbl_accountNum=1001;
	}

	//开始界面
	CBeginWin* beg=new CBeginWin(10,2,100,28);
	winArr[0]=beg;//存入开始界面

	//盘点员和仓库管理者的切换窗口--小窗口
	CRegisterWin* reg_select=new CRegisterWin;
	//选择后的注册窗口---盘点员
	CRegisterWin* reg_order=new CRegisterWin(10,2,100,28);
	CButton* btn_1=new CButton(12,7,20,2,1,1,0,BUTTON,"盘点员");
	CEdit* myaccount=new CEdit(48,10,40,2,20,MODE_TEXT,0,LABEL,nn);
	reg_order->change(btn_1,0);
	reg_order->change(myaccount,1);
	//选择后的注册窗口---仓库管理者
	CRegisterWin* reg_manager=new CRegisterWin(10,2,100,28);
	CButton* m=new CButton(12,7,20,2,1,1,0,BUTTON,"仓库管理员");
	CEdit* orderaccount=new CEdit(48,10,40,2,20,MODE_TEXT,0,LABEL,nn);
	reg_manager->change(orderaccount,1);
	reg_manager->change(m,0);
	winArr2[0]=reg_select;//存入下拉选择窗口
	winArr2[1]=reg_order;//存入盘点员注册窗口
	winArr2[2]=reg_manager;//存入仓库管理员注册窗口

	//登入--主界面
	CLogin* login=new CLogin(10,2,100,28);
	winArr[2]=login;//存入登入窗口

	//注册--主界面
	CRegisterWin* reg=new CRegisterWin(10,2,100,28);
	winArr[1]=reg;//存入注册窗口

	//仓库管理员--主界面
	CManagerMenuWin* managerWin=new	CManagerMenuWin(10,2,100,28);
	winArr[3]=managerWin;

	//盘点员--主界面
	COrderManWin* orderManWin=new COrderManWin(10,2,100,28);
	winArr[4]=orderManWin;//存入盘点员窗口

	
	//商品查询窗口
	CGoodsSearchWin* searchWin=new CGoodsSearchWin(10,2,100,28);
	winArr[5]=searchWin;//存入查询窗口

	//商品查询窗口--模糊
	CGoodsSearchWin* fuzzyWin=new CGoodsSearchWin(10,2,100,28);
	fuzzyWin->getArr(9)->setCount(666);//模糊翻页
	winArr[6]=fuzzyWin;//存入查询窗口--模糊

	//商品出库窗口
	COutGoodsWin* goodsOut=new COutGoodsWin(10,2,100,28);
	winArr[7]=goodsOut;//存入商品出库窗口

	//提示窗口
	CTipsWin* tipsWin=new CTipsWin(10,2,100,28);
	winArr[8]=tipsWin;//存入提示窗口

	//新建盘点窗口
	CNewOrderWin* neworderWin=new CNewOrderWin(10,2,100,28);
	winArr[9]=neworderWin;//存入新建盘点窗口

	//盘点报表窗口
	COrderTableWin* orderTableWin=new COrderTableWin(10,2,100,28);
	winArr[10]=orderTableWin;//存入盘点表窗口

	//商品入库菜单界面
	CAddGoodsMenuWin* addGoodsMenu=new CAddGoodsMenuWin(10,2,100,28);
	winArr[11]=addGoodsMenu;//存入入库菜单窗口

	//商品入库界面
	CInputGoodsWin* inputGoodsWin=new CInputGoodsWin(10,2,100,28);
	winArr[12]=inputGoodsWin;//存入入库界面

	//入库界面--未找到商品--提示窗口
	CTipsWin_2* tipsWin_2=new CTipsWin_2(10,2,100,28);
	winArr[13]=tipsWin_2;//存入提示窗口

	//新增商品界面
	CAddGoods* addGoods=new CAddGoods(10,2,100,28);
	winArr[14]=addGoods;

	//盘点员菜单界面
	COrderManWin_Menu* orderManWin_Menu=new COrderManWin_Menu(10,2,100,28);
	winArr[15]=orderManWin_Menu;//存入盘点菜单主界面

	//提示窗口--盘点
	CTipsWin* tipsWin_3=new CTipsWin(10,2,100,28);
	winArr[16]=tipsWin_3;//存入提示窗口--盘点

	//冲正窗口
	COrderCheckWin* order_Check=new COrderCheckWin(10,2,100,28);
	winArr[17]=order_Check;//存入冲正窗口

	//冲正窗口
	COrderCheckWin_2* order_Check_2=new COrderCheckWin_2(10,2,100,28);
	winArr[18]=order_Check_2;//存入冲正窗口

	//冲正提示窗口--7个属性
	CTips_Check_Win* tips_check_win=new CTips_Check_Win(10,2,100,28);
	winArr[19]=tips_check_win;//存入冲正提示窗口--7个属性

	winArr[0]->CWindow_Show();
	winArr[0]->winRun();

	system("pause");
	return 0;
}
