#ifndef CTABLE_3_H//通用
#define CTABLE_3_H
#pragma   warning (disable: 4786)
#include "CControl.h"
#include <sstream>
class CTable_3:public CControl
{
public:
	CTable_3(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//带参构造--负责给父类构造传参
	void Control_Show();//控件展示
};
#endif
