#include "CFile.h"
//用户文件读取
void CFile::userFileRead()//读取用户类
{
	//创建流对象
	ifstream  ifs;
	//打开文件
	ifs.open("./data/user.txt",ios::in );
	ifs.seekg(ios::beg);//定位到文件头部
	char buf[1024];//存读取一行的数据
	char ID[20];
	char name[20];
	char pwd[20];
	int role;
	int a;//char->int 需要
	while(ifs.peek()!=EOF)
	{
		ifs.getline(buf,1024);
		sscanf(buf,"%s %s %s %d",ID,name,pwd,&role);
		a=atoi(ID);//char数组变为int型
		//创建用户用读取的数据初始化用户
		CUser user(ID,name,pwd,role);

		mymap.insert(make_pair(a,user));

	}
	ifs.close();//关闭文件
}
//文件读取--读取仓库商品
void CFile::goodsFileRead()
{
	//创建流对象
	ifstream  ifs;
	//打开文件
	ifs.open("./data/goods.txt",ios::in );
	ifs.seekg(ios::beg);//定位到文件头部
	char buf[1024];//存读取一行的数据
	char goodsNum[20];//商品编号
	char goodsName[20];//商品名称
	char goodsType[20];//商品类型
	char goodsPrice[20];//商品价格
	char inventory[20];//库存数量
	char warehouseNum[20];//仓位编号
	while(ifs.peek()!=EOF)
	{
		ifs.getline(buf,1024);
		sscanf(buf,"%s %s %s %s %s %s",goodsNum,goodsName,goodsType,goodsPrice,inventory,warehouseNum);
		//字符数组->string
		string str1=goodsNum;
		string str2=goodsName;
	    string str3=goodsType;
		string str4=goodsPrice;
		string str5=inventory;
		string str6=warehouseNum;
		//创建商品类
		CGoods mygoods(str1,str2,str3,str4,str5,str6);
		mymap_goods.insert(make_pair(str1,mygoods));
	}
	ifs.close();//关闭文件	
}
	
//用户写入文件--注册可用
void CFile::userWrite(string ID,string name,string pwd,int role)
{
	//创建流对象
	ofstream ofs;
	//打开文件
	ofs.open("./data/user.txt",ios::out | ios::app);//默认当前路径
	//写入数据---存入顺序 账号id--姓名--密码
	ofs<<ID<<" "<<name<<" "<<pwd<<" "<<role<<endl;
	ofs.close();
}
//商品写入文件
void CFile::goodsWrite(string goodsNum,string goodsName,string goodsType,string goodsPrice,string inventory,string warehouseNum)
{
	//创建流对象
	ofstream ofs;
	//打开文件
	ofs.open("./data/goods.txt",ios::out | ios::app);//默认当前路径
	//写入数据---存入顺序 商品编号--商品名称--商品类型--商品价格--库存数量--仓位编号
	ofs<<goodsNum<<" "<<goodsName<<" "<<goodsType<<" "<<goodsPrice<<" "<<inventory<<" "<<warehouseNum<<endl;
	ofs.close();
}

//盘点编号写入文件
void CFile::goods_Record_Write(string goodsNum,string goodsName,string inventory,string orderNum,string errorNum,int num)
{


	// 基于当前系统的当前日期/时间
    tm *ltm;
    time_t now = time(0);
    ltm= localtime(&now); 
	string str=CTool::strtoInt(ltm->tm_year+1900)+CTool::strtoInt(ltm->tm_mon+1)+CTool::strtoInt(ltm->tm_mday);//获取时间
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
			str=str+"-0"+CTool::strtoInt(num);//拼接编号 例: 010
		}else
		{
			str=str+"-00"+CTool::strtoInt(num);//拼接编号 例: 001
		}
	}
	str="./data/"+str+".txt";
	string str1="0";
	string str2="无";
	//创建流对象
	ofstream ofs;
	//打开文件
	ofs.open(str.c_str(),ios::out | ios::app);//默认当前路径
	//写入数据---存入顺序 商品编号--商品名称--库存数量--盘点数量--差异数量
	ofs<<goodsNum<<" "<<goodsName<<" "<<inventory<<" "<<orderNum<<" "<<errorNum<<" "<<str1<<" "<<str2<<endl;
	ofs.close();
}
//读取盘点编号文件 存入容器
void CFile::goods_Order_Read(list<CGoods> &order_list,string src)//盘点容器 和 文件路径
{
	//创建流对象
	ifstream  ifs;
	//打开文件
	ifs.open("./data/2021611-001.txt",ios::in );
	ifs.seekg(ios::beg);//定位到文件头部
	char buf[1024];//存读取一行的数据
	char goodsNum[20];//商品编号
	char goodsName[20];//商品名称
	char inventory[20];//库存数量
	char orderNum[20];//盘点数量
	char errorNum[20];//差异数量	
	while(ifs.peek()!=EOF)
	{
		ifs.getline(buf,1024);
		sscanf(buf,"%s %s %s %s %s",goodsNum,goodsName,inventory,orderNum,errorNum);
		//字符数组->string
		string str1=goodsNum;
		string str2=goodsName;
	    string str3=inventory;
		string str4=orderNum;
		string str5=errorNum;
//		cout<<str1<<str2;
//system("pause");
		//创建商品类
		CGoods mygoods(str1,str2,str3,str4,str5,"");
		order_list.push_back(mygoods);
	}
	ifs.close();//关闭文件	
}
//冲正信息
void CFile::ALL_Check_Write(string order_num,string goodsNum,string goodsName,string inventory,string orderNum,string errorNum,string check,string seaon)
{
	//创建流对象
	ofstream ofs;
	//打开文件
	ofs.open("./data./record.txt",ios::out | ios::app);//默认当前路径
	//写入数据---存入顺序 盘点编号--商品编号--商品名称--库存数量--盘点数量--差异数量--冲正说明--冲正原因
	ofs<<order_num<<" "<<goodsNum<<" "<<goodsName<<" "<<inventory<<" "<<orderNum<<" "<<errorNum<<" "<<check<<" "<<seaon<<" "<<endl;
	ofs.close();	
}

void CFile::order_check_read()//冲正选择的盘点编号读到容器
{
	map_check.clear();//先置空容器
	string src= "./data/"+gbl_selectNUM+".txt";//路径="./data/"+冲正--盘点编号+".txt"
	//创建流对象
	ifstream  ifs;
	//打开文件
	ifs.open(src.c_str(),ios::in );
	ifs.seekg(ios::beg);//定位到文件头部
	char buf[1024];//存读取一行的数据
	char goodsNum[20];//商品编号
	char goodsName[20];//商品名称
	char inventory[20];//库存数量
	char order_Num[20];//盘点数量
	char error_Num[20];//差异数量
	char check_Num[20];//冲正数量
	char season[20];//冲正原因
	while(ifs.peek()!=EOF)
	{
		ifs.getline(buf,1024);
		sscanf(buf,"%s %s %s %s %s %s %s",goodsNum,goodsName,inventory,order_Num,error_Num,check_Num,season);
		//字符数组->string
		string str1=goodsNum;
		string str2=goodsName;
	    string str3=inventory;
		string str4=order_Num;
		string str5=error_Num;
		string str6=check_Num;
		string str7=season;
		//创建商品类
		CGoods mygoods(str2,str3,str4,str5,str6,str7);
		map_check.insert(make_pair(str1,mygoods));
	}
	ifs.close();//关闭文件*
}
//盘点编号和冲正的容器mymap_order_num写入文件
void CFile::num_and_state_write(string num,string state)//参数 盘点编号和冲正状态
{
	//创建流对象
	ofstream ofs;
	//打开文件
	ofs.open("./data/checkdata.txt",ios::out | ios::app);//默认当前路径
	//写入数据---存入顺序 盘点编号--盘点状态
	ofs<<num<<" "<<state<<endl;
	ofs.close();	
}
//读取文件中盘点编号和冲正状态写入mymap_order_num容器
void CFile::num_and_state_read()
{
	//创建流对象
	ifstream  ifs;
	//打开文件
	ifs.open("./data/checkdata.txt",ios::in );
	ifs.seekg(ios::beg);//定位到文件头部
	char goodsnum[20];//存读取一行的数据
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
		//文件数据读到盘点编号和盘点状态的容器
		mymap_order_num.insert(make_pair(str1,str2));

	}
	

	ifs.close();//关闭文件	
}
//冲正后的商品信息写入文件
void CFile::new_Check_Data_Write()
{
	//map_check
	string src= "./data/"+gbl_selectNUM+".txt";//路径="./data/"+冲正--盘点编号+".txt"

	ofstream ofs;
	//重新打开文件写入盘点冲正新数据
	ofs.open(src.c_str(),ios::out | ios::app);
	for(map<string,CGoods>::iterator iter=map_check.begin();iter!=map_check.end();iter++)
	{
		string good_num=iter->first;
		string str1=iter->second.getGoodsNum();//商品名称
		string str2=iter->second.getGoodsName();//商品库存
		string str3=iter->second.getGoodsType();//盘点数量
		string str4=iter->second.getGoodsPrice();//差异数量
		string str5=iter->second.getInventory();//冲正数量
		string str6=iter->second.getWarehouseNum();//冲正原因
		//写入顺序 商品编号--商品名称--商品库存--盘点数量--差异数量--冲正数量--冲正原因
		ofs<<good_num<<" "<<str1<<" "<<str2<<" "<<str3<<" "<<str4<<" "<<str5<<" "<<str6<<endl;	
	}
	ofs.close();
}