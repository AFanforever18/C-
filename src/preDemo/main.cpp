#include <iostream>
#pragma   warning (disable: 4786)
#include "CTool.h"
#include "CButton.h"
#include "CLogin.h"
#include "CBeginWin.h"
#include "CRegisterWin.h"
#include "CManagerMenuWin.h"
#include "COrderManWin.h"
#include "CGoodsSearch.h"
#include "COutGoodsWin.h"//��Ʒ����
#include "CTipsWin.h"//��ʾ����
#include "CTipsWin_2.h"//��ʾ����--���
#include "CNewOrderWin.h";//�½��̵�
#include "COrderTableWin.h"//�̵��
#include "CAddGoodsMenuWin.h"//��Ʒ���˵�����
#include "CInputGoodsWin.h"//��Ʒ������
#include "CAddGoods.h"//������Ʒ
#include "COrderCheckWin.h"//����
#include "COrderCheckWin_2.h"//����2
#include "CTips_Check_Win.h"//����--7������--��ʾ����--����
#include "COrderManWin_Menu.h"
#include "CGoods.h"
#include <io.h>
#include <string>
#include <sstream>//int to string
#include <map>
#include <list>
#include <ctime>
using namespace std;
//ȫ�ֱ���
CWindow * winArr[30];//�洰��---��ת
CWindow * winArr2[15];//�洰��--ע��
map<int,CUser>mymap;//���û���Ϣ
map<string,CGoods>mymap_goods;//����Ʒ��Ϣ
map<string,string>mymap_order_num;//���̵��źͳ���״̬
list<string>order_goods_record;//����Ʒ�̵���
int gbl_accountNum=0;//�����˺��õ�
int current_Account=0;//��ǰ�������˺�
string user_name;//�û���
string fuzzy_word;//ģ����ѯ 
string data;//ʱ������
list<CGoods> temp_list;//�̵㱨��
int page_current=1;//��ǰҳ��--�̵㱨��
int page_current_2=1;//��ǰҳ��--����
int page_current_3=1;//��ǰҳ��--������
int page_current_4=1;//��ǰҳ��--����--7������
string gbl_orderNUM;//data�������̵���
string gbl_selectNUM;//����--ѡ���̵���
string gbl_goods_selectNUM;//����--7������--ѡ����Ʒ���
map<string,CGoods> map_check;//������Ϣ����--7������
int main()
{   
	//�̵��ź��̵�״̬��������mymap_order_num
	CFile::num_and_state_read();

	//�����ļ����µ������ļ�
	CTool::file_opear();
	
    // ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
    tm *ltm;
    time_t now = time(0);
    ltm= localtime(&now); 
	data=CTool::strtoInt(ltm->tm_year+1900)+"-"+CTool::strtoInt(ltm->tm_mon+1)+"-"+CTool::strtoInt(ltm->tm_mday);//��ȡʱ��
	//һ��ʼ��Ҫ���ļ����� map����
	CFile::userFileRead();
	CFile::goodsFileRead();	

	map<int,CUser>::iterator iter;//�õ������ҵ����һ��
	iter=mymap.end();
	string nn;//���˺�
	if(mymap.begin()!=iter)
	{
		iter--;
		//���ַ�����Ϊint��
		string str=iter->second.getID();
		int temp=atoi(str.c_str());
		temp=temp+1;//�ҵ����һ���˺� ��1
		gbl_accountNum=temp;
		stringstream ss;
		ss<<temp;
		ss>>nn;
		if(nn=="1" ||nn=="")//��user.txt�����  user.txtΪ�յ����
		{
			gbl_accountNum=1001;
			nn="1001";
		}
	}else{
		nn="1001";
		gbl_accountNum=1001;
	}

	//��ʼ����
	CBeginWin* beg=new CBeginWin(10,2,100,28);
	winArr[0]=beg;//���뿪ʼ����

	//�̵�Ա�Ͳֿ�����ߵ��л�����--С����
	CRegisterWin* reg_select=new CRegisterWin;
	//ѡ����ע�ᴰ��---�̵�Ա
	CRegisterWin* reg_order=new CRegisterWin(10,2,100,28);
	CButton* btn_1=new CButton(12,7,20,2,1,1,0,BUTTON,"�̵�Ա");
	CEdit* myaccount=new CEdit(48,10,40,2,20,MODE_TEXT,0,LABEL,nn);
	reg_order->change(btn_1,0);
	reg_order->change(myaccount,1);
	//ѡ����ע�ᴰ��---�ֿ������
	CRegisterWin* reg_manager=new CRegisterWin(10,2,100,28);
	CButton* m=new CButton(12,7,20,2,1,1,0,BUTTON,"�ֿ����Ա");
	CEdit* orderaccount=new CEdit(48,10,40,2,20,MODE_TEXT,0,LABEL,nn);
	reg_manager->change(orderaccount,1);
	reg_manager->change(m,0);
	winArr2[0]=reg_select;//��������ѡ�񴰿�
	winArr2[1]=reg_order;//�����̵�Աע�ᴰ��
	winArr2[2]=reg_manager;//����ֿ����Աע�ᴰ��

	//����--������
	CLogin* login=new CLogin(10,2,100,28);
	winArr[2]=login;//������봰��

	//ע��--������
	CRegisterWin* reg=new CRegisterWin(10,2,100,28);
	winArr[1]=reg;//����ע�ᴰ��

	//�ֿ����Ա--������
	CManagerMenuWin* managerWin=new	CManagerMenuWin(10,2,100,28);
	winArr[3]=managerWin;

	//�̵�Ա--������
	COrderManWin* orderManWin=new COrderManWin(10,2,100,28);
	winArr[4]=orderManWin;//�����̵�Ա����

	
	//��Ʒ��ѯ����
	CGoodsSearchWin* searchWin=new CGoodsSearchWin(10,2,100,28);
	winArr[5]=searchWin;//�����ѯ����

	//��Ʒ��ѯ����--ģ��
	CGoodsSearchWin* fuzzyWin=new CGoodsSearchWin(10,2,100,28);
	fuzzyWin->getArr(9)->setCount(666);//ģ����ҳ
	winArr[6]=fuzzyWin;//�����ѯ����--ģ��

	//��Ʒ���ⴰ��
	COutGoodsWin* goodsOut=new COutGoodsWin(10,2,100,28);
	winArr[7]=goodsOut;//������Ʒ���ⴰ��

	//��ʾ����
	CTipsWin* tipsWin=new CTipsWin(10,2,100,28);
	winArr[8]=tipsWin;//������ʾ����

	//�½��̵㴰��
	CNewOrderWin* neworderWin=new CNewOrderWin(10,2,100,28);
	winArr[9]=neworderWin;//�����½��̵㴰��

	//�̵㱨����
	COrderTableWin* orderTableWin=new COrderTableWin(10,2,100,28);
	winArr[10]=orderTableWin;//�����̵����

	//��Ʒ���˵�����
	CAddGoodsMenuWin* addGoodsMenu=new CAddGoodsMenuWin(10,2,100,28);
	winArr[11]=addGoodsMenu;//�������˵�����

	//��Ʒ������
	CInputGoodsWin* inputGoodsWin=new CInputGoodsWin(10,2,100,28);
	winArr[12]=inputGoodsWin;//����������

	//������--δ�ҵ���Ʒ--��ʾ����
	CTipsWin_2* tipsWin_2=new CTipsWin_2(10,2,100,28);
	winArr[13]=tipsWin_2;//������ʾ����

	//������Ʒ����
	CAddGoods* addGoods=new CAddGoods(10,2,100,28);
	winArr[14]=addGoods;

	//�̵�Ա�˵�����
	COrderManWin_Menu* orderManWin_Menu=new COrderManWin_Menu(10,2,100,28);
	winArr[15]=orderManWin_Menu;//�����̵�˵�������

	//��ʾ����--�̵�
	CTipsWin* tipsWin_3=new CTipsWin(10,2,100,28);
	winArr[16]=tipsWin_3;//������ʾ����--�̵�

	//��������
	COrderCheckWin* order_Check=new COrderCheckWin(10,2,100,28);
	winArr[17]=order_Check;//�����������

	//��������
	COrderCheckWin_2* order_Check_2=new COrderCheckWin_2(10,2,100,28);
	winArr[18]=order_Check_2;//�����������

	//������ʾ����--7������
	CTips_Check_Win* tips_check_win=new CTips_Check_Win(10,2,100,28);
	winArr[19]=tips_check_win;//���������ʾ����--7������

	winArr[0]->CWindow_Show();
	winArr[0]->winRun();

	system("pause");
	return 0;
}
