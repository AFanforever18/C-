#include "COrderManWin_Menu.h"
//���ι���
COrderManWin_Menu::COrderManWin_Menu(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	//��ǩ
	string str="��ӭʹ�òִ��̵��ϵͳ!";//��������
	//Ϊ�˱�ǩ�洰�ڴ�Сλ�ñ䶯
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);

	//��ť
	newOrder_Btn=new CButton(this->getX()+16,this->getY()+10,18,2,1,1,0,BUTTON,"�½��̵�");
	orderRecord_Btn=new CButton(this->getX()+this->getWidth()-34,this->getY()+10,18,2,1,1,0,BUTTON,"�̵��¼");
	myexit=new CButton(this->getX()+16,this->getY()+18,18,2,1,1,0,BUTTON,"����[Esc]");
		
	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(newOrder_Btn);//�½��̵�--3
	addControl(orderRecord_Btn);//�̵��¼--4
	addControl(myexit);//����Esc-5

}

//��д���ി�麯��
void COrderManWin_Menu::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
	case 3://�½��̵�
		system("cls");//����
		winArr[9]->getArr(1)->setTextConcent("��ӭ:"+user_name);
		winArr[9]->CWindow_Show();//������Ʒ��ѯ
		CTool::paintBorder(16,13,60,16);//������Ʒ��Ϣ�߿�
		winArr[9]->winRun();
		break;
	case 4://�̵��¼
		system("cls");//����
		winArr[17]->getArr(1)->setTextConcent("�û�:"+user_name+"<�̵�Ա>");
		winArr[17]->CWindow_Show();	
		CTool::printf_Table_Order();//�̵��źͳ���״̬
		winArr[17]->winRun();//�̵����--ѡ���������
		break;
	case 5://����
		system("cls");
		winArr[4]->CWindow_Show();
		winArr[4]->winRun();
		break;
	}
}
