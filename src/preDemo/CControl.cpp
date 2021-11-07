#include "CControl.h"
//Ĭ�Ϲ��캯��
CControl::CControl()
{
	
}
//��������������
CControl::CControl(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content)
{
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	this->length=length;//©д
	this->state=state;
	this->intputtype=intputtype;
	this->type=type;
	this->content=content;
	this->page=1;//��ǰҳ��Ϊ1
	this->count=1;//Ĭ����ͨ��ҳ
	int page_Num=mymap_goods.size();
	if(page_Num%6==0)//һҳ����
	{
		page_Num=page_Num/6;
	}else
	{
		page_Num=page_Num/6+1;
	}
	this->page_Max=page_Num;
}
//��������
CControl::~CControl()
{
	
}
//��ȡx����
int CControl::getX()
{
	return this->x;
}
//��ȡy����
int CControl::getY()
{
	return this->y;
}
//��ȡ���
int CControl::getWidth()
{
	return this->width;
}
//��ȡ�߶�
int CControl::getHeight()
{
	return this->height;
}
//��ȡ��󳤶�
int CControl::getLength()
{
	return this->length;
}
//��ȡ��ʾ״̬
int CControl::getState()
{
	return this->state;
}
//�������
int CControl::getIntputtype()
{
	return this->intputtype;
}
//�ؼ�����
int CControl::getType()
{
	return this->type;
}
//��ȡҳ��
int CControl::getPage()
{
	return this->page;
}
//��ȡ���ҳ��
int CControl::getPageMax()
{
	return this->page_Max;
}
//��ȡcount
int CControl::getCount()
{
	return this->count;
}
//��ȡ�ı�����
string CControl::getContent()
{
	return this->content;
}
//���ķ�ҳ 0-left 1--right
void CControl::setCount(int x)
{
	this->count=x;//����ҳ
}
//��ҳ��
void CControl::setPage(int page)
{
	this->page=page;
}
//�����ҳ��--ģ����ѯʹ��
void  CControl::setPage_Max(int page)
{
	this->page_Max=page;
}
//����Ϊ�ı�����
void CControl::setContent(int ikey)
{
	
	if(ikey=='\b')//ɾ��
	{
		content.erase(content.end() -1);//�����һ������ɾ��
		content.append("a");

	}
	else 
	{
		if(ikey!='\b')
		{
			char a=char(ikey);
			string str;
			str=a;
			content.append(str);
			//	content.erase(content.end() -1);//�����һ������ɾ��
		}

	}

		
}
//ģ����ѯ
void CControl::setContent_Fuzzy_Table(string word)
{
	this->content=word;
}
//�ı������ÿ�--ҳ����ת��
void CControl::setContentNull()
{
	content="";
}
//�˺ſؼ��ı����ݸ���--�˺�����--ע����
void CControl::changeAccount(int num)
{
	map<int,CUser>::iterator iter;
	iter=mymap.end();
	//ע����ڶ�һ���ļ� ����д��map
	mymap.erase(mymap.begin(),mymap.end());//��������ٶ�һ��
	CFile::userFileRead();
	if(iter!=mymap.begin() || mymap.size()==1)//�ļ���Ϊ��
	{
		
		iter--;//�ҵ����һ���˺�id
		//��string��Ϊint��
		string str=iter->second.getID();
		int temp=atoi(str.c_str());
		if(num==1)
		{
			gbl_accountNum++;//��ȫ�ֱ���		
		}
		temp++;
		// temp=temp;//��ȫ�ֱ���
		stringstream ss;
		string account_str;
		ss<<gbl_accountNum;//int->ss
		ss>>account_str;//ss->string
		content=account_str;
	}else//���ļ�
	{
		content="1002";
		gbl_accountNum++;
	}
}
//ɾ��--��ɾ����
void CControl::delContent()
{
	content.erase(content.end() -1);//�����һ������ɾ��
}
//�麯��--�༭������
void CControl::gbl_putstring(CControl* con,int ikey)
{
	
}
void CControl::sss()
{
	
}
//ģ����ѯ
void CControl::Control_Table_Show()
{

}
//������ʾ������ʾ����
void CControl::setTitle(string newTitle)
{
	this->content=newTitle;
}
//�����ı�����
void CControl::setTextConcent(string word)
{
	this->content=word;
}