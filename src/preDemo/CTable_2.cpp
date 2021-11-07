#include "CTable_2.h"
//默认构造
CTable_2::CTable_2()
{
	
}
//带参构造--负责给父类构造传参
CTable_2::CTable_2(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content):CControl(x,y,width,height,length,state,intputtype,type,content)
{
	
}
//析构
CTable_2::~CTable_2()
{
	
}
//

//控件展示
void CTable_2::Control_Show()
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
	cout<<"库存数量";
	CTool::gotoxy(x+46,y_temp);
	cout<<"盘点数量";
	CTool::gotoxy(x+60,y_temp);
	cout<<"差异数量";
	CTool::gotoxy(x+74,y_temp);
}
