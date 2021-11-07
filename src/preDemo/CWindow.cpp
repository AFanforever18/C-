#include "CWindow.h"
//#include "CLogin.h"
//Ĭ�Ϲ��캯��
CWindow::CWindow()//ע��С������
{
	this->count=0;//�ؼ���һ��ʼΪ0
	this->focus=0;//enter�����±�һ��ʼΪ0
	this->num=0;;
	for(int i=0;i<sizeof(arr)/sizeof(CControl *);i++)
	{
		arr[i]=NULL;
	}
}
//Ĭ����������
CWindow::~CWindow()
{
	
}
//���ι��캯��
CWindow::CWindow(int x,int y,int width,int height)
{
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	this->count=0;//�ؼ���һ��ʼΪ0
	this->focus=0;//enter�����±�һ��ʼΪ0
	this->num=0;
	for(int i=0;i<sizeof(arr)/sizeof(CControl *);i++)
	{
		arr[i]=NULL;
	}
	this->type="";//��������
}
//��ȡ�ؼ���
int CWindow::getCount()
{
	return count;
}
//���ӿؼ�
void CWindow::addControl(CControl *con)
{
	arr[this->count]=con;
	this->count++;
}
//������
void CWindow::CWindow_Show()
{
	//������--�ָ���
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),4);
	//����߿�
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),this->getHeight());
	for(int i=0;i<this->count;i++)
	{
		arr[i]->Control_Show();
	}
}
//������--ģ����ѯ
void CWindow::CWindow_Table_Show()
{
	arr[4]->setContent_Fuzzy_Table(fuzzy_word);	
	//������--�ָ���
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),4);
	//����߿�
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),this->getHeight());
	for(int i=0;i<this->count;i++)
	{
		if(arr[i]->getContent()=="��ѯ")
		{	
			arr[i]->Control_Table_Show();
		}else{
			arr[i]->Control_Show();
		}

	}
}
//������--ѡ���û����ʹ���
void CWindow::CWindow_Show_Select()
{
	CTool::paintBorder(this->x,this->y,this->width,this->height);
	for(int i=0;i<this->count;i++)
	{
			arr[i]->Control_Show();
	}	
}
//��ȡx����
int CWindow::getX()
{	
	return this->x;
}
//��ȡy����
int CWindow::getY()
{
	return this->y;
}
//��ȡ��
int CWindow::getWidth()
{
	return this->width;
}
//��ȡ��
int CWindow::getHeight()
{
	return this->height;
}
//��ȡenter�����±�
int CWindow::getFocus()
{
	return this->focus;
}
//��ȡnum
int CWindow::getNum()
{
	return this->num;	
}
//��ȡ�ؼ�����
CControl* CWindow::getArr(int x)
{
	return this->arr[x];
}
//����ƶ�
void CWindow::winRun()
{
	int ikey=0;
	int i;//��ǰ�ؼ�����λ��
	for(i=0;i<this->count;i++)//�����ҵ�edit ��button
	{
		if(this->arr[i]->getType()==EDIT || this->arr[i]->getType()==BUTTON)
		{
			break;
		}
	}
	//��λ�����ʼλ��
	if(this->arr[i]->getType()==EDIT)
	{
		CTool::gotoxy(this->arr[i]->getX()+2+this->arr[i]->getContent().size(),this->arr[i]->getY()+1);//EDIT
	}
	else{
		CTool::gotoxy(this->arr[i]->getX()+2,this->arr[i]->getY()+1);//BUTTON
	}
	while(1)//
	{
		//��ȡ��ǰedit���ݳ���
		int len=0;
		ikey=CTool::Key();

		switch(ikey)
		{
		case -4://����
			if(this->getCount()<7)//�����������淭ҳ
				break;
			//*********�̵㱨��--�ҷ�ҳ**********//
			if(this->arr[6]->getContent()=="�����̵�")
			{
				page_current++;
				int page_max;
				if(temp_list.size()%5==0)//�õ����ҳ��
				{
					page_max=temp_list.size()/5;
				}else
				{
					page_max=temp_list.size()/5+1;
				}
				if(page_current>page_max)
				{
					winArr[8]->getArr(0)->setTitle("�ѵ����һҳ!");//������ʾ��Ϣ
					winArr[8]->setTitleType("�̵㱨��--�ѵ����һҳ");//������ʾ��������
					CTool::clear(52,16,20,8);//�ֲ�ˢ��
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::prtinf_Table_Content(temp_list);//��ӡ�̵㱨��
			}
			//*********����--ѡ������--�ҷ�ҳ**********//
			if(this->arr[4]->getContent()=="�̵���")
			{
				page_current_2++;
				int page_max;
				if(mymap_order_num.size()%7==0)//�õ����ҳ��
				{
					page_max=mymap_order_num.size()/7;
				}else
				{
					page_max=mymap_order_num.size()/7+1;
				}
				if(page_current_2>page_max)
				{
					winArr[8]->getArr(0)->setTitle("�ѵ����һҳ!");//������ʾ��Ϣ
					winArr[8]->setTitleType("�̵���--����--�ѵ����һҳ");//������ʾ��������
					CTool::clear(52,16,20,8);//�ֲ�ˢ��
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::printf_Table_Order();//��ӡ�̵��źͳ���״̬
			}
			//*********����--7������-�ҷ�ҳ**********//
			if(this->arr[5]->getContent()=="��ɳ���")
			{
				page_current_4++;
				int page_max;
				if(map_check.size()%6==0)//�õ����ҳ��
				{
					page_max=map_check.size()/6;
				}else
				{
					page_max=map_check.size()/6+1;
				}
				if(page_current_4>page_max)
				{
					winArr[8]->getArr(0)->setTitle("�ѵ����һҳ!");//������ʾ��Ϣ
					winArr[8]->setTitleType("7������--����--�ѵ����һҳ");//������ʾ��������
					CTool::clear(52,16,20,8);//�ֲ�ˢ��
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::printf_Table_Order_All();//��ӡ������Ϣ--7������
			}
			//*********����--�ҷ�ҳ**********//
			if(this->arr[5]->getContent()=="��ѯ" && this->arr[9]->getCount()==1)
			{
				this->arr[9]->setPage(this->arr[9]->getPage()+1);//����ҳ��+1
				if(this->arr[9]->getPage()>this->arr[9]->getPageMax() )//���ҳ��λ=ΪpageMax �������ҷ�ҳ
				{
					this->arr[9]->setPage(this->arr[9]->getPage()-1);//����ҳ��+1
					winArr[8]->getArr(0)->setTitle("�ѵ����һҳ!");//������ʾ��Ϣ
					winArr[8]->setTitleType("������ҳ--�ѵ����һҳ");//������ʾ��������
					CTool::clear(52,16,20,8);//�ֲ�ˢ��
					winArr[8]->CWindow_Show();//��ʾ����
					winArr[8]->winRun(); 		
				}else{
					winArr[5]->CWindow_Show();//��ҳ
				}
			}
			//*********ģ������--�ҷ�ҳ**********//
			if(this->arr[5]->getContent()=="��ѯ" && this->arr[9]->getCount()==666)
			{
				this->arr[9]->setPage(this->arr[9]->getPage()+1);//����ҳ��+1
				if(this->arr[9]->getPage()>this->arr[9]->getPageMax())//���ҳ��λ=ΪpageMax �������ҷ�ҳ
				{
					this->arr[9]->setPage(this->arr[9]->getPage()-1);
					winArr[8]->getArr(0)->setTitle("�����һҳ,����ҳ!");//������ʾ��Ϣ
					winArr[8]->setTitleType("������ҳ--�ѵ����һҳ--ģ��");//������ʾ��������
					CTool::clear(52,16,20,8);//�ֲ�ˢ��
					winArr[8]->CWindow_Show();//��ʾ����
					winArr[8]->winRun(); 		
				}else{
					winArr[6]->CWindow_Table_Show();//ģ��
				}
			}
			break;

		case -2: //����    ����BUTTON ��EDIT �в�ͬ�Ĺ�궨λ
			i++;
			if(i>=this->count)//�ؼ����Ϊ���һ��,�������¼�,��������һ���ؼ�
			{
				i=0;
			}
			while(this->arr[i]->getType()==LABEL)//����LABELֱ������
			{
				i++;
			if(i>=this->count)//�ؼ����Ϊ���һ��,�������¼�,��������һ���ؼ�
			{
				i=0;
			}
			}
			if(this->arr[i]->getType()==EDIT)
			{
				len=arr[i]->getContent().length();
				if(len>0)
				{
					CTool::gotoxy(this->arr[i]->getX()+2+len,this->arr[i]->getY()+1);//���λ�� x ����Ҫ�������ݳ���				
				}else
				{
					CTool::gotoxy(this->arr[i]->getX()+2,this->arr[i]->getY()+1);//len<=0 ���øı�
				}
			}else//BUTTON �ؼ�
			{
				CTool::gotoxy(this->arr[i]->getX()+2,this->arr[i]->getY()+1);//BUTTON��궨λ
			}
			break;
		case -3://����
			if(this->getCount()<7)//�����������淭ҳ
				break;

			//*********�̵㱨��--��ҳ**********//
			if(this->arr[6]->getContent()=="�����̵�")
			{
				page_current--;
				int page_max;
				if(temp_list.size()%5==0)//�õ����ҳ��
				{
					page_max=temp_list.size()/5;
				}else
				{
					page_max=temp_list.size()/5+1;
				}
				if(page_current<1)//ҳ��С��1
				{
					winArr[8]->getArr(0)->setTitle("�ѵ���һҳ!");//������ʾ��Ϣ
					winArr[8]->setTitleType("�̵㱨��--�ѵ���һҳ");//������ʾ��������
					CTool::clear(52,16,20,8);//�ֲ�ˢ��
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::prtinf_Table_Content(temp_list);//��ӡ�̵㱨��
			}
			//*********--����--ѡ������--��ҳ**********//
			if(this->arr[4]->getContent()=="�̵���")
			{
				page_current_2--;	
				int page_max;
				if(mymap_order_num.size()%7==0)//�õ����ҳ��
				{
					page_max=mymap_order_num.size()/7;
				}else
				{
					page_max=mymap_order_num.size()/7+1;
				}
			
				if(page_current_2<1)//ҳ��С��1
				{
					winArr[8]->getArr(0)->setTitle("�ѵ���һҳ!");//������ʾ��Ϣ
					winArr[8]->setTitleType("�̵���--����--�ѵ���һҳ");//������ʾ��������
					CTool::clear(52,16,20,8);//�ֲ�ˢ��
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::printf_Table_Order();//��ӡ�̵㱨��
			}
			//*********--����--7������--��ҳ**********//
			if(this->arr[5]->getContent()=="��ɳ���")
			{
				page_current_4--;	
				int page_max;
				if(mymap_order_num.size()%6==0)//�õ����ҳ��
				{
					page_max=mymap_order_num.size()/6;
				}else
				{
					page_max=mymap_order_num.size()/6+1;
				}
			
				if(page_current_4<1)//ҳ��С��1
				{
					winArr[8]->getArr(0)->setTitle("�ѵ���һҳ!");//������ʾ��Ϣ
					winArr[8]->setTitleType("7������--����--�ѵ���һҳ");//������ʾ��������
					CTool::clear(52,16,20,8);//�ֲ�ˢ��
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::printf_Table_Order_All();//��ӡ������Ϣ--7������
			}
			
			//*********����--��ҳ**********//
			if(this->arr[5]->getContent()=="��ѯ" && this->arr[9]->getCount()==1)
			{
				this->arr[9]->setPage(this->arr[9]->getPage()-1);//����ҳ��-1
				if(this->arr[9]->getPage()<1)//���ҳ��λ=ΪpageMax �������ҷ�ҳ
				{
					this->arr[9]->setPage(this->arr[9]->getPage()+1);//����ҳ��+1
					winArr[8]->getArr(0)->setTitle("�ѵ���һҳ!");//������ʾ��Ϣ
					winArr[8]->setTitleType("������ҳ--�ѵ���һҳ");//������ʾ��������
					CTool::clear(52,16,20,8);//�ֲ�ˢ��
					winArr[8]->CWindow_Show();//��ʾ����
					winArr[8]->winRun(); 		
				}else{
					winArr[5]->CWindow_Show();//��ҳ
				}
			}
			//*********ģ������--��ҳ**********//
			if(this->arr[5]->getContent()=="��ѯ" && this->arr[9]->getCount()==666)
			{
				this->arr[9]->setPage(this->arr[9]->getPage()-1);//����ҳ��-1
				if(this->arr[9]->getPage()<1)//���ҳ��λ=ΪpageMax �������ҷ�ҳ
				{
					this->arr[9]->setPage(this->arr[9]->getPage()+1);//����ҳ��+1
					winArr[8]->getArr(0)->setTitle("�ѵ���һҳ,����ҳ!");//������ʾ��Ϣ
					winArr[8]->setTitleType("������ҳ--�ѵ���һҳ--ģ��");//������ʾ��������
					CTool::clear(52,16,20,8);//�ֲ�ˢ��
					winArr[8]->CWindow_Show();//��ʾ����
					winArr[8]->winRun(); 		
				}else{
					winArr[6]->CWindow_Table_Show();//ģ��
				}
			}

			break;
		case -1: //����

			i--;
			if(i<=-1)//�ؼ����Ϊ��һ��,�������ϼ�,���������һ���ؼ�
			{
				i=this->count-1;
			}else
			{
				while(this->arr[i]->getType()==LABEL)
				{
					i--;
					if(i<=-1)
					{
						i=this->count-1;
					}
				}
			}
				if(this->arr[i]->getType()==EDIT)
			{
				len=arr[i]->getContent().length();
				if(len>0)
				{
					CTool::gotoxy(this->arr[i]->getX()+2+len,this->arr[i]->getY()+1);//���λ�� x ����Ҫ�������ݳ���				
				}else
				{
					CTool::gotoxy(this->arr[i]->getX()+2,this->arr[i]->getY()+1);//len<=0 ���øı�
				}
			}else//BUTTON �ؼ�
			{
				CTool::gotoxy(this->arr[i]->getX()+2,this->arr[i]->getY()+1);//BUTTON��궨λ
			}
			break;
		case '\r'://�س�

			//ҳ����ת
			if(this->arr[i]->getType()==BUTTON)
			{
				if(this->arr[i]->getContent()=="[Enter]ѡ������")
				{
						winArr2[0]->CWindow_Show_Select();
						winArr2[0]->winRun();
				}
				if(this->arr[i]->getContent()=="�̵�Ա")
				{
					system("cls");
						winArr2[1]->CWindow_Show();
						winArr2[1]->winRun();

				}
				if(this->arr[i]->getContent()=="�ֿ����Ա")
				{
					system("cls");
						winArr2[2]->CWindow_Show();
						winArr2[2]->winRun();
				}
				this->focus=i;
				this->doAction();
			}
			
			break;
			 if(this->arr[i]->getType()==BUTTON && this->arr[i]->getContent()=="ȡ��")
		//	reg(win);
			break;
		case 27://ESC�˳�
			//ѧ��--��ʾ�½ű�
			CTool::gotoxy(this->getX()+this->getWidth()-60,this->getY()+this->getHeight()-3);
			system("pause");
			system("cls");
			winArr[0]->CWindow_Show();
			winArr[0]->winRun();
			break;
		default://�����������Ҽ�
			if(this->arr[i]->getType()==EDIT)
			{
				arr[i]->gbl_putstring(arr[i], ikey);
			}
		}
	}
}
//���ؼ�
void CWindow::change(CControl* con,int i)
{
	this->arr[i]=con;
}
void CWindow::search(string word)//��ѯ��ӡ��Ʒ��Ϣ--���ⴰ��
{
	
}
//��ȡ�������Ʒ����--���ⴰ��  �̵㴰��
string CWindow::get_Search_word()
{
   return "s";
}
//��ȡ�����δ��ѯ������Ʒ����--���ⴰ��  �̵㴰��
string CWindow::get_search_null()
{
   return "s";
}
//��ȡ����ĳ�������--���ⴰ��
int CWindow::get_input_Goods_Num()
{
	return 0;
}
//��ȡ��ʾ��������--��ʾ����
string CWindow::getTitleType()
{
	string a="δ����";
	return a;
}
//������ʾ��������--��ʾ����
void CWindow::setTitleType(string word)
{
	
}
//��ȡ������̵�����--�̵㴰��
string CWindow::get_Order_num()
{
	return "0";
}//��ȡ�̵���--�̵㱨��
string CWindow::get_makeOrder_Num()
{
	return "0";
}
int CWindow::fuzzyQuery()//ģ����ѯ
{
	int a=0;
	return a;
}