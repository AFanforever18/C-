#ifndef CADDGODDSMENUWIN_H
#define CADDGODDSMENUWIN_H
#include "CWindow.h"
class CAddGoodsMenuWin:public CWindow
{
public:
	CAddGoodsMenuWin();//Ĭ�Ϲ���
	CAddGoodsMenuWin(int x,int y,int width,int height);//���ι���
	~CAddGoodsMenuWin();//��������
	void doAction();//��д���ി�麯��

	//��ť
	CButton* add_Button;//����
	CButton* record_Button;//ע��
	CButton* exit_Button;//�˳�

	//��ǩ
	CLabel* title;//����
	CLabel* managername;//�û���
	CLabel* mydate;//����
};
#endif