#include "CTool.h"
/*
	函 数 名: 光标切换
	函数功能: 光标切换
	函数参数: int x, int y 窗口坐标
	返 回 值: 无
*/
void CTool::gotoxy(int x,int y)//光标切换
{
	HANDLE hOut;
	COORD pos= {x,y};
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void CTool::show()
{
cout<<"d";
}

/*
	函数名: 画框
	函数功能: 画框
	函数参数: int x, int y 窗口坐标 width 宽 height 高
	返回值 : 无    ┌  ┉   ┐   ┋    └  ┘
*/
void CTool::paintBorder(int startX, int startY,int width,int height)//定位光标位置到指定坐标
{   
	int i=0,j=0,preX,preY;
	preX=startX;
	preY=startY;
	//第一行
	for(i=0;i<startX+width;i++)
	{
		//光标定位
		gotoxy(startX,startY);
		if(preX==startX)//左上角 第一个位置
		{
			printf("┌");
		}
		else if(startX==(preX+width))//右上角
		{
			printf("┐");
			break;
		}
		else{
			printf("┉");
		}
		startX+=2;
	}
	printf("\n");
	//左边
	for(j=0;j<startY+height;j++)
	{
		startY+=1;
		//光标定位
		gotoxy(preX,startY);
		if(startY==preY+height)
		{
			printf("└");
			break;

		}
		else//左下角
		{
			printf("┋");
		}
	}
	printf("\n");
	//底边
	startX=preX;//把初始值再赋值给startX
	for(i=0;i<preX+width;i++)
	{
		
		startX+=2;
		//光标定位
		gotoxy(startX,startY);
		if(startX==preX+width)
		{
			printf("┘");
			break;

		}
		 else if (startX<=preX+width)
		{
			printf("┉");
		}
	}
	printf("\n");
	printf("\n");
	//右边
	for(i=0;i<preX+width;i++)
	{
		startY-=1;
		//光标定位
		gotoxy(startX,startY);
		if(preY==startY)
		{
			break;

		}
		else
		{
			printf("┋");
		}
	}
	printf("\n");
	printf("\n");
} 
//获取键值
 int CTool::Key()
{
	int key=0;
	while(1)
	{
		key=getch();
		if(key==KEY_ESC)
		{
			return KEY_ESC;
		}
		else if(key==KEY_ENTER)
		{
			return KEY_ENTER;
		}
		else if(key==224 || key==-32)
		{
			key=getch();
			switch(key)
			{
				case 72: return KEY_UP;
				case 80: return KEY_DOWN;
				case 75: return KEY_LEFT;
				case 77: return KEY_RIGHT;
			}
		}
		else
		{
			return key;
		}
	}
}
//盘点报表--数据打印
 void CTool::prtinf_Table_Content(list<CGoods> goods_list)
 {
	int page_Num=goods_list.size();
	if(page_Num%5==0)//一页5行
	{
		page_Num=page_Num/5;
	}else
	{
		page_Num=page_Num/5+1;
	}
	CTool::gotoxy(56,29);
	string pagenum="   "+CTool::strtoInt(page_current)+"/"+CTool::strtoInt(page_Num)+"  ";
	cout<<pagenum;
	list<CGoods>::iterator iter=goods_list.begin();
	advance(iter,(page_current-1)*5);
	
	//打印
	int rowsum=24;
	int colsum=14;
	int size;
	int b;//控制空格


	for(int m_1=0;m_1<5;m_1++)// 打印空格 类似局部刷新
	{		
		CTool::gotoxy(rowsum+2,colsum+1);
		for(int n=0; n<5;n++)
		{				
			CTool::gotoxy(rowsum+2,colsum+1);
			for(b=0;b<12;b++)
			{
				cout<<" ";	
			}	
			rowsum=14+rowsum;
		}	
		rowsum=24;
		colsum=2+colsum;
	}
	
	rowsum=24;
	colsum=14;

	for(int m=0;m<5;m++)// 打印内容
	{

		for(int n=0; n<5;n++)
		{				
			CTool::gotoxy(rowsum+2,colsum+1);
			switch(n)
			{
			case 0:
				size=(*iter).getGoodsNum().size();
				cout<<(*iter).getGoodsNum();//获取商品编号
				break;
			case 1:
				size=(*iter).getGoodsName().size();
				cout<<(*iter).getGoodsName();//获取商品名称
				break;
			case 2:
				size=(*iter).getGoodsType().size();
				cout<<(*iter).getGoodsType();//获取商品类型
				break;
			case 3:
				size=(*iter).getGoodsPrice().size();
				cout<<(*iter).getGoodsPrice();//获取商品价格
				break; 
			case 4:
				size=(*iter).getInventory().size();
				cout<<(*iter).getInventory();//获取库存数量
				break;
			}
			for(b=0;b<12-size;b++)
			{
				cout<<" ";
			}
			rowsum=14+rowsum;
		}
		iter++;
		if(iter==goods_list.end())
		{
			return;
		}
		rowsum=24;
		colsum=2+colsum;
	}

 }
//int->string
string CTool::strtoInt(int val)
{
	 string str;
	 stringstream ss;
	 ss<<val;
	 ss>>str;
	 return str;
} 
//局部清空 
void CTool::clear(int x,int y,int width,int height) //x,y--坐标   width,height--宽高
{
	for(int i=0;i<height;i++)
	{	
		CTool::gotoxy(x,y);
		for(int j=0;j<width;j++)//36为对应  16对应
		{
			cout<<" ";
		}	
		y++;
	}	
}
//盘点编号和冲正状态--数据打印
void CTool::printf_Table_Order()
{
	int page_Num=mymap_order_num.size();
	if(page_Num%7==0)//一页7行
	{
		page_Num=page_Num/7;
	}else
	{
		page_Num=page_Num/7+1;
	}
	CTool::gotoxy(56,29);
	string pagenum="   "+CTool::strtoInt(page_current_2)+"/"+CTool::strtoInt(page_Num)+"  ";
	cout<<pagenum;
	map<string,string>::iterator iter=mymap_order_num.begin();
	advance(iter,(page_current_2-1)*7);
	
	//打印
	int rowsum=40;
	int colsum=12;
	int size;
	int b;

	
	for(int m_1=0;m_1<7;m_1++)// 打印空格 类似局部刷新
	{		
		CTool::gotoxy(rowsum+2,colsum+1);
		for(int n=0; n<2;n++)
		{				
			CTool::gotoxy(rowsum+2,colsum+1);
			for(b=0;b<6;b++)
			{
				cout<<"  ";	
			}	
			rowsum=20+rowsum;
		}	
		rowsum=40;
		colsum=2+colsum;
	}
	
	rowsum=40;
	colsum=12;

	CTool::gotoxy(42,11);
	cout<<"盘点编号";
	CTool::gotoxy(62,11);
	cout<<"冲正状态";
	for(int m=0;m<7;m++)// 打印内容
	{

		for(int n=0; n<2;n++)
		{				
			CTool::gotoxy(rowsum+2,colsum+1);
			switch(n)
			{
			case 0:
				size=iter->first.size();
				cout<<iter->first;//获取盘点编号
				break;
			case 1:
				size=iter->second.size();
				cout<<iter->second;//获取冲正状态
				break;
			}
			for(b=0;b<12-size;b++)
			{
				cout<<" ";
			}
			rowsum=20+rowsum;
		}
		iter++;
		if(iter==mymap_order_num.end())
		{
			return;
		}
		rowsum=40;
		colsum=2+colsum;
	}
	
}
//盘点冲正信息--数据打印--7个属性
void CTool::printf_Table_Order_All()
{
// map_check;//冲正信息容器	


	int page_Num=map_check.size();
	if(page_Num%6==0)//一页6行
	{
		page_Num=page_Num/6;
	}else
	{
		page_Num=page_Num/6+1;
	}
	CTool::gotoxy(58,29);
	string pagenum="   "+CTool::strtoInt(page_current_4)+"/"+CTool::strtoInt(page_Num)+"  ";//页数
	cout<<pagenum;
	map<string,CGoods>::iterator iter=map_check.begin();
	advance(iter,(page_current_4-1)*6);
	
	//打印
	int rowsum=19;
	int colsum=13;
	int size;
	int b;//控制空格


	for(int m_1=0;m_1<6;m_1++)// 打印空格 类似局部刷新
	{		
	//	CTool::gotoxy(rowsum+2,colsum+1);
		for(int n=0; n<7;n++)
		{				
			CTool::gotoxy(rowsum+1,colsum+1);
			for(b=0;b<8;b++)
			{
				cout<<" ";	
			}	
			rowsum=12+rowsum;
		}	
		rowsum=19;
		colsum=2+colsum;
	}
	CTool::gotoxy(20,12);cout<<"商品编号";
	CTool::gotoxy(32,12);cout<<"商品名称";
	CTool::gotoxy(44,12);cout<<"库存数量";
	CTool::gotoxy(56,12);cout<<"盘点数量";
	CTool::gotoxy(68,12);cout<<"差异数量";
	CTool::gotoxy(80,12);cout<<"冲正数量";
	CTool::gotoxy(92,12);cout<<"冲正原因";
	
	rowsum=18;
	colsum=13;
	for(int m=0;m<6;m++)// 打印内容
	{

		for(int n=0; n<7;n++)
		{				
			CTool::gotoxy(rowsum+2,colsum+1);
			switch(n)
			{
			case 0:
				size=iter->first.size();
				cout<<iter->first;//获取商品编号
				break;
			case 1:
				size=iter->second.getGoodsNum().size();
				cout<<iter->second.getGoodsNum();//获取商品名称
				break;
			case 2:
				size=iter->second.getGoodsName().size();
				cout<<iter->second.getGoodsName();//获取库存数量
				break;
			case 3:
				size=iter->second.getGoodsType().size();
				cout<<iter->second.getGoodsType();//盘点数
				break;
			case 4:
				size=iter->second.getGoodsPrice().size();
				cout<<iter->second.getGoodsPrice();//差异数
				break; 
			case 5:
				size=iter->second.getInventory().size();
				cout<<iter->second.getInventory();//冲正数
				break;
			case 6:
				size=iter->second.getInventory().size();
				cout<<iter->second.getWarehouseNum();//原因	
				break;
			}
			for(b=0;b<6-size;b++)
			{
				cout<<" ";
			}
			rowsum=12+rowsum;
		}
		iter++;
		if(iter==map_check.end())
		{
			return;
		}
		rowsum=18;
		colsum=2+colsum;
	}



}
//遍历文件
void CTool::file_opear()
{
	//目标文件路径
	string inPath="./data\\*";//遍历文件夹下的所有文件
	//用于查找句柄
	long handle;
	struct _finddata_t fileinfo;
	//第一次查找
	handle=_findfirst(inPath.c_str(),&fileinfo);
	string name;
	if(handle==-1)
	return;
	do
	{
		name=fileinfo.name;	
		if(name.size()<15)//找到最新盘点编号  小于14避免把其他文件拿进来
		{
			continue;
		}
		string str="未冲正";
		name.erase(11,4);//去除".txt"
		mymap_order_num.insert(make_pair(name,str));//盘点编号和冲正状态存入容器
	//	cout<<name<<endl;
		name.erase(7,1);//去除"-"
		//找到的文件的文件名
		gbl_orderNUM=name;
	}
	while(!_findnext(handle,&fileinfo));
	_findclose(handle);
}