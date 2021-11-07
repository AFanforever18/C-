#ifndef CUSER_H
#define CUSER_H
#include <iostream>
#include <map>
using namespace std;
class CUser
{
public:
	CUser();//Ĭ�Ϲ���
	CUser(string ID,string name,string pwd,int role);//���ι���
	~CUser();//����
	static map<int,CUser> *user_map;//�û���Ϣmap
	string getID();//��ȡ�û�ID
	string getPwd();//��ȡ�û�����
	string getName();//��ȡ�û�����
	int getrole();//��ȡ��ɫ����
	static int current_user;//��¼��ǰ�ڲ������û�

private:
	int role;//�û�����
	string ID;//�û�ID
	string pwd;//�û�����
	string name;//�û�����
};
#endif

