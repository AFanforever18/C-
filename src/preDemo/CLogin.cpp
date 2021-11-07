#include "CLogin.h"
//默认构造
CLogin::CLogin()
{

}
//带参构造
CLogin::CLogin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	

	//标签
	string str="用户登入";//为了标签随窗口大小位置变动
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
//	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),4);
	label_account=new CLabel(34,12,40,2,20,MODE_TEXT,0,LABEL,"帐    号 :");
	label_pwd=new CLabel(34,18,40,2,20,MODE_PWD,0,LABEL,"密    码 :");

	//按钮
	check=new CButton(this->getX()+10,this->getY()+24,18,2,1,1,0,BUTTON,"确定[Enter]");
	myexit=new CButton(this->getX()+this->getWidth()-28,this->getY()+24,18,2,1,1,0,BUTTON,"取消[Esc]");
		
	//编辑框         //输出类型 0无控制 1字母 2数字 3数字加字母
	account=new CEdit(48,12,40,2,20,MODE_TEXT,2,EDIT,"");
	pwd=new CEdit(48,18,40,2,10,MODE_PWD,2,EDIT,"");

	//添加控件
	addControl(account);//0
	addControl(label_account);
	addControl(label_pwd);
	addControl(title);
	addControl(pwd);
	addControl(check);//第5个控件
	addControl(myexit);//第6个控件
}

//默认析构
CLogin::~CLogin()
{
	
}
//重写父类纯虚函数
void CLogin::doAction()
{
	int i=this->getFocus();//在第几个控件
	bool ret;
	switch(i)//选择所在控件完成不同的操作
	{
		case 5:
			ret=login();
			if(ret)//登入成功
			{
				map<int,CUser>::iterator iter=mymap.find(current_Account);//去用户容器mymap查找--当前登入账号
				if(iter->second.getrole()==1)//盘点员
				{
					CTool::gotoxy(this->getX()+48,this->getY()+26);//提示消息位置
					system("pause");
					system("cls");
					winArr[4]->getArr(1)->setTextConcent("欢迎:"+user_name);
					winArr[4]->CWindow_Show();//盘点员--主界面--4
					winArr[4]->winRun();
				}else if(iter->second.getrole()==2)//仓库管理员
				{
					CTool::gotoxy(this->getX()+48,this->getY()+26);//提示消息位置
					system("pause");
					system("cls");
					winArr[3]->getArr(1)->setTextConcent("欢迎:"+user_name);
					winArr[3]->CWindow_Show();//仓库管理员--主界面--
					winArr[3]->winRun();
				}



				winArr[3]->CWindow_Show();
				winArr[3]->winRun();
			}else//登入失败
			{
				CTool::gotoxy(this->getX()+46,this->getY()+26);//提示消息位置
				system("pause");
				system("cls");
				winArr[2]->CWindow_Show();//登入界面
				winArr[2]->winRun();		
			}
			break;
			case 6://回到开始界面
			CTool::gotoxy(this->getX()+42,this->getY()+25);//提示消息位置
			system("pause");//按任意键继续
			system("cls");//清屏
			//回主界面也清空accout和pwd文本
			account->setContentNull();
			pwd->setContentNull();
			winArr[0]->CWindow_Show();
			winArr[0]->winRun();
			break;
	}
}

bool CLogin::login()//登入操作
{
	map<int,CUser>::iterator iter;

	string str=this->account->getContent();
	int a=atoi(str.c_str());//ID变为int型
	iter=mymap.find(a);//mymap.find() 找到key 返回为迭代器 iter   没找到 返回迭代器iter 指向mymap.end() 末尾元素  
	 if(this->pwd->getContent()=="" || this->account->getContent()=="")//账号或密码不能为空
	{
		//无论失败成功都清空accout和pwd文本
		account->setContentNull();
		pwd->setContentNull();
		winArr[8]->getArr(0)->setTitle("账号密码不能为空!");//更改提示消息
		winArr[8]->setTitleType("登入界面--账号或密码不能为空");//更改提示窗口类型
		CTool::clear(52,16,20,8);//局部刷新
		winArr[8]->CWindow_Show();//提示窗口
		winArr[8]->winRun(); 
		return false;
	}
	if(iter!=mymap.end())
	{
		if(iter->second.getID()==str && iter->second.getPwd()==this->pwd->getContent())
		{
			current_Account=atoi(account->getContent().c_str());//获取账号给全局变量--判断哪个用户界面用
			user_name=iter->second.getName();//欢迎xxx用到
			account->setContentNull();//无论失败成功都accout和pwd文本
			pwd->setContentNull();
			CTool::gotoxy(this->getX()+48,this->getY()+25);//按钮的坐标旁边
			cout<<"登入成功!"<<endl;
			return true;
		}
		else if(iter->second.getID()!=str || iter->second.getPwd()!=this->pwd->getContent())//账号或密码错误
		{
			//无论失败成功都清空accout和pwd文本
			account->setContentNull();
			pwd->setContentNull();
			winArr[8]->getArr(0)->setTitle("账号或密码错误!");//更改提示消息
			winArr[8]->setTitleType("登入界面--账号密码错误");//更改提示窗口类型
			CTool::clear(52,16,20,8);//局部刷新
			winArr[8]->CWindow_Show();//提示窗口
			winArr[8]->winRun(); 
			return false;
		}
	}
	else{
		//未找到用户ID!
		//无论失败成功都清空accout和pwd文本
		account->setContentNull();
		pwd->setContentNull();
		winArr[8]->getArr(0)->setTitle("未找到用户ID!");//更改提示消息
		winArr[8]->setTitleType("登入界面--未找到用户");//更改提示窗口类型
		CTool::clear(52,16,20,8);//局部刷新
		winArr[8]->CWindow_Show();//提示窗口
		winArr[8]->winRun(); 
		return false;
	}
	return false;
}