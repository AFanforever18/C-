#ifndef CLABEL_H
#define CLABEL_H
#include "CControl.h"
class CLabel:public CControl
{
public:
	CLabel();//Ĭ�Ϲ���
	CLabel(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//���ι���--��������๹�촫��
	~CLabel();//����

	doAction();
	void Control_Show();//�ؼ�չʾ
};
#endif