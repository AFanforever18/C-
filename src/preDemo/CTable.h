#ifndef CTABLE_H
#define CTABLE_H
#pragma   warning (disable: 4786)
#include "CControl.h"
#include <sstream>
class CTable:public CControl
{
public:
	CTable();//Ĭ�Ϲ���
	CTable(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//���ι���--��������๹�촫��
	~CTable();//����
	void Control_Show();//�ؼ�չʾ
	void Control_Table_Show();//ģ����ѯ
};
#endif
extern string fuzzy_word;//ģ����ѯ
