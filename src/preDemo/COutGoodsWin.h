#ifndef COUTGOODSWIN_H
#define COUTGOODSWIN_H
#pragma   warning (disable: 4786)
#include "CWindow.h"
#include <sstream>
#include <string>
class COutGoodsWin:public CWindow
{
private:
	string search_word;//���������Ʒ����
	int input_Goods_Num;//����ĳ�������
public:
	COutGoodsWin();//Ĭ�Ϲ���
	COutGoodsWin(int x,int y,int width,int height);//Ĭ�Ϲ���//���ι���
	~COutGoodsWin();//Ĭ������
	void doAction();//���ڵĲ��� ÿ������һ�� ���� ����������д
	void search(string word);//��ѯ��ӡ��Ʒ��Ϣ
	void goodsOut();//��Ʒ����
	string get_Search_word();//��ȡ�������Ʒ����
	int get_input_Goods_Num();//��ȡ����ĳ�������
	//��ǩ
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;//����
	CLabel* inputNum_label;//��ѯ��Ʒ���
	CLabel* outGoods_label;//��������
	CLabel* goods_Name;//��Ʒ����
	CLabel* goods_Type;//"��Ʒ����:");
	CLabel* goods_Price;//��Ʒ�۸�
	CLabel* goods_NUm;//�������
	CLabel* goods_WarehouseNum;//��λ���
	//�༭��
	CEdit* inputNum_edit;//������Ʒ���
	CEdit* inputoutGoods_edit;//�����������
	//��ť
	CButton* find_Btn;//��Ʒ��ѯ
	CButton* import_Btn;//ȷ�����ⰴť
	CButton* myexit;//�˳�
	//���
	CTable* table;
};
#endif
