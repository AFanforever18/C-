#include "CUser.h"
//Ĭ�Ϲ���
CUser::CUser()
{
	
}
//���ι���
CUser::CUser(string ID,string name,string pwd,int role)
{
	this->ID=ID;
	this->name=name;
	this->pwd=pwd;
	this->role=role;
}
//����
CUser::~CUser()
{
	
}
//��ȡ�˺�
string CUser::getID()
{
	return this->ID;
}
//��ȡ����
string CUser::getPwd()
{
	return this->pwd;
}
//��ȡ����
string CUser::getName()
{
	return this->name;
}
//��ȡ�û�����
int CUser::getrole()
{
	return this->role;
}
