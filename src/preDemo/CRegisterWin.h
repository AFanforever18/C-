#ifndef CREGISTERWIN_H
#define CREGISTERWIN_H
#include "CWindow.h"
#include <fstream>//�ļ�ͷ�ļ�
#include "CFile.h"
#include "CUser.h"
class CRegisterWin:public CWindow
{
public:
	CRegisterWin();//Ĭ�Ϲ���
	CRegisterWin(int x,int y,int width,int height);//���ι���
	~CRegisterWin();//Ĭ�Ϲ���
	void doAction();//���ڵĲ��� ÿ������һ�� ���� ����������д
	bool reg();//ע�����

	//��ǩ
	CLabel* title;
	CLabel* label_account;
	CLabel* label_name;
	CLabel* label_pwd;
	CLabel* label_check_pwd;
	//��ť
	CButton* manager;
	CButton* orderman;
	CButton* check;
	CButton* myexit;
	//�༭��
	CEdit* account;
	CEdit* name;
	CEdit* pwd;
	CEdit* check_pwd;
};
#endif
