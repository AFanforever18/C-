#include "COrderCheckWin.h"
//���ι���
COrderCheckWin::COrderCheckWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	this->
	//��ť
	exit_Button=new CButton(this->getX()+8,27,18,2,1,1,0,BUTTON,"����[Esc]");
	Btn_1=new CLabel(36,12,18,2,1,1,0,BUTTON,"");
	Btn_2=new CLabel(36,14,18,2,1,1,0,BUTTON,"");
	Btn_3=new CLabel(36,16,18,2,1,1,0,BUTTON,"");
	Btn_4=new CLabel(36,18,18,2,1,1,0,BUTTON,"");
	Btn_5=new CLabel(36,20,18,2,1,1,0,BUTTON,"");
	Btn_6=new CLabel(36,22,18,2,1,1,0,BUTTON,"");
	Btn_7=new CLabel(36,24,18,2,1,1,0,BUTTON,"");

	//��ǩ
	title=new CLabel(53,3,8,5,1,1,1,LABEL,"�ִ��̵����Ŀ");
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);
	jiantou=new CLabel(this->getX()+this->getWidth()-30,this->getY()+25,20,2,1,1,0,LABEL,"��������ҳ,������ѡ������");
	order_num=new CLabel(40,10,20,2,1,1,0,LABEL,"�̵���");
	order_state=new CLabel(52,10,20,2,1,1,0,LABEL,"����״̬");

	//���
	table=new CTable_3(this->getX()+30,this->getY()+9,8,2,9,1,0,LABEL,"��ѯ");//ͨ�ñ��

	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(jiantou);
	addControl(order_num);//4
	addControl(order_state);
	addControl(table);
	addControl(Btn_1);//7
	addControl(Btn_2);//8
	addControl(Btn_3);//9
	addControl(Btn_4);//10
	addControl(Btn_5);//11
	addControl(Btn_6);//12
	addControl(Btn_7);//13
	addControl(exit_Button);//�ؼ������±�--14--����

}
//������ϸ����--������ť���
void COrderCheckWin::enter_Check(int Btn_num)
{
	int m;//ѭ��������++
	map<string,string>::iterator iter=mymap_order_num.begin();
	map<string,string>::iterator it=mymap_order_num.begin();//���Ҳ���״̬
	advance(iter,(page_current_2-1)*7);	
	for( m=0;m<Btn_num;m++)//���ݰ�ťλ��ƫ�Ƶ�����
	{
		iter++;	
		if(iter==mymap_order_num.end())
		{
			winArr[8]->getArr(0)->setTitle("����Ϊ��!");//������ʾ��Ϣ
			winArr[8]->setTitleType("����Ϊ��--����");//������ʾ��������
			CTool::clear(52,16,20,8);//�ֲ�ˢ��
			winArr[8]->CWindow_Show();//��ʾ����
			winArr[8]->winRun(); 
		}
	}
	gbl_selectNUM=iter->first;//����ѡ����̵���	
	it=mymap_order_num.find(gbl_selectNUM);//ͨ��ѡ��ı������������״̬
	string check_State=it->second;//����״̬
	system("cls");//����
	CFile::order_check_read();//����ѡ����̵��Ŷ�������
	change_check_state();//δ���������Ϊ������,����״̬����
	winArr[18]->getArr(1)->setTextConcent("�û�:"+user_name+"<�ֿ����Ա>");//�޸��û����Ʊ�ǩ
	winArr[18]->getArr(3)->setTextConcent("�̵���:"+gbl_selectNUM);//�޸��̵��ű�ǩ
	winArr[18]->getArr(4)->setTextConcent("����״̬:"+check_State);//�޸ĳ���״̬��ǩ
	winArr[18]->CWindow_Show();
	CTool::printf_Table_Order_All();//��ӡ������Ϣ--7������
	winArr[18]->winRun();	
}
//�ı����״̬
void COrderCheckWin::change_check_state()
{
	//gbl_selectNUM--ȫ�ֱ���--����ѡ�����Ʒ���
	map<string,string>::iterator iter;
	iter=mymap_order_num.find(gbl_selectNUM);//ȥ�̵��źͳ���״̬�������ҵ�ǰѡ����̵���
	//ԭ���̵��źͳ���״̬
	string str="������";
	string order_num=iter->first;//�̵���
	string check_state=iter->second;//����״̬
	if(iter->second=="δ����")
	{
		//��������ɾ���ɵ�����
		mymap_order_num.erase(gbl_selectNUM);
		//�����µ�����
		mymap_order_num.insert(make_pair(gbl_selectNUM,str));//���ѡ��δ�������̵���,����ͱ�ɳ�����
		//����������
		ofstream ofs;
		//���ļ�
		ofs.open("./data/checkdata.txt");//ios::trunc�����ԭ�ļ�����,�ɲ�д,Ĭ�Ͼ�����
		ofs.close;//�ر��ļ�
		for(map<string,string>::iterator iter_2=mymap_order_num.begin();iter_2!=mymap_order_num.end();iter_2++)
		{
			order_num=iter_2->first;//�̵���
			check_state=iter_2->second;//����״̬
			CFile::num_and_state_write(order_num,check_state);
		}	
	}

}
//��д���ി�麯��
void COrderCheckWin::doAction()
{
	int i=this->getFocus();
	map<int,CUser>::iterator iter;
	iter=mymap.find(current_Account);
	switch(i)
	{
	case 7:	//Bt_1
		if(iter->second.getrole()==2)//�ֿ����Ա--�ɲ���
		enter_Check(0);//������ϸ����--������ť���--�������������--7������
		break;
	case 8:	//Bt_2
		if(iter->second.getrole()==2)//�ֿ����Ա--�ɲ���
		enter_Check(1);//������ϸ����--������ť���--�������������--7������
		break;
	case 9://Bt_3
		if(iter->second.getrole()==2)//�ֿ����Ա--�ɲ���
		enter_Check(2);//������ϸ����--������ť���--�������������--7������
			break;
	case 10://Bt_4
		if(iter->second.getrole()==2)//�ֿ����Ա--�ɲ���
		enter_Check(3);//������ϸ����--������ť���--�������������--7������
			break;
	case 11://Bt_5
		if(iter->second.getrole()==2)//�ֿ����Ա--�ɲ���
		enter_Check(4);//������ϸ����--������ť���--�������������--7������
		break;
	case 12:////Bt_6
		if(iter->second.getrole()==2)//�ֿ����Ա--�ɲ���
		enter_Check(5);//������ϸ����--������ť���--�������������--7������
		break;
	case 13:////Bt_7
		if(iter->second.getrole()==2)//�ֿ����Ա--�ɲ���
		enter_Check(6);//������ϸ����--������ť���--�������������--7������
		break;
	case 14://����
		system("cls");//����
		if(iter->second.getrole()==1)//	�̵�Ա
		{
			winArr[4]->CWindow_Show();//�����̵�Ա�˵�
			winArr[4]->winRun();
		}else//�ֿ����Ա
		{
			winArr[3]->CWindow_Show();//����ֿ����Ա�˵�
			winArr[3]->winRun();
		}
		break;
	}
}