#include "CBeginWin.h"
//Ĭ�Ϲ���
CBeginWin::CBeginWin()
{
	
}
//���ι���
CBeginWin::CBeginWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	//��ť
	login_Button=new CButton(52,8,18,2,1,1,0,BUTTON,"����");
	reg_Button=new CButton(52,12,18,2,1,1,0,BUTTON,"ע��");
	exit_Button=new CButton(52,16,18,2,1,1,0,BUTTON,"�˳�");

	//��ǩ
	title=new CLabel(53,3,8,5,1,1,1,LABEL,"�ִ��̵����Ŀ");
	

	//��ӿؼ�
	addControl(title);
	addControl(login_Button);//�ؼ������±�--1--����
	addControl(reg_Button);//�ؼ������±�--2--ע��
	addControl(exit_Button);//�ؼ������±�--3--�˳�

}
//��������
CBeginWin::	~CBeginWin()
{

}
//��д���ി�麯��
void CBeginWin::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
	case 1://����������
		CTool::gotoxy(52,20);
		system("pause");//�����������
		system("cls");//����

		winArr[2]->CWindow_Show();
		winArr[2]->winRun();
		break;
	case 2://����ע�����
		CTool::gotoxy(52,20);
		system("pause");//�����������
		system("cls");//����
		winArr[1]->CWindow_Show();
		winArr[1]->winRun();
		break;
	case 3://�˳�ϵͳ
		winArr[8]->getArr(0)->setTitle("�˳�ϵͳ!");//������ʾ��Ϣ
		winArr[8]->setTitleType("�˳�ϵͳ--��ʼ����");//������ʾ��������
		CTool::clear(52,16,20,8);//�ֲ�ˢ��
		winArr[8]->CWindow_Show();//��ʾ����
		winArr[8]->winRun(); 
		break;
	}
}