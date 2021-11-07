#include "CGoodsSearch.h"
//默认构造
CGoodsSearchWin::CGoodsSearchWin()
{

}
//带参构造
CGoodsSearchWin::CGoodsSearchWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	string num="1/";
	stringstream ss;
	string num_2;
	int size=mymap_goods.size();
	while(size%5!=0)//变为5的整数
	{
		size++;	
	}
	ss<<size/5;
	ss>>num_2;
	num.append(num_2);//表格页数
	string str="欢迎使用仓储盘点机系统!";//更改主题
	//标签
	//为了标签随窗口大小位置变动
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"日期: "+data);
	inputNum_label=new CLabel(this->getX()+2,this->getY()+7,20,2,1,1,0,LABEL,"请输入商品查询的编号:");
	tableNum_label=new CLabel(this->getX()+48,this->getY()+26,20,2,1,1,0,LABEL,num);

	//编辑框
	inputNum_edit=new CEdit(this->getX()+28,this->getY()+7,46,2,10,1,3,EDIT,"");

	//按钮
	find_Btn=new CButton(this->getX()+76,this->getY()+7,10,2,1,1,0,BUTTON,"查询");
	import_Btn=new CButton(this->getX()+4,this->getY()+24,18,2,1,1,0,BUTTON,"导出商品信息");
	myexit=new CButton(this->getX()+76,this->getY()+24,18,2,1,1,0,BUTTON,"返回[Esc]");

	//表格
	table=new CTable(this->getX()+8,this->getY()+12,6,6,1,1,0,LABEL,"查询");	
	//添加控件
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(inputNum_label);
	addControl(inputNum_edit);//商品查询编辑框--4
	addControl(find_Btn);//商品查询按钮--5
	addControl(import_Btn);//导出商品信息--6
	addControl(myexit);//退出--7
	addControl(tableNum_label);//翻页脚标
	addControl(table);//表格--9



}

//默认构造
CGoodsSearchWin::~CGoodsSearchWin()
{
	
}
//精确查询--返回值判断是否进入模糊查询
int CGoodsSearchWin::accurateQuery()
{
	int rowsum=18;
	int colsum=15;
	int m,n,b;
	int size;//需要覆盖的长度为13即 文本长度加" "长度为13
	map<string,CGoods>::iterator iter;//接收find返回值--精确
	iter=mymap_goods.find(this->inputNum_edit->getContent());
	if(iter==mymap_goods.end())
	{
		return 1;
	}
	this->table->setCount(-1);//精确查询不可翻页-1
	for(m=0;m<5;m++)// 打印内容
	{
		for(n=0; n<6;n++)
		{	
			CTool::gotoxy(rowsum+2,colsum+1);
			if(m==0)
			{
				switch(n)
				{
				case 0:
					size=iter->second.getGoodsNum().size();
					cout<<iter->second.getGoodsNum();
					break;
				case 1:
					size=iter->second.getGoodsName().size();
					cout<<iter->second.getGoodsName();
					break;
				case 2:
					size=iter->second.getGoodsType().size();
					cout<<iter->second.getGoodsType();
					break;
				case 3:
					size=iter->second.getGoodsPrice().size();
					cout<<iter->second.getGoodsPrice();
					break;
				case 4:
					size=iter->second.getInventory().size();
					cout<<iter->second.getInventory();
					break;
				case 5:
					size=iter->second.getWarehouseNum().size();
					cout<<iter->second.getWarehouseNum();
					break;
				}
				for(b=0;b<12-size;b++)
				{
					cout<<" ";
				}
			}else
				for(b=0;b<12;b++)//12空格
				{
					cout<<" ";
				}
				rowsum=14+rowsum;
		}
		rowsum=18;
		colsum=2+colsum;
	}
	CTool::gotoxy(60,29);
	cout<<"1/1";//不可翻页,页数不能改变
	CTool::gotoxy(this->getX()+76+2,this->getY()+7+1);
	return 0;
}
//模糊查询--查找含有关键字的商品内容
int CGoodsSearchWin::fuzzyQuery()
{	
	map<string,CGoods>temp_map;//创建临时map容器存放模糊查找到的商品数据
	string word=this->inputNum_edit->getContent();//输入的编号
	for(map<string,CGoods>::iterator iter=mymap_goods.begin();iter!=mymap_goods.end();iter++)//遍历商品容器
	{
		if(strstr(iter->first.c_str(),word.c_str())!=NULL)//找到就插入临时容器
		{
			temp_map.insert(make_pair(iter->first,iter->second));  
		}
	}
	int temp_MaxPage;//模糊查询最大页数
	//取到最大页数
	if(temp_map.size()%6==0)
	{
		temp_MaxPage=temp_map.size()/5;
	}else
	{
		temp_MaxPage=temp_map.size()/5+1;	
	}



	this->table->setPage_Max(temp_MaxPage);//更改表格最大页数
	if(this->table->getPage()>this->table->getPageMax())//当前页数大于等于最大页数
	{
		//覆盖页数--翻页
		CTool::gotoxy(this->table->getX()+42,this->table->getY()+15);
		if(this->table->getPage()<=this->table->getPageMax())
		{
			cout<<this->table->getPage();
			
		}else
		{
			cout<<this->table->getPageMax();	
		}
			if(temp_map.size()==0)
	{
		winArr[8]->getArr(0)->setTitle("未找到商品!");//更改提示消息
		winArr[8]->setTitleType("搜索翻页--未找到商品");//更改提示窗口类型
		CTool::clear(52,16,20,8);//局部刷新
		winArr[8]->CWindow_Show();//提示窗口
		winArr[8]->winRun(); 
	}

	}
	int row=this->table->getWidth();//宽作为行
	int col=this->table->getHeight();//高作为列
	row=row*2+1;//行数
	int x_temp=this->table->getX();
	int y_temp=this->table->getY();
	int x=this->table->getX();
	int y=this->table->getY();
	for(int i=0;i<row;i++)//画表格
	{
		if(i==0)//第一行
		{
			CTool::gotoxy(x,y-1);
			cout<<"┌";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"——————┐";	
				}else
				cout<<"——————┬";
			}
			cout<<endl;
		}else if(i==row-1)
		{
			CTool::gotoxy(x,y);
			cout<<"└";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"——————┘";	
				}else
					cout<<"——————┴";
			}
			cout<<endl;
		}
		else if(i%2==1 && i!=row-1)
		{
			CTool::gotoxy(x,y++);
			cout<<"｜";
			for(int j=0;j<col;j++)
			{
				cout<<"            ";
				cout<<"｜";
			}
			cout<<endl;
		}else if(i%2==0 && i!=row-1)
		{
			CTool::gotoxy(x,y++);
			cout<<"├";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"——————┤";	
				}else
					cout<<"——————┼";
			}
			cout<<endl;
		}
	}
	x=x-2;//与文本对齐
	CTool::gotoxy(x+4,y_temp);//+x坐标+14
	cout<<"商品编码";
	CTool::gotoxy(x+18,y_temp);
	cout<<"商品名称";
	CTool::gotoxy(x+32,y_temp);
	cout<<"商品类型";
	CTool::gotoxy(x+46,y_temp);
	cout<<"商品价格";
	CTool::gotoxy(x+60,y_temp);
	cout<<"库存数量";
	CTool::gotoxy(x+74,y_temp);
	cout<<"仓位编号";
	CTool::gotoxy(x+88,y_temp);
	int rowsum=x_temp;
	int colsum=y_temp+1;
	//覆盖页数--翻页
	CTool::gotoxy(this->table->getX()+42,this->table->getY()+15);
	if(this->table->getPage()<=this->table->getPageMax())
	{
		cout<<this->table->getPage();

	}else
	{
		cout<<this->table->getPageMax();	
	}
	map<string,CGoods>::iterator temp_iter=temp_map.begin();
	if(this->table->getPage()<=this->table->getPageMax())
	{
		advance(temp_iter,(this->table->getPage()-1)*5);//迭代移动
	} 
	int count=this->table->getCount();//判断迭代器有无超出

	for(int m=0;m<5;m++)// 打印内容
	{
		for(int n=0; n<6;n++)
		{
			CTool::gotoxy(rowsum+2,colsum+1);
			switch(n)
			{
			case 0:
				cout<<temp_iter->second.getGoodsNum();//获取商品编号
				break;
			case 1:
				cout<<temp_iter->second.getGoodsName();//获取商品名称
				break;
			case 2:
				cout<<temp_iter->second.getGoodsType();//获取商品类型
				break;
			case 3:
				cout<<temp_iter->second.getGoodsPrice();//获取商品价格
				break;
			case 4:
				cout<<temp_iter->second.getInventory();//获取库存数量
				break;
			case 5:
				cout<<temp_iter->second.getWarehouseNum();//获取仓位编号
				break;
			}
			rowsum=14+rowsum;
		}
			temp_iter++;
			if(temp_iter==temp_map.end())
			{
				return 1;
			}
		rowsum=x_temp;
		colsum=2+colsum;

	}
	return 1;
}
//导出商品信息
void CGoodsSearchWin::input_goods_data()
{
	map<string,CGoods>::iterator iter;
	string str_temp=data;//时间
	int m;//"-"位置
	iter=mymap_goods.find(inputNum_edit->getContent());
	if(iter!=mymap_goods.end())
	{
		string str1=iter->second.getGoodsNum();//获取商品编号
		string str2=iter->second.getGoodsName();//获取商品名称
		string str3=iter->second.getGoodsType();//获取商品类型
		string str4=iter->second.getGoodsPrice();//获取商品价格
		string str5=iter->second.getInventory();//获取库存数量
		string str6=iter->second.getWarehouseNum();//获取仓位编号
		str_temp.erase(4,1);
		m=str_temp.find("-");
		str_temp.erase(m,1);
		str_temp="./data/"+str_temp+"GI"+".txt";
		//创建流对象
		ofstream ofs;
		//打开文件
		ofs.open(str_temp.c_str(),ios::out | ios::app);//默认当前路径
		//写入数据---时间-- 盘点编号--盘点状态
		ofs<<data<<" "<<str1<<" "<<str2<<" "<<str3<<" "<<str4<<" "<<str5<<" "<<str6<<endl;
		ofs.close();
	}else
	{
		winArr[8]->getArr(0)->setTitle("请精确搜索!");//更改提示消息
		winArr[8]->setTitleType("请精确搜索--搜索商品");//更改提示窗口类型
		CTool::clear(52,16,20,8);//局部刷新
		winArr[8]->CWindow_Show();//提示窗口
		winArr[8]->winRun(); 
	}
}
//重写父类纯虚函数
void CGoodsSearchWin::doAction()
{	
	map<int,CUser>::iterator iter;
	int i=this->getFocus();
	if(i==7)
	{
		//回主界面也清空文本
		inputNum_edit->setContentNull();
		fuzzy_word="";
		CTool::gotoxy(this->getX()+42,this->getY()+25);//提示消息位置
		system("cls");//清屏
		//设置页数为1
		table->setPage(1);
		table->setCount(1);
		iter=mymap.find(current_Account);
		if(iter->second.getrole()==1)//	盘点员
		{
			winArr[4]->CWindow_Show();//进入盘点员菜单
			winArr[4]->winRun();
		}else//仓库管理员
		{
			winArr[3]->CWindow_Show();//进入仓库管理员菜单
			winArr[3]->winRun();
		}
	}
	if(inputNum_edit->getContent()=="")
	{
		winArr[8]->getArr(0)->setTitle("查询信息为空!");//更改提示消息
		winArr[8]->setTitleType("查询信息为空--搜索商品");//更改提示窗口类型
		CTool::clear(52,16,20,8);//局部刷新
		winArr[8]->CWindow_Show();//提示窗口
		winArr[8]->winRun(); 
	}

	switch(i)
	{
	case 5://精确查询or模糊查询
		if(!accurateQuery())//精确查询到就退出
		{
			break;
		}else
		{
			fuzzyQuery();//模糊查询
		}
		if(inputNum_edit->getContent()=="")
		{
			break;
		}	
		fuzzy_word=inputNum_edit->getContent();//模糊查询关键字赋值
		this->inputNum_edit->setContentNull();
		winArr[6]->getArr(9)->setCount(666);//模糊翻页
		winArr[6]->CWindow_Table_Show();
		winArr[6]->winRun();
		break;
	case 6://导出商品信息--6
		if(inputNum_edit->getContent()=="")
		{
			winArr[8]->getArr(0)->setTitle("查询信息为空!");//更改提示消息
			winArr[8]->setTitleType("查询信息为空--搜索商品");//更改提示窗口类型
			CTool::clear(52,16,20,8);//局部刷新
			winArr[8]->CWindow_Show();//提示窗口
			winArr[8]->winRun(); 
		}else
		{
			input_goods_data();//导出商品信息
			winArr[8]->getArr(0)->setTitle("正在导出...");//更改提示消息
			winArr[8]->setTitleType("正在导出商品--搜索商品");//更改提示窗口类型
			CTool::clear(52,16,20,8);//局部刷新
			winArr[8]->CWindow_Show();//提示窗口
			winArr[8]->winRun(); 
		}
		break;
	case 7:
		//回主界面也清空文本
		inputNum_edit->setContentNull();
		fuzzy_word="";
		CTool::gotoxy(this->getX()+42,this->getY()+25);//提示消息位置
		system("cls");//清屏
		//设置页数为1
		table->setPage(1);
		table->setCount(1);
		iter=mymap.find(current_Account);
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
