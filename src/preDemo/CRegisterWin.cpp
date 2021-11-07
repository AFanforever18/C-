#include "CRegisterWin.h"
//默认构造
CRegisterWin::CRegisterWin()
{
	manager=new CButton(12,9,20,2,1,1,0,BUTTON,"仓库管理员");
	orderman=new CButton(12,11,20,2,1,1,0,BUTTON,"盘点员");
	addControl(manager);	
	addControl(orderman);
}
//带参构造
CRegisterWin::CRegisterWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	

	//标签
	string str="欢迎来到用户注册页面!";//为了标签随窗口大小位置变动
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	
	label_account=new CLabel(34,10,40,2,20,MODE_TEXT,0,LABEL,"帐    号 :");
	label_name=new CLabel(34,14,40,2,20,MODE_TEXT,0,LABEL,"姓    名 :");
	label_pwd=new CLabel(34,18,40,2,20,MODE_PWD,0,LABEL,"密    码 :");
	label_check_pwd=new CLabel(34,22,40,2,20,MODE_TEXT,0,LABEL,"确认密码 :");

	//按钮
	manager=new CButton(this->getX()+2,this->getY()+5,20,2,1,1,0,BUTTON,"[Enter]选择类型");
	orderman=new CButton(this->getX()+this->getWidth()-20,this->getY()+5,18,2,1,1,0,BUTTON,"盘点员");
	check=new CButton(this->getX()+10,this->getY()+24,18,2,1,1,0,BUTTON,"确定[Enter]");
	myexit=new CButton(this->getX()+this->getWidth()-28,this->getY()+24,18,2,1,1,0,BUTTON,"取消[Esc]");
		
	//编辑框              //输出类型 0无控制 1字母 2数字 3数字加字母
	account=new CEdit(48,10,40,2,20,MODE_TEXT,0,LABEL,"");
	name=new CEdit(48,14,40,2,12,MODE_TEXT,1,EDIT,"");
	pwd=new CEdit(48,18,40,2,10,MODE_PWD,2,EDIT,"");
	check_pwd=new CEdit(48,22,40,2,10,MODE_PWD,2,EDIT,"");

	//添加控件
	addControl(manager);	
	addControl(account);//1
	addControl(label_account);
	addControl(label_name);
	addControl(label_pwd);
	addControl(label_check_pwd);
	addControl(title);
	addControl(name);//姓名--7
	addControl(pwd);//密码--8
	addControl(check_pwd);//确定密码--9
	addControl(check);//确定--10
	addControl(myexit);//退出--11


}

//默认构造
CRegisterWin::~CRegisterWin()
{
	
}
//重写父类纯虚函数
void CRegisterWin::doAction()
{
	int i=this->getFocus();
	bool ret;
	switch(i)
	{
	case 10://注册成功 进入登入界面
		if(this->getArr(0)->getContent()=="[Enter]选择类型" && i==10)
		{
			//清空编辑框输入的文本
			account->setContentNull();
			name->setContentNull();
			pwd->setContentNull();
			check_pwd->setContentNull();
			winArr[8]->getArr(0)->setTitle("请选择注册类型!");//更改提示消息
			winArr[8]->setTitleType("注册界面--请选择注册类型");//更改提示窗口类型
			CTool::clear(52,16,20,8);//局部刷新
			winArr[8]->CWindow_Show();//提示窗口
			winArr[8]->winRun(); 
		}
		else if(this->getArr(0)->getContent()=="盘点员")
		{
			ret=reg();
			if(ret)
			{
				//清空文本
							
				this->name->setContentNull();
				this->pwd->setContentNull();
				this->check_pwd->setContentNull();
				this->getArr(1)->changeAccount(1);//账号自增
				winArr2[2]->getArr(1)->changeAccount(0);
				CTool::gotoxy(this->getX()+46,this->getY()+25);
				cout<<"注册成功!"<<endl;
				system("cls");
				winArr[2]->CWindow_Show();
				winArr[2]->winRun();	
			}else{//reg函数返回false的情况--重回注册界面
				//清空文本
				this->name->setContentNull();
				this->pwd->setContentNull();
				this->check_pwd->setContentNull();
				system("cls");
				winArr2[1]->CWindow_Show();//盘点员--注册界面
				winArr2[1]->winRun();//盘点员--注册界面
			}
		}
		else if(this->getArr(0)->getContent()=="仓库管理员")
		{
			ret=reg();
			if(ret)
			{

				//清空文本
				this->name->setContentNull();
				this->pwd->setContentNull();
				this->check_pwd->setContentNull();
				this->getArr(1)->changeAccount(1);//账号自增
				winArr2[1]->getArr(1)->changeAccount(0);

				CTool::gotoxy(this->getX()+46,this->getY()+25);
				cout<<"注册成功!"<<endl;
				CTool::gotoxy(this->getX()+46,this->getY()+26);
				system("pause");
				system("cls");
				winArr[2]->CWindow_Show();
				winArr[2]->winRun();	
			}else{//reg函数返回false的情况--重回注册界面
				//清空文本
				this->name->setContentNull();
				this->pwd->setContentNull();
				this->check_pwd->setContentNull();
				system("cls");
				winArr2[2]->CWindow_Show();//仓库管理者--注册界面
				winArr2[2]->winRun();//仓库管理者--注册界面
			}
		}
	
		break;
	case 11://退出 进入主界面
		//清空文本
		this->name->setContentNull();
		this->pwd->setContentNull();
		this->check_pwd->setContentNull();
		system("cls");
		winArr[0]->CWindow_Show();
		winArr[0]->winRun();
		break;
	}
}

bool CRegisterWin::reg()//注册操作
{
	int x;//判断用户类型
	if(this->getArr(0)->getContent()=="盘点员")
	{
		x=1;
	}
	else if(this->getArr(0)->getContent()=="仓库管理员")
	{
		x=2;
	}
	if(this->name->getContent()=="" || this->pwd->getContent()=="")//账号密码不能为空
	{
		CTool::gotoxy(this->getX()+46,this->getY()+25);
		cout<<"账号密码不能为空!"<<endl;
		CTool::gotoxy(this->getX()+46,this->getY()+26);
		system("pause");
		
		return false;
	}
	else if(this->name->getContent()!="" && this->pwd->getContent()!="" && this->check_pwd->getContent()=="")//输入验证密码
	{
		CTool::gotoxy(this->getX()+46,this->getY()+25);
		cout<<"验证密码不能为空!"<<endl;
		CTool::gotoxy(this->getX()+46,this->getY()+26);
		system("pause");
		return false;	
	}else if(this->pwd->getContent()!=this->check_pwd->getContent())//两次输入的密码不一致
	{
		CTool::gotoxy(this->getX()+46,this->getY()+25);
		cout<<"验证密码不一致!"<<endl;
		CTool::gotoxy(this->getX()+46,this->getY()+26);
		system("pause");
		return false;
	}else//注册成功
	{
		//存入顺序 账号id--姓名--密码
		CFile::userWrite(this->getArr(1)->getContent(),this->name->getContent(),this->pwd->getContent(),x);
		return true;
	}

}

