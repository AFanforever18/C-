#include "COrderTableWin.h"
//Ĭ�Ϲ���
COrderTableWin::COrderTableWin()
{
	
}
//Ĭ�Ϲ���//���ι���
COrderTableWin::COrderTableWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	string str="��ӭʹ�òִ��̵��ϵͳ!";//��������
	//��ǩ
	//Ϊ�˱�ǩ�洰�ڴ�Сλ�ñ䶯
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);
	order_state=new CLabel(this->getX()+this->getWidth()-20,this->getY()+7,20,2,1,1,0,LABEL,"�̵�״̬:������");
	orderNum=new CLabel(this->getX()+2,this->getY()+7,20,2,1,1,0,LABEL,"�̵���:");
	jiantou=new CLabel(this->getX()+58,this->getY()+26,18,2,1,1,0,LABEL,"��������ҳ");
	page_num=new CLabel(this->getX()+46,this->getY()+26,20,2,1,1,0,LABEL,"1/1");

	//��ť
	myexit=new CButton(this->getX()+76,this->getY()+24,18,2,1,1,0,BUTTON,"����[Esc]");
	over_order=new CButton(this->getX()+8,this->getY()+24,18,2,1,1,0,BUTTON,"�����̵�");

	//���
	table=new CTable_2(this->getX()+14,this->getY()+11,6,5,1,1,0,LABEL,"��ѯ");	
	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(orderNum);//3
	addControl(table);
	addControl(order_state);
	addControl(over_order);//�����̵㰴ť--6
	addControl(myexit);//����--
	addControl(jiantou);//��������
	addControl(page_num);//ҳ��
	printf_Content();//��ӡ��Ʒ��Ϣ

}
//Ĭ������
COrderTableWin::~COrderTableWin()
{
	
}
void COrderTableWin::printf_Content()//��ӡ��Ʒ��Ϣ
{

}
//���ڵĲ��� ÿ������һ�� ���� ����������д
void COrderTableWin::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
		case 6://�����̵� 
		//����ı�
		system("cls");
		winArr[9]->CWindow_Show();//���̵�˵�����
		winArr[9]->winRun();
			break;
		case 7://���� 
		//����ı�
		system("cls");
		winArr[9]->CWindow_Show();//���½��̵����
		CTool::paintBorder(16,13,60,16);//������Ʒ��Ϣ�߿�
		winArr[9]->winRun();
			break;

	}
}