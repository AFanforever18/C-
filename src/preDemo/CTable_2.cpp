#include "CTable_2.h"
//Ĭ�Ϲ���
CTable_2::CTable_2()
{
	
}
//���ι���--��������๹�촫��
CTable_2::CTable_2(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content):CControl(x,y,width,height,length,state,intputtype,type,content)
{
	
}
//����
CTable_2::~CTable_2()
{
	
}
//

//�ؼ�չʾ
void CTable_2::Control_Show()
{
	int row=this->getWidth();//����Ϊ��
	int col=this->getHeight();//����Ϊ��
	row=row*2+1;//����
	int x_temp=this->getX();
	int y_temp=this->getY();
	int x=this->getX();
	int y=this->getY();
	for(int i=0;i<row;i++)
	{
		if(i==0)//��һ��
		{
			CTool::gotoxy(x,y-1);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"��������������";	
				}else
				cout<<"��������������";
			}
			cout<<endl;
		}else if(i==row-1)
		{
			CTool::gotoxy(x,y);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"��������������";	
				}else
					cout<<"��������������";
			}
			cout<<endl;
		}
		else if(i%2==1 && i!=row-1)
		{
			CTool::gotoxy(x,y++);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				cout<<"            ";
				cout<<"��";
			}
			cout<<endl;
		}else if(i%2==0 && i!=row-1)
		{
			CTool::gotoxy(x,y++);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"��������������";	
				}else
					cout<<"��������������";
			}
			cout<<endl;
		}
	}
	x=x-2;//���ı�����
	CTool::gotoxy(x+4,y_temp);//+x����+14
	cout<<"��Ʒ����";
	CTool::gotoxy(x+18,y_temp);
	cout<<"��Ʒ����";
	CTool::gotoxy(x+32,y_temp);
	cout<<"�������";
	CTool::gotoxy(x+46,y_temp);
	cout<<"�̵�����";
	CTool::gotoxy(x+60,y_temp);
	cout<<"��������";
	CTool::gotoxy(x+74,y_temp);
}
