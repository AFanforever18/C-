#ifndef CUSER_H
#define CUSER_H
#include <iostream>
#include <map>
using namespace std;
class CUser
{
public:
	CUser();//默认构造
	CUser(string ID,string name,string pwd,int role);//带参构造
	~CUser();//析构
	static map<int,CUser> *user_map;//用户信息map
	string getID();//获取用户ID
	string getPwd();//获取用户密码
	string getName();//获取用户名称
	int getrole();//获取角色类型
	static int current_user;//记录当前在操作的用户

private:
	int role;//用户类型
	string ID;//用户ID
	string pwd;//用户密码
	string name;//用户名称
};
#endif

