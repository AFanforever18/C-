#include "CTipsWin_2.h"
//带参构造
CTipsWin_2::CTipsWin_2(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	titleType="未确定";
	//按钮
	enter_Button=new CButton(52,18,18,2,1,1,0,BUTTON,"重新输入");
	add_Button=new   CButton(52,21,18,2,1,1,0,BUTTON,"新增商品");

	//标签
	title=new CLabel(44,13,8,5,1,1,1, LABEL,"提示:");
	word=new  CLabel(44,15,8,5,1,1,1,LABEL,"未找到对应的商品");

	//添加控件
	addControl(title);
	addControl(word);
	addControl(enter_Button);//2--重新输入
	addControl(add_Button);//3--新增商品
}	
//获取提示窗口类型--提示窗口
string CTipsWin_2::getTitleType()
{
	return this->titleType;
}
//设置提示窗口类型--提示窗口
void CTipsWin_2::setTitleType(string word)
{
	this->titleType=word;
}
//重写父类纯虚函数
void CTipsWin_2::doAction()
{
	int i=this->getFocus();//获取当前操作下角标
	switch(i)
	{
	case 2://2--重新输入  
		system("cls");//清屏
		CTool::paintBorder(16,13,60,16);//商品信息边框
		winArr[12]->CWindow_Show();
		winArr[12]->winRun();
		break;
	case 3://3--新增商品
		system("cls");//清屏
		winArr[14]->getArr(4)->setTextConcent(winArr[12]->get_search_null());//新增商品的编号--来自入库窗口
		winArr[14]->getArr(12)->setTextConcent("new"+winArr[12]->get_search_null());//新增商品的仓位编号--来自入库窗口
		winArr[14]->CWindow_Show();
		winArr[14]->winRun();
		break;
	}
}
