#ifndef CMANAGERMENUWIN_H
#define CMANAGERMENUWIN_H
#include "CWindow.h"
class CManagerMenuWin:public CWindow
{
public:
	CManagerMenuWin();//默认构造
	CManagerMenuWin(int x,int y,int width,int height);//默认构造//带参构造
	~CManagerMenuWin();//默认析构
	void doAction();//窗口的操作 每个都不一样 纯虚 所有子类重写

	//标签
	CLabel* title;
	CLabel* managername;
	CLabel* mydate;
	//按钮
	CButton* find_Btn;
	CButton* import_Btn;
	CButton* input_Btn;
	CButton* output_Btn;
	CButton* orderCheck_Btn;
	CButton* myexit;
};

#endif
