#include "CAddGoods.h"
CAddGoods::CAddGoods(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	string str="��ӭʹ�òִ��̵��ϵͳ!";//��������
	//�༭��
	Name=new CEdit(this->getX()+28,this->getY()+11,46,2,10,1,3,EDIT,"");
	Type=new CEdit(this->getX()+28,this->getY()+14,46,2,10,1,3,EDIT,"");
	Price=new CEdit(this->getX()+28,this->getY()+17,46,2,10,1,4,EDIT,"");
	warehouseNum=new CEdit(this->getX()+28,this->getY()+20,46,2,10,1,0,LABEL,"");//����  �����޿�������

	//��ǩ
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"����: "+data);
	goods_Num=new CLabel(this->getX()+16,this->getY()+8,20,2,1,1,0,LABEL,"��Ʒ���:");
	goods_Num_content=new CLabel(this->getX()+27,this->getY()+8,20,2,1,1,0,LABEL,"");//���
	goods_Name=new CLabel(this->getX()+16,this->getY()+11,20,2,1,1,0,LABEL,"��Ʒ����:");
	goods_Type=new CLabel(this->getX()+16,this->getY()+14,20,2,1,1,0,LABEL,"��Ʒ����:");
	goods_Price=new CLabel(this->getX()+16,this->getY()+17,20,2,1,1,0,LABEL,"��Ʒ�۸�:");
	goods_warehouseNum=new CLabel(this->getX()+16,this->getY()+20,20,2,1,1,0,LABEL,"��λ���:");
	
	//��ť
	enter_Button=new CButton(this->getX()+22,this->getY()+24,18,2,1,1,0,BUTTON,"ȷ��[Enter]");//ȷ��
	esc_Button=new CButton(this->getX()+50,this->getY()+24,18,2,1,1,0,BUTTON,"ȡ��[Esc]");//ȡ��

	//��ӿؼ�
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(goods_Num);//3
	addControl(goods_Num_content);//4
	addControl(goods_Name);
	addControl(goods_Type);
	addControl(goods_Price);
	addControl(goods_warehouseNum);
	addControl(Name);
	addControl(Type);
	addControl(Price);
	addControl(warehouseNum);
	addControl(enter_Button);//13
	addControl(esc_Button);//14
}
//��Ʒ��Ӻ���
void CAddGoods::addGoods()
{
	//������Ʒд����Ʒ�ļ�
	CFile::goodsWrite(goods_Num_content->getContent(),Name->getContent(),this->Type->getContent(),this->Price->getContent(),"0",this->warehouseNum->getContent());
	//���¶�������
	CFile::goodsFileRead();
}
//��д���ി�麯��
void CAddGoods::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
	case 13://ȷ��
		if(this->Name->getContent()=="" || this->Type->getContent()=="" || this->Price->getContent()=="" || this->warehouseNum->getContent()=="")
		{
			winArr[8]->getArr(0)->setTitle("����������!");//������ʾ��Ϣ
			winArr[8]->setTitleType("����������");//������ʾ��������
			CTool::clear(52,16,20,8);
			winArr[8]->CWindow_Show();
			winArr[8]->winRun(); 
		}else
		{
			addGoods();//��Ʒ��Ӻ���
			//����ı�
			this->Name->setContentNull();
			this->Type->setContentNull();
			this->Price->setContentNull();
			this->warehouseNum->setContentNull();
			winArr[8]->getArr(0)->setTitle("��Ʒ��ӳɹ�!");//������ʾ��Ϣ
			winArr[8]->setTitleType("��Ʒ��ӳɹ�");//������ʾ��������
			CTool::clear(52,16,20,8);//�ֲ����
			winArr[8]->CWindow_Show();
			winArr[8]->winRun(); 
		}
		break;
	case 14://����Esc
			//����ı�
			this->Name->setContentNull();
			this->Type->setContentNull();
			this->Price->setContentNull();
			this->warehouseNum->setContentNull();
			system("cls");
			winArr[11]->CWindow_Show();//��Ʒ���˵�����
			winArr[11]->winRun(); 
		break;
	}
}



