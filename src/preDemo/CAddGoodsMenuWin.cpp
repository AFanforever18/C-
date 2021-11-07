#include "CAddGoodsMenuWin.h"
//默认构造
CAddGoodsMenuWin::CAddGoodsMenuWin()
{
	
}
//带参构造
CAddGoodsMenuWin::CAddGoodsMenuWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	//按钮
	add_Button=new CButton(30,14,18,2,1,1,0,BUTTON,"入库");
	record_Button=new CButton(70,14,18,2,1,1,0,BUTTON,"入库记录");
	exit_Button=new CButton(30,22,18,2,1,1,0,BUTTON,"返回[Esc]");

	//标签
	title=new CLabel(50,3,8,5,1,1,1,LABEL,"欢迎使用xx盘点机系统");
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"日期: "+data);

	//添加控件
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(add_Button);//控件数组下标--3--入库
	addControl(record_Button);//控件数组下标--4--入库记录
	addControl(exit_Button);//控件数组下标--5--返回

}
//析构函数
CAddGoodsMenuWin::~CAddGoodsMenuWin()
{

}
//重写父类纯虚函数
void CAddGoodsMenuWin::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
	case 3://进入入库界面
		CTool::gotoxy(this->getX()+42,this->getY()+25);//提示消息位置
		system("pause");//按任意键继续
		system("cls");//清屏

		winArr[12]->getArr(1)->setTextConcent("欢迎:"+user_name);
		winArr[12]->CWindow_Show();
		CTool::paintBorder(16,13,60,16);//商品信息边框
		winArr[12]->winRun();
		break;
	case 4://进入入库记录界面
		break;
	case 5:
		CTool::gotoxy(52,29);
		system("pause");//按任意键继续
		system("cls");//清屏
		winArr[3]->CWindow_Show();//返回仓库管理界面
		winArr[3]->winRun();
		break;
	}
}