#ifndef CLOGIN_H
#define CLOGIN_H
#pragma   warning (disable: 4786)
#include "CWindow.h"
#include <fstream>//�ļ�ͷ�ļ�
#include <map>
#include "CUser.h"
class CLogin:public CWindow
{
public:
	CLogin();//Ĭ�Ϲ���
	CLogin(int x,int y,int width,int height);//���ι���
	~CLogin();//Ĭ�Ϲ���
	void doAction();//���ڵĲ��� ÿ������һ�� ���� ����������д
	bool login();//�������

	//��ǩ
	CLabel* title;
	CLabel* label_account;
	CLabel* label_pwd;
	//��ť
	CButton* check;
	CButton* myexit;
	//�༭��
	CEdit* account;
	CEdit* pwd;
};
#endif
