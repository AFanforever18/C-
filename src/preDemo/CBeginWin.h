#ifndef CBEGINWIN_H
#define CBEGINWIN_H
#include "CWindow.h"
class CBeginWin:public CWindow
{
public:
	CBeginWin();//Ĭ�Ϲ���
	CBeginWin(int x,int y,int width,int height);//���ι���
	~CBeginWin();//��������
	void doAction();//��д���ി�麯��

	//��ť
	CButton* login_Button;//����
	CButton* reg_Button;//ע��
	CButton* exit_Button;//�˳�

	//��ǩ
	CLabel* title;
	CLabel* stu_num;
};
#endif