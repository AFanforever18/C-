#include "CTipsWin.h"
//���ι���
CTipsWin::CTipsWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	titleType="δȷ��";
	//��ť
	exit_Button=new CButton(52,16,20,8,1,1,0,BUTTON,"");

	//��ǩ
	title=new CLabel(53,19,8,5,1,1,1,LABEL,"�����������ڿ��!");
	exit_label=new CLabel(53,16,8,5,1,1,1,LABEL,"ȷ��[enter]");

	//��ӿؼ�
	addControl(title);
	addControl(exit_label);
	addControl(exit_Button);//�ؼ������±�--1--�˳�

}
//��������
CTipsWin::~CTipsWin()
{

}
//��ȡ��ʾ��������--��ʾ����
string CTipsWin::getTitleType()
{
	return this->titleType;
}
//������ʾ��������--��ʾ����
void CTipsWin::setTitleType(string word)
{
	this->titleType=word;
}
//��д���ി�麯��
void CTipsWin::doAction()
{
	int i=this->getFocus();//��ȡ��ǰ�����½Ǳ�
	switch(i)
	{
	case 2://�˳����ó��ⴰ��   
		if(this->titleType=="����ɹ�" || this->titleType=="�����������ڿ��" || this->titleType=="������������" )//������ⴰ��
		{
			system("cls");//����
			CTool::paintBorder(16,13,60,16);//��Ʒ��Ϣ�߿�
			winArr[7]->CWindow_Show();
			winArr[7]->search(winArr[7]->get_Search_word());//��Ʒ����--��ӡ��������Ʒ����
			winArr[7]->winRun();
		}else if(this->titleType=="�̵����")//������ⴰ��
		{
			system("cls");//����
			CTool::paintBorder(16,13,60,16);//��Ʒ��Ϣ�߿�
			winArr[9]->CWindow_Show();
			winArr[9]->search(winArr[9]->get_Search_word());//��Ʒ����--��ӡ��������Ʒ����
			winArr[9]->winRun();
		}else if(this->titleType=="��������ȷ���--����")//������ⴰ��
		{
			system("cls");//����
			CTool::paintBorder(16,13,60,16);//��Ʒ��Ϣ�߿�
			winArr[7]->CWindow_Show();
			winArr[7]->search(winArr[9]->get_Search_word());//��Ʒ����--��ӡ��������Ʒ����
			winArr[7]->winRun();
		}
	
		else if(this->titleType=="���ɹ�")//������ⴰ��
		{
			system("cls");//����
			CTool::paintBorder(16,13,60,16);//��Ʒ��Ϣ�߿�
			winArr[12]->CWindow_Show();
			winArr[12]->search(winArr[12]->get_Search_word());//��Ʒ����--��ӡ��������Ʒ����
			winArr[12]->winRun();		
		}else if(this->titleType=="�����������")//������ⴰ��
		{
			system("cls");//����
			CTool::paintBorder(16,13,60,16);//��Ʒ��Ϣ�߿�
			winArr[12]->CWindow_Show();
			winArr[12]->search(winArr[12]->get_Search_word());//��Ʒ���--��ӡ��������Ʒ����
			winArr[12]->winRun();		
		}else if(this->titleType=="����������")//������Ʒ
		{
			system("cls");//����
			winArr[14]->CWindow_Show();
			winArr[14]->winRun();		
		}
		else if(this->titleType=="��Ʒ��ӳɹ�")//������Ʒ
		{
			system("cls");//����
			winArr[11]->CWindow_Show();//
			winArr[11]->winRun();		
		}
		else if(this->titleType=="�̵㱨��--�ѵ����һҳ")//������Ʒ
		{
			system("cls");//����
			winArr[10]->CWindow_Show();//
			page_current--;//����Ҫҳ����1
			CTool::prtinf_Table_Content(temp_list);//�ڴ�ӡ������ݲ���
			winArr[10]->winRun();		
		}
		else if(this->titleType=="�̵㱨��--�ѵ���һҳ")//������Ʒ
		{
			system("cls");//����
			winArr[10]->CWindow_Show();//
			page_current++;//����Ҫҳ����1
			CTool::prtinf_Table_Content(temp_list);//�ڴ�ӡ������ݲ���
			winArr[10]->winRun();		
		}
		else if(this->titleType=="������ҳ--�ѵ���һҳ")
		{
			system("cls");//����
			this->titleType="";
			winArr[5]->CWindow_Show();
			winArr[5]->winRun();
			
		}
		else if(this->titleType=="������ҳ--�ѵ����һҳ")
		{
			system("cls");//����
			this->titleType="";
			winArr[5]->CWindow_Show();
			winArr[5]->winRun();
			
		}
		else if(this->titleType=="������ҳ--δ�ҵ���Ʒ")
		{
			system("cls");//����
			this->titleType="";
			int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//����
			winArr[5]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->getArr(9)->setCount(1);
			winArr[5]->CWindow_Show();
			winArr[5]->winRun();
			
		}
		else if(this->titleType=="������ҳ--�ѵ���һҳ--ģ��")//�ص�������
		{
			int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//����
			this->titleType="";
			winArr[5]->getArr(9)->setPage(1);
			winArr[6]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->CWindow_Show();
			winArr[5]->winRun();
			
		}
		else if(this->titleType=="������ҳ--�ѵ����һҳ--ģ��")//�ص�������
		{
		int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//����
			this->titleType="";
			winArr[5]->getArr(9)->setPage(1);
			winArr[6]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->CWindow_Show();
			winArr[5]->winRun();
			
		}
		else if(this->titleType=="δ�ҵ���Ʒ--�½��̵�")
		{
			system("cls");//����
			this->titleType="";
			winArr[9]->CWindow_Show();
			CTool::paintBorder(16,13,60,16);//������Ʒ��Ϣ�߿�
			winArr[9]->winRun();
			
		}
		else if(this->titleType=="�̵���--����--�ѵ����һҳ")
		{
			system("cls");//�����õ�
			this->titleType="";
			page_current_2--;//����Ҫҳ����1
			winArr[17]->CWindow_Show();//�ص��̵���--����
			CTool::printf_Table_Order();//�̵��źͳ���״̬
			winArr[17]->winRun();
			
		}
		else if(this->titleType=="�̵���--����--�ѵ���һҳ")
		{
			system("cls");//�����õ�
			this->titleType="";
			page_current_2++;//����Ҫҳ����1
			winArr[17]->CWindow_Show();//�ص��̵���--����
			CTool::printf_Table_Order();//�̵��źͳ���״̬
			winArr[17]->winRun();
			
		}
		else if(this->titleType=="�����˳�ϵͳ")
		{
			system("cls");//����
			this->titleType="";
			winArr[0]->CWindow_Show();
			winArr[0]->winRun();
			
		}
		else if(this->titleType=="����Ϊ��--����")
		{
			system("cls");//����
			this->titleType="";
			winArr[17]->CWindow_Show();//����ѡ���̵㱾��Ž���
			CTool::printf_Table_Order();//�̵��źͳ���״̬
			winArr[17]->winRun();
			
		}
		else if(this->titleType=="7������--����--�ѵ����һҳ")
		{
			system("cls");//����
			this->titleType="";
			page_current_4--;//����Ҫҳ����1
			winArr[18]->CWindow_Show();//7������--��������
			CTool::printf_Table_Order_All();//��ӡ������Ϣ--7������
			winArr[18]->winRun();	
		}
		else if(this->titleType=="7������--����--�ѵ���һҳ")
		{
			system("cls");//����
			this->titleType="";
			page_current_4++;//����Ҫҳ����1
			winArr[18]->CWindow_Show();//7������--��������
			CTool::printf_Table_Order_All();//��ӡ������Ϣ--7������
			winArr[18]->winRun();	
		}
		else if(this->titleType=="����Ϊ��--����--7������")
		{
			system("cls");//����
			this->titleType="";
			winArr[18]->CWindow_Show();//7������--��������
			CTool::printf_Table_Order_All();//��ӡ������Ϣ--7������
			winArr[18]->winRun();	
		}
		else if(this->titleType=="�˳�ϵͳ--��ʼ����")
		{
			system("cls");//����
			exit(0);	
		}
		else if(this->titleType=="�������--�˺��������")
		{
			system("cls");//����
			winArr[2]->CWindow_Show();//�ص��������
			winArr[2]->winRun();	
		}
		else if(this->titleType=="�������--δ�ҵ��û�")
		{
			system("cls");//����
			winArr[2]->CWindow_Show();//�ص��������
			winArr[2]->winRun();	
		}
		else if(this->titleType=="�������--�˺Ż����벻��Ϊ��")
		{
			system("cls");//����
			winArr[2]->CWindow_Show();//�ص��������
			winArr[2]->winRun();	
		}
		else if(this->titleType=="ע�����--��ѡ��ע������")
		{
			system("cls");//����
			winArr[1]->CWindow_Show();//�ص�ѡ��ע�����
			winArr[1]->winRun();	
		}
		else if(this->titleType=="��ѯ��ϢΪ��--������Ʒ")
		{
			int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//����
			winArr[5]->getArr(1)->setTextConcent("��ӭ:"+user_name);
			winArr[5]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->getArr(9)->setCount(1);
			winArr[5]->CWindow_Show();//�����ѯ����
			winArr[5]->winRun();	
		}
		else if(this->titleType=="�뾫ȷ����--������Ʒ")
		{
			int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//����
			winArr[5]->getArr(1)->setTextConcent("��ӭ:"+user_name);
			winArr[5]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->getArr(9)->setCount(1);
			winArr[5]->CWindow_Show();//�����ѯ����
			winArr[5]->winRun();	
		}
		else if(this->titleType=="���ڵ�����Ʒ--������Ʒ")
		{
			int pageMax;
			if(mymap_goods.size()%5==0)
			{
				pageMax	=mymap_goods.size()/5;
			}else
			{
				pageMax	=mymap_goods.size()/5+1;
			}
			system("cls");//����
			winArr[5]->getArr(1)->setTextConcent("��ӭ:"+user_name);
			winArr[5]->getArr(9)->setPage(1);
			winArr[5]->getArr(9)->setPage_Max(pageMax);
			winArr[5]->getArr(9)->setCount(1);
			winArr[5]->CWindow_Show();//�����ѯ����
			winArr[5]->winRun();	
		}
		break;
	}
}
