#include "CManagerMenuWin.h"
//默认构造
CManagerMenuWin::CManagerMenuWin()
{

}
//带参构造
CManagerMenuWin::CManagerMenuWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{


	//标签
	string str="欢迎使用仓储盘点机系统!";//为了标签随窗口大小位置变动
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
//	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),4);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"日期: "+data);

	//按钮
	find_Btn=new CButton(this->getX()+16,this->getY()+10,18,2,1,1,0,BUTTON,"商品查询");
	import_Btn=new CButton(this->getX()+this->getWidth()-34,this->getY()+10,18,2,1,1,0,BUTTON,"导入商品");
	input_Btn=new CButton(this->getX()+16,this->getY()+14,18,2,1,1,0,BUTTON,"商品入库");
	output_Btn=new CButton(this->getX()+this->getWidth()-34,this->getY()+14,18,2,1,1,0,BUTTON,"商品出库");
	orderCheck_Btn=new CButton(this->getX()+16,this->getY()+18,18,2,1,1,0,BUTTON,"盘点冲正");
	myexit=new CButton(this->getX()+this->getWidth()-34,this->getY()+18,18,2,1,1,0,BUTTON,"退出[Esc]");
		
	//添加控件
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(find_Btn);//商品查询--3
	addControl(import_Btn);//导入商品--4
	addControl(input_Btn);//商品入库--5
	addControl(output_Btn);//商品出库--6
	addControl(orderCheck_Btn);//盘点冲正--7
	addControl(myexit);//退出--8



}

//默认构造
CManagerMenuWin::~CManagerMenuWin()
{
	
}
//重写父类纯虚函数
void CManagerMenuWin::doAction()
{
	int pageMax;
	if(mymap_goods.size()%5==0)
	{
		pageMax	=mymap_goods.size()/5;
	}else
	{
		pageMax	=mymap_goods.size()/5+1;
	}
	int i=this->getFocus();
	switch(i)
	{
	case 3:
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
	case 4:
		break;
	case 5:
		CTool::gotoxy(this->getX()+42,this->getY()+25);//提示消息位置
		system("pause");//按任意键继续
		system("cls");//清屏
		winArr[11]->getArr(1)->setTextConcent("欢迎:"+user_name);
		winArr[11]->CWindow_Show();//进入入库菜单窗口
		winArr[11]->winRun(); 
		break;
	case 6://进入出库窗口
		CTool::gotoxy(this->getX()+42,this->getY()+25);//提示消息位置
		system("pause");//按任意键继续
		system("cls");//清屏
		winArr[7]->getArr(1)->setTextConcent("欢迎:"+user_name);
		CTool::paintBorder(16,13,60,16);
		winArr[7]->CWindow_Show();
		winArr[7]->winRun(); 
		break;
	case 7:
		system("cls");//清屏
		winArr[17]->getArr(1)->setTextConcent("用户:"+user_name+"<仓库管理者>");
		winArr[17]->CWindow_Show();	
		CTool::printf_Table_Order();//盘点编号和冲正状态
		winArr[17]->winRun();//盘点冲正--选择冲正数据
		break;
	case 8:
		winArr[8]->getArr(0)->setTitle("即将退出系统!");//更改提示消息
		winArr[8]->setTitleType("即将退出系统");//更改提示窗口类型
		CTool::clear(52,16,20,8);//局部刷新
		winArr[8]->CWindow_Show();//提示窗口
		winArr[8]->winRun(); 
		break;
	}
}
