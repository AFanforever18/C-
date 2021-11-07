#ifndef CLOGIN_H
#define CLOGIN_H
#pragma   warning (disable: 4786)
#include "CWindow.h"
#include <fstream>//文件头文件
#include <map>
#include "CUser.h"
class CLogin:public CWindow
{
public:
	CLogin();//默认构造
	CLogin(int x,int y,int width,int height);//带参构造
	~CLogin();//默认构造
	void doAction();//窗口的操作 每个都不一样 纯虚 所有子类重写
	bool login();//登入操作

	//标签
	CLabel* title;
	CLabel* label_account;
	CLabel* label_pwd;
	//按钮
	CButton* check;
	CButton* myexit;
	//编辑框
	CEdit* account;
	CEdit* pwd;
};
#endif
