#include "COrderManWin.h"
//默认构造
COrderManWin::COrderManWin()
{

}
//带参构造
COrderManWin::COrderManWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	

	//标签
	string str="欢迎使用仓储盘点机系统!";//更改主题
	//为了标签随窗口大小位置变动
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"日期: "+data);

	//按钮
	find_Btn=new CButton(this->getX()+16,this->getY()+10,18,2,1,1,0,BUTTON,"商品查询");
	order_Btn=new CButton(this->getX()+this->getWidth()-34,this->getY()+10,18,2,1,1,0,BUTTON,"仓库盘点");
	myexit=new CButton(this->getX()+16,this->getY()+18,18,2,1,1,0,BUTTON,"退出[Esc]");
		
	//添加控件
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(find_Btn);//商品查询--3
	addControl(order_Btn);//仓库盘点--4
	addControl(myexit);//退出--5

}

//默认构造
COrderManWin::~COrderManWin()
{
	
}
//重写父类纯虚函数
void COrderManWin::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
	case 3://商品查询
		int pageMax;
		if(mymap_goods.size()%5==0)
		{
			pageMax	=mymap_goods.size()/5;
		}else
		{
			pageMax	=mymap_goods.size()/5+1;
		}
		CTool::gotoxy(this->getX()+42,this->getY()+25);//提示消息位置
		system("pause");//按任意键继续
		system("cls");//清屏
		winArr[5]->getArr(1)->setTextConcent("欢迎:"+user_name);
		winArr[5]->getArr(9)->setPage(1);
		winArr[5]->getArr(9)->setPage_Max(pageMax);
		winArr[5]->getArr(9)->setCount(1);
		winArr[5]->CWindow_Show();//进入查询界面
		winArr[5]->winRun();
		break;
	case 4://仓库盘点
		system("cls");//清屏
		winArr[15]->getArr(1)->setTextConcent("欢迎:"+user_name);
		winArr[15]->CWindow_Show();//盘点
		winArr[15]->winRun();		break;
	case 5://退出
		winArr[8]->getArr(0)->setTitle("即将退出系统!");//更改提示消息
		winArr[8]->setTitleType("即将退出系统");//更改提示窗口类型
		CTool::clear(52,16,20,8);//局部刷新
		winArr[8]->CWindow_Show();//提示窗口
		winArr[8]->winRun(); 
		break;
	}
}
