#include "CAddGoodsMenuWin.h"
//Ĭ�Ϲ���
CAddGoodsMenuWin::CAddGoodsMenuWin()
{
	
}
//���ι���
CAddGoodsMenuWin::CAddGoodsMenuWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	//��ť
	add_Button=new CButton(30,14,18,2,1,1,0,BUTTON,"���");
	record_Button=new CButton(70,14,18,2,1,1,0,BUTTON,"����¼");
	exit_Button=new CButton(30,22,18,2,1,1,0,BUTTON,"����[Esc]");

	//��ǩ
	title=new CLabel(50,3,8,5,1,1,1,LABEL,"��ӭʹ��xx�̵��ϵͳ");
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);

	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(add_Button);//�ؼ������±�--3--���
	addControl(record_Button);//�ؼ������±�--4--����¼
	addControl(exit_Button);//�ؼ������±�--5--����

}
//��������
CAddGoodsMenuWin::~CAddGoodsMenuWin()
{

}
//��д���ി�麯��
void CAddGoodsMenuWin::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
	case 3://����������
		CTool::gotoxy(this->getX()+42,this->getY()+25);//��ʾ��Ϣλ��
		system("pause");//�����������
		system("cls");//����

		winArr[12]->getArr(1)->setTextConcent("��ӭ:"+user_name);
		winArr[12]->CWindow_Show();
		CTool::paintBorder(16,13,60,16);//��Ʒ��Ϣ�߿�
		winArr[12]->winRun();
		break;
	case 4://��������¼����
		break;
	case 5:
		CTool::gotoxy(52,29);
		system("pause");//�����������
		system("cls");//����
		winArr[3]->CWindow_Show();//���زֿ�������
		winArr[3]->winRun();
		break;
	}
}