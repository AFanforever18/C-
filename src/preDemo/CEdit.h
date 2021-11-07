#ifndef CEdit_H
#define CEdit_H
#include "CControl.h"
class CEdit:public CControl
{
public:
	CEdit();//默认构造
	CEdit(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//带参构造--负责给父类构造传参
	~CEdit();//析构

	doAction();
	void Control_Show();//控件展示
	void gbl_putstring(CControl* con,int ikey);//键盘监听
};
#endif