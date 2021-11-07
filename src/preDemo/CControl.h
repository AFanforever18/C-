#ifndef CCONTROL_H
#define CCONTROL_H
#pragma   warning (disable: 4786)
#include <iostream>
#include <string>
#include <sstream>//int to string
#include <map>//�Զ������˺���
#include "CUser.h"
#include "CTool.h"
#include "CFile.h"

#define EDIT 1
#define LABEL 2
#define BUTTON 3
#define MODE_TEXT 1///����
#define MODE_PWD 2//����
using namespace std;
/*CControlΪEdit,Button,Label�ȿؼ��ĸ���*/
class CControl
{
private:
	int x;//x����
	int y;//y����
	int width;//���
	int height;//�߶�
	int length;//��󳤶�
	int state;//��ʾ 1���� 2����
	int intputtype;//������� 0�޿��� 1��ĸ 2���� 3���ּ���ĸ 4 ����+"."  5 ����
	int type;//�ؼ�����
	string content;//�ı�����
	int page;//��ǰҳ��
	int page_Max;//���ҳ��
	int count;//0--left   1--rigeht
	
public:
	CControl();//Ĭ�Ϲ��캯��
	CControl(int x,int y,int width,int height,int length,int state,int intputtype,int type,string content);//��������������
	~CControl();//��������

	int getX();//��ȡx����
	int getY();//��ȡy����
	int getWidth();//��ȡ���
	int getHeight();//��ȡ�߶�
	int getLength();//��ȡ��󳤶�
	int getState();//��ȡ��ʾ״̬
	int getIntputtype();//�������
	int getType();//�ؼ�����
	int getPage();//��ȡҳ��
	int getPageMax();//��ȡ���ҳ��
	int getCount();//��ȡcount
	string getContent();//��ȡ�ı�����
	void setPage(int page);//��ҳ��
	void setPage_Max(int page);//�����ҳ��--ģ����ѯʹ��
	void setCount(int x);//���ķ�ҳ 0-left 1--right
	void setContent(int ikey);//����Ϊ�ı�����--��ɾ��
	void setTextConcent(string word);//�����ı�����
	void setContentNull();//�ı������ÿ�--ҳ����ת��
	void setContent_Fuzzy_Table(string word);//ģ����ѯ
	void setTitle(string newTitle);//������ʾ������ʾ����--���ⴰ��
	void changeAccount(int num);//�˺ſؼ��ı����ݸ���--�˺�����  int num Ϊ�˺��Ƿ��1 0--���� 1--��
	void delContent();//ɾ��
	virtual void gbl_putstring(CControl* con,int ikey);//��Ҫ��������д
	virtual void Control_Show()=0;//���麯�� ���������д ������ �����б� ����ֵ���� ���಻��д ֻҪ�������麯��
	virtual	void Control_Table_Show();//ģ����ѯ
	virtual void sss();
};
#endif
extern map<int,CUser>mymap;//�û���Ϣ
extern map<string,CGoods>mymap_goods;//����Ʒ��Ϣ
extern gbl_accountNum;//�����˺��õ�