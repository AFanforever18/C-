#ifndef CTIPS_CHECK_WIN_H
#define CTIPS_CHECK_WIN_H
#include "CWindow.h"
#include <fstream>
class CTips_Check_Win:public CWindow
{
public:
	 CTips_Check_Win(int x,int y,int width,int height);//带参构造
	void doAction();//重写父类纯虚函数
	void change_chcek_data();//改变商品冲正信息
	int get_check_state();//冲正状态 1--未冲正  2--冲正中 3--已冲正
	void change_order_num_and_state(string mycheck_state);//更改盘点编号和冲正状态容器的数据

	//按钮
	CButton* ok_Button;//确定
	CButton* cal_Button;//取消

	//编辑框
	CEdit* border;//用来当边框
	CEdit* edit_num;
	CEdit* edit_season;
	//标签
	CLabel* title;
	CLabel* title_num;
	CLabel* title_season;
};
#endif