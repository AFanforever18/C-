#include "CButton.h"
//Ĭ�Ϲ���
CButton::CButton()
{
	
}
//���ι���--��������๹�촫��
CButton::CButton(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content):CControl(x,y,width,height,length,state,intputtype,type,content)
{
	
}
//����
CButton::~CButton()
{
	
}
//
CButton::doAction()
{
	
}
//�ؼ�չʾ
void CButton::Control_Show()
{
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),this->getHeight());//�����ؼ��߿�
	
	string str=this->getContent();
	CTool::gotoxy(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1);//����ƶ�������λ��--����
	cout<<this->getContent()<<endl;//�������
}

	void CButton::sss()
	{	
		CButton* manager=new CButton(this->getX(),this->getY()+2,18,2,1,1,0,BUTTON,"�̵�Ա");
		manager->Control_Show();
		CTool::gotoxy(this->getX()+2,this->getY()+3);
	}