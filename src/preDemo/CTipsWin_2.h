#ifndef CTIPSWIN_2_H
#define CTIPSWIN_2_H
#include "CWindow.h"
class CTipsWin_2:public CWindow
{
private:
	string titleType;//判定提示窗口类型
public:
	CTipsWin_2(int x,int y,int width,int height);//带参构造
	void doAction();//重写父类纯虚函数
	string getTitleType();////获取提示窗口类型
	void setTitleType(string word);////设置提示窗口类型
	//按钮
	CButton* enter_Button;
	CButton* add_Button;
	//标签
	CLabel* title;
	CLabel* word;
};
#endif
