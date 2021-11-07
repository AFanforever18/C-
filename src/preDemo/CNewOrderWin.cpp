#include "CNewOrderWin.h"
//Ĭ�Ϲ���
CNewOrderWin::CNewOrderWin()
{
	
}
//Ĭ�Ϲ���//���ι���
CNewOrderWin::CNewOrderWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	num=1;//
	count=0;//��Ż�ȥ
	search_word="";//��Ʒ����--��ʼΪ��
	order_num="";//�̵�����--��ʼΪ��
	string str="��ӭʹ�òִ��̵��ϵͳ!";//��������
	//��ǩ
	//Ϊ�˱�ǩ�洰�ڴ�Сλ�ñ䶯
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);
	inputNum_label=new CLabel(this->getX()+2,this->getY()+7,20,2,1,1,0,LABEL,"��������Ʒ��ѯ�ı��:");
	orderNum=new CLabel(this->getX()+2,this->getY()+9,20,2,1,1,0,LABEL,"�̵���:"+makeOrder_Num());
	outGoods_label=new CLabel(this->getX()+70,this->getY()+12 ,20,2,1,1,0,LABEL,"�������̵�������[0-10000]:");
	goods_Name=new CLabel(this->getX()+10,this->getY()+12,20,2,1,1,0,LABEL,"��Ʒ����:");
	goods_Type=new CLabel(this->getX()+10,this->getY()+16,20,2,1,1,0,LABEL,"��Ʒ����:");
	goods_Price=new CLabel(this->getX()+10,this->getY()+20,20,2,1,1,0,LABEL,"��Ʒ�۸�:");
	goods_WarehouseNum=new CLabel(this->getX()+10,this->getY()+24,20,2,1,1,0,LABEL,"��λ���:");

	//�༭��
	inputNum_edit=new CEdit(this->getX()+28,this->getY()+7,46,2,10,1,3,EDIT,"");
	inputoutGoods_edit=new CEdit(this->getX()+76,this->getY()+15 ,18 ,2,10,1,2,EDIT,"");
	//��ť
	find_Btn=new CButton(this->getX()+76,this->getY()+7,10,2,1,1,0,BUTTON,"��ѯ");
	import_Btn=new CButton(this->getX()+76,this->getY()+18,18,2,1,1,0,BUTTON,"ȷ��[enter]");
	myexit=new CButton(this->getX()+76,this->getY()+21,18,2,1,1,0,BUTTON,"����[Esc]");
	orderTable=new CButton(this->getX()+76,this->getY()+24,18,2,1,1,0,BUTTON,"�����̵㱨��");

	//���
	table=new CTable(this->getX()+8,this->getY()+12,6,6,1,1,0,LABEL,"��ѯ");	
	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(orderNum);
	addControl(inputNum_label);
	addControl(outGoods_label);
	addControl(goods_Name);
	addControl(goods_Type);
	addControl(goods_Price);
	addControl(goods_WarehouseNum);
	addControl(inputNum_edit);//��Ʒ��ѯ�༭��--10
	addControl(find_Btn);//��Ʒ��ѯ��ť--11
	addControl(inputoutGoods_edit);//�����������--12
	addControl(import_Btn);//ȷ���̵㰴ť--13
	addControl(myexit);//����--14
	addControl(orderTable);//�����̵㱨��ť--15

	
}
//Ĭ������
CNewOrderWin::~CNewOrderWin()
{
	
}
//��ȡ�������Ʒ����
string CNewOrderWin::get_Search_word()
{
	return this->search_word;
}
//��ȡ������̵�����
string CNewOrderWin::get_Order_num()
{
	return this->order_num;
}
//��ȡ�̵���--�̵㱨��
string CNewOrderWin::get_makeOrder_Num()
{
	return this->orderNUM;//�̵���
}
//�����̵��
string  CNewOrderWin::makeOrder_Num()
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

	return str;
}
//��ӡ��ѯ����Ʒ��Ϣ
void CNewOrderWin::search(string word)
{
	if(inputNum_edit->getContent()=="" && search_word=="" )//��Ʒ��ѯ�༭��Ϊ��
	{
		return;
	}
	map<string,CGoods>::iterator iter;
	iter=mymap_goods.find(word);
	if(iter==mymap_goods.end())
	{
		winArr[8]->getArr(0)->setTitle("δ�ҵ���Ʒ!");//������ʾ��Ϣ
		winArr[8]->setTitleType("δ�ҵ���Ʒ--�½��̵�");//������ʾ��������
		//����ı�
		this->inputNum_edit->setContentNull();
		this->inputoutGoods_edit->setContentNull();
		CTool::clear(52,16,20,8);//�ֲ�ˢ��
		winArr[8]->CWindow_Show();//��ʾ����
		winArr[8]->winRun(); 
		return;
	}else
	{
		CTool::gotoxy(this->getX()+23,this->getY()+13);
		cout<<iter->second.getGoodsName()<<"          ";//��Ʒ����
		CTool::gotoxy(this->getX()+23,this->getY()+17);
		cout<<iter->second.getGoodsType()<<"          ";//��Ʒ����
		CTool::gotoxy(this->getX()+23,this->getY()+21);
		cout<<iter->second.getGoodsPrice()<<"          ";//��Ʒ�۸�
		CTool::gotoxy(this->getX()+23,this->getY()+25);
		cout<<iter->second.getWarehouseNum()<<"         ";//��λ���
	}
}
//��¼�̵��
void CNewOrderWin::record()
{
	map<string,CGoods>::iterator iter;
	iter=mymap_goods.find(search_word);
	int tempNum=atoi(iter->second.getInventory().c_str())-atoi(order_num.c_str());
	stringstream ss;
	string errorNum;
	ss<<tempNum;
	ss>>errorNum;
	//�����б� ��Ʒ����--��Ʒ����--�������--�̵�����--��������---�̵���
	CFile::goods_Record_Write(search_word,iter->second.getGoodsName(),iter->second.getInventory(),order_num,errorNum,num);
	//��������
	temp_list.push_back((CGoods(search_word,iter->second.getGoodsName(),iter->second.getInventory(),order_num,errorNum,"")));
	//д������---����˳�� �̵���--��Ʒ���--��Ʒ����--�������--�̵�����--��������--����˵��--����ԭ��
	CFile::ALL_Check_Write(makeOrder_Num(),search_word,iter->second.getGoodsName(),iter->second.getInventory(),order_num,errorNum,"0","��");
}
//���ڵĲ��� ÿ������һ�� ���� ����������д
void CNewOrderWin::doAction()
{	
	int i=this->getFocus();
	if(i==14)
	{
		//����ı�
		this->inputNum_edit->setContentNull();
		this->inputoutGoods_edit->setContentNull();
		system("cls");
		winArr[15]->CWindow_Show();//���̵�˵�����
		winArr[15]->winRun();
	}

	if(inputNum_edit->getContent()=="" && search_word=="" )
	{
		return;
	}
	string str="";
	if(inputNum_edit->getContent()=="")
	{
		str="��Ʒ���:"+search_word;//��ʾ���ڵ���ʾ��Ϣ
	}else
	{
		str="��Ʒ���:"+inputNum_edit->getContent();//��ʾ���ڵ���ʾ��Ϣ
	}

	map<string,CGoods>::iterator iter;
	if(search_word=="")
	{
		iter=mymap_goods.find(this->inputNum_edit->getContent());
	}else
	{
		iter=mymap_goods.find(search_word);
	}
//	if(iter==mymap_goods.end())
//	{
//		winArr[8]->getArr(0)->setTitle("δ�ҵ���Ʒ!");//������ʾ��Ϣ
//		winArr[8]->setTitleType("δ�ҵ���Ʒ--�½��̵�");//������ʾ��������
		//����ı�
//		this->inputNum_edit->setContentNull();
//		this->inputoutGoods_edit->setContentNull();
//		CTool::clear(52,16,20,8);//�ֲ�ˢ��
//		winArr[8]->CWindow_Show();//��ʾ����
//		winArr[8]->winRun(); 
//		return;
//	}
	switch(i)
	{
	case 11://��Ʒ��ѯ
		search_word=inputNum_edit->getContent();//������Ʒ����
		if(inputNum_edit->getContent()=="")
		{
			search(search_word);//��ѯ��ӡ��Ʒ��Ϣ
		}else
		{
			search(inputNum_edit->getContent());//��ѯ��ӡ��Ʒ��Ϣ
		}
		break;
	case 13://ȷ���̵�
			count++;//�̵�һ��
			order_num=this->inputoutGoods_edit->getContent();//�����̵�����
			record();//�̵���д���ļ�����
			winArr[16]->getArr(1)->setTextConcent("��ӭ:"+user_name);
			winArr[16]->getArr(0)->setTitle(str);//������ʾ��Ϣ strΪ��Ʒ���
			winArr[16]->addControl(new CLabel(53,18,20,2,1,1,0,LABEL,""));//��ӿؼ�
			winArr[16]->getArr(1)->setTextConcent("�̵�����Ϊ:"+inputoutGoods_edit->getContent());
			//����ı�
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			winArr[16]->setTitleType("�̵����");//������ʾ��������
			winArr[16]->CWindow_Show();
			winArr[16]->winRun(); 
		break;
	case 14://����
		//����ı�
		this->inputNum_edit->setContentNull();
		this->inputoutGoods_edit->setContentNull();
		system("cls");
		winArr[11]->CWindow_Show();//���̵�˵�����
		winArr[11]->winRun();
		break;
	case 15://���������̵㱨����
		CTool::file_opear();//���������ļ���--����Ҳ��������������̵��ź��̵�״̬
		orderNUM=CTool::strtoInt(atoi(makeOrder_Num().erase(7,1).c_str())-1).insert(7,"-");//�̵㱨����δ�������̵���
		CFile::num_and_state_write(orderNUM,"δ����");//�̵��ź�״̬д���ļ�
		count=0;//����û����
		string temp_str="./data/"+orderNUM+".txt";//·��
		num++;//�����̵����+1 num++
		this->orderNum->setTextConcent(makeOrder_Num());//�����µ��̵��� ����
		//����ı�
		this->inputNum_edit->setContentNull();
		this->inputoutGoods_edit->setContentNull();
		//winArr[10]->setTitleType("�̵����");//������ʾ��������
		system("cls");//����
		winArr[10]->getArr(3)->setTextConcent("�̵���:"+orderNUM);//�ı��̵���
		winArr[10]->CWindow_Show();//�����̵㱨�����
		CTool::prtinf_Table_Content(temp_list);//�ڴ�ӡ������ݲ���
		winArr[10]->winRun(); 
		break;
	}
}