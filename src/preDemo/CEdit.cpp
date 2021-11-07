#include "CEdit.h"
//默认构造
CEdit::CEdit()
{
	
}
//带参构造--负责给父类构造传参
CEdit::CEdit(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content):CControl(x,y,width,height,length,state,intputtype,type,content)
{
	
}
//析构
CEdit::~CEdit()
{
	
}
//
CEdit::doAction()
{
	
}
//控件展示
void CEdit::Control_Show()
{
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),this->getHeight());//画出控件边框
	CTool::gotoxy(this->getX()+2,this->getY()+1);//光标移动到内容位置
	cout<<this->getContent()<<endl;//输出内容
}
/*
	函数名: gbl_putstring
	函数功能: 输入
	函数参数:	CONTROL* con 控件
				int ikey 
	返回值 : 无   

*/
void CEdit::gbl_putstring(CControl* con,int ikey)
{
	//计数content内的内容长度
	int count=con->getContent().length();

	//长度上限--回删
	if(count==con->getLength())
	{
		if(ikey=='\b')//回删
		{
			count--;
			con->delContent();
			printf("\b \b");
		}
	}else//长度未满
	{
		//1 字母  2 数字  3 字母+数字 4 数字+"."
		if(con->getIntputtype()==1)//1 字母
		{
			if(ikey>='a' && ikey<='z' || ikey>='A' && ikey<='Z')
			{
				switch(con->getState())//1明文 2密文
				{
				case 1: 
					con->setContent(ikey);
					count++;
					//	cout<<count;
					putch(ikey);
				//	CTool::gotoxy(this->getX()+2+count,this->getY()+1);//光标移到输入内容后
					break;
				case 2: 
					con->setContent(ikey);
					printf("*");
					break;
				}
			}else//长度未满--回删
			{	
				
				if(ikey=='\b' && count>0)
				{
					count--;
					con->delContent();
					printf("\b \b");
				}
			}
		}
		if(con->getIntputtype()==3)//3 字母+数字
		{
			if(ikey>='a' && ikey<='z' || ikey>='A' && ikey<='Z' ||ikey>='0' && ikey<='9')
			{
				switch(con->getState())//1明文 2密文
				{
				case 1: 
					con->setContent(ikey);
					count++;
					//	cout<<count;
					putch(ikey);
					//	CTool::gotoxy(this->getX()+2+count,this->getY()+1);//光标移到输入内容后
					break;
				case 2: 
					con->setContent(ikey);
					printf("*");
					break;
				}
			}else//长度未满--回删
			{	
				
				if(ikey=='\b' && count>0)
				{
					count--;
					con->delContent();
					printf("\b \b");
				}
			}
		}

		if(con->getIntputtype()==4)//数字+"."
		{
			if(ikey>='0' && ikey<='9' || ikey=='.')
			{
				switch(con->getState())//1明文 2密文
				{
				case 1: 
					con->setContent(ikey);
					count++;
					//	cout<<count;
					putch(ikey);
					//	CTool::gotoxy(this->getX()+2+count,this->getY()+1);//光标移到输入内容后
					break;
				case 2: 
					con->setContent(ikey);
					printf("*");
					break;
				}
			}else//长度未满--回删
			{	
				
				if(ikey=='\b' && count>0)
				{
					count--;
					con->delContent();
					printf("\b \b");
				}
			}
		}

		else if(con->getIntputtype()==2)//2 数字
		{
			if(ikey>='0' && ikey<='9')
			{
				switch(con->getState())//1明文 2密文
				{
				case 1: 
					con->setContent(ikey);
					count++;
					putch(ikey);
					CTool::gotoxy(this->getX()+2+count,this->getY()+1);//光标移到输入内容后
					break;
				case 2: 
					con->setContent(ikey);
					printf("*");
					break;
				}
			}else//长度未满--回删
			{
				if(ikey=='\b' && count>0)
				{
					count--;
					con->delContent();
					printf("\b \b");
				}
			}
		}

//--------------

//-------------

	}
}
