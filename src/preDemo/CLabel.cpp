#include "CLabel.h"
//默认构造
CLabel::CLabel()
{
	
}
//带参构造--负责给父类构造传参
CLabel::CLabel(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content):CControl(x,y,width,height,length,state,intputtype,type,content)
{
	
}
//析构
CLabel::~CLabel()
{
	
}
//
CLabel::doAction()
{
	
}
//控件展示
void CLabel::Control_Show()
{
	CTool::gotoxy(this->getX()+2,this->getY()+1);//光标移动到内容位置
	cout<<this->getContent()<<endl;//输出内容	
}
