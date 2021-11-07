#include "CTable.h"
//默认构造
CTable::CTable()
{
	
}
//带参构造--负责给父类构造传参
CTable::CTable(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content):CControl(x,y,width,height,length,state,intputtype,type,content)
{
	
}
//析构
CTable::~CTable()
{
	
}
//

//控件展示
void CTable::Control_Show()
{
	int row=this->getWidth();//宽作为行
	int col=this->getHeight();//高作为列
	row=row*2+1;//行数
	int x_temp=this->getX();
	int y_temp=this->getY();
	int x=this->getX();
	int y=this->getY();
	for(int i=0;i<row;i++)
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
	map<string,CGoods>::iterator iter=mymap_goods.begin();
	int page_Num=mymap_goods.size();
	if(page_Num%5==0)//一页5行
	{
		page_Num=page_Num/5;
	}else
	{
		page_Num=page_Num/5+1;
	}
		advance(iter,(this->getPage()-1)*5);	
	//覆盖页数--翻页
	CTool::gotoxy(this->getX()+42,this->getY()+15);
	if(this->getPage()<=page_Num)
	{
		cout<<this->getPage();

	}else
	{
		cout<<this->getPageMax();	
	}
	for(int m=0;m<5;m++)// 打印内容
	{
		for(int n=0; n<6;n++)
		{
			CTool::gotoxy(rowsum+2,colsum+1);
			switch(n)
			{
			case 0:
				cout<<iter->second.getGoodsNum();//获取商品编号
				break;
			case 1:
				cout<<iter->second.getGoodsName();//获取商品名称
				break;
			case 2:
				cout<<iter->second.getGoodsType();//获取商品类型
				break;
			case 3:
				cout<<iter->second.getGoodsPrice();//获取商品价格
				break;
			case 4:
				cout<<iter->second.getInventory();//获取库存数量
				break;
			case 5:
				cout<<iter->second.getWarehouseNum();//获取仓位编号
				break;
			}
			rowsum=14+rowsum;
		}
		if(this->getCount()==1 || this->getCount()==0)//1--right
		{
			iter++;
			if(iter==mymap_goods.end())
			{
				return;
			}
		}

		rowsum=x_temp;
		colsum=2+colsum;

	}


}
//模糊查询
void CTable::Control_Table_Show()
{	

	map<string,CGoods>temp_map;//创建临时map容器存放模糊查找到的商品数据
	string word=fuzzy_word;//模糊查询的编号
	for(map<string,CGoods>::iterator iter=mymap_goods.begin();iter!=mymap_goods.end();iter++)//遍历商品容器
	{
		if(strstr(iter->first.c_str(),word.c_str())!=NULL)//找到就插入临时容器
		{
			temp_map.insert(make_pair(iter->first,iter->second));  
		}
	}
	int temp_MaxPage;//模糊查询最大页数
	//取到最大页数
	if(temp_map.size()%5==0)
	{
		temp_MaxPage=temp_map.size()/5;
	}else
	{
		temp_MaxPage=temp_map.size()/5+1;	
	}
	this->setPage_Max(temp_MaxPage);//更改表格最大页数
	if(this->getPage()>this->getPageMax())//当前页数大于等于最大页数
	{
		//覆盖页数--翻页
		CTool::gotoxy(this->getX()+42,this->getY()+15);
		if(this->getPage()<=this->getPageMax())
		{
			cout<<this->getPage();
			
		}else
		{
			cout<<this->getPageMax();	
		}

		return;
	}
	int row=this->getWidth();//宽作为行
	int col=this->getHeight();//高作为列
	row=row*2+1;//行数
	int x_temp=this->getX();
	int y_temp=this->getY();
	int x=this->getX();
	int y=this->getY();
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
	CTool::gotoxy(this->getX()+42,this->getY()+15);
	if(this->getPage()<=this->getPageMax())
	{
		cout<<this->getPage();

	}else
	{
		cout<<9 ;	
	}
	map<string,CGoods>::iterator temp_iter=temp_map.begin();
	if(this->getPage()<=this->getPageMax())
	{
		advance(temp_iter,(this->getPage()-1)*5);//迭代移动
	} 
	int count=this->getCount();//判断迭代器有无超出

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
				CTool::gotoxy(62,29);//打印最大页码
				cout<<temp_MaxPage; 
				return;
			}
	

		rowsum=x_temp;
		colsum=2+colsum;

	}
	CTool::gotoxy(62,29);
	cout<<temp_MaxPage;
}