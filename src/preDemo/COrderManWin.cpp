#include "COrderManWin.h"
//Ĭ�Ϲ���
COrderManWin::COrderManWin()
{

}
//���ι���
COrderManWin::COrderManWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	

	//��ǩ
	string str="��ӭʹ�òִ��̵��ϵͳ!";//��������
	//Ϊ�˱�ǩ�洰�ڴ�Сλ�ñ䶯
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);

	//��ť
	find_Btn=new CButton(this->getX()+16,this->getY()+10,18,2,1,1,0,BUTTON,"��Ʒ��ѯ");
	order_Btn=new CButton(this->getX()+this->getWidth()-34,this->getY()+10,18,2,1,1,0,BUTTON,"�ֿ��̵�");
	myexit=new CButton(this->getX()+16,this->getY()+18,18,2,1,1,0,BUTTON,"�˳�[Esc]");
		
	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(find_Btn);//��Ʒ��ѯ--3
	addControl(order_Btn);//�ֿ��̵�--4
	addControl(myexit);//�˳�--5

}

//Ĭ�Ϲ���
COrderManWin::~COrderManWin()
{
	
}
//��д���ി�麯��
void COrderManWin::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
	case 3://��Ʒ��ѯ
		int pageMax;
		if(mymap_goods.size()%5==0)
		{
			pageMax	=mymap_goods.size()/5;
		}else
		{
			pageMax	=mymap_goods.size()/5+1;
		}
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
	case 4://�ֿ��̵�
		system("cls");//����
		winArr[15]->getArr(1)->setTextConcent("��ӭ:"+user_name);
		winArr[15]->CWindow_Show();//�̵�
		winArr[15]->winRun();		break;
	case 5://�˳�
		winArr[8]->getArr(0)->setTitle("�����˳�ϵͳ!");//������ʾ��Ϣ
		winArr[8]->setTitleType("�����˳�ϵͳ");//������ʾ��������
		CTool::clear(52,16,20,8);//�ֲ�ˢ��
		winArr[8]->CWindow_Show();//��ʾ����
		winArr[8]->winRun(); 
		break;
	}
}
