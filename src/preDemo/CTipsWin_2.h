#ifndef CTIPSWIN_2_H
#define CTIPSWIN_2_H
#include "CWindow.h"
class CTipsWin_2:public CWindow
{
private:
	string titleType;//�ж���ʾ��������
public:
	CTipsWin_2(int x,int y,int width,int height);//���ι���
	void doAction();//��д���ി�麯��
	string getTitleType();////��ȡ��ʾ��������
	void setTitleType(string word);////������ʾ��������
	//��ť
	CButton* enter_Button;
	CButton* add_Button;
	//��ǩ
	CLabel* title;
	CLabel* word;
};
#endif
