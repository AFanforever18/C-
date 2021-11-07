#ifndef CTIPSWIN_H
#define CTIPSWIN_H
#include "CWindow.h"
class CTipsWin:public CWindow
{
private:
	string titleType;//判定提示窗口类型
public:
	CTipsWin(int x,int y,int width,int height);//带参构造
	~CTipsWin();//默认析构
	void doAction();//重写父类纯虚函数
	string getTitleType();////获取提示窗口类型
	void setTitleType(string word);////设置提示窗口类型
	//按钮
	CButton* exit_Button;
	//标签
	CLabel* title;
	CLabel* exit_label;
};
#endif