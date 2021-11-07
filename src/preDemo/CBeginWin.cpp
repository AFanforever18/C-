#include "CBeginWin.h"
//默认构造
CBeginWin::CBeginWin()
{
	
}
//带参构造
CBeginWin::CBeginWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	//按钮
	login_Button=new CButton(52,8,18,2,1,1,0,BUTTON,"登入");
	reg_Button=new CButton(52,12,18,2,1,1,0,BUTTON,"注册");
	exit_Button=new CButton(52,16,18,2,1,1,0,BUTTON,"退出");

	//标签
	title=new CLabel(53,3,8,5,1,1,1,LABEL,"仓储盘点机项目");
	

	//添加控件
	addControl(title);
	addControl(login_Button);//控件数组下标--1--登入
	addControl(reg_Button);//控件数组下标--2--注册
	addControl(exit_Button);//控件数组下标--3--退出

}
//析构函数
CBeginWin::	~CBeginWin()
{

}
//重写父类纯虚函数
void CBeginWin::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
	case 1://进入登入界面
		CTool::gotoxy(52,20);
		system("pause");//按任意键继续
		system("cls");//清屏

		winArr[2]->CWindow_Show();
		winArr[2]->winRun();
		break;
	case 2://进入注册界面
		CTool::gotoxy(52,20);
		system("pause");//按任意键继续
		system("cls");//清屏
		winArr[1]->CWindow_Show();
		winArr[1]->winRun();
		break;
	case 3://退出系统
		winArr[8]->getArr(0)->setTitle("退出系统!");//更改提示消息
		winArr[8]->setTitleType("退出系统--开始界面");//更改提示窗口类型
		CTool::clear(52,16,20,8);//局部刷新
		winArr[8]->CWindow_Show();//提示窗口
		winArr[8]->winRun(); 
		break;
	}
}