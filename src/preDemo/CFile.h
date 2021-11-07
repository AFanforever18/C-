#ifndef CFILE_H
#define CFILE_H
#pragma   warning (disable: 4786)
#include <iostream>
#include <fstream>
#include <string>
#include "CUser.h"
#include "CGoods.h"
#include "CTool.h"
#include <ctime>
#include <list>
using namespace std;
class CFile
{
public:
	CFile();//����
	~CFile();//����
	static void userFileRead();//�û��ļ���ȡ--��ȡ�û���
	static void goodsFileRead();//�ļ���ȡ--��ȡ�ֿ���Ʒ
	static void userWrite(string ID,string name,string pwd,int role);//�û�д���ļ�--ע�����
	static void goodsWrite(string goodsNum,string goodsName,string goodsType,string goodsPrice,string inventory,string warehouseNum);//��Ʒд���ļ�
	static void goods_Record_Write(string goodsNum,string goodsName,string inventory,string orderNum,string errorNum,int num);//�̵���д���ļ�	
	static void goods_Order_Read(list<CGoods> &order_list,string src);//��ȡ�̵���     ����:�̵����� �� �ļ�·��
	static void ALL_Check_Write(string order_num,string goodsNum,string goodsName,string inventory,string orderNum,string errorNum,string check,string seaon);//������Ϣ
	static void order_check_read();//����ѡ����̵��Ŷ�������
	static void num_and_state_read();//��ȡ�ļ����̵��źͳ���״̬д��mymap_order_num����
	static void num_and_state_write(string num,string state);//�̵��źͳ���������mymap_order_numд���ļ�
	static void new_Check_Data_Write();//���������Ʒ��Ϣд���ļ�
};
#endif
extern map<int,CUser>mymap;//���û���Ϣ
extern map<string,CGoods>mymap_goods;//����Ʒ��Ϣ
extern string data;//ʱ��
extern string gbl_orderNUM;
extern string gbl_orderNUM;//data�������̵���
extern map<string,CGoods> map_check;//������Ϣ����
extern map<string,string>mymap_order_num;//���̵��źͳ���״̬������

