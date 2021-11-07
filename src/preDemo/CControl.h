#ifndef CCONTROL_H
#define CCONTROL_H
#pragma   warning (disable: 4786)
#include <iostream>
#include <string>
#include <sstream>//int to string
#include <map>//自动生成账号用
#include "CUser.h"
#include "CTool.h"
#include "CFile.h"

#define EDIT 1
#define LABEL 2
#define BUTTON 3
#define MODE_TEXT 1///名文
#define MODE_PWD 2//密文
using namespace std;
/*CControl为Edit,Button,Label等控件的父类*/
class CControl
{
private:
	int x;//x坐标
	int y;//y坐标
	int width;//宽度
	int height;//高度
	int length;//最大长度
	int state;//显示 1明文 2密文
	int intputtype;//输出类型 0无控制 1字母 2数字 3数字加字母 4 数字+"."  5 中文
	int type;//控件类型
	string content;//文本内容
	int page;//当前页数
	int page_Max;//最大页数
	int count;//0--left   1--rigeht
	
public:
	CControl();//默认构造函数
	CControl(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//带参数析构函数
	~CControl();//析构函数

	int getX();//获取x坐标
	int getY();//获取y坐标
	int getWidth();//获取宽度
	int getHeight();//获取高度
	int getLength();//获取最大长度
	int getState();//获取显示状态
	int getIntputtype();//输出类型
	int getType();//控件类型
	int getPage();//获取页数
	int getPageMax();//获取最大页数
	int getCount();//获取count
	string getContent();//获取文本内容
	void setPage(int page);//改页数
	void setPage_Max(int page);//改最大页数--模糊查询使用
	void setCount(int x);//更改翻页 0-left 1--right
	void setContent(int ikey);//更改为文本内容--回删用
	void setTextConcent(string word);//更改文本内容
	void setContentNull();//文本内容置空--页面跳转用
	void setContent_Fuzzy_Table(string word);//模糊查询
	void setTitle(string newTitle);//更改提示窗口提示内容--出库窗口
	void changeAccount(int num);//账号控件文本内容更改--账号自增  int num 为账号是否加1 0--不加 1--加
	void delContent();//删除
	virtual void gbl_putstring(CControl* con,int ikey);//需要的子类重写
	virtual void Control_Show()=0;//纯虚函数 子类必须重写 函数名 参数列表 返回值类型 父类不用写 只要声明纯虚函数
	virtual	void Control_Table_Show();//模糊查询
	virtual void sss();
};
#endif
extern map<int,CUser>mymap;//用户信息
extern map<string,CGoods>mymap_goods;//存商品信息
extern gbl_accountNum;//生成账号用的