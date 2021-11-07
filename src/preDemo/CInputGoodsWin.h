#ifndef CINPUTGOODSWIN_H
#define CINPUTGOODSWIN_H
#pragma   warning (disable: 4786)
#include "CWindow.h"
#include <sstream>
#include <string>
class CInputGoodsWin:public CWindow
{
private:
	string search_word;//���������Ʒ����
	string search_null;//������δ���ҵı���
	int input_Goods_Num;//������������
public:
	CInputGoodsWin(int x,int y,int width,int height);//���ι���
	~CInputGoodsWin();//Ĭ������
	void doAction();//���ڵĲ��� ÿ������һ�� ���� ����������д
	void search(string word);//��ѯ��ӡ��Ʒ��Ϣ
	void goodsOut();//��Ʒ����
	string get_Search_word();//��ȡ�������Ʒ����
	string get_search_null();//��ȡ����δ���ҵı���
	int get_input_Goods_Num();//��ȡ������������

	//��ǩ
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;//����
	CLabel* inputNum_label;//��ѯ��Ʒ���
	CLabel* inputGoods_label;//�������
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
extern CWindow * winArr[30];//�洰��
extern map<string,CGoods>mymap_goods;//����Ʒ��Ϣ
extern string fuzzy_word;//ģ����ѯ
