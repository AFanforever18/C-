#ifndef CTABLE_2_H
#define CTABLE_2_H
#pragma   warning (disable: 4786)
#include "CControl.h"
#include <sstream>
class CTable_2:public CControl
{
public:
	CTable_2();//Ĭ�Ϲ���
	CTable_2(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//���ι���--��������๹�촫��
	~CTable_2();//����
	void Control_Show();//�ؼ�չʾ
};
#endif
