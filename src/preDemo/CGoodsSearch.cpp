#include "CGoodsSearch.h"
//Ĭ�Ϲ���
CGoodsSearchWin::CGoodsSearchWin()
{

}
//���ι���
CGoodsSearchWin::CGoodsSearchWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	string num="1/";
	stringstream ss;
	string num_2;
	int size=mymap_goods.size();
	while(size%5!=0)//��Ϊ5������
	{
		size++;	
	}
	ss<<size/5;
	ss>>num_2;
	num.append(num_2);//���ҳ��
	string str="��ӭʹ�òִ��̵��ϵͳ!";//��������
	//��ǩ
	//Ϊ�˱�ǩ�洰�ڴ�Сλ�ñ䶯
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);
	inputNum_label=new CLabel(this->getX()+2,this->getY()+7,20,2,1,1,0,LABEL,"��������Ʒ��ѯ�ı��:");
	tableNum_label=new CLabel(this->getX()+48,this->getY()+26,20,2,1,1,0,LABEL,num);

	//�༭��
	inputNum_edit=new CEdit(this->getX()+28,this->getY()+7,46,2,10,1,3,EDIT,"");

	//��ť
	find_Btn=new CButton(this->getX()+76,this->getY()+7,10,2,1,1,0,BUTTON,"��ѯ");
	import_Btn=new CButton(this->getX()+4,this->getY()+24,18,2,1,1,0,BUTTON,"������Ʒ��Ϣ");
	myexit=new CButton(this->getX()+76,this->getY()+24,18,2,1,1,0,BUTTON,"����[Esc]");

	//���
	table=new CTable(this->getX()+8,this->getY()+12,6,6,1,1,0,LABEL,"��ѯ");	
	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(inputNum_label);
	addControl(inputNum_edit);//��Ʒ��ѯ�༭��--4
	addControl(find_Btn);//��Ʒ��ѯ��ť--5
	addControl(import_Btn);//������Ʒ��Ϣ--6
	addControl(myexit);//�˳�--7
	addControl(tableNum_label);//��ҳ�ű�
	addControl(table);//���--9



}

//Ĭ�Ϲ���
CGoodsSearchWin::~CGoodsSearchWin()
{
	
}
//��ȷ��ѯ--����ֵ�ж��Ƿ����ģ����ѯ
int CGoodsSearchWin::accurateQuery()
{
	int rowsum=18;
	int colsum=15;
	int m,n,b;
	int size;//��Ҫ���ǵĳ���Ϊ13�� �ı����ȼ�" "����Ϊ13
	map<string,CGoods>::iterator iter;//����find����ֵ--��ȷ
	iter=mymap_goods.find(this->inputNum_edit->getContent());
	if(iter==mymap_goods.end())
	{
		return 1;
	}
	this->table->setCount(-1);//��ȷ��ѯ���ɷ�ҳ-1
	for(m=0;m<5;m++)// ��ӡ����
	{
		for(n=0; n<6;n++)
		{	
			CTool::gotoxy(rowsum+2,colsum+1);
			if(m==0)
			{
				switch(n)
				{
				case 0:
					size=iter->second.getGoodsNum().size();
					cout<<iter->second.getGoodsNum();
					break;
				case 1:
					size=iter->second.getGoodsName().size();
					cout<<iter->second.getGoodsName();
					break;
				case 2:
					size=iter->second.getGoodsType().size();
					cout<<iter->second.getGoodsType();
					break;
				case 3:
					size=iter->second.getGoodsPrice().size();
					cout<<iter->second.getGoodsPrice();
					break;
				case 4:
					size=iter->second.getInventory().size();
					cout<<iter->second.getInventory();
					break;
				case 5:
					size=iter->second.getWarehouseNum().size();
					cout<<iter->second.getWarehouseNum();
					break;
				}
				for(b=0;b<12-size;b++)
				{
					cout<<" ";
				}
			}else
				for(b=0;b<12;b++)//12�ո�
				{
					cout<<" ";
				}
				rowsum=14+rowsum;
		}
		rowsum=18;
		colsum=2+colsum;
	}
	CTool::gotoxy(60,29);
	cout<<"1/1";//���ɷ�ҳ,ҳ�����ܸı�
	CTool::gotoxy(this->getX()+76+2,this->getY()+7+1);
	return 0;
}
//ģ����ѯ--���Һ��йؼ��ֵ���Ʒ����
int CGoodsSearchWin::fuzzyQuery()
{	
	map<string,CGoods>temp_map;//������ʱmap�������ģ�����ҵ�����Ʒ����
	string word=this->inputNum_edit->getContent();//����ı��
	for(map<string,CGoods>::iterator iter=mymap_goods.begin();iter!=mymap_goods.end();iter++)//������Ʒ����
	{
		if(strstr(iter->first.c_str(),word.c_str())!=NULL)//�ҵ��Ͳ�����ʱ����
		{
			temp_map.insert(make_pair(iter->first,iter->second));  
		}
	}
	int temp_MaxPage;//ģ����ѯ���ҳ��
	//ȡ�����ҳ��
	if(temp_map.size()%6==0)
	{
		temp_MaxPage=temp_map.size()/5;
	}else
	{
		temp_MaxPage=temp_map.size()/5+1;	
	}



	this->table->setPage_Max(temp_MaxPage);//���ı�����ҳ��
	if(this->table->getPage()>this->table->getPageMax())//��ǰҳ�����ڵ������ҳ��
	{
		//����ҳ��--��ҳ
		CTool::gotoxy(this->table->getX()+42,this->table->getY()+15);
		if(this->table->getPage()<=this->table->getPageMax())
		{
			cout<<this->table->getPage();
			
		}else
		{
			cout<<this->table->getPageMax();	
		}
			if(temp_map.size()==0)
	{
		winArr[8]->getArr(0)->setTitle("δ�ҵ���Ʒ!");//������ʾ��Ϣ
		winArr[8]->setTitleType("������ҳ--δ�ҵ���Ʒ");//������ʾ��������
		CTool::clear(52,16,20,8);//�ֲ�ˢ��
		winArr[8]->CWindow_Show();//��ʾ����
		winArr[8]->winRun(); 
	}

	}
	int row=this->table->getWidth();//����Ϊ��
	int col=this->table->getHeight();//����Ϊ��
	row=row*2+1;//����
	int x_temp=this->table->getX();
	int y_temp=this->table->getY();
	int x=this->table->getX();
	int y=this->table->getY();
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
	CTool::gotoxy(this->table->getX()+42,this->table->getY()+15);
	if(this->table->getPage()<=this->table->getPageMax())
	{
		cout<<this->table->getPage();

	}else
	{
		cout<<this->table->getPageMax();	
	}
	map<string,CGoods>::iterator temp_iter=temp_map.begin();
	if(this->table->getPage()<=this->table->getPageMax())
	{
		advance(temp_iter,(this->table->getPage()-1)*5);//�����ƶ�
	} 
	int count=this->table->getCount();//�жϵ��������޳���

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
				return 1;
			}
		rowsum=x_temp;
		colsum=2+colsum;

	}
	return 1;
}
//������Ʒ��Ϣ
void CGoodsSearchWin::input_goods_data()
{
	map<string,CGoods>::iterator iter;
	string str_temp=data;//ʱ��
	int m;//"-"λ��
	iter=mymap_goods.find(inputNum_edit->getContent());
	if(iter!=mymap_goods.end())
	{
		string str1=iter->second.getGoodsNum();//��ȡ��Ʒ���
		string str2=iter->second.getGoodsName();//��ȡ��Ʒ����
		string str3=iter->second.getGoodsType();//��ȡ��Ʒ����
		string str4=iter->second.getGoodsPrice();//��ȡ��Ʒ�۸�
		string str5=iter->second.getInventory();//��ȡ�������
		string str6=iter->second.getWarehouseNum();//��ȡ��λ���
		str_temp.erase(4,1);
		m=str_temp.find("-");
		str_temp.erase(m,1);
		str_temp="./data/"+str_temp+"GI"+".txt";
		//����������
		ofstream ofs;
		//���ļ�
		ofs.open(str_temp.c_str(),ios::out | ios::app);//Ĭ�ϵ�ǰ·��
		//д������---ʱ��-- �̵���--�̵�״̬
		ofs<<data<<" "<<str1<<" "<<str2<<" "<<str3<<" "<<str4<<" "<<str5<<" "<<str6<<endl;
		ofs.close();
	}else
	{
		winArr[8]->getArr(0)->setTitle("�뾫ȷ����!");//������ʾ��Ϣ
		winArr[8]->setTitleType("�뾫ȷ����--������Ʒ");//������ʾ��������
		CTool::clear(52,16,20,8);//�ֲ�ˢ��
		winArr[8]->CWindow_Show();//��ʾ����
		winArr[8]->winRun(); 
	}
}
//��д���ി�麯��
void CGoodsSearchWin::doAction()
{	
	map<int,CUser>::iterator iter;
	int i=this->getFocus();
	if(i==7)
	{
		//��������Ҳ����ı�
		inputNum_edit->setContentNull();
		fuzzy_word="";
		CTool::gotoxy(this->getX()+42,this->getY()+25);//��ʾ��Ϣλ��
		system("cls");//����
		//����ҳ��Ϊ1
		table->setPage(1);
		table->setCount(1);
		iter=mymap.find(current_Account);
		if(iter->second.getrole()==1)//	�̵�Ա
		{
			winArr[4]->CWindow_Show();//�����̵�Ա�˵�
			winArr[4]->winRun();
		}else//�ֿ����Ա
		{
			winArr[3]->CWindow_Show();//����ֿ����Ա�˵�
			winArr[3]->winRun();
		}
	}
	if(inputNum_edit->getContent()=="")
	{
		winArr[8]->getArr(0)->setTitle("��ѯ��ϢΪ��!");//������ʾ��Ϣ
		winArr[8]->setTitleType("��ѯ��ϢΪ��--������Ʒ");//������ʾ��������
		CTool::clear(52,16,20,8);//�ֲ�ˢ��
		winArr[8]->CWindow_Show();//��ʾ����
		winArr[8]->winRun(); 
	}

	switch(i)
	{
	case 5://��ȷ��ѯorģ����ѯ
		if(!accurateQuery())//��ȷ��ѯ�����˳�
		{
			break;
		}else
		{
			fuzzyQuery();//ģ����ѯ
		}
		if(inputNum_edit->getContent()=="")
		{
			break;
		}	
		fuzzy_word=inputNum_edit->getContent();//ģ����ѯ�ؼ��ָ�ֵ
		this->inputNum_edit->setContentNull();
		winArr[6]->getArr(9)->setCount(666);//ģ����ҳ
		winArr[6]->CWindow_Table_Show();
		winArr[6]->winRun();
		break;
	case 6://������Ʒ��Ϣ--6
		if(inputNum_edit->getContent()=="")
		{
			winArr[8]->getArr(0)->setTitle("��ѯ��ϢΪ��!");//������ʾ��Ϣ
			winArr[8]->setTitleType("��ѯ��ϢΪ��--������Ʒ");//������ʾ��������
			CTool::clear(52,16,20,8);//�ֲ�ˢ��
			winArr[8]->CWindow_Show();//��ʾ����
			winArr[8]->winRun(); 
		}else
		{
			input_goods_data();//������Ʒ��Ϣ
			winArr[8]->getArr(0)->setTitle("���ڵ���...");//������ʾ��Ϣ
			winArr[8]->setTitleType("���ڵ�����Ʒ--������Ʒ");//������ʾ��������
			CTool::clear(52,16,20,8);//�ֲ�ˢ��
			winArr[8]->CWindow_Show();//��ʾ����
			winArr[8]->winRun(); 
		}
		break;
	case 7:
		//��������Ҳ����ı�
		inputNum_edit->setContentNull();
		fuzzy_word="";
		CTool::gotoxy(this->getX()+42,this->getY()+25);//��ʾ��Ϣλ��
		system("cls");//����
		//����ҳ��Ϊ1
		table->setPage(1);
		table->setCount(1);
		iter=mymap.find(current_Account);
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
