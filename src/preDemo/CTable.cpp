#include "CTable.h"
//Ĭ�Ϲ���
CTable::CTable()
{
	
}
//���ι���--��������๹�촫��
CTable::CTable(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content):CControl(x,y,width,height,length,state,intputtype,type,content)
{
	
}
//����
CTable::~CTable()
{
	
}
//

//�ؼ�չʾ
void CTable::Control_Show()
{
	int row=this->getWidth();//����Ϊ��
	int col=this->getHeight();//����Ϊ��
	row=row*2+1;//����
	int x_temp=this->getX();
	int y_temp=this->getY();
	int x=this->getX();
	int y=this->getY();
	for(int i=0;i<row;i++)
	{
		if(i==0)//��һ��
		{
			CTool::gotoxy(x,y-1);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"��������������";	
				}else
				cout<<"��������������";
			}
			cout<<endl;
		}else if(i==row-1)
		{
			CTool::gotoxy(x,y);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"��������������";	
				}else
					cout<<"��������������";
			}
			cout<<endl;
		}
		else if(i%2==1 && i!=row-1)
		{
			CTool::gotoxy(x,y++);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				cout<<"            ";
				cout<<"��";
			}
			cout<<endl;
		}else if(i%2==0 && i!=row-1)
		{
			CTool::gotoxy(x,y++);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"��������������";	
				}else
					cout<<"��������������";
			}
			cout<<endl;
		}
	}
	x=x-2;//���ı�����
	CTool::gotoxy(x+4,y_temp);//+x����+14
	cout<<"��Ʒ����";
	CTool::gotoxy(x+18,y_temp);
	cout<<"��Ʒ����";
	CTool::gotoxy(x+32,y_temp);
	cout<<"��Ʒ����";
	CTool::gotoxy(x+46,y_temp);
	cout<<"��Ʒ�۸�";
	CTool::gotoxy(x+60,y_temp);
	cout<<"�������";
	CTool::gotoxy(x+74,y_temp);
	cout<<"��λ���";
	CTool::gotoxy(x+88,y_temp);
	int rowsum=x_temp;
	int colsum=y_temp+1;
	map<string,CGoods>::iterator iter=mymap_goods.begin();
	int page_Num=mymap_goods.size();
	if(page_Num%5==0)//һҳ5��
	{
		page_Num=page_Num/5;
	}else
	{
		page_Num=page_Num/5+1;
	}
		advance(iter,(this->getPage()-1)*5);	
	//����ҳ��--��ҳ
	CTool::gotoxy(this->getX()+42,this->getY()+15);
	if(this->getPage()<=page_Num)
	{
		cout<<this->getPage();

	}else
	{
		cout<<this->getPageMax();	
	}
	for(int m=0;m<5;m++)// ��ӡ����
	{
		for(int n=0; n<6;n++)
		{
			CTool::gotoxy(rowsum+2,colsum+1);
			switch(n)
			{
			case 0:
				cout<<iter->second.getGoodsNum();//��ȡ��Ʒ���
				break;
			case 1:
				cout<<iter->second.getGoodsName();//��ȡ��Ʒ����
				break;
			case 2:
				cout<<iter->second.getGoodsType();//��ȡ��Ʒ����
				break;
			case 3:
				cout<<iter->second.getGoodsPrice();//��ȡ��Ʒ�۸�
				break;
			case 4:
				cout<<iter->second.getInventory();//��ȡ�������
				break;
			case 5:
				cout<<iter->second.getWarehouseNum();//��ȡ��λ���
				break;
			}
			rowsum=14+rowsum;
		}
		if(this->getCount()==1 || this->getCount()==0)//1--right
		{
			iter++;
			if(iter==mymap_goods.end())
			{
				return;
			}
		}

		rowsum=x_temp;
		colsum=2+colsum;

	}


}
//ģ����ѯ
void CTable::Control_Table_Show()
{	

	map<string,CGoods>temp_map;//������ʱmap�������ģ�����ҵ�����Ʒ����
	string word=fuzzy_word;//ģ����ѯ�ı��
	for(map<string,CGoods>::iterator iter=mymap_goods.begin();iter!=mymap_goods.end();iter++)//������Ʒ����
	{
		if(strstr(iter->first.c_str(),word.c_str())!=NULL)//�ҵ��Ͳ�����ʱ����
		{
			temp_map.insert(make_pair(iter->first,iter->second));  
		}
	}
	int temp_MaxPage;//ģ����ѯ���ҳ��
	//ȡ�����ҳ��
	if(temp_map.size()%5==0)
	{
		temp_MaxPage=temp_map.size()/5;
	}else
	{
		temp_MaxPage=temp_map.size()/5+1;	
	}
	this->setPage_Max(temp_MaxPage);//���ı�����ҳ��
	if(this->getPage()>this->getPageMax())//��ǰҳ�����ڵ������ҳ��
	{
		//����ҳ��--��ҳ
		CTool::gotoxy(this->getX()+42,this->getY()+15);
		if(this->getPage()<=this->getPageMax())
		{
			cout<<this->getPage();
			
		}else
		{
			cout<<this->getPageMax();	
		}

		return;
	}
	int row=this->getWidth();//����Ϊ��
	int col=this->getHeight();//����Ϊ��
	row=row*2+1;//����
	int x_temp=this->getX();
	int y_temp=this->getY();
	int x=this->getX();
	int y=this->getY();
	for(int i=0;i<row;i++)//�����
	{
		if(i==0)//��һ��
		{
			CTool::gotoxy(x,y-1);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"��������������";	
				}else
				cout<<"��������������";
			}
			cout<<endl;
		}else if(i==row-1)
		{
			CTool::gotoxy(x,y);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"��������������";	
				}else
					cout<<"��������������";
			}
			cout<<endl;
		}
		else if(i%2==1 && i!=row-1)
		{
			CTool::gotoxy(x,y++);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				cout<<"            ";
				cout<<"��";
			}
			cout<<endl;
		}else if(i%2==0 && i!=row-1)
		{
			CTool::gotoxy(x,y++);
			cout<<"��";
			for(int j=0;j<col;j++)
			{
				if(j==col-1)
				{
					cout<<"��������������";	
				}else
					cout<<"��������������";
			}
			cout<<endl;
		}
	}
	x=x-2;//���ı�����
	CTool::gotoxy(x+4,y_temp);//+x����+14
	cout<<"��Ʒ����";
	CTool::gotoxy(x+18,y_temp);
	cout<<"��Ʒ����";
	CTool::gotoxy(x+32,y_temp);
	cout<<"��Ʒ����";
	CTool::gotoxy(x+46,y_temp);
	cout<<"��Ʒ�۸�";
	CTool::gotoxy(x+60,y_temp);
	cout<<"�������";
	CTool::gotoxy(x+74,y_temp);
	cout<<"��λ���";
	CTool::gotoxy(x+88,y_temp);
	int rowsum=x_temp;
	int colsum=y_temp+1;
	//����ҳ��--��ҳ
	CTool::gotoxy(this->getX()+42,this->getY()+15);
	if(this->getPage()<=this->getPageMax())
	{
		cout<<this->getPage();

	}else
	{
		cout<<9 ;	
	}
	map<string,CGoods>::iterator temp_iter=temp_map.begin();
	if(this->getPage()<=this->getPageMax())
	{
		advance(temp_iter,(this->getPage()-1)*5);//�����ƶ�
	} 
	int count=this->getCount();//�жϵ��������޳���

	for(int m=0;m<5;m++)// ��ӡ����
	{
		for(int n=0; n<6;n++)
		{
			CTool::gotoxy(rowsum+2,colsum+1);
			switch(n)
			{
			case 0:
				cout<<temp_iter->second.getGoodsNum();//��ȡ��Ʒ���
				break;
			case 1:
				cout<<temp_iter->second.getGoodsName();//��ȡ��Ʒ����
				break;
			case 2:
				cout<<temp_iter->second.getGoodsType();//��ȡ��Ʒ����
				break;
			case 3:
				cout<<temp_iter->second.getGoodsPrice();//��ȡ��Ʒ�۸�
				break;
			case 4:
				cout<<temp_iter->second.getInventory();//��ȡ�������
				break;
			case 5:
				cout<<temp_iter->second.getWarehouseNum();//��ȡ��λ���
				break;
			}
			rowsum=14+rowsum;
		}

			temp_iter++;
			if(temp_iter==temp_map.end())
			{
				CTool::gotoxy(62,29);//��ӡ���ҳ��
				cout<<temp_MaxPage; 
				return;
			}
	

		rowsum=x_temp;
		colsum=2+colsum;

	}
	CTool::gotoxy(62,29);
	cout<<temp_MaxPage;
}