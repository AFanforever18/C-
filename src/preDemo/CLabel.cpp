#include "CLabel.h"
//Ĭ�Ϲ���
CLabel::CLabel()
{
	
}
//���ι���--��������๹�촫��
CLabel::CLabel(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content):CControl(x,y,width,height,length,state,intputtype,type,content)
{
	
}
//����
CLabel::~CLabel()
{
	
}
//
CLabel::doAction()
{
	
}
//�ؼ�չʾ
void CLabel::Control_Show()
{
	CTool::gotoxy(this->getX()+2,this->getY()+1);//����ƶ�������λ��
	cout<<this->getContent()<<endl;//�������	
}
