#include "COutGoodsWin.h"
//Ĭ�Ϲ���
COutGoodsWin::COutGoodsWin()
{

}
//���ι���
COutGoodsWin::COutGoodsWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	search_word="";//һ��ʼΪ��
	string str="��ӭʹ�òִ��̵��ϵͳ!";//��������
	//��ǩ
	//Ϊ�˱�ǩ�洰�ڴ�Сλ�ñ䶯
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);
	inputNum_label=new CLabel(this->getX()+2,this->getY()+7,20,2,1,1,0,LABEL,"��������Ʒ��ѯ�ı��:");
	outGoods_label=new CLabel(this->getX()+70,this->getY()+12 ,20,2,1,1,0,LABEL,"�������������[0-10000]:");
	goods_Name=new CLabel(this->getX()+10,this->getY()+12,20,2,1,1,0,LABEL,"��Ʒ����:");
	goods_Type=new CLabel(this->getX()+10,this->getY()+15,20,2,1,1,0,LABEL,"��Ʒ����:");
	goods_Price=new CLabel(this->getX()+10,this->getY()+18,20,2,1,1,0,LABEL,"��Ʒ�۸�:");
	goods_NUm=new CLabel(this->getX()+10,this->getY()+21,21,2,1,1,0,LABEL,"�������:");
	goods_WarehouseNum=new CLabel(this->getX()+10,this->getY()+24,20,2,1,1,0,LABEL,"��λ���:");
	//�༭��
	inputNum_edit=new CEdit(this->getX()+28,this->getY()+7,46,2,10,1,3,EDIT,"");
	inputoutGoods_edit=new CEdit(this->getX()+76,this->getY()+15 ,18 ,2,10,1,2,EDIT,"");
	//��ť
	find_Btn=new CButton(this->getX()+76,this->getY()+7,10,2,1,1,0,BUTTON,"��ѯ");
	import_Btn=new CButton(this->getX()+76,this->getY()+20,18,2,1,1,0,BUTTON,"ȷ��");
	myexit=new CButton(this->getX()+76,this->getY()+24,18,2,1,1,0,BUTTON,"����[Esc]");

	//���
	table=new CTable(this->getX()+8,this->getY()+12,6,6,1,1,0,LABEL,"��ѯ");	
	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(inputNum_label);
	addControl(outGoods_label);
	addControl(goods_Name);
	addControl(goods_Type);
	addControl(goods_Price);
	addControl(goods_NUm);
	addControl(goods_WarehouseNum);
	addControl(inputNum_edit);//��Ʒ��ѯ�༭��--10
	addControl(find_Btn);//��Ʒ��ѯ��ť--11
	addControl(inputoutGoods_edit);//�����������--12
	addControl(import_Btn);//ȷ�����ⰴť--13
	addControl(myexit);//�˳�--14

}

//Ĭ�Ϲ���
COutGoodsWin::~COutGoodsWin()
{
	
}
//��ȡ�������Ʒ����
string COutGoodsWin::get_Search_word()
{
	return this->search_word;
}
//��ȡ����ĳ�������--���ⴰ��
int COutGoodsWin::get_input_Goods_Num()
{
	return this->input_Goods_Num;
}
//��ѯ��ӡ��Ʒ��Ϣ
void COutGoodsWin::search(string word)
{
	map<string,CGoods>::iterator iter;
	iter=mymap_goods.find(word);
	if(iter==mymap_goods.end())
	{
		return;
	}else
	{
		CTool::gotoxy(this->getX()+23,this->getY()+13);
		cout<<iter->second.getGoodsName()<<"          ";//��Ʒ����
		CTool::gotoxy(this->getX()+23,this->getY()+16);
		cout<<iter->second.getGoodsType()<<"          ";//��Ʒ����
		CTool::gotoxy(this->getX()+23,this->getY()+19);
		cout<<iter->second.getGoodsPrice()<<"          ";//��Ʒ�۸�
		CTool::gotoxy(this->getX()+23,this->getY()+22);
		cout<<iter->second.getInventory()<<"          ";//�������
		CTool::gotoxy(this->getX()+23,this->getY()+25);
		cout<<iter->second.getWarehouseNum()<<"         ";//��λ���
	}
}
//��Ʒ����--����Ʒ��������Ϊ����������
void COutGoodsWin::goodsOut()
{
	map<string,CGoods>::iterator iter;
	iter=mymap_goods.find(search_word);//�ҵ�Ҫ�������Ʒ
	string goodsNum=iter->second.getGoodsNum();//��ȡ��Ʒ���
	string goodsName=iter->second.getGoodsName();//��ȡ��Ʒ����
	string goodsTyp=iter->second.getGoodsType();//��ȡ��Ʒ����
	string goodsPrice=iter->second.getGoodsPrice();//��ȡ��Ʒ�۸�
	string inventory=iter->second.getInventory();//��ȡ�������
	string warehouseNum=iter->second.getWarehouseNum();//��ȡ��λ���

	//�����: ���=ԭ�ȿ��-��������input_Goods_Num
	int inventory_temp=atoi(inventory.c_str())-input_Goods_Num;
	//int->string
	stringstream ss;
	ss<<inventory_temp;
	ss>>inventory;//�õ������Ŀ��
	//ɾ�������������Ʒ����Ϣ
	mymap_goods.erase(iter);
	//��Ʒ������������Ʒ��Ϣ
	CGoods mygoods(goodsNum,goodsName,goodsTyp,goodsPrice,inventory,warehouseNum);
	mymap_goods.insert(make_pair(goodsNum,mygoods));

	ofstream ofs;
	ofs.open("./data/goods.txt");
	ofs.flush();
	ofs.close();
	for(map<string,CGoods>::iterator it=mymap_goods.begin();it!=mymap_goods.end();it++)
	{
		CFile::goodsWrite(it->second.getGoodsNum(),it->second.getGoodsName(),it->second.getGoodsType(),it->second.getGoodsPrice(),it->second.getInventory(),it->second.getWarehouseNum());
	}
	//����Ʒ����д���ļ���,�ٶ�һ����Ʒ�ļ�
	CFile::goodsWrite(goodsNum,goodsName,goodsTyp,goodsPrice,inventory,warehouseNum);
	CFile::goodsFileRead();
}
//���ڵĲ��� ÿ������һ�� ���� ����������д
void COutGoodsWin::doAction()
{
	int i=this->getFocus();
	if(i==14)//����
	{
		system("cls");
		winArr[3]->getArr(1)->setTextConcent("��ӭ:"+user_name);
		winArr[3]->CWindow_Show();//�ֿ����Ա--������--
		winArr[3]->winRun();
	}
	map<string,CGoods>::iterator iter;
	if(search_word=="")
	{
		iter=mymap_goods.find(this->inputNum_edit->getContent());
	}else
	{
		iter=mymap_goods.find(search_word);
	}
	if(iter==mymap_goods.end())
	{
		//����ı�
		this->inputNum_edit->setContentNull();
		this->inputoutGoods_edit->setContentNull();
		winArr[8]->getArr(0)->setTitle("��������ȷ���!");//������ʾ��Ϣ
		winArr[8]->setTitleType("��������ȷ���--����");//������ʾ��������
		winArr[8]->CWindow_Show();
		winArr[8]->winRun(); 
		return;
	}
	int goodsNumber=atoi(iter->second.getInventory().c_str());//���;
	switch(i)
	{
	case 11://��ѯ
		
		search_word=inputNum_edit->getContent();//������Ʒ����
		if(inputNum_edit->getContent()=="")
		{
			search(search_word);//��ѯ��ӡ��Ʒ��Ϣ
		}else
		{
			search(inputNum_edit->getContent());//��ѯ��ӡ��Ʒ��Ϣ
		}
		
		break;
	case 13://����
		input_Goods_Num=atoi(inputoutGoods_edit->getContent().c_str());//���³�������
		if(atoi(inputoutGoods_edit->getContent().c_str())>10000 || inputoutGoods_edit->getContent()=="")//��������Ϊ�ջ��ߴ���10000
		{
			//����ı�
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			winArr[8]->getArr(0)->setTitle("������������!");//������ʾ��Ϣ
			winArr[8]->setTitleType("������������");//������ʾ��������
			winArr[8]->CWindow_Show();
			winArr[8]->winRun(); 
		}
		else if(atoi(inputoutGoods_edit->getContent().c_str())>goodsNumber)
		{
			//����ı�
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			winArr[8]->getArr(0)->setTitle("�����������ڿ��!");//������ʾ��Ϣ
			winArr[8]->setTitleType("�����������ڿ��");//������ʾ��������
			winArr[8]->CWindow_Show();
			winArr[8]->winRun(); 
		}else////��������С�ڵ��ڿ�� 
		{
			//����ı�
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			goodsOut();//��Ʒ����--����Ʒ��������Ϊ����������
			winArr[8]->getArr(0)->setTitle("����ɹ�!");//������ʾ��Ϣ
			winArr[8]->setTitleType("����ɹ�");//������ʾ��������
			winArr[8]->CWindow_Show();
			winArr[8]->winRun(); 
		}
		break;
	}
}