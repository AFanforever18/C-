#include "CUser.h"
//默认构造
CUser::CUser()
{
	
}
//带参构造
CUser::CUser(string ID,string name,string pwd,int role)
{
	this->ID=ID;
	this->name=name;
	this->pwd=pwd;
	this->role=role;
}
//析构
CUser::~CUser()
{
	
}
//获取账号
string CUser::getID()
{
	return this->ID;
}
//获取密码
string CUser::getPwd()
{
	return this->pwd;
}
//获取姓名
string CUser::getName()
{
	return this->name;
}
//获取用户类型
int CUser::getrole()
{
	return this->role;
}
