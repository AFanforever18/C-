#ifndef CGOODSSEARCH_H
#define CGOODSSEARCH_H
#pragma   warning (disable: 4786)
#include "CWindow.h"
#include <sstream>
#include <string>
class CGoodsSearchWin:public CWindow
{
public:
	CGoodsSearchWin();//Ĭ�Ϲ���
	CGoodsSearchWin(int x,int y,int width,int height);//Ĭ�Ϲ���//���ι���
	~CGoodsSearchWin();//Ĭ������
	void doAction();//���ڵĲ��� ÿ������һ�� ���� ����������д
	int accurateQuery();//��ȷ��ѯ
	int fuzzyQuery();//ģ����ѯ
	void input_goods_data();//������Ʒ��Ϣ
	//��ǩ
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;
	CLabel* inputNum_label;
	CLabel* tableNum_label;
	//�༭��
	CEdit* inputNum_edit;
	//��ť
	CButton* find_Btn;//��Ʒ��ѯ
	CButton* import_Btn;//������Ʒ
	CButton* myexit;//�˳�
	//���
	CTable* table;
};
#endif
