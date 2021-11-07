#include "CButton.h"
//默认构造
CButton::CButton()
{
	
}
//带参构造--负责给父类构造传参
CButton::CButton(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content):CControl(x,y,width,height,length,state,intputtype,type,content)
{
	
}
//析构
CButton::~CButton()
{
	
}
//
CButton::doAction()
{
	
}
//控件展示
void CButton::Control_Show()
{
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),this->getHeight());//画出控件边框
	
	string str=this->getContent();
	CTool::gotoxy(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1);//光标移动到内容位置--居中
	cout<<this->getContent()<<endl;//输出内容
}

	void CButton::sss()
	{	
		CButton* manager=new CButton(this->getX(),this->getY()+2,18,2,1,1,0,BUTTON,"盘点员");
		manager->Control_Show();
		CTool::gotoxy(this->getX()+2,this->getY()+3);
	}