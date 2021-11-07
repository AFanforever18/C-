#ifndef CWINDOW_H
#define CWINDOW_H
#include <iostream>
#include <string>
#include "CTool.h"
#include "CControl.h"
#include "CEdit.h"
#include "CButton.h"
#include "CLabel.h"
#include "CTable.h"
#include "CTable_2.h"
#include "CTable_3.h"
#include <list>
#include <ctime>
#include <fstream>
using namespace std;
class CWindow//������
{
private:
	int x;//x����
	int y;//y����
	int width;//���
	int height;//�߶�
	int count;//�ؼ���
	int focus;//����enter�����±�
	CControl* arr[20];//�ؼ�����
	int num;//�����˺�����
	string type;//��������
public:
	CWindow();//Ĭ�Ϲ���
	CWindow(int x,int y,int width,int height);//���ι��캯��
	~CWindow();//��������
	int getX();//��ȡx����
	int getY();//��ȡy����
	int getWidth();//��ȡ��
	int getHeight();//��ȡ��
	int getFocus();//��ȡenter�����±�
	int getCount();//��ȡ�ؼ���
	int getNum();//��ȡnum
	CControl* getArr(int x);//��ȡ�ؼ�����
	void addControl(CControl *con);//��ӿؼ�
	virtual void doAction()=0;//���ڵĲ��� ÿ������һ�� ���� ����������д
	virtual	void search(string word);//��ѯ��ӡ��Ʒ��Ϣ--1.���ⴰ��  2.�̵㴰��
	virtual string get_Search_word();//��ȡ�������Ʒ����--���ⴰ��,�̵㴰��
	virtual string get_makeOrder_Num();//��ȡ�̵���--�̵㱨��
	virtual string get_Order_num();//��ȡ������̵�����--�̵㴰��
	virtual int get_input_Goods_Num();//��ȡ����ĳ�������--���ⴰ��
	virtual string get_search_null();//��ȡ�����δ�鵽����Ʒ����--������Ʒ
	virtual string getTitleType();//��ȡ��ʾ��������--��ʾ����
	virtual void setTitleType(string word);//������ʾ��������--��ʾ����
	virtual int fuzzyQuery();//ģ����ѯ-6.12test
	


	void CWindow_Show();//������
	void CWindow_Table_Show();//������--ģ����ѯ
	void CWindow_Show_Select();//������--ѡ���û����ʹ���
	void winRun();//���ڽ���
	void change(CControl* con,int i);//���ؼ�

};
#endif
extern CWindow * winArr2[15];//�洰��
extern CWindow * winArr[30];//�洰��
extern string fuzzy_word;//ģ����ѯ

extern list<string>order_goods_record;//����Ʒ�̵��¼
extern string data;//ʱ��
extern map<int,CUser>mymap;//���û���Ϣ
extern map<string,CGoods>mymap_goods;//����Ʒ��Ϣ
extern gbl_accountNum;//�����˺��õ�
extern current_Account;//��ǰ�������˺�
extern  string user_name;//�û���
extern list<CGoods> temp_list;//�̵㱨��
extern page_current;//��ǰҳ��--�̵㱨��
extern page_current_2;//��ǰҳ��--����
extern page_current_3;//��ǰҳ��--������
extern string gbl_selectNUM;//����--�̵���
extern string gbl_goods_selectNUM;//����--7������--ѡ����Ʒ���
extern map<string,CGoods> map_check;//������Ϣ����--7������