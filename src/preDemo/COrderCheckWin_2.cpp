#include "COrderCheckWin_2.h"
//���ι���
COrderCheckWin_2::COrderCheckWin_2(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	this->
	//��ť
	exit_Button=new CButton(this->getX()+28,27,18,2,1,1,0,BUTTON,"����[Esc]");
	over_Button=new CButton(this->getX()+8,27,18,2,1,1,0,BUTTON,"��ɳ���");
	Btn_1=new CLabel(14,13,18,2,1,1,0,BUTTON,"");
	Btn_2=new CLabel(14,15,18,2,1,1,0,BUTTON,"");
	Btn_3=new CLabel(14,17,18,2,1,1,0,BUTTON,"");
	Btn_4=new CLabel(14,19,18,2,1,1,0,BUTTON,"");
	Btn_5=new CLabel(14,21,18,2,1,1,0,BUTTON,"");
	Btn_6=new CLabel(14,23,18,2,1,1,0,BUTTON,"");

	//��ǩ
	title=new CLabel(53,3,8,5,1,1,1,LABEL,"�ִ��̵����Ŀ");
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);
	jiantou=new CLabel(this->getX()+this->getWidth()-30,this->getY()+25,20,2,1,1,0,LABEL,"��������ҳ,������ѡ������");
	order_num=new CLabel(this->getX()+2,this->getY()+7,20,2,1,1,0,LABEL,"�̵���:");
	order_state=new CLabel(this->getX()+this->getWidth()-20,this->getY()+7,20,2,1,1,0,LABEL,"����״̬:");

	//���
	table=new CTable_3(this->getX()+8,this->getY()+10,7,7,5,1,0,LABEL,"��ɳ���");//ͨ�ñ��

	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(order_num);//3--�̵���
	addControl(order_state);//4--����״̬
	addControl(table);
	addControl(jiantou);
	addControl(Btn_1);//7
	addControl(Btn_2);
	addControl(Btn_3);
	addControl(Btn_4);
	addControl(Btn_5);
	addControl(Btn_6);
	addControl(over_Button);//13--��ɳ���--��ť
	addControl(exit_Button);//�ؼ������±�--14--����
	

}
//��ʼ����--���� ��ť���
void COrderCheckWin_2::beg_Check(int Btn_num)
{
	int m;//ѭ��������++
	map<string,CGoods>::iterator iter=map_check.begin();
	advance(iter,(page_current_4-1)*6);	
	for( m=0;m<Btn_num;m++)//���ݰ�ťλ��ƫ�Ƶ�����
	{
		iter++;	
		if(iter==map_check.end())
		{
			winArr[8]->getArr(0)->setTitle("����Ϊ��!");//������ʾ��Ϣ
			winArr[8]->setTitleType("����Ϊ��--����--7������");//������ʾ��������
			CTool::clear(52,16,20,8);//�ֲ�ˢ��
			winArr[8]->CWindow_Show();//��ʾ����
			winArr[8]->winRun(); 
		}
	}
	gbl_goods_selectNUM=iter->first;//����ѡ�����Ʒ���
	CTool::clear(42,11,40,14);//�ֲ����
	winArr[19]->CWindow_Show();
	winArr[19]->winRun();//���������ʾ����
	system("cls");//����
}
//��д���ി�麯��
void COrderCheckWin_2::doAction()
{
	int i=this->getFocus();
	map<string,string>::iterator iter=mymap_order_num.begin();
	switch(i)
	{
	case 7://Btn_1 ���Ϊ0
		beg_Check(0);//��ʼ����
	//	CTool::clear(42,11,40,14);//�ֲ����
	//	winArr[19]->CWindow_Show();
		//winArr[19]->winRun();
		break;
	case 8://Btn_2 ���Ϊ1
		beg_Check(1);//��ʼ����
		break;
	case 9://Btn_2 ���Ϊ2
		beg_Check(2);//��ʼ����
		break;
	case 10://Btn_1 ���Ϊ3
		beg_Check(3);//��ʼ����
		break;
	case 11://Btn_2 ���Ϊ4
		beg_Check(4);//��ʼ����
		break;
	case 12://Btn_2 ���Ϊ5
		beg_Check(5);//��ʼ����
		break;
	case 14://�����̵�����˵�
		system("cls");//����
		winArr[17]->CWindow_Show();
		CTool::printf_Table_Order();//�̵��źͳ���״̬
		winArr[17]->winRun();
		break;
	}
}