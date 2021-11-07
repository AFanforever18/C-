#include "CFile.h"
//�û��ļ���ȡ
void CFile::userFileRead()//��ȡ�û���
{
	//����������
	ifstream  ifs;
	//���ļ�
	ifs.open("./data/user.txt",ios::in );
	ifs.seekg(ios::beg);//��λ���ļ�ͷ��
	char buf[1024];//���ȡһ�е�����
	char ID[20];
	char name[20];
	char pwd[20];
	int role;
	int a;//char->int ��Ҫ
	while(ifs.peek()!=EOF)
	{
		ifs.getline(buf,1024);
		sscanf(buf,"%s %s %s %d",ID,name,pwd,&role);
		a=atoi(ID);//char�����Ϊint��
		//�����û��ö�ȡ�����ݳ�ʼ���û�
		CUser user(ID,name,pwd,role);

		mymap.insert(make_pair(a,user));

	}
	ifs.close();//�ر��ļ�
}
//�ļ���ȡ--��ȡ�ֿ���Ʒ
void CFile::goodsFileRead()
{
	//����������
	ifstream  ifs;
	//���ļ�
	ifs.open("./data/goods.txt",ios::in );
	ifs.seekg(ios::beg);//��λ���ļ�ͷ��
	char buf[1024];//���ȡһ�е�����
	char goodsNum[20];//��Ʒ���
	char goodsName[20];//��Ʒ����
	char goodsType[20];//��Ʒ����
	char goodsPrice[20];//��Ʒ�۸�
	char inventory[20];//�������
	char warehouseNum[20];//��λ���
	while(ifs.peek()!=EOF)
	{
		ifs.getline(buf,1024);
		sscanf(buf,"%s %s %s %s %s %s",goodsNum,goodsName,goodsType,goodsPrice,inventory,warehouseNum);
		//�ַ�����->string
		string str1=goodsNum;
		string str2=goodsName;
	    string str3=goodsType;
		string str4=goodsPrice;
		string str5=inventory;
		string str6=warehouseNum;
		//������Ʒ��
		CGoods mygoods(str1,str2,str3,str4,str5,str6);
		mymap_goods.insert(make_pair(str1,mygoods));
	}
	ifs.close();//�ر��ļ�	
}
	
//�û�д���ļ�--ע�����
void CFile::userWrite(string ID,string name,string pwd,int role)
{
	//����������
	ofstream ofs;
	//���ļ�
	ofs.open("./data/user.txt",ios::out | ios::app);//Ĭ�ϵ�ǰ·��
	//д������---����˳�� �˺�id--����--����
	ofs<<ID<<" "<<name<<" "<<pwd<<" "<<role<<endl;
	ofs.close();
}
//��Ʒд���ļ�
void CFile::goodsWrite(string goodsNum,string goodsName,string goodsType,string goodsPrice,string inventory,string warehouseNum)
{
	//����������
	ofstream ofs;
	//���ļ�
	ofs.open("./data/goods.txt",ios::out | ios::app);//Ĭ�ϵ�ǰ·��
	//д������---����˳�� ��Ʒ���--��Ʒ����--��Ʒ����--��Ʒ�۸�--�������--��λ���
	ofs<<goodsNum<<" "<<goodsName<<" "<<goodsType<<" "<<goodsPrice<<" "<<inventory<<" "<<warehouseNum<<endl;
	ofs.close();
}

//�̵���д���ļ�
void CFile::goods_Record_Write(string goodsNum,string goodsName,string inventory,string orderNum,string errorNum,int num)
{


	// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
    tm *ltm;
    time_t now = time(0);
    ltm= localtime(&now); 
	string str=CTool::strtoInt(ltm->tm_year+1900)+CTool::strtoInt(ltm->tm_mon+1)+CTool::strtoInt(ltm->tm_mday);//��ȡʱ��
	string temp=gbl_orderNUM;
	temp=temp.erase(7,3);
	if(atoi(str.c_str())==atoi(temp.c_str()))
	{
		str=CTool::strtoInt(atoi(gbl_orderNUM.c_str())+1);
		str.insert(7,"-");
	}else
	{
		if(num>=10)
		{
			str=str+"-0"+CTool::strtoInt(num);//ƴ�ӱ�� ��: 010
		}else
		{
			str=str+"-00"+CTool::strtoInt(num);//ƴ�ӱ�� ��: 001
		}
	}
	str="./data/"+str+".txt";
	string str1="0";
	string str2="��";
	//����������
	ofstream ofs;
	//���ļ�
	ofs.open(str.c_str(),ios::out | ios::app);//Ĭ�ϵ�ǰ·��
	//д������---����˳�� ��Ʒ���--��Ʒ����--�������--�̵�����--��������
	ofs<<goodsNum<<" "<<goodsName<<" "<<inventory<<" "<<orderNum<<" "<<errorNum<<" "<<str1<<" "<<str2<<endl;
	ofs.close();
}
//��ȡ�̵����ļ� ��������
void CFile::goods_Order_Read(list<CGoods> &order_list,string src)//�̵����� �� �ļ�·��
{
	//����������
	ifstream  ifs;
	//���ļ�
	ifs.open("./data/2021611-001.txt",ios::in );
	ifs.seekg(ios::beg);//��λ���ļ�ͷ��
	char buf[1024];//���ȡһ�е�����
	char goodsNum[20];//��Ʒ���
	char goodsName[20];//��Ʒ����
	char inventory[20];//�������
	char orderNum[20];//�̵�����
	char errorNum[20];//��������	
	while(ifs.peek()!=EOF)
	{
		ifs.getline(buf,1024);
		sscanf(buf,"%s %s %s %s %s",goodsNum,goodsName,inventory,orderNum,errorNum);
		//�ַ�����->string
		string str1=goodsNum;
		string str2=goodsName;
	    string str3=inventory;
		string str4=orderNum;
		string str5=errorNum;
//		cout<<str1<<str2;
//system("pause");
		//������Ʒ��
		CGoods mygoods(str1,str2,str3,str4,str5,"");
		order_list.push_back(mygoods);
	}
	ifs.close();//�ر��ļ�	
}
//������Ϣ
void CFile::ALL_Check_Write(string order_num,string goodsNum,string goodsName,string inventory,string orderNum,string errorNum,string check,string seaon)
{
	//����������
	ofstream ofs;
	//���ļ�
	ofs.open("./data./record.txt",ios::out | ios::app);//Ĭ�ϵ�ǰ·��
	//д������---����˳�� �̵���--��Ʒ���--��Ʒ����--�������--�̵�����--��������--����˵��--����ԭ��
	ofs<<order_num<<" "<<goodsNum<<" "<<goodsName<<" "<<inventory<<" "<<orderNum<<" "<<errorNum<<" "<<check<<" "<<seaon<<" "<<endl;
	ofs.close();	
}

void CFile::order_check_read()//����ѡ����̵��Ŷ�������
{
	map_check.clear();//���ÿ�����
	string src= "./data/"+gbl_selectNUM+".txt";//·��="./data/"+����--�̵���+".txt"
	//����������
	ifstream  ifs;
	//���ļ�
	ifs.open(src.c_str(),ios::in );
	ifs.seekg(ios::beg);//��λ���ļ�ͷ��
	char buf[1024];//���ȡһ�е�����
	char goodsNum[20];//��Ʒ���
	char goodsName[20];//��Ʒ����
	char inventory[20];//�������
	char order_Num[20];//�̵�����
	char error_Num[20];//��������
	char check_Num[20];//��������
	char season[20];//����ԭ��
	while(ifs.peek()!=EOF)
	{
		ifs.getline(buf,1024);
		sscanf(buf,"%s %s %s %s %s %s %s",goodsNum,goodsName,inventory,order_Num,error_Num,check_Num,season);
		//�ַ�����->string
		string str1=goodsNum;
		string str2=goodsName;
	    string str3=inventory;
		string str4=order_Num;
		string str5=error_Num;
		string str6=check_Num;
		string str7=season;
		//������Ʒ��
		CGoods mygoods(str2,str3,str4,str5,str6,str7);
		map_check.insert(make_pair(str1,mygoods));
	}
	ifs.close();//�ر��ļ�*
}
//�̵��źͳ���������mymap_order_numд���ļ�
void CFile::num_and_state_write(string num,string state)//���� �̵��źͳ���״̬
{
	//����������
	ofstream ofs;
	//���ļ�
	ofs.open("./data/checkdata.txt",ios::out | ios::app);//Ĭ�ϵ�ǰ·��
	//д������---����˳�� �̵���--�̵�״̬
	ofs<<num<<" "<<state<<endl;
	ofs.close();	
}
//��ȡ�ļ����̵��źͳ���״̬д��mymap_order_num����
void CFile::num_and_state_read()
{
	//����������
	ifstream  ifs;
	//���ļ�
	ifs.open("./data/checkdata.txt",ios::in );
	ifs.seekg(ios::beg);//��λ���ļ�ͷ��
	char goodsnum[20];//���ȡһ�е�����
	char check_state[20];
	char buf[1024];
	string str1;
	string str2;
	while(ifs.peek()!=EOF)
	{
		ifs.getline(buf,1024);
		sscanf(buf,"%s %s",goodsnum,check_state);
		str1=goodsnum;
		str2=check_state;
		//�ļ����ݶ����̵��ź��̵�״̬������
		mymap_order_num.insert(make_pair(str1,str2));

	}
	

	ifs.close();//�ر��ļ�	
}
//���������Ʒ��Ϣд���ļ�
void CFile::new_Check_Data_Write()
{
	//map_check
	string src= "./data/"+gbl_selectNUM+".txt";//·��="./data/"+����--�̵���+".txt"

	ofstream ofs;
	//���´��ļ�д���̵����������
	ofs.open(src.c_str(),ios::out | ios::app);
	for(map<string,CGoods>::iterator iter=map_check.begin();iter!=map_check.end();iter++)
	{
		string good_num=iter->first;
		string str1=iter->second.getGoodsNum();//��Ʒ����
		string str2=iter->second.getGoodsName();//��Ʒ���
		string str3=iter->second.getGoodsType();//�̵�����
		string str4=iter->second.getGoodsPrice();//��������
		string str5=iter->second.getInventory();//��������
		string str6=iter->second.getWarehouseNum();//����ԭ��
		//д��˳�� ��Ʒ���--��Ʒ����--��Ʒ���--�̵�����--��������--��������--����ԭ��
		ofs<<good_num<<" "<<str1<<" "<<str2<<" "<<str3<<" "<<str4<<" "<<str5<<" "<<str6<<endl;	
	}
	ofs.close();
}