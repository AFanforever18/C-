#include "COrderTableWin.h"
//默认构造
COrderTableWin::COrderTableWin()
{
	
}
//默认构造//带参构造
COrderTableWin::COrderTableWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	string str="欢迎使用仓储盘点机系统!";//更改主题
	//标签
	//为了标签随窗口大小位置变动
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"日期: "+data);
	order_state=new CLabel(this->getX()+this->getWidth()-20,this->getY()+7,20,2,1,1,0,LABEL,"盘点状态:进行中");
	orderNum=new CLabel(this->getX()+2,this->getY()+7,20,2,1,1,0,LABEL,"盘点编号:");
	jiantou=new CLabel(this->getX()+58,this->getY()+26,18,2,1,1,0,LABEL,"按←→翻页");
	page_num=new CLabel(this->getX()+46,this->getY()+26,20,2,1,1,0,LABEL,"1/1");

	//按钮
	myexit=new CButton(this->getX()+76,this->getY()+24,18,2,1,1,0,BUTTON,"返回[Esc]");
	over_order=new CButton(this->getX()+8,this->getY()+24,18,2,1,1,0,BUTTON,"结束盘点");

	//表格
	table=new CTable_2(this->getX()+14,this->getY()+11,6,5,1,1,0,LABEL,"查询");	
	//添加控件
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(orderNum);//3
	addControl(table);
	addControl(order_state);
	addControl(over_order);//结束盘点按钮--6
	addControl(myexit);//返回--
	addControl(jiantou);//→←↑↓
	addControl(page_num);//页数
	printf_Content();//打印商品信息

}
//默认析构
COrderTableWin::~COrderTableWin()
{
	
}
void COrderTableWin::printf_Content()//打印商品信息
{

}
//窗口的操作 每个都不一样 纯虚 所有子类重写
void COrderTableWin::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
		case 6://结束盘点 
		//清空文本
		system("cls");
		winArr[9]->CWindow_Show();//回盘点菜单界面
		winArr[9]->winRun();
			break;
		case 7://返回 
		//清空文本
		system("cls");
		winArr[9]->CWindow_Show();//回新建盘点界面
		CTool::paintBorder(16,13,60,16);//存入商品信息边框
		winArr[9]->winRun();
			break;

	}
}