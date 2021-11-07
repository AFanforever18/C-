#include "CTable_3.h"

//带参构造--负责给父类构造传参
CTable_3::CTable_3(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content):CControl(x,y,width,height,length,state,intputtype,type,content)
{
	
}

//控件展示
void CTable_3::Control_Show()
{
	int row=this->getWidth();//宽作为行
	int col=this->getHeight();//高作为列
	row=row*2+1;//行数
	int x_temp=this->getX();
	int y_temp=this->getY();
	int x=this->getX();
	int y=this->getY();
	int ww=this->getLength();//表格单个宽控制
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
					for(int wid=0;wid<ww;wid++)
					{
						cout<<"—";
					}
					cout<<"┐";	
				}else
				{
					for(int wid=0;wid<ww;wid++)
					{
						cout<<"—";
					}
					cout<<"┬";
				}


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
					for(int wid=0;wid<ww;wid++)
					{
						cout<<"—";
					}
					cout<<"┘";	
				}else
				{
					for(int wid=0;wid<ww;wid++)
					{
						cout<<"—";
					}	
					cout<<"┴";
				}
					
			}
			cout<<endl;
		}
		else if(i%2==1 && i!=row-1)
		{
			CTool::gotoxy(x,y++);
			cout<<"｜";
			for(int j=0;j<col;j++)
			{
				for(int wid=0;wid<ww;wid++)
				{
					cout<<"  ";
				}
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
					for(int wid=0;wid<ww;wid++)
					{
						cout<<"—";
					}
					cout<<"┤";	
				}else
				{
					for(int wid=0;wid<ww;wid++)
					{
						cout<<"—";
					}
					cout<<"┼";	
				}
					
			}
			cout<<endl;
		}
	}
	x=x-2;//与文本对齐
}
