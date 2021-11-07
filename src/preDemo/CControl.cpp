#include "CControl.h"
//默认构造函数
CControl::CControl()
{
	
}
//带参数析构函数
CControl::CControl(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content)
{
	this->x=x;
	this->y=y;
	this->width=width;
	this->height=height;
	this->length=length;//漏写
	this->state=state;
	this->intputtype=intputtype;
	this->type=type;
	this->content=content;
	this->page=1;//当前页数为1
	this->count=1;//默认普通翻页
	int page_Num=mymap_goods.size();
	if(page_Num%6==0)//一页六行
	{
		page_Num=page_Num/6;
	}else
	{
		page_Num=page_Num/6+1;
	}
	this->page_Max=page_Num;
}
//析构函数
CControl::~CControl()
{
	
}
//获取x坐标
int CControl::getX()
{
	return this->x;
}
//获取y坐标
int CControl::getY()
{
	return this->y;
}
//获取宽度
int CControl::getWidth()
{
	return this->width;
}
//获取高度
int CControl::getHeight()
{
	return this->height;
}
//获取最大长度
int CControl::getLength()
{
	return this->length;
}
//获取显示状态
int CControl::getState()
{
	return this->state;
}
//输出类型
int CControl::getIntputtype()
{
	return this->intputtype;
}
//控件类型
int CControl::getType()
{
	return this->type;
}
//获取页数
int CControl::getPage()
{
	return this->page;
}
//获取最大页数
int CControl::getPageMax()
{
	return this->page_Max;
}
//获取count
int CControl::getCount()
{
	return this->count;
}
//获取文本内容
string CControl::getContent()
{
	return this->content;
}
//更改翻页 0-left 1--right
void CControl::setCount(int x)
{
	this->count=x;//向左翻页
}
//改页数
void CControl::setPage(int page)
{
	this->page=page;
}
//改最大页数--模糊查询使用
void  CControl::setPage_Max(int page)
{
	this->page_Max=page;
}
//更改为文本内容
void CControl::setContent(int ikey)
{
	
	if(ikey=='\b')//删除
	{
		content.erase(content.end() -1);//将最后一个内容删除
		content.append("a");

	}
	else 
	{
		if(ikey!='\b')
		{
			char a=char(ikey);
			string str;
			str=a;
			content.append(str);
			//	content.erase(content.end() -1);//将最后一个内容删除
		}

	}

		
}
//模糊查询
void CControl::setContent_Fuzzy_Table(string word)
{
	this->content=word;
}
//文本内容置空--页面跳转用
void CControl::setContentNull()
{
	content="";
}
//账号控件文本内容更改--账号自增--注册用
void CControl::changeAccount(int num)
{
	map<int,CUser>::iterator iter;
	iter=mymap.end();
	//注册后在读一次文件 数据写入map
	mymap.erase(mymap.begin(),mymap.end());//清空容器再读一遍
	CFile::userFileRead();
	if(iter!=mymap.begin() || mymap.size()==1)//文件不为空
	{
		
		iter--;//找到最后一个账号id
		//将string变为int型
		string str=iter->second.getID();
		int temp=atoi(str.c_str());
		if(num==1)
		{
			gbl_accountNum++;//给全局变量		
		}
		temp++;
		// temp=temp;//给全局变量
		stringstream ss;
		string account_str;
		ss<<gbl_accountNum;//int->ss
		ss>>account_str;//ss->string
		content=account_str;
	}else//空文件
	{
		content="1002";
		gbl_accountNum++;
	}
}
//删除--回删除键
void CControl::delContent()
{
	content.erase(content.end() -1);//将最后一个内容删除
}
//虚函数--编辑框输入
void CControl::gbl_putstring(CControl* con,int ikey)
{
	
}
void CControl::sss()
{
	
}
//模糊查询
void CControl::Control_Table_Show()
{

}
//更改提示窗口提示内容
void CControl::setTitle(string newTitle)
{
	this->content=newTitle;
}
//更改文本内容
void CControl::setTextConcent(string word)
{
	this->content=word;
}