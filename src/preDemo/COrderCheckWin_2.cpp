#include "COrderCheckWin_2.h"
//带参构造
COrderCheckWin_2::COrderCheckWin_2(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	this->
	//按钮
	exit_Button=new CButton(this->getX()+28,27,18,2,1,1,0,BUTTON,"返回[Esc]");
	over_Button=new CButton(this->getX()+8,27,18,2,1,1,0,BUTTON,"完成冲正");
	Btn_1=new CLabel(14,13,18,2,1,1,0,BUTTON,"");
	Btn_2=new CLabel(14,15,18,2,1,1,0,BUTTON,"");
	Btn_3=new CLabel(14,17,18,2,1,1,0,BUTTON,"");
	Btn_4=new CLabel(14,19,18,2,1,1,0,BUTTON,"");
	Btn_5=new CLabel(14,21,18,2,1,1,0,BUTTON,"");
	Btn_6=new CLabel(14,23,18,2,1,1,0,BUTTON,"");

	//标签
	title=new CLabel(53,3,8,5,1,1,1,LABEL,"仓储盘点机项目");
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"日期: "+data);
	jiantou=new CLabel(this->getX()+this->getWidth()-30,this->getY()+25,20,2,1,1,0,LABEL,"按←→翻页,按↑↓选择数据");
	order_num=new CLabel(this->getX()+2,this->getY()+7,20,2,1,1,0,LABEL,"盘点编号:");
	order_state=new CLabel(this->getX()+this->getWidth()-20,this->getY()+7,20,2,1,1,0,LABEL,"冲正状态:");

	//表格
	table=new CTable_3(this->getX()+8,this->getY()+10,7,7,5,1,0,LABEL,"完成冲正");//通用表格

	//添加控件
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(order_num);//3--盘点编号
	addControl(order_state);//4--冲正状态
	addControl(table);
	addControl(jiantou);
	addControl(Btn_1);//7
	addControl(Btn_2);
	addControl(Btn_3);
	addControl(Btn_4);
	addControl(Btn_5);
	addControl(Btn_6);
	addControl(over_Button);//13--完成冲正--按钮
	addControl(exit_Button);//控件数组下标--14--返回
	

}
//开始冲正--参数 按钮序号
void COrderCheckWin_2::beg_Check(int Btn_num)
{
	int m;//循环迭代器++
	map<string,CGoods>::iterator iter=map_check.begin();
	advance(iter,(page_current_4-1)*6);	
	for( m=0;m<Btn_num;m++)//根据按钮位置偏移迭代器
	{
		iter++;	
		if(iter==map_check.end())
		{
			winArr[8]->getArr(0)->setTitle("内容为空!");//更改提示消息
			winArr[8]->setTitleType("内容为空--冲正--7个属性");//更改提示窗口类型
			CTool::clear(52,16,20,8);//局部刷新
			winArr[8]->CWindow_Show();//提示窗口
			winArr[8]->winRun(); 
		}
	}
	gbl_goods_selectNUM=iter->first;//保存选择的商品编号
	CTool::clear(42,11,40,14);//局部清空
	winArr[19]->CWindow_Show();
	winArr[19]->winRun();//进入冲正提示窗口
	system("cls");//清屏
}
//重写父类纯虚函数
void COrderCheckWin_2::doAction()
{
	int i=this->getFocus();
	map<string,string>::iterator iter=mymap_order_num.begin();
	switch(i)
	{
	case 7://Btn_1 序号为0
		beg_Check(0);//开始冲正
	//	CTool::clear(42,11,40,14);//局部清空
	//	winArr[19]->CWindow_Show();
		//winArr[19]->winRun();
		break;
	case 8://Btn_2 序号为1
		beg_Check(1);//开始冲正
		break;
	case 9://Btn_2 序号为2
		beg_Check(2);//开始冲正
		break;
	case 10://Btn_1 序号为3
		beg_Check(3);//开始冲正
		break;
	case 11://Btn_2 序号为4
		beg_Check(4);//开始冲正
		break;
	case 12://Btn_2 序号为5
		beg_Check(5);//开始冲正
		break;
	case 14://返回盘点冲正菜单
		system("cls");//清屏
		winArr[17]->CWindow_Show();
		CTool::printf_Table_Order();//盘点编号和冲正状态
		winArr[17]->winRun();
		break;
	}
}