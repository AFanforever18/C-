#include "CInputGoodsWin.h"
//���ι���
CInputGoodsWin::CInputGoodsWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	search_word="";//һ��ʼΪ��
	string str="��ӭʹ�òִ��̵��ϵͳ!";//��������
	//��ǩ
	//Ϊ�˱�ǩ�洰�ڴ�Сλ�ñ䶯
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);
	inputNum_label=new CLabel(this->getX()+2,this->getY()+7,20,2,1,1,0,LABEL,"��������Ʒ��ѯ�ı��:");
	inputGoods_label=new CLabel(this->getX()+70,this->getY()+12 ,20,2,1,1,0,LABEL,"�������������[1-10000]:");
	goods_Name=new CLabel(this->getX()+10,this->getY()+12,20,2,1,1,0,LABEL,"��Ʒ����:");
	goods_Type=new CLabel(this->getX()+10,this->getY()+15,20,2,1,1,0,LABEL,"��Ʒ����:");
	goods_Price=new CLabel(this->getX()+10,this->getY()+18,20,2,1,1,0,LABEL,"��Ʒ�۸�:");
	goods_NUm=new CLabel(this->getX()+10,this->getY()+21,21,2,1,1,0,LABEL,"�������:");
	goods_WarehouseNum=new CLabel(this->getX()+10,this->getY()+24,20,2,1,1,0,LABEL,"��λ���:");
	//�༭��
	inputNum_edit=new CEdit(this->getX()+28,this->getY()+7,46,2,10,1,3,EDIT,"");
	inputoutGoods_edit=new CEdit(this->getX()+70,this->getY()+15 ,28 ,2,10,1,2,EDIT,"");
	//��ť
	find_Btn=new CButton(this->getX()+76,this->getY()+7,10,2,1,1,0,BUTTON,"��ѯ");
	import_Btn=new CButton(this->getX()+70,this->getY()+20,12,2,1,1,0,BUTTON,"ȷ��");
	myexit=new CButton(this->getX()+86,this->getY()+20,12,2,1,1,0,BUTTON,"����[Esc]");

	//���
	table=new CTable(this->getX()+8,this->getY()+12,6,6,1,1,0,LABEL,"��ѯ");	
	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(inputNum_label);
	addControl(inputGoods_label);
	addControl(goods_Name);
	addControl(goods_Type);
	addControl(goods_Price);
	addControl(goods_NUm);
	addControl(goods_WarehouseNum);
	addControl(inputNum_edit);//��Ʒ��ѯ�༭��--10
	addControl(find_Btn);//��Ʒ��ѯ��ť--11
	addControl(inputoutGoods_edit);//�����������--12
	addControl(import_Btn);//ȷ����ⰴť--13
	addControl(myexit);//ȡ��--14

}

//Ĭ�Ϲ���
CInputGoodsWin::~CInputGoodsWin()
{
	
}
//��ȡ�������Ʒ����
string CInputGoodsWin::get_Search_word()
{
	return this->search_word;
}
//��ȡ����δ���ҵı���
string CInputGoodsWin::get_search_null()
{
	return this->search_null;
}
//��ȡ������������--��ⴰ��
int CInputGoodsWin::get_input_Goods_Num()
{
	return this->input_Goods_Num;
}
//��ѯ��ӡ��Ʒ��Ϣ
void CInputGoodsWin::search(string word)
{
	map<string,CGoods>::iterator iter;
	iter=mymap_goods.find(word);
	if(iter==mymap_goods.end())
	{
		//����ı�
		this->inputNum_edit->setContentNull();
		this->inputoutGoods_edit->setContentNull();
		CTool::clear(41,12,36,16);//�ֲ����
		CTool::paintBorder(42,12,36,14);//�߿�
		winArr[13]->CWindow_Show();
		winArr[13]->winRun();
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
//��Ʒ���--����Ʒ��������Ϊ���������
void CInputGoodsWin::goodsOut()
{
	map<string,CGoods>::iterator iter;
	iter=mymap_goods.find(search_word);//�ҵ�Ҫ�������Ʒ
	string goodsNum=iter->second.getGoodsNum();//��ȡ��Ʒ���
	string goodsName=iter->second.getGoodsName();//��ȡ��Ʒ����
	string goodsTyp=iter->second.getGoodsType();//��ȡ��Ʒ����
	string goodsPrice=iter->second.getGoodsPrice();//��ȡ��Ʒ�۸�
	string inventory=iter->second.getInventory();//��ȡ�������
	string warehouseNum=iter->second.getWarehouseNum();//��ȡ��λ���

	//����: ���=ԭ�ȿ��+�������input_Goods_Num
	int inventory_temp=atoi(inventory.c_str())+input_Goods_Num;
	//int->string
	stringstream ss;
	ss<<inventory_temp;
	ss>>inventory;//�õ�����Ŀ��
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
void CInputGoodsWin::doAction()
{
	int i=this->getFocus();
	map<string,CGoods>::iterator iter;
	switch(i)
	{
	case 11://��ѯ
		if(this->inputNum_edit->getContent()!="")
		{
			iter=mymap_goods.find(this->inputNum_edit->getContent());
		}else
		{
			iter=mymap_goods.find(search_word);
		}
		if(iter==mymap_goods.end())//δ�ҵ���Ʒ
		{
			search_null=inputNum_edit->getContent();//δ��ѯ������Ʒ���--������Ʒ
			//����ı�
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			CTool::clear(41,12,36,16);//�ֲ����
			CTool::paintBorder(42,12,36,14);//�߿�
			winArr[13]->CWindow_Show();//����δ�ҵ���Ʒ--��ʾ����
			winArr[13]->winRun();
		}
		search_word=inputNum_edit->getContent();//������Ʒ����
		if(inputNum_edit->getContent()=="")
		{
			search(search_word);//��ѯ��ӡ��Ʒ��Ϣ
		}else
		{
			search(inputNum_edit->getContent());//��ѯ��ӡ��Ʒ��Ϣ
		}
		
		break;
	case 13://���
		input_Goods_Num=atoi(inputoutGoods_edit->getContent().c_str());//�����������
		if(atoi(inputoutGoods_edit->getContent().c_str())>10000 || inputoutGoods_edit->getContent()=="")//��������Ϊ�ջ��ߴ���10000
		{
			//����ı�
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			winArr[8]->getArr(0)->setTitle("�����������!");//������ʾ��Ϣ
			winArr[8]->setTitleType("�����������");//������ʾ��������
			winArr[8]->CWindow_Show();
			winArr[8]->winRun(); 
		}
		else//�����������
		{
			//����ı�
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			goodsOut();//��Ʒ����--����Ʒ��������Ϊ����������
			winArr[8]->getArr(0)->setTitle("���ɹ�!");//������ʾ��Ϣ
			winArr[8]->setTitleType("���ɹ�");//������ʾ��������
			winArr[8]->CWindow_Show();
			winArr[8]->winRun(); 
		}
		break;
	case 14:
			//����ı�
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			system("cls");
			winArr[11]->CWindow_Show();//�������˵�����
			winArr[11]->winRun();
		break;
	}
}