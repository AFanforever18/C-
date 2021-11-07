#include "COrderCheckWin.h"
//带参构造
COrderCheckWin::COrderCheckWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	this->
	//按钮
	exit_Button=new CButton(this->getX()+8,27,18,2,1,1,0,BUTTON,"返回[Esc]");
	Btn_1=new CLabel(36,12,18,2,1,1,0,BUTTON,"");
	Btn_2=new CLabel(36,14,18,2,1,1,0,BUTTON,"");
	Btn_3=new CLabel(36,16,18,2,1,1,0,BUTTON,"");
	Btn_4=new CLabel(36,18,18,2,1,1,0,BUTTON,"");
	Btn_5=new CLabel(36,20,18,2,1,1,0,BUTTON,"");
	Btn_6=new CLabel(36,22,18,2,1,1,0,BUTTON,"");
	Btn_7=new CLabel(36,24,18,2,1,1,0,BUTTON,"");

	//标签
	title=new CLabel(53,3,8,5,1,1,1,LABEL,"仓储盘点机项目");
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"日期: "+data);
	jiantou=new CLabel(this->getX()+this->getWidth()-30,this->getY()+25,20,2,1,1,0,LABEL,"按←→翻页,按↑↓选择数据");
	order_num=new CLabel(40,10,20,2,1,1,0,LABEL,"盘点编号");
	order_state=new CLabel(52,10,20,2,1,1,0,LABEL,"冲正状态");

	//表格
	table=new CTable_3(this->getX()+30,this->getY()+9,8,2,9,1,0,LABEL,"查询");//通用表格

	//添加控件
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(jiantou);
	addControl(order_num);//4
	addControl(order_state);
	addControl(table);
	addControl(Btn_1);//7
	addControl(Btn_2);//8
	addControl(Btn_3);//9
	addControl(Btn_4);//10
	addControl(Btn_5);//11
	addControl(Btn_6);//12
	addControl(Btn_7);//13
	addControl(exit_Button);//控件数组下标--14--返回

}
//进入详细数据--参数按钮序号
void COrderCheckWin::enter_Check(int Btn_num)
{
	int m;//循环迭代器++
	map<string,string>::iterator iter=mymap_order_num.begin();
	map<string,string>::iterator it=mymap_order_num.begin();//查找查找状态
	advance(iter,(page_current_2-1)*7);	
	for( m=0;m<Btn_num;m++)//根据按钮位置偏移迭代器
	{
		iter++;	
		if(iter==mymap_order_num.end())
		{
			winArr[8]->getArr(0)->setTitle("内容为空!");//更改提示消息
			winArr[8]->setTitleType("内容为空--冲正");//更改提示窗口类型
			CTool::clear(52,16,20,8);//局部刷新
			winArr[8]->CWindow_Show();//提示窗口
			winArr[8]->winRun(); 
		}
	}
	gbl_selectNUM=iter->first;//冲正选择的盘点编号	
	it=mymap_order_num.find(gbl_selectNUM);//通过选择的编号来查找他的状态
	string check_State=it->second;//冲正状态
	system("cls");//清屏
	CFile::order_check_read();//冲正选择的盘点编号读到容器
	change_check_state();//未冲正进入变为冲正中,其他状态不变
	winArr[18]->getArr(1)->setTextConcent("用户:"+user_name+"<仓库管理员>");//修改用户名称标签
	winArr[18]->getArr(3)->setTextConcent("盘点编号:"+gbl_selectNUM);//修改盘点编号标签
	winArr[18]->getArr(4)->setTextConcent("冲正状态:"+check_State);//修改冲正状态标签
	winArr[18]->CWindow_Show();
	CTool::printf_Table_Order_All();//打印冲正信息--7个属性
	winArr[18]->winRun();	
}
//改变冲正状态
void COrderCheckWin::change_check_state()
{
	//gbl_selectNUM--全局变量--冲正选择的商品编号
	map<string,string>::iterator iter;
	iter=mymap_order_num.find(gbl_selectNUM);//去盘点编号和冲正状态容器查找当前选择的盘点编号
	//原先盘点编号和冲正状态
	string str="冲正中";
	string order_num=iter->first;//盘点编号
	string check_state=iter->second;//冲正状态
	if(iter->second=="未冲正")
	{
		//在容器中删除旧的数据
		mymap_order_num.erase(gbl_selectNUM);
		//插入新的数据
		mymap_order_num.insert(make_pair(gbl_selectNUM,str));//如果选择未冲正的盘点编号,进入就变成冲正中
		//创建流对象
		ofstream ofs;
		//打开文件
		ofs.open("./data/checkdata.txt");//ios::trunc是清除原文件内容,可不写,默认就是它
		ofs.close;//关闭文件
		for(map<string,string>::iterator iter_2=mymap_order_num.begin();iter_2!=mymap_order_num.end();iter_2++)
		{
			order_num=iter_2->first;//盘点编号
			check_state=iter_2->second;//冲正状态
			CFile::num_and_state_write(order_num,check_state);
		}	
	}

}
//重写父类纯虚函数
void COrderCheckWin::doAction()
{
	int i=this->getFocus();
	map<int,CUser>::iterator iter;
	iter=mymap.find(current_Account);
	switch(i)
	{
	case 7:	//Bt_1
		if(iter->second.getrole()==2)//仓库管理员--可操作
		enter_Check(0);//进入详细数据--参数按钮序号--进入冲正主界面--7个属性
		break;
	case 8:	//Bt_2
		if(iter->second.getrole()==2)//仓库管理员--可操作
		enter_Check(1);//进入详细数据--参数按钮序号--进入冲正主界面--7个属性
		break;
	case 9://Bt_3
		if(iter->second.getrole()==2)//仓库管理员--可操作
		enter_Check(2);//进入详细数据--参数按钮序号--进入冲正主界面--7个属性
			break;
	case 10://Bt_4
		if(iter->second.getrole()==2)//仓库管理员--可操作
		enter_Check(3);//进入详细数据--参数按钮序号--进入冲正主界面--7个属性
			break;
	case 11://Bt_5
		if(iter->second.getrole()==2)//仓库管理员--可操作
		enter_Check(4);//进入详细数据--参数按钮序号--进入冲正主界面--7个属性
		break;
	case 12:////Bt_6
		if(iter->second.getrole()==2)//仓库管理员--可操作
		enter_Check(5);//进入详细数据--参数按钮序号--进入冲正主界面--7个属性
		break;
	case 13:////Bt_7
		if(iter->second.getrole()==2)//仓库管理员--可操作
		enter_Check(6);//进入详细数据--参数按钮序号--进入冲正主界面--7个属性
		break;
	case 14://返回
		system("cls");//清屏
		if(iter->second.getrole()==1)//	盘点员
		{
			winArr[4]->CWindow_Show();//进入盘点员菜单
			winArr[4]->winRun();
		}else//仓库管理员
		{
			winArr[3]->CWindow_Show();//进入仓库管理员菜单
			winArr[3]->winRun();
		}
		break;
	}
}