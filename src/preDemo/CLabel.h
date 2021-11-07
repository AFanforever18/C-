#ifndef CLABEL_H
#define CLABEL_H
#include "CControl.h"
class CLabel:public CControl
{
public:
	CLabel();//默认构造
	CLabel(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//带参构造--负责给父类构造传参
	~CLabel();//析构

	doAction();
	void Control_Show();//控件展示
};
#endif