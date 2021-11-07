#include "CWindow.h"
//#include "CLogin.h"
//默认构造函数
CWindow::CWindow()//注册小窗口用
{
	this->count=0;//控件数一开始为0
	this->focus=0;//enter操作下标一开始为0
	this->num=0;;
	for(int i=0;i<sizeof(arr)/sizeof(CControl *);i++)
	{
		arr[i]=NULL;
	}
}
//默认析构函数
CWindow::~CWindow()
{
	
}
//带参构造函数
CWindow::CWindow(int x,int y,int width,int height)
{
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	this->count=0;//控件数一开始为0
	this->focus=0;//enter操作下标一开始为0
	this->num=0;
	for(int i=0;i<sizeof(arr)/sizeof(CControl *);i++)
	{
		arr[i]=NULL;
	}
	this->type="";//窗口类型
}
//获取控件数
int CWindow::getCount()
{
	return count;
}
//添加控件
void CWindow::addControl(CControl *con)
{
	arr[this->count]=con;
	this->count++;
}
//画窗口
void CWindow::CWindow_Show()
{
	//标题下--分割线
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),4);
	//画外边框
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),this->getHeight());
	for(int i=0;i<this->count;i++)
	{
		arr[i]->Control_Show();
	}
}
//画窗口--模糊查询
void CWindow::CWindow_Table_Show()
{
	arr[4]->setContent_Fuzzy_Table(fuzzy_word);	
	//标题下--分割线
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),4);
	//画外边框
	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),this->getHeight());
	for(int i=0;i<this->count;i++)
	{
		if(arr[i]->getContent()=="查询")
		{	
			arr[i]->Control_Table_Show();
		}else{
			arr[i]->Control_Show();
		}

	}
}
//画窗口--选择用户类型窗口
void CWindow::CWindow_Show_Select()
{
	CTool::paintBorder(this->x,this->y,this->width,this->height);
	for(int i=0;i<this->count;i++)
	{
			arr[i]->Control_Show();
	}	
}
//获取x坐标
int CWindow::getX()
{	
	return this->x;
}
//获取y坐标
int CWindow::getY()
{
	return this->y;
}
//获取宽
int CWindow::getWidth()
{
	return this->width;
}
//获取高
int CWindow::getHeight()
{
	return this->height;
}
//获取enter操作下标
int CWindow::getFocus()
{
	return this->focus;
}
//获取num
int CWindow::getNum()
{
	return this->num;	
}
//获取控件数组
CControl* CWindow::getArr(int x)
{
	return this->arr[x];
}
//光标移动
void CWindow::winRun()
{
	int ikey=0;
	int i;//当前控件数组位置
	for(i=0;i<this->count;i++)//遍历找到edit 和button
	{
		if(this->arr[i]->getType()==EDIT || this->arr[i]->getType()==BUTTON)
		{
			break;
		}
	}
	//定位光标起始位置
	if(this->arr[i]->getType()==EDIT)
	{
		CTool::gotoxy(this->arr[i]->getX()+2+this->arr[i]->getContent().size(),this->arr[i]->getY()+1);//EDIT
	}
	else{
		CTool::gotoxy(this->arr[i]->getX()+2,this->arr[i]->getY()+1);//BUTTON
	}
	while(1)//
	{
		//获取当前edit内容长度
		int len=0;
		ikey=CTool::Key();

		switch(ikey)
		{
		case -4://→右
			if(this->getCount()<7)//避免其他界面翻页
				break;
			//*********盘点报表--右翻页**********//
			if(this->arr[6]->getContent()=="结束盘点")
			{
				page_current++;
				int page_max;
				if(temp_list.size()%5==0)//得到最大页数
				{
					page_max=temp_list.size()/5;
				}else
				{
					page_max=temp_list.size()/5+1;
				}
				if(page_current>page_max)
				{
					winArr[8]->getArr(0)->setTitle("已到最后一页!");//更改提示消息
					winArr[8]->setTitleType("盘点报表--已到最后一页");//更改提示窗口类型
					CTool::clear(52,16,20,8);//局部刷新
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::prtinf_Table_Content(temp_list);//打印盘点报表
			}
			//*********冲正--选择数据--右翻页**********//
			if(this->arr[4]->getContent()=="盘点编号")
			{
				page_current_2++;
				int page_max;
				if(mymap_order_num.size()%7==0)//得到最大页数
				{
					page_max=mymap_order_num.size()/7;
				}else
				{
					page_max=mymap_order_num.size()/7+1;
				}
				if(page_current_2>page_max)
				{
					winArr[8]->getArr(0)->setTitle("已到最后一页!");//更改提示消息
					winArr[8]->setTitleType("盘点编号--冲正--已到最后一页");//更改提示窗口类型
					CTool::clear(52,16,20,8);//局部刷新
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::printf_Table_Order();//打印盘点编号和冲正状态
			}
			//*********冲正--7个属性-右翻页**********//
			if(this->arr[5]->getContent()=="完成冲正")
			{
				page_current_4++;
				int page_max;
				if(map_check.size()%6==0)//得到最大页数
				{
					page_max=map_check.size()/6;
				}else
				{
					page_max=map_check.size()/6+1;
				}
				if(page_current_4>page_max)
				{
					winArr[8]->getArr(0)->setTitle("已到最后一页!");//更改提示消息
					winArr[8]->setTitleType("7个属性--冲正--已到最后一页");//更改提示窗口类型
					CTool::clear(52,16,20,8);//局部刷新
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::printf_Table_Order_All();//打印冲正信息--7个属性
			}
			//*********搜索--右翻页**********//
			if(this->arr[5]->getContent()=="查询" && this->arr[9]->getCount()==1)
			{
				this->arr[9]->setPage(this->arr[9]->getPage()+1);//按右页数+1
				if(this->arr[9]->getPage()>this->arr[9]->getPageMax() )//如果页数位=为pageMax 不可以右翻页
				{
					this->arr[9]->setPage(this->arr[9]->getPage()-1);//按右页数+1
					winArr[8]->getArr(0)->setTitle("已到最后一页!");//更改提示消息
					winArr[8]->setTitleType("搜索翻页--已到最后一页");//更改提示窗口类型
					CTool::clear(52,16,20,8);//局部刷新
					winArr[8]->CWindow_Show();//提示窗口
					winArr[8]->winRun(); 		
				}else{
					winArr[5]->CWindow_Show();//翻页
				}
			}
			//*********模糊搜索--右翻页**********//
			if(this->arr[5]->getContent()=="查询" && this->arr[9]->getCount()==666)
			{
				this->arr[9]->setPage(this->arr[9]->getPage()+1);//按右页数+1
				if(this->arr[9]->getPage()>this->arr[9]->getPageMax())//如果页数位=为pageMax 不可以右翻页
				{
					this->arr[9]->setPage(this->arr[9]->getPage()-1);
					winArr[8]->getArr(0)->setTitle("到最后一页,回主页!");//更改提示消息
					winArr[8]->setTitleType("搜索翻页--已到最后一页--模糊");//更改提示窗口类型
					CTool::clear(52,16,20,8);//局部刷新
					winArr[8]->CWindow_Show();//提示窗口
					winArr[8]->winRun(); 		
				}else{
					winArr[6]->CWindow_Table_Show();//模糊
				}
			}
			break;

		case -2: //向下    遇到BUTTON 和EDIT 有不同的光标定位
			i++;
			if(i>=this->count)//控件如果为最后一个,继续按下键,则跳到第一个控件
			{
				i=0;
			}
			while(this->arr[i]->getType()==LABEL)//遇到LABEL直接跳过
			{
				i++;
			if(i>=this->count)//控件如果为最后一个,继续按下键,则跳到第一个控件
			{
				i=0;
			}
			}
			if(this->arr[i]->getType()==EDIT)
			{
				len=arr[i]->getContent().length();
				if(len>0)
				{
					CTool::gotoxy(this->arr[i]->getX()+2+len,this->arr[i]->getY()+1);//光标位置 x 坐标要加上内容长度				
				}else
				{
					CTool::gotoxy(this->arr[i]->getX()+2,this->arr[i]->getY()+1);//len<=0 不用改变
				}
			}else//BUTTON 控件
			{
				CTool::gotoxy(this->arr[i]->getX()+2,this->arr[i]->getY()+1);//BUTTON光标定位
			}
			break;
		case -3://→左
			if(this->getCount()<7)//避免其他界面翻页
				break;

			//*********盘点报表--左翻页**********//
			if(this->arr[6]->getContent()=="结束盘点")
			{
				page_current--;
				int page_max;
				if(temp_list.size()%5==0)//得到最大页数
				{
					page_max=temp_list.size()/5;
				}else
				{
					page_max=temp_list.size()/5+1;
				}
				if(page_current<1)//页数小于1
				{
					winArr[8]->getArr(0)->setTitle("已到第一页!");//更改提示消息
					winArr[8]->setTitleType("盘点报表--已到第一页");//更改提示窗口类型
					CTool::clear(52,16,20,8);//局部刷新
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::prtinf_Table_Content(temp_list);//打印盘点报表
			}
			//*********--冲正--选择数据--左翻页**********//
			if(this->arr[4]->getContent()=="盘点编号")
			{
				page_current_2--;	
				int page_max;
				if(mymap_order_num.size()%7==0)//得到最大页数
				{
					page_max=mymap_order_num.size()/7;
				}else
				{
					page_max=mymap_order_num.size()/7+1;
				}
			
				if(page_current_2<1)//页数小于1
				{
					winArr[8]->getArr(0)->setTitle("已到第一页!");//更改提示消息
					winArr[8]->setTitleType("盘点编号--冲正--已到第一页");//更改提示窗口类型
					CTool::clear(52,16,20,8);//局部刷新
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::printf_Table_Order();//打印盘点报表
			}
			//*********--冲正--7个属性--左翻页**********//
			if(this->arr[5]->getContent()=="完成冲正")
			{
				page_current_4--;	
				int page_max;
				if(mymap_order_num.size()%6==0)//得到最大页数
				{
					page_max=mymap_order_num.size()/6;
				}else
				{
					page_max=mymap_order_num.size()/6+1;
				}
			
				if(page_current_4<1)//页数小于1
				{
					winArr[8]->getArr(0)->setTitle("已到第一页!");//更改提示消息
					winArr[8]->setTitleType("7个属性--冲正--已到第一页");//更改提示窗口类型
					CTool::clear(52,16,20,8);//局部刷新
					winArr[8]->CWindow_Show();
					winArr[8]->winRun(); 
					break;
				}
				CTool::printf_Table_Order_All();//打印冲正信息--7个属性
			}
			
			//*********搜索--左翻页**********//
			if(this->arr[5]->getContent()=="查询" && this->arr[9]->getCount()==1)
			{
				this->arr[9]->setPage(this->arr[9]->getPage()-1);//按左页数-1
				if(this->arr[9]->getPage()<1)//如果页数位=为pageMax 不可以右翻页
				{
					this->arr[9]->setPage(this->arr[9]->getPage()+1);//按右页数+1
					winArr[8]->getArr(0)->setTitle("已到第一页!");//更改提示消息
					winArr[8]->setTitleType("搜索翻页--已到第一页");//更改提示窗口类型
					CTool::clear(52,16,20,8);//局部刷新
					winArr[8]->CWindow_Show();//提示窗口
					winArr[8]->winRun(); 		
				}else{
					winArr[5]->CWindow_Show();//翻页
				}
			}
			//*********模糊搜索--左翻页**********//
			if(this->arr[5]->getContent()=="查询" && this->arr[9]->getCount()==666)
			{
				this->arr[9]->setPage(this->arr[9]->getPage()-1);//按左页数-1
				if(this->arr[9]->getPage()<1)//如果页数位=为pageMax 不可以右翻页
				{
					this->arr[9]->setPage(this->arr[9]->getPage()+1);//按右页数+1
					winArr[8]->getArr(0)->setTitle("已到第一页,回主页!");//更改提示消息
					winArr[8]->setTitleType("搜索翻页--已到第一页--模糊");//更改提示窗口类型
					CTool::clear(52,16,20,8);//局部刷新
					winArr[8]->CWindow_Show();//提示窗口
					winArr[8]->winRun(); 		
				}else{
					winArr[6]->CWindow_Table_Show();//模糊
				}
			}

			break;
		case -1: //向上

			i--;
			if(i<=-1)//控件如果为第一个,继续按上键,则跳到最后一个控件
			{
				i=this->count-1;
			}else
			{
				while(this->arr[i]->getType()==LABEL)
				{
					i--;
					if(i<=-1)
					{
						i=this->count-1;
					}
				}
			}
				if(this->arr[i]->getType()==EDIT)
			{
				len=arr[i]->getContent().length();
				if(len>0)
				{
					CTool::gotoxy(this->arr[i]->getX()+2+len,this->arr[i]->getY()+1);//光标位置 x 坐标要加上内容长度				
				}else
				{
					CTool::gotoxy(this->arr[i]->getX()+2,this->arr[i]->getY()+1);//len<=0 不用改变
				}
			}else//BUTTON 控件
			{
				CTool::gotoxy(this->arr[i]->getX()+2,this->arr[i]->getY()+1);//BUTTON光标定位
			}
			break;
		case '\r'://回车

			//页面跳转
			if(this->arr[i]->getType()==BUTTON)
			{
				if(this->arr[i]->getContent()=="[Enter]选择类型")
				{
						winArr2[0]->CWindow_Show_Select();
						winArr2[0]->winRun();
				}
				if(this->arr[i]->getContent()=="盘点员")
				{
					system("cls");
						winArr2[1]->CWindow_Show();
						winArr2[1]->winRun();

				}
				if(this->arr[i]->getContent()=="仓库管理员")
				{
					system("cls");
						winArr2[2]->CWindow_Show();
						winArr2[2]->winRun();
				}
				this->focus=i;
				this->doAction();
			}
			
			break;
			 if(this->arr[i]->getType()==BUTTON && this->arr[i]->getContent()=="取消")
		//	reg(win);
			break;
		case 27://ESC退出
			//学号--显示下脚标
			CTool::gotoxy(this->getX()+this->getWidth()-60,this->getY()+this->getHeight()-3);
			system("pause");
			system("cls");
			winArr[0]->CWindow_Show();
			winArr[0]->winRun();
			break;
		default://不是上下左右键
			if(this->arr[i]->getType()==EDIT)
			{
				arr[i]->gbl_putstring(arr[i], ikey);
			}
		}
	}
}
//换控件
void CWindow::change(CControl* con,int i)
{
	this->arr[i]=con;
}
void CWindow::search(string word)//查询打印商品信息--出库窗口
{
	
}
//获取输入的商品编码--出库窗口  盘点窗口
string CWindow::get_Search_word()
{
   return "s";
}
//获取输入的未查询到的商品编码--出库窗口  盘点窗口
string CWindow::get_search_null()
{
   return "s";
}
//获取输入的出库数量--出库窗口
int CWindow::get_input_Goods_Num()
{
	return 0;
}
//获取提示窗口类型--提示窗口
string CWindow::getTitleType()
{
	string a="未定义";
	return a;
}
//设置提示窗口类型--提示窗口
void CWindow::setTitleType(string word)
{
	
}
//获取输入的盘点数量--盘点窗口
string CWindow::get_Order_num()
{
	return "0";
}//获取盘点编号--盘点报表
string CWindow::get_makeOrder_Num()
{
	return "0";
}
int CWindow::fuzzyQuery()//模糊查询
{
	int a=0;
	return a;
}