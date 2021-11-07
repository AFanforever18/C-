#ifndef CTABLE_2_H
#define CTABLE_2_H
#pragma   warning (disable: 4786)
#include "CControl.h"
#include <sstream>
class CTable_2:public CControl
{
public:
	CTable_2();//默认构造
	CTable_2(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//带参构造--负责给父类构造传参
	~CTable_2();//析构
	void Control_Show();//控件展示
};
#endif
