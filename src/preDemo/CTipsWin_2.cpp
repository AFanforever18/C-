#include "CTipsWin_2.h"
//���ι���
CTipsWin_2::CTipsWin_2(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	titleType="δȷ��";
	//��ť
	enter_Button=new CButton(52,18,18,2,1,1,0,BUTTON,"��������");
	add_Button=new   CButton(52,21,18,2,1,1,0,BUTTON,"������Ʒ");

	//��ǩ
	title=new CLabel(44,13,8,5,1,1,1, LABEL,"��ʾ:");
	word=new  CLabel(44,15,8,5,1,1,1,LABEL,"δ�ҵ���Ӧ����Ʒ");

	//��ӿؼ�
	addControl(title);
	addControl(word);
	addControl(enter_Button);//2--��������
	addControl(add_Button);//3--������Ʒ
}	
//��ȡ��ʾ��������--��ʾ����
string CTipsWin_2::getTitleType()
{
	return this->titleType;
}
//������ʾ��������--��ʾ����
void CTipsWin_2::setTitleType(string word)
{
	this->titleType=word;
}
//��д���ി�麯��
void CTipsWin_2::doAction()
{
	int i=this->getFocus();//��ȡ��ǰ�����½Ǳ�
	switch(i)
	{
	case 2://2--��������  
		system("cls");//����
		CTool::paintBorder(16,13,60,16);//��Ʒ��Ϣ�߿�
		winArr[12]->CWindow_Show();
		winArr[12]->winRun();
		break;
	case 3://3--������Ʒ
		system("cls");//����
		winArr[14]->getArr(4)->setTextConcent(winArr[12]->get_search_null());//������Ʒ�ı��--������ⴰ��
		winArr[14]->getArr(12)->setTextConcent("new"+winArr[12]->get_search_null());//������Ʒ�Ĳ�λ���--������ⴰ��
		winArr[14]->CWindow_Show();
		winArr[14]->winRun();
		break;
	}
}
