#include "CTipsWin.h"
//带参构造
CTipsWin::CTipsWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	titleType="未确定";
	//按钮
	exit_Button=new CButton(52,16,20,8,1,1,0,BUTTON,"");

	//标签
	title=new CLabel(53,19,8,5,1,1,1,LABEL,"出库数量大于库存!");
	exit_label=new CLabel(53,16,8,5,1,1,1,LABEL,"确定[enter]");

	//添加控件
	addControl(title);
	addControl(exit_label);
	addControl(exit_Button);//控件数组下标--1--退出

}
//析构函数
CTipsWin::~CTipsWin()
{

}
//获取提示窗口类型--提示窗口
string CTipsWin::getTitleType()
{
	return this->titleType;
}
//设置提示窗口类型--提示窗口
void CTipsWin::setTitleType(string word)
{
	this->titleType=word;
}
//重写父类纯虚函数
void CTipsWin::doAction()
{
	int i=this->getFocus();//获取当前操作下角标
	switch(i)
	{
	case 2://退出调用出库窗口   
		if(this->titleType=="出库成功" || this->titleType=="出库数量大于库存" || this->titleType=="出库数量有误" )//进入出库窗口
		{
			system("cls");//清屏
			CTool::paintBorder(16,13,60,16);//商品信息边框
			winArr[7]->CWindow_Show();
			winArr[7]->search(winArr[7]->get_Search_word());//商品出库--打印搜索的商品编码
			winArr[7]->winRun();
		}else if(this->titleType=="盘点出库")//进入出库窗口
		{
			system("cls");//清屏
			CTool::paintBorder(16,13,60,16);//商品信息边框
			winArr[9]->CWindow_Show();
			winArr[9]->search(winArr[9]->get_Search_word());//商品出库--打印搜索的商品编码
			winArr[9]->winRun();
		}else if(this->titleType=="请输入正确编号--出库")//进入出库窗口
		{
			system("cls");//清屏
			CTool::paintBorder(16,13,60,16);//商品信息边框
			winArr[7]->CWindow_Show();
			winArr[7]->search(winArr[9]->get_Search_word());//商品出库--打印搜索的商品编码
			winArr[7]->winRun();
		}
	
		else if(this->titleType=="入库成功")//进入入库窗口
		{
			system("cls");//清屏
			CTool::paintBorder(16,13,60,16);//商品信息边框
			winArr[12]->CWindow_Show();
			winArr[12]->search(winArr[12]->get_Search_word());//商品出库--打印搜索的商品编码
			winArr[12]->winRun();		
		}else if(this->titleType=="入库数量有误")//进入入库窗口
		{
			system("cls");//清屏
			CTool::paintBorder(16,13,60,16);//商品信息边框
			winArr[12]->CWindow_Show();
			winArr[12]->search(winArr[12]->get_Search_word());//商品入库--打印搜索的商品编码
			winArr[12]->winRun();		
		}else if(this->titleType=="请完善内容")//新增商品
		{
			system("cls");//清屏
			winArr[14]->CWindow_Show();
			winArr[14]->winRun();		
		}
		else if(this->titleType=="商品添加成功")//新增商品
		{
			system("cls");//清屏
			winArr[11]->CWindow_Show();//
			winArr[11]->winRun();		
		}
		else if(this->titleType=="盘点报表--已到最后一页")//新增商品
		{
			system("cls");//清屏
			winArr[10]->CWindow_Show();//
			page_current--;//这里要页数减1
			CTool::prtinf_Table_Content(temp_list);//在打印表格内容操作
			winArr[10]->winRun();		
		}
		else if(this->titleType=="盘点报表--已到第一页")//新增商品
		{
			system("cls");//清屏
			winArr[10]->CWindow_Show();//
			page_current++;//这里要页数加1
			CTool::prtinf_Table_Content(temp_list);//在打印表格内容操作
			winArr[10]->winRun();		
		}
		else if(this->titleType=="搜索翻页--已到第一页")
		{
			system("cls");//清屏
			this->titleType="";
			winArr[5]->CWindow_Show();
			winArr[5]->winRun();
			
		}
		else if(this->titleType=="搜索翻页--已到最后一页")
		{
			system("cls");//清屏
			this->titleType="";
			winArr[5]->CWindow_Show();
			winArr[5]->winRun();
			
		}
		else if(this->titleType=="搜索翻页--未找到商品")
		{
			system("cls");//清屏
			this->titleType="";
			int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//清屏
			winArr[5]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->getArr(9)->setCount(1);
			winArr[5]->CWindow_Show();
			winArr[5]->winRun();
			
		}
		else if(this->titleType=="搜索翻页--已到第一页--模糊")//回到主搜索
		{
			int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//清屏
			this->titleType="";
			winArr[5]->getArr(9)->setPage(1);
			winArr[6]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->CWindow_Show();
			winArr[5]->winRun();
			
		}
		else if(this->titleType=="搜索翻页--已到最后一页--模糊")//回到主搜索
		{
		int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//清屏
			this->titleType="";
			winArr[5]->getArr(9)->setPage(1);
			winArr[6]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->CWindow_Show();
			winArr[5]->winRun();
			
		}
		else if(this->titleType=="未找到商品--新建盘点")
		{
			system("cls");//清屏
			this->titleType="";
			winArr[9]->CWindow_Show();
			CTool::paintBorder(16,13,60,16);//存入商品信息边框
			winArr[9]->winRun();
			
		}
		else if(this->titleType=="盘点编号--冲正--已到最后一页")
		{
			system("cls");//清屏得到
			this->titleType="";
			page_current_2--;//这里要页数减1
			winArr[17]->CWindow_Show();//回到盘点编号--冲正
			CTool::printf_Table_Order();//盘点编号和冲正状态
			winArr[17]->winRun();
			
		}
		else if(this->titleType=="盘点编号--冲正--已到第一页")
		{
			system("cls");//清屏得到
			this->titleType="";
			page_current_2++;//这里要页数加1
			winArr[17]->CWindow_Show();//回到盘点编号--冲正
			CTool::printf_Table_Order();//盘点编号和冲正状态
			winArr[17]->winRun();
			
		}
		else if(this->titleType=="即将退出系统")
		{
			system("cls");//清屏
			this->titleType="";
			winArr[0]->CWindow_Show();
			winArr[0]->winRun();
			
		}
		else if(this->titleType=="内容为空--冲正")
		{
			system("cls");//清屏
			this->titleType="";
			winArr[17]->CWindow_Show();//冲正选择盘点本编号界面
			CTool::printf_Table_Order();//盘点编号和冲正状态
			winArr[17]->winRun();
			
		}
		else if(this->titleType=="7个属性--冲正--已到最后一页")
		{
			system("cls");//清屏
			this->titleType="";
			page_current_4--;//这里要页数减1
			winArr[18]->CWindow_Show();//7个属性--冲正界面
			CTool::printf_Table_Order_All();//打印冲正信息--7个属性
			winArr[18]->winRun();	
		}
		else if(this->titleType=="7个属性--冲正--已到第一页")
		{
			system("cls");//清屏
			this->titleType="";
			page_current_4++;//这里要页数减1
			winArr[18]->CWindow_Show();//7个属性--冲正界面
			CTool::printf_Table_Order_All();//打印冲正信息--7个属性
			winArr[18]->winRun();	
		}
		else if(this->titleType=="内容为空--冲正--7个属性")
		{
			system("cls");//清屏
			this->titleType="";
			winArr[18]->CWindow_Show();//7个属性--冲正界面
			CTool::printf_Table_Order_All();//打印冲正信息--7个属性
			winArr[18]->winRun();	
		}
		else if(this->titleType=="退出系统--开始界面")
		{
			system("cls");//清屏
			exit(0);	
		}
		else if(this->titleType=="登入界面--账号密码错误")
		{
			system("cls");//清屏
			winArr[2]->CWindow_Show();//回到登入界面
			winArr[2]->winRun();	
		}
		else if(this->titleType=="登入界面--未找到用户")
		{
			system("cls");//清屏
			winArr[2]->CWindow_Show();//回到登入界面
			winArr[2]->winRun();	
		}
		else if(this->titleType=="登入界面--账号或密码不能为空")
		{
			system("cls");//清屏
			winArr[2]->CWindow_Show();//回到登入界面
			winArr[2]->winRun();	
		}
		else if(this->titleType=="注册界面--请选择注册类型")
		{
			system("cls");//清屏
			winArr[1]->CWindow_Show();//回到选择注册界面
			winArr[1]->winRun();	
		}
		else if(this->titleType=="查询信息为空--搜索商品")
		{
			int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//清屏
			winArr[5]->getArr(1)->setTextConcent("欢迎:"+user_name);
			winArr[5]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->getArr(9)->setCount(1);
			winArr[5]->CWindow_Show();//进入查询界面
			winArr[5]->winRun();	
		}
		else if(this->titleType=="请精确搜索--搜索商品")
		{
			int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//清屏
			winArr[5]->getArr(1)->setTextConcent("欢迎:"+user_name);
			winArr[5]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->getArr(9)->setCount(1);
			winArr[5]->CWindow_Show();//进入查询界面
			winArr[5]->winRun();	
		}
		else if(this->titleType=="正在导出商品--搜索商品")
		{
			int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//清屏
			winArr[5]->getArr(1)->setTextConcent("欢迎:"+user_name);
			winArr[5]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->getArr(9)->setCount(1);
			winArr[5]->CWindow_Show();//进入查询界面
			winArr[5]->winRun();	
		}
		break;
	}
}
