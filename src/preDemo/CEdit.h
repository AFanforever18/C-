#ifndef CEdit_H
#define CEdit_H
#include "CControl.h"
class CEdit:public CControl
{
public:
	CEdit();//Ĭ�Ϲ���
	CEdit(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//���ι���--��������๹�촫��
	~CEdit();//����

	doAction();
	void Control_Show();//�ؼ�չʾ
	void gbl_putstring(CControl* con,int ikey);//���̼���
};
#endif