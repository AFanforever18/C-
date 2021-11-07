#ifndef CBUTTON_H
#define CBUTTON_H
#include "CControl.h"
class CButton:public CControl
{
public:
	CButton();//默认构造
	CButton(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//带参构造--负责给父类构造传参
	~CButton();//析构

	doAction();
	void Control_Show();//控件展示
	void sss();
};
#endif