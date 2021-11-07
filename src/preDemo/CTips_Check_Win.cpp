#include "CTips_Check_Win.h"

//���ι���
CTips_Check_Win::CTips_Check_Win(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	//��ť
	ok_Button=new CButton(45,22,16,2,1,1,0,BUTTON,"ȷ��[Enter]");
	cal_Button=new CButton(64,22,16,2,1,1,0,BUTTON,"ȡ��[Esc]");

	//��ǩ
	title=new CLabel(43,12,8,5,1,1,1,LABEL,"������¼:");
	title_num=new CLabel(43,14,8,5,1,1,1,LABEL,"��������:");
	title_season=new CLabel(43,18,8,5,1,1,1,LABEL,"����˵��:");

	//�༭��
	border=new CEdit(42,11,40,14,1,1,0,LABEL,"");//�߿�����
	edit_num=new CEdit(56,14,20,2,10,1,2,EDIT,"");
	edit_season=new CEdit(56,18,20,3,10,1,3,EDIT,"");


	//��ӿؼ�
	addControl(title);
	addControl(border);
	addControl(title_num);
	addControl(title_season);
	addControl(edit_num);
	addControl(edit_season);
	addControl(ok_Button);//�ؼ������±�--6--ȷ��
	addControl(cal_Button);//�ؼ������±�--7--����

}
//�ı���Ʒ������Ϣ
void CTips_Check_Win::change_chcek_data()
{
	map<string,CGoods>::iterator iter;
	iter=map_check.find(gbl_goods_selectNUM);//�ҵ�ѡ�����Ʒ���
	//ԭ�ȵ���Ϣ
	string str1=iter->second.getGoodsNum();//��Ʒ����
	string str2=iter->second.getGoodsName();//��Ʒ���
	string str3=iter->second.getGoodsType();//�̵�����
	string str4=iter->second.getGoodsPrice();//��������
	string str5=iter->second.getInventory();//��������
	string str6=iter->second.getWarehouseNum();//����ԭ��
	//������
	str5=this->edit_num->getContent();//��������--�����
	str6=this->edit_season->getContent();//����ԭ��--�����
	//ɾ������ԭ�е�����
	map_check.erase(gbl_goods_selectNUM);
	//�����µĳ�������
	CGoods good_temp(str1,str2,str3,str4,str5,str6);
	map_check.insert(make_pair(gbl_goods_selectNUM,good_temp));
	string src= "./data/"+gbl_selectNUM+".txt";//·��="./data/"+����--�̵���+".txt"
	//����������
	ofstream ofs;
	//���ļ�
	ofs.open(src.c_str());//ios::trunc�����ԭ�ļ�����,�ɲ�д,Ĭ�Ͼ�����
	ofs.close;//�ر��ļ�
	//����ļ�����д�� ��Ӧ�̵����ļ�
	CFile::new_Check_Data_Write();//���̵�����д��
}
//����״̬ 1--δ����  2--������ 3--�ѳ���
int CTips_Check_Win::get_check_state()
{
	//map_check
	int error_num;//��������
	int count=0;//ͳ���Ƿ񶼳������
	for(map<string,CGoods>::iterator iter=map_check.begin();iter!=map_check.end();iter++)
	{
		error_num=atoi(iter->second.getGoodsPrice().c_str());//��������--��������Ʒ�൱���� �������ƺ���
		//�õ����������ľ���ֵ
		if(atoi(iter->second.getGoodsPrice().c_str())>0)
		{
			error_num=atoi(iter->second.getGoodsPrice().c_str());
		}else
		{
			error_num=0-atoi(iter->second.getGoodsPrice().c_str());	
		}
		//ͳ�Ƴ�����ɵ���Ʒ����
		if(error_num==atoi(iter->second.getInventory().c_str()))//�������������������ֵ��� ������ɳ���
		{
			count++;//���һ�γ��� count++
		}
	}
	if(count==map_check.size())//count==map_check.size() ȫ���������
	{
		return 3;//�ѳ���
	}else
	{
		return 2;//������
	}
}
//�����̵��źͳ���״̬����������
void CTips_Check_Win::change_order_num_and_state(string mycheck_state)
{
	//gbl_selectNUM--ȫ�ֱ���--����ѡ�����Ʒ���
	map<string,string>::iterator iter;
	iter=mymap_order_num.find(gbl_selectNUM);//ȥ�̵��źͳ���״̬�������ҵ�ǰѡ����̵���
	//ԭ���̵��źͳ���״̬
	string order_num=iter->first;//�̵���
	string check_state=iter->second;//����״̬
	//�޸ĳ���״̬
	check_state=mycheck_state;
	//��������ɾ���ɵ�����
	mymap_order_num.erase(gbl_selectNUM);
	//�����µ�����
	mymap_order_num.insert(make_pair(gbl_selectNUM,check_state));
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

//��д���ി�麯��
void CTips_Check_Win::doAction()
{
	//gbl_goods_selectNUM
	string check_state;//����״̬
	int num_temp;//���շ���ֵ�жϳ���״̬
	int i=this->getFocus();
	switch(i)
	{
	case 6:
	change_chcek_data();//�ı���Ʒ������Ϣ
	num_temp=get_check_state();//����״̬ 1--δ����  2--������ 3--�ѳ���
	if(num_temp==2)
	{
		check_state="������";
	}else if(num_temp==3)
	{
		check_state="�ѳ���";
	}

	//�����̵��źͳ���״̬����������
	change_order_num_and_state(check_state);

	this->edit_num->setContentNull();//���������ı����
	this->edit_season->setContentNull();//����ԭ���ı����
	winArr[18]->getArr(4)->setTextConcent("����״̬:"+check_state);//���ĳ���״̬
	winArr[18]->CWindow_Show();
	CTool::printf_Table_Order_All();//��ӡ������Ϣ--7������
	winArr[18]->winRun();	
		break;
	case 7:
	//change_chcek_data();//�ı���Ʒ������Ϣ
	this->edit_num->setContentNull();//���������ı����
	this->edit_season->setContentNull();//����ԭ���ı����
	winArr[18]->CWindow_Show();
	CTool::printf_Table_Order_All();//��ӡ������Ϣ--7������
	winArr[18]->winRun();	
		break;
	}
}