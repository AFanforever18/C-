#ifndef CTABLE_3_H//ͨ��
#define CTABLE_3_H
#pragma   warning (disable: 4786)
#include "CControl.h"
#include <sstream>
class CTable_3:public CControl
{
public:
	CTable_3(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//���ι���--��������๹�촫��
	void Control_Show();//�ؼ�չʾ
};
#endif
