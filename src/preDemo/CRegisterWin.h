#ifndef CREGISTERWIN_H
#define CREGISTERWIN_H
#include "CWindow.h"
#include <fstream>//文件头文件
#include "CFile.h"
#include "CUser.h"
class CRegisterWin:public CWindow
{
public:
	CRegisterWin();//默认构造
	CRegisterWin(int x,int y,int width,int height);//带参构造
	~CRegisterWin();//默认构造
	void doAction();//窗口的操作 每个都不一样 纯虚 所有子类重写
	bool reg();//注册操作

	//标签
	CLabel* title;
	CLabel* label_account;
	CLabel* label_name;
	CLabel* label_pwd;
	CLabel* label_check_pwd;
	//按钮
	CButton* manager;
	CButton* orderman;
	CButton* check;
	CButton* myexit;
	//编辑框
	CEdit* account;
	CEdit* name;
	CEdit* pwd;
	CEdit* check_pwd;
};
#endif
