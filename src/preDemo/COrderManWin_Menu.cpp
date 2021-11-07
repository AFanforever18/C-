#include "COrderManWin_Menu.h"
//带参构造
COrderManWin_Menu::COrderManWin_Menu(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	//标签
	string str="欢迎使用仓储盘点机系统!";//更改主题
	//为了标签随窗口大小位置变动
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"日期: "+data);

	//按钮
	newOrder_Btn=new CButton(this->getX()+16,this->getY()+10,18,2,1,1,0,BUTTON,"新建盘点");
	orderRecord_Btn=new CButton(this->getX()+this->getWidth()-34,this->getY()+10,18,2,1,1,0,BUTTON,"盘点记录");
	myexit=new CButton(this->getX()+16,this->getY()+18,18,2,1,1,0,BUTTON,"返回[Esc]");
		
	//添加控件
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(newOrder_Btn);//新建盘点--3
	addControl(orderRecord_Btn);//盘点记录--4
	addControl(myexit);//返回Esc-5

}

//重写父类纯虚函数
void COrderManWin_Menu::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
	case 3://新建盘点
		system("cls");//清屏
		winArr[9]->getArr(1)->setTextConcent("欢迎:"+user_name);
		winArr[9]->CWindow_Show();//进入商品查询
		CTool::paintBorder(16,13,60,16);//存入商品信息边框
		winArr[9]->winRun();
		break;
	case 4://盘点记录
		system("cls");//清屏
		winArr[17]->getArr(1)->setTextConcent("用户:"+user_name+"<盘点员>");
		winArr[17]->CWindow_Show();	
		CTool::printf_Table_Order();//盘点编号和冲正状态
		winArr[17]->winRun();//盘点冲正--选择冲正数据
		break;
	case 5://返回
		system("cls");
		winArr[4]->CWindow_Show();
		winArr[4]->winRun();
		break;
	}
}
