#ifndef CBUTTON_H
#define CBUTTON_H
#include "CControl.h"
class CButton:public CControl
{
public:
	CButton();//Ĭ�Ϲ���
	CButton(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//���ι���--��������๹�촫��
	~CButton();//����

	doAction();
	void Control_Show();//�ؼ�չʾ
	void sss();
};
#endif