#include "CEdit.h"
//Ĭ�Ϲ���
CEdit::CEdit()
{
	
}
//���ι���--��������๹�촫��
CEdit::CEdit(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content):CControl(x,y,width,height,length,state,intputtype,type,content)
{
	
}
//����
CEdit::~CEdit()
{
	
}
//
CEdit::doAction()
{
	
}
//�ؼ�չʾ
void CEdit::Control_Show()
{
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),this->getHeight());//�����ؼ��߿�
	CTool::gotoxy(this->getX()+2,this->getY()+1);//����ƶ�������λ��
	cout<<this->getContent()<<endl;//�������
}
/*
	������: gbl_putstring
	��������: ����
	��������:	CONTROL* con �ؼ�
				int ikey 
	����ֵ : ��   

*/
void CEdit::gbl_putstring(CControl* con,int ikey)
{
	//����content�ڵ����ݳ���
	int count=con->getContent().length();

	//��������--��ɾ
	if(count==con->getLength())
	{
		if(ikey=='\b')//��ɾ
		{
			count--;
			con->delContent();
			printf("\b \b");
		}
	}else//����δ��
	{
		//1 ��ĸ  2 ����  3 ��ĸ+���� 4 ����+"."
		if(con->getIntputtype()==1)//1 ��ĸ
		{
			if(ikey>='a' && ikey<='z' || ikey>='A' && ikey<='Z')
			{
				switch(con->getState())//1���� 2����
				{
				case 1: 
					con->setContent(ikey);
					count++;
					//	cout<<count;
					putch(ikey);
				//	CTool::gotoxy(this->getX()+2+count,this->getY()+1);//����Ƶ��������ݺ�
					break;
				case 2: 
					con->setContent(ikey);
					printf("*");
					break;
				}
			}else//����δ��--��ɾ
			{	
				
				if(ikey=='\b' && count>0)
				{
					count--;
					con->delContent();
					printf("\b \b");
				}
			}
		}
		if(con->getIntputtype()==3)//3 ��ĸ+����
		{
			if(ikey>='a' && ikey<='z' || ikey>='A' && ikey<='Z' ||ikey>='0' && ikey<='9')
			{
				switch(con->getState())//1���� 2����
				{
				case 1: 
					con->setContent(ikey);
					count++;
					//	cout<<count;
					putch(ikey);
					//	CTool::gotoxy(this->getX()+2+count,this->getY()+1);//����Ƶ��������ݺ�
					break;
				case 2: 
					con->setContent(ikey);
					printf("*");
					break;
				}
			}else//����δ��--��ɾ
			{	
				
				if(ikey=='\b' && count>0)
				{
					count--;
					con->delContent();
					printf("\b \b");
				}
			}
		}

		if(con->getIntputtype()==4)//����+"."
		{
			if(ikey>='0' && ikey<='9' || ikey=='.')
			{
				switch(con->getState())//1���� 2����
				{
				case 1: 
					con->setContent(ikey);
					count++;
					//	cout<<count;
					putch(ikey);
					//	CTool::gotoxy(this->getX()+2+count,this->getY()+1);//����Ƶ��������ݺ�
					break;
				case 2: 
					con->setContent(ikey);
					printf("*");
					break;
				}
			}else//����δ��--��ɾ
			{	
				
				if(ikey=='\b' && count>0)
				{
					count--;
					con->delContent();
					printf("\b \b");
				}
			}
		}

		else if(con->getIntputtype()==2)//2 ����
		{
			if(ikey>='0' && ikey<='9')
			{
				switch(con->getState())//1���� 2����
				{
				case 1: 
					con->setContent(ikey);
					count++;
					putch(ikey);
					CTool::gotoxy(this->getX()+2+count,this->getY()+1);//����Ƶ��������ݺ�
					break;
				case 2: 
					con->setContent(ikey);
					printf("*");
					break;
				}
			}else//����δ��--��ɾ
			{
				if(ikey=='\b' && count>0)
				{
					count--;
					con->delContent();
					printf("\b \b");
				}
			}
		}

//--------------

//-------------

	}
}
