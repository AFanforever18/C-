#include "CManagerMenuWin.h"
//Ĭ�Ϲ���
CManagerMenuWin::CManagerMenuWin()
{

}
//���ι���
CManagerMenuWin::CManagerMenuWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{


	//��ǩ
	string str="��ӭʹ�òִ��̵��ϵͳ!";//Ϊ�˱�ǩ�洰�ڴ�Сλ�ñ䶯
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
//	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),4);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);

	//��ť
	find_Btn=new CButton(this->getX()+16,this->getY()+10,18,2,1,1,0,BUTTON,"��Ʒ��ѯ");
	import_Btn=new CButton(this->getX()+this->getWidth()-34,this->getY()+10,18,2,1,1,0,BUTTON,"������Ʒ");
	input_Btn=new CButton(this->getX()+16,this->getY()+14,18,2,1,1,0,BUTTON,"��Ʒ���");
	output_Btn=new CButton(this->getX()+this->getWidth()-34,this->getY()+14,18,2,1,1,0,BUTTON,"��Ʒ����");
	orderCheck_Btn=new CButton(this->getX()+16,this->getY()+18,18,2,1,1,0,BUTTON,"�̵����");
	myexit=new CButton(this->getX()+this->getWidth()-34,this->getY()+18,18,2,1,1,0,BUTTON,"�˳�[Esc]");
		
	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(find_Btn);//��Ʒ��ѯ--3
	addControl(import_Btn);//������Ʒ--4
	addControl(input_Btn);//��Ʒ���--5
	addControl(output_Btn);//��Ʒ����--6
	addControl(orderCheck_Btn);//�̵����--7
	addControl(myexit);//�˳�--8



}

//Ĭ�Ϲ���
CManagerMenuWin::~CManagerMenuWin()
{
	
}
//��д���ി�麯��
void CManagerMenuWin::doAction()
{
	int pageMax;
	if(mymap_goods.size()%5==0)
	{
		pageMax	=mymap_goods.size()/5;
	}else
	{
		pageMax	=mymap_goods.size()/5+1;
	}
	int i=this->getFocus();
	switch(i)
	{
	case 3:
		CTool::gotoxy(this->getX()+42,this->getY()+25);//��ʾ��Ϣλ��
		system("pause");//�����������
		system("cls");//����
		winArr[5]->getArr(1)->setTextConcent("��ӭ:"+user_name);
		winArr[5]->getArr(9)->setPage(1);
		winArr[5]->getArr(9)->setPage_Max(pageMax);
		winArr[5]->getArr(9)->setCount(1);
		winArr[5]->CWindow_Show();//�����ѯ����
		winArr[5]->winRun();
		break;
	case 4:
		break;
	case 5:
		CTool::gotoxy(this->getX()+42,this->getY()+25);//��ʾ��Ϣλ��
		system("pause");//�����������
		system("cls");//����
		winArr[11]->getArr(1)->setTextConcent("��ӭ:"+user_name);
		winArr[11]->CWindow_Show();//�������˵�����
		winArr[11]->winRun(); 
		break;
	case 6://������ⴰ��
		CTool::gotoxy(this->getX()+42,this->getY()+25);//��ʾ��Ϣλ��
		system("pause");//�����������
		system("cls");//����
		winArr[7]->getArr(1)->setTextConcent("��ӭ:"+user_name);
		CTool::paintBorder(16,13,60,16);
		winArr[7]->CWindow_Show();
		winArr[7]->winRun(); 
		break;
	case 7:
		system("cls");//����
		winArr[17]->getArr(1)->setTextConcent("�û�:"+user_name+"<�ֿ������>");
		winArr[17]->CWindow_Show();	
		CTool::printf_Table_Order();//�̵��źͳ���״̬
		winArr[17]->winRun();//�̵����--ѡ���������
		break;
	case 8:
		winArr[8]->getArr(0)->setTitle("�����˳�ϵͳ!");//������ʾ��Ϣ
		winArr[8]->setTitleType("�����˳�ϵͳ");//������ʾ��������
		CTool::clear(52,16,20,8);//�ֲ�ˢ��
		winArr[8]->CWindow_Show();//��ʾ����
		winArr[8]->winRun(); 
		break;
	}
}
