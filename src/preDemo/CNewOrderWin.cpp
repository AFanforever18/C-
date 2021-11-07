#include "CNewOrderWin.h"
//默认构造
CNewOrderWin::CNewOrderWin()
{
	
}
//默认构造//带参构造
CNewOrderWin::CNewOrderWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	num=1;//
	count=0;//编号回去
	search_word="";//商品编码--开始为空
	order_num="";//盘点数控--开始为空
	string str="欢迎使用仓储盘点机系统!";//更改主题
	//标签
	//为了标签随窗口大小位置变动
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"日期: "+data);
	inputNum_label=new CLabel(this->getX()+2,this->getY()+7,20,2,1,1,0,LABEL,"请输入商品查询的编号:");
	orderNum=new CLabel(this->getX()+2,this->getY()+9,20,2,1,1,0,LABEL,"盘点编号:"+makeOrder_Num());
	outGoods_label=new CLabel(this->getX()+70,this->getY()+12 ,20,2,1,1,0,LABEL,"请输入盘点库存数量[0-10000]:");
	goods_Name=new CLabel(this->getX()+10,this->getY()+12,20,2,1,1,0,LABEL,"商品名称:");
	goods_Type=new CLabel(this->getX()+10,this->getY()+16,20,2,1,1,0,LABEL,"商品类型:");
	goods_Price=new CLabel(this->getX()+10,this->getY()+20,20,2,1,1,0,LABEL,"商品价格:");
	goods_WarehouseNum=new CLabel(this->getX()+10,this->getY()+24,20,2,1,1,0,LABEL,"仓位编号:");

	//编辑框
	inputNum_edit=new CEdit(this->getX()+28,this->getY()+7,46,2,10,1,3,EDIT,"");
	inputoutGoods_edit=new CEdit(this->getX()+76,this->getY()+15 ,18 ,2,10,1,2,EDIT,"");
	//按钮
	find_Btn=new CButton(this->getX()+76,this->getY()+7,10,2,1,1,0,BUTTON,"查询");
	import_Btn=new CButton(this->getX()+76,this->getY()+18,18,2,1,1,0,BUTTON,"确定[enter]");
	myexit=new CButton(this->getX()+76,this->getY()+21,18,2,1,1,0,BUTTON,"返回[Esc]");
	orderTable=new CButton(this->getX()+76,this->getY()+24,18,2,1,1,0,BUTTON,"生成盘点报表");

	//表格
	table=new CTable(this->getX()+8,this->getY()+12,6,6,1,1,0,LABEL,"查询");	
	//添加控件
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(orderNum);
	addControl(inputNum_label);
	addControl(outGoods_label);
	addControl(goods_Name);
	addControl(goods_Type);
	addControl(goods_Price);
	addControl(goods_WarehouseNum);
	addControl(inputNum_edit);//商品查询编辑框--10
	addControl(find_Btn);//商品查询按钮--11
	addControl(inputoutGoods_edit);//输入出库数量--12
	addControl(import_Btn);//确定盘点按钮--13
	addControl(myexit);//返回--14
	addControl(orderTable);//生成盘点报表按钮--15

	
}
//默认析构
CNewOrderWin::~CNewOrderWin()
{
	
}
//获取输入的商品编码
string CNewOrderWin::get_Search_word()
{
	return this->search_word;
}
//获取输入的盘点数量
string CNewOrderWin::get_Order_num()
{
	return this->order_num;
}
//获取盘点编号--盘点报表
string CNewOrderWin::get_makeOrder_Num()
{
	return this->orderNUM;//盘点编号
}
//生成盘点编
string  CNewOrderWin::makeOrder_Num()
{
	// 基于当前系统的当前日期/时间
    tm *ltm;
    time_t now = time(0);
    ltm= localtime(&now); 
	string str=CTool::strtoInt(ltm->tm_year+1900)+CTool::strtoInt(ltm->tm_mon+1)+CTool::strtoInt(ltm->tm_mday);//获取时间
	string temp=gbl_orderNUM;
	temp=temp.erase(7,3);
	if(atoi(str.c_str())==atoi(temp.c_str()))
	{
		str=CTool::strtoInt(atoi(gbl_orderNUM.c_str())+1);
		str.insert(7,"-");
	}else
	{
		if(num>=10)
		{
			str=str+"-0"+CTool::strtoInt(num);//拼接编号 例: 010
		}else
		{
			str=str+"-00"+CTool::strtoInt(num);//拼接编号 例: 001
		}
	}

	return str;
}
//打印查询的商品信息
void CNewOrderWin::search(string word)
{
	if(inputNum_edit->getContent()=="" && search_word=="" )//商品查询编辑框为空
	{
		return;
	}
	map<string,CGoods>::iterator iter;
	iter=mymap_goods.find(word);
	if(iter==mymap_goods.end())
	{
		winArr[8]->getArr(0)->setTitle("未找到商品!");//更改提示消息
		winArr[8]->setTitleType("未找到商品--新建盘点");//更改提示窗口类型
		//清空文本
		this->inputNum_edit->setContentNull();
		this->inputoutGoods_edit->setContentNull();
		CTool::clear(52,16,20,8);//局部刷新
		winArr[8]->CWindow_Show();//提示窗口
		winArr[8]->winRun(); 
		return;
	}else
	{
		CTool::gotoxy(this->getX()+23,this->getY()+13);
		cout<<iter->second.getGoodsName()<<"          ";//商品名称
		CTool::gotoxy(this->getX()+23,this->getY()+17);
		cout<<iter->second.getGoodsType()<<"          ";//商品类型
		CTool::gotoxy(this->getX()+23,this->getY()+21);
		cout<<iter->second.getGoodsPrice()<<"          ";//商品价格
		CTool::gotoxy(this->getX()+23,this->getY()+25);
		cout<<iter->second.getWarehouseNum()<<"         ";//仓位编号
	}
}
//记录盘点表
void CNewOrderWin::record()
{
	map<string,CGoods>::iterator iter;
	iter=mymap_goods.find(search_word);
	int tempNum=atoi(iter->second.getInventory().c_str())-atoi(order_num.c_str());
	stringstream ss;
	string errorNum;
	ss<<tempNum;
	ss>>errorNum;
	//参数列表 商品编码--商品名称--库存数量--盘点数量--差异数量---盘点编号
	CFile::goods_Record_Write(search_word,iter->second.getGoodsName(),iter->second.getInventory(),order_num,errorNum,num);
	//放入容器
	temp_list.push_back((CGoods(search_word,iter->second.getGoodsName(),iter->second.getInventory(),order_num,errorNum,"")));
	//写入数据---存入顺序 盘点编号--商品编号--商品名称--库存数量--盘点数量--差异数量--冲正说明--冲正原因
	CFile::ALL_Check_Write(makeOrder_Num(),search_word,iter->second.getGoodsName(),iter->second.getInventory(),order_num,errorNum,"0","无");
}
//窗口的操作 每个都不一样 纯虚 所有子类重写
void CNewOrderWin::doAction()
{	
	int i=this->getFocus();
	if(i==14)
	{
		//清空文本
		this->inputNum_edit->setContentNull();
		this->inputoutGoods_edit->setContentNull();
		system("cls");
		winArr[15]->CWindow_Show();//回盘点菜单界面
		winArr[15]->winRun();
	}

	if(inputNum_edit->getContent()=="" && search_word=="" )
	{
		return;
	}
	string str="";
	if(inputNum_edit->getContent()=="")
	{
		str="商品编号:"+search_word;//提示窗口的提示信息
	}else
	{
		str="商品编号:"+inputNum_edit->getContent();//提示窗口的提示信息
	}

	map<string,CGoods>::iterator iter;
	if(search_word=="")
	{
		iter=mymap_goods.find(this->inputNum_edit->getContent());
	}else
	{
		iter=mymap_goods.find(search_word);
	}
//	if(iter==mymap_goods.end())
//	{
//		winArr[8]->getArr(0)->setTitle("未找到商品!");//更改提示消息
//		winArr[8]->setTitleType("未找到商品--新建盘点");//更改提示窗口类型
		//清空文本
//		this->inputNum_edit->setContentNull();
//		this->inputoutGoods_edit->setContentNull();
//		CTool::clear(52,16,20,8);//局部刷新
//		winArr[8]->CWindow_Show();//提示窗口
//		winArr[8]->winRun(); 
//		return;
//	}
	switch(i)
	{
	case 11://商品查询
		search_word=inputNum_edit->getContent();//存下商品编码
		if(inputNum_edit->getContent()=="")
		{
			search(search_word);//查询打印商品信息
		}else
		{
			search(inputNum_edit->getContent());//查询打印商品信息
		}
		break;
	case 13://确定盘点
			count++;//盘点一次
			order_num=this->inputoutGoods_edit->getContent();//存下盘点数量
			record();//盘点编号写入文件报表
			winArr[16]->getArr(1)->setTextConcent("欢迎:"+user_name);
			winArr[16]->getArr(0)->setTitle(str);//更改提示消息 str为商品编号
			winArr[16]->addControl(new CLabel(53,18,20,2,1,1,0,LABEL,""));//添加控件
			winArr[16]->getArr(1)->setTextConcent("盘点数量为:"+inputoutGoods_edit->getContent());
			//清空文本
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			winArr[16]->setTitleType("盘点出库");//更改提示窗口类型
			winArr[16]->CWindow_Show();
			winArr[16]->winRun(); 
		break;
	case 14://返回
		//清空文本
		this->inputNum_edit->setContentNull();
		this->inputoutGoods_edit->setContentNull();
		system("cls");
		winArr[11]->CWindow_Show();//回盘点菜单界面
		winArr[11]->winRun();
		break;
	case 15://进入生成盘点报表窗口
		CTool::file_opear();//更新最新文件名--这里也会向容器里插入盘点编号和盘点状态
		orderNUM=CTool::strtoInt(atoi(makeOrder_Num().erase(7,1).c_str())-1).insert(7,"-");//盘点报表还是未自增的盘点编号
		CFile::num_and_state_write(orderNUM,"未冲正");//盘点编号和状态写入文件
		count=0;//好像没有用
		string temp_str="./data/"+orderNUM+".txt";//路径
		num++;//整次盘点结束+1 num++
		this->orderNum->setTextConcent(makeOrder_Num());//生成新的盘点编号 自增
		//清空文本
		this->inputNum_edit->setContentNull();
		this->inputoutGoods_edit->setContentNull();
		//winArr[10]->setTitleType("盘点出库");//更改提示窗口类型
		system("cls");//清屏
		winArr[10]->getArr(3)->setTextConcent("盘点编号:"+orderNUM);//改变盘点编号
		winArr[10]->CWindow_Show();//进入盘点报表界面
		CTool::prtinf_Table_Content(temp_list);//在打印表格内容操作
		winArr[10]->winRun(); 
		break;
	}
}