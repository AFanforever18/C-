#ifndef CTIPSWIN_H
#define CTIPSWIN_H
#include "CWindow.h"
class CTipsWin:public CWindow
{
private:
	string titleType;//�ж���ʾ��������
public:
	CTipsWin(int x,int y,int width,int height);//���ι���
	~CTipsWin();//Ĭ������
	void doAction();//��д���ി�麯��
	string getTitleType();////��ȡ��ʾ��������
	void setTitleType(string word);////������ʾ��������
	//��ť
	CButton* exit_Button;
	//��ǩ
	CLabel* title;
	CLabel* exit_label;
};
#endif