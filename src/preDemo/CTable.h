#ifndef CTABLE_H
#define CTABLE_H
#pragma   warning (disable: 4786)
#include "CControl.h"
#include <sstream>
class CTable:public CControl
{
public:
	CTable();//默认构造
	CTable(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//带参构造--负责给父类构造传参
	~CTable();//析构
	void Control_Show();//控件展示
	void Control_Table_Show();//模糊查询
};
#endif
extern string fuzzy_word;//模糊查询
