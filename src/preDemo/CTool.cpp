#include "CTool.h"
/*
	�� �� ��: ����л�
	��������: ����л�
	��������: int x, int y ��������
	�� �� ֵ: ��
*/
void CTool::gotoxy(int x,int y)//����л�
{
	HANDLE hOut;
	COORD pos= {x,y};
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void CTool::show()
{
cout<<"d";
}

/*
	������: ����
	��������: ����
	��������: int x, int y �������� width �� height ��
	����ֵ : ��    ��  ��   ��   ��    ��  ��
*/
void CTool::paintBorder(int startX, int startY,int width,int height)//��λ���λ�õ�ָ������
{   
	int i=0,j=0,preX,preY;
	preX=startX;
	preY=startY;
	//��һ��
	for(i=0;i<startX+width;i++)
	{
		//��궨λ
		gotoxy(startX,startY);
		if(preX==startX)//���Ͻ� ��һ��λ��
		{
			printf("��");
		}
		else if(startX==(preX+width))//���Ͻ�
		{
			printf("��");
			break;
		}
		else{
			printf("��");
		}
		startX+=2;
	}
	printf("\n");
	//���
	for(j=0;j<startY+height;j++)
	{
		startY+=1;
		//��궨λ
		gotoxy(preX,startY);
		if(startY==preY+height)
		{
			printf("��");
			break;

		}
		else//���½�
		{
			printf("��");
		}
	}
	printf("\n");
	//�ױ�
	startX=preX;//�ѳ�ʼֵ�ٸ�ֵ��startX
	for(i=0;i<preX+width;i++)
	{
		
		startX+=2;
		//��궨λ
		gotoxy(startX,startY);
		if(startX==preX+width)
		{
			printf("��");
			break;

		}
		 else if (startX<=preX+width)
		{
			printf("��");
		}
	}
	printf("\n");
	printf("\n");
	//�ұ�
	for(i=0;i<preX+width;i++)
	{
		startY-=1;
		//��궨λ
		gotoxy(startX,startY);
		if(preY==startY)
		{
			break;

		}
		else
		{
			printf("��");
		}
	}
	printf("\n");
	printf("\n");
} 
//��ȡ��ֵ
 int CTool::Key()
{
	int key=0;
	while(1)
	{
		key=getch();
		if(key==KEY_ESC)
		{
			return KEY_ESC;
		}
		else if(key==KEY_ENTER)
		{
			return KEY_ENTER;
		}
		else if(key==224 || key==-32)
		{
			key=getch();
			switch(key)
			{
				case 72: return KEY_UP;
				case 80: return KEY_DOWN;
				case 75: return KEY_LEFT;
				case 77: return KEY_RIGHT;
			}
		}
		else
		{
			return key;
		}
	}
}
//�̵㱨��--���ݴ�ӡ
 void CTool::prtinf_Table_Content(list<CGoods> goods_list)
 {
	int page_Num=goods_list.size();
	if(page_Num%5==0)//һҳ5��
	{
		page_Num=page_Num/5;
	}else
	{
		page_Num=page_Num/5+1;
	}
	CTool::gotoxy(56,29);
	string pagenum="   "+CTool::strtoInt(page_current)+"/"+CTool::strtoInt(page_Num)+"  ";
	cout<<pagenum;
	list<CGoods>::iterator iter=goods_list.begin();
	advance(iter,(page_current-1)*5);
	
	//��ӡ
	int rowsum=24;
	int colsum=14;
	int size;
	int b;//���ƿո�


	for(int m_1=0;m_1<5;m_1++)// ��ӡ�ո� ���ƾֲ�ˢ��
	{		
		CTool::gotoxy(rowsum+2,colsum+1);
		for(int n=0; n<5;n++)
		{				
			CTool::gotoxy(rowsum+2,colsum+1);
			for(b=0;b<12;b++)
			{
				cout<<" ";	
			}	
			rowsum=14+rowsum;
		}	
		rowsum=24;
		colsum=2+colsum;
	}
	
	rowsum=24;
	colsum=14;

	for(int m=0;m<5;m++)// ��ӡ����
	{

		for(int n=0; n<5;n++)
		{				
			CTool::gotoxy(rowsum+2,colsum+1);
			switch(n)
			{
			case 0:
				size=(*iter).getGoodsNum().size();
				cout<<(*iter).getGoodsNum();//��ȡ��Ʒ���
				break;
			case 1:
				size=(*iter).getGoodsName().size();
				cout<<(*iter).getGoodsName();//��ȡ��Ʒ����
				break;
			case 2:
				size=(*iter).getGoodsType().size();
				cout<<(*iter).getGoodsType();//��ȡ��Ʒ����
				break;
			case 3:
				size=(*iter).getGoodsPrice().size();
				cout<<(*iter).getGoodsPrice();//��ȡ��Ʒ�۸�
				break; 
			case 4:
				size=(*iter).getInventory().size();
				cout<<(*iter).getInventory();//��ȡ�������
				break;
			}
			for(b=0;b<12-size;b++)
			{
				cout<<" ";
			}
			rowsum=14+rowsum;
		}
		iter++;
		if(iter==goods_list.end())
		{
			return;
		}
		rowsum=24;
		colsum=2+colsum;
	}

 }
//int->string
string CTool::strtoInt(int val)
{
	 string str;
	 stringstream ss;
	 ss<<val;
	 ss>>str;
	 return str;
} 
//�ֲ���� 
void CTool::clear(int x,int y,int width,int height) //x,y--����   width,height--���
{
	for(int i=0;i<height;i++)
	{	
		CTool::gotoxy(x,y);
		for(int j=0;j<width;j++)//36Ϊ��Ӧ  16��Ӧ
		{
			cout<<" ";
		}	
		y++;
	}	
}
//�̵��źͳ���״̬--���ݴ�ӡ
void CTool::printf_Table_Order()
{
	int page_Num=mymap_order_num.size();
	if(page_Num%7==0)//һҳ7��
	{
		page_Num=page_Num/7;
	}else
	{
		page_Num=page_Num/7+1;
	}
	CTool::gotoxy(56,29);
	string pagenum="   "+CTool::strtoInt(page_current_2)+"/"+CTool::strtoInt(page_Num)+"  ";
	cout<<pagenum;
	map<string,string>::iterator iter=mymap_order_num.begin();
	advance(iter,(page_current_2-1)*7);
	
	//��ӡ
	int rowsum=40;
	int colsum=12;
	int size;
	int b;

	
	for(int m_1=0;m_1<7;m_1++)// ��ӡ�ո� ���ƾֲ�ˢ��
	{		
		CTool::gotoxy(rowsum+2,colsum+1);
		for(int n=0; n<2;n++)
		{				
			CTool::gotoxy(rowsum+2,colsum+1);
			for(b=0;b<6;b++)
			{
				cout<<"  ";	
			}	
			rowsum=20+rowsum;
		}	
		rowsum=40;
		colsum=2+colsum;
	}
	
	rowsum=40;
	colsum=12;

	CTool::gotoxy(42,11);
	cout<<"�̵���";
	CTool::gotoxy(62,11);
	cout<<"����״̬";
	for(int m=0;m<7;m++)// ��ӡ����
	{

		for(int n=0; n<2;n++)
		{				
			CTool::gotoxy(rowsum+2,colsum+1);
			switch(n)
			{
			case 0:
				size=iter->first.size();
				cout<<iter->first;//��ȡ�̵���
				break;
			case 1:
				size=iter->second.size();
				cout<<iter->second;//��ȡ����״̬
				break;
			}
			for(b=0;b<12-size;b++)
			{
				cout<<" ";
			}
			rowsum=20+rowsum;
		}
		iter++;
		if(iter==mymap_order_num.end())
		{
			return;
		}
		rowsum=40;
		colsum=2+colsum;
	}
	
}
//�̵������Ϣ--���ݴ�ӡ--7������
void CTool::printf_Table_Order_All()
{
// map_check;//������Ϣ����	


	int page_Num=map_check.size();
	if(page_Num%6==0)//һҳ6��
	{
		page_Num=page_Num/6;
	}else
	{
		page_Num=page_Num/6+1;
	}
	CTool::gotoxy(58,29);
	string pagenum="   "+CTool::strtoInt(page_current_4)+"/"+CTool::strtoInt(page_Num)+"  ";//ҳ��
	cout<<pagenum;
	map<string,CGoods>::iterator iter=map_check.begin();
	advance(iter,(page_current_4-1)*6);
	
	//��ӡ
	int rowsum=19;
	int colsum=13;
	int size;
	int b;//���ƿո�


	for(int m_1=0;m_1<6;m_1++)// ��ӡ�ո� ���ƾֲ�ˢ��
	{		
	//	CTool::gotoxy(rowsum+2,colsum+1);
		for(int n=0; n<7;n++)
		{				
			CTool::gotoxy(rowsum+1,colsum+1);
			for(b=0;b<8;b++)
			{
				cout<<" ";	
			}	
			rowsum=12+rowsum;
		}	
		rowsum=19;
		colsum=2+colsum;
	}
	CTool::gotoxy(20,12);cout<<"��Ʒ���";
	CTool::gotoxy(32,12);cout<<"��Ʒ����";
	CTool::gotoxy(44,12);cout<<"�������";
	CTool::gotoxy(56,12);cout<<"�̵�����";
	CTool::gotoxy(68,12);cout<<"��������";
	CTool::gotoxy(80,12);cout<<"��������";
	CTool::gotoxy(92,12);cout<<"����ԭ��";
	
	rowsum=18;
	colsum=13;
	for(int m=0;m<6;m++)// ��ӡ����
	{

		for(int n=0; n<7;n++)
		{				
			CTool::gotoxy(rowsum+2,colsum+1);
			switch(n)
			{
			case 0:
				size=iter->first.size();
				cout<<iter->first;//��ȡ��Ʒ���
				break;
			case 1:
				size=iter->second.getGoodsNum().size();
				cout<<iter->second.getGoodsNum();//��ȡ��Ʒ����
				break;
			case 2:
				size=iter->second.getGoodsName().size();
				cout<<iter->second.getGoodsName();//��ȡ�������
				break;
			case 3:
				size=iter->second.getGoodsType().size();
				cout<<iter->second.getGoodsType();//�̵���
				break;
			case 4:
				size=iter->second.getGoodsPrice().size();
				cout<<iter->second.getGoodsPrice();//������
				break; 
			case 5:
				size=iter->second.getInventory().size();
				cout<<iter->second.getInventory();//������
				break;
			case 6:
				size=iter->second.getInventory().size();
				cout<<iter->second.getWarehouseNum();//ԭ��	
				break;
			}
			for(b=0;b<6-size;b++)
			{
				cout<<" ";
			}
			rowsum=12+rowsum;
		}
		iter++;
		if(iter==map_check.end())
		{
			return;
		}
		rowsum=18;
		colsum=2+colsum;
	}



}
//�����ļ�
void CTool::file_opear()
{
	//Ŀ���ļ�·��
	string inPath="./data\\*";//�����ļ����µ������ļ�
	//���ڲ��Ҿ��
	long handle;
	struct _finddata_t fileinfo;
	//��һ�β���
	handle=_findfirst(inPath.c_str(),&fileinfo);
	string name;
	if(handle==-1)
	return;
	do
	{
		name=fileinfo.name;	
		if(name.size()<15)//�ҵ������̵���  С��14����������ļ��ý���
		{
			continue;
		}
		string str="δ����";
		name.erase(11,4);//ȥ��".txt"
		mymap_order_num.insert(make_pair(name,str));//�̵��źͳ���״̬��������
	//	cout<<name<<endl;
		name.erase(7,1);//ȥ��"-"
		//�ҵ����ļ����ļ���
		gbl_orderNUM=name;
	}
	while(!_findnext(handle,&fileinfo));
	_findclose(handle);
}