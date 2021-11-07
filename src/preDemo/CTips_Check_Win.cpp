#include "CTips_Check_Win.h"

//带参构造
CTips_Check_Win::CTips_Check_Win(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	//按钮
	ok_Button=new CButton(45,22,16,2,1,1,0,BUTTON,"确定[Enter]");
	cal_Button=new CButton(64,22,16,2,1,1,0,BUTTON,"取消[Esc]");

	//标签
	title=new CLabel(43,12,8,5,1,1,1,LABEL,"冲正记录:");
	title_num=new CLabel(43,14,8,5,1,1,1,LABEL,"冲正数量:");
	title_season=new CLabel(43,18,8,5,1,1,1,LABEL,"冲正说明:");

	//编辑框
	border=new CEdit(42,11,40,14,1,1,0,LABEL,"");//边框作用
	edit_num=new CEdit(56,14,20,2,10,1,2,EDIT,"");
	edit_season=new CEdit(56,18,20,3,10,1,3,EDIT,"");


	//添加控件
	addControl(title);
	addControl(border);
	addControl(title_num);
	addControl(title_season);
	addControl(edit_num);
	addControl(edit_season);
	addControl(ok_Button);//控件数组下标--6--确定
	addControl(cal_Button);//控件数组下标--7--返回

}
//改变商品冲正信息
void CTips_Check_Win::change_chcek_data()
{
	map<string,CGoods>::iterator iter;
	iter=map_check.find(gbl_goods_selectNUM);//找到选择的商品编号
	//原先的信息
	string str1=iter->second.getGoodsNum();//商品名称
	string str2=iter->second.getGoodsName();//商品库存
	string str3=iter->second.getGoodsType();//盘点数量
	string str4=iter->second.getGoodsPrice();//差异数量
	string str5=iter->second.getInventory();//冲正数量
	string str6=iter->second.getWarehouseNum();//冲正原因
	//冲正后
	str5=this->edit_num->getContent();//冲正数量--输入的
	str6=this->edit_season->getContent();//冲正原因--输入的
	//删除容器原有的这条
	map_check.erase(gbl_goods_selectNUM);
	//插入新的冲正数据
	CGoods good_temp(str1,str2,str3,str4,str5,str6);
	map_check.insert(make_pair(gbl_goods_selectNUM,good_temp));
	string src= "./data/"+gbl_selectNUM+".txt";//路径="./data/"+冲正--盘点编号+".txt"
	//创建流对象
	ofstream ofs;
	//打开文件
	ofs.open(src.c_str());//ios::trunc是清除原文件内容,可不写,默认就是它
	ofs.close;//关闭文件
	//清空文件重新写入 对应盘点编号文件
	CFile::new_Check_Data_Write();//新盘点数据写入
}
//冲正状态 1--未冲正  2--冲正中 3--已冲正
int CTips_Check_Win::get_check_state()
{
	//map_check
	int error_num;//差异数量
	int count=0;//统计是否都冲正完成
	for(map<string,CGoods>::iterator iter=map_check.begin();iter!=map_check.end();iter++)
	{
		error_num=atoi(iter->second.getGoodsPrice().c_str());//差异数量--用了了商品类当载体 函数名称忽略
		//得到差异数量的绝对值
		if(atoi(iter->second.getGoodsPrice().c_str())>0)
		{
			error_num=atoi(iter->second.getGoodsPrice().c_str());
		}else
		{
			error_num=0-atoi(iter->second.getGoodsPrice().c_str());	
		}
		//统计冲正完成的商品个数
		if(error_num==atoi(iter->second.getInventory().c_str()))//冲正数与差异数量绝对值相等 就算完成冲正
		{
			count++;//完成一次冲正 count++
		}
	}
	if(count==map_check.size())//count==map_check.size() 全部冲正完成
	{
		return 3;//已冲正
	}else
	{
		return 2;//冲正中
	}
}
//更改盘点编号和冲正状态容器的数据
void CTips_Check_Win::change_order_num_and_state(string mycheck_state)
{
	//gbl_selectNUM--全局变量--冲正选择的商品编号
	map<string,string>::iterator iter;
	iter=mymap_order_num.find(gbl_selectNUM);//去盘点编号和冲正状态容器查找当前选择的盘点编号
	//原先盘点编号和冲正状态
	string order_num=iter->first;//盘点编号
	string check_state=iter->second;//冲正状态
	//修改冲正状态
	check_state=mycheck_state;
	//在容器中删除旧的数据
	mymap_order_num.erase(gbl_selectNUM);
	//插入新的数据
	mymap_order_num.insert(make_pair(gbl_selectNUM,check_state));
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

//重写父类纯虚函数
void CTips_Check_Win::doAction()
{
	//gbl_goods_selectNUM
	string check_state;//冲正状态
	int num_temp;//接收返回值判断冲正状态
	int i=this->getFocus();
	switch(i)
	{
	case 6:
	change_chcek_data();//改变商品冲正信息
	num_temp=get_check_state();//冲正状态 1--未冲正  2--冲正中 3--已冲正
	if(num_temp==2)
	{
		check_state="冲正中";
	}else if(num_temp==3)
	{
		check_state="已冲正";
	}

	//更改盘点编号和冲正状态容器的数据
	change_order_num_and_state(check_state);

	this->edit_num->setContentNull();//冲正数量文本清空
	this->edit_season->setContentNull();//冲正原因文本清空
	winArr[18]->getArr(4)->setTextConcent("冲正状态:"+check_state);//更改冲正状态
	winArr[18]->CWindow_Show();
	CTool::printf_Table_Order_All();//打印冲正信息--7个属性
	winArr[18]->winRun();	
		break;
	case 7:
	//change_chcek_data();//改变商品冲正信息
	this->edit_num->setContentNull();//冲正数量文本清空
	this->edit_season->setContentNull();//冲正原因文本清空
	winArr[18]->CWindow_Show();
	CTool::printf_Table_Order_All();//打印冲正信息--7个属性
	winArr[18]->winRun();	
		break;
	}
}