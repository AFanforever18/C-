#ifndef CTOOL_H
#define CTOOL_H
#pragma   warning (disable: 4786)
#include <iostream>
#include <string>
#include <windows.h>//��궨λ��Ҫ
#include "Control.h"
#include "CUser.h"
#include "CGoods.h"
#include <sstream>
#include "CGoods.h"
#include <map>
#include <list>
#include <fstream>
#include <conio.h>//
#include <io.h>

#define KEY_ESC 27
#define KEY_ENTER 13
#define KEY_UP -1
#define KEY_DOWN -2
#define KEY_LEFT -3
#define KEY_RIGHT -4

using namespace std;
class CTool
{
public:
	//����л�
	static void gotoxy(int x,int y);
	//����
	static void paintBorder(int startX, int startY,int width,int height);
	//��ȡ��ֵ
	static int Key();
	//
	static void show();
	static void prtinf_Table_Content(list<CGoods> goods_list);//�̵㱨��--���ݴ�ӡ
	static void printf_Table_Order();//�̵��źͳ���״̬--���ݴ�ӡ
	static void printf_Table_Order_All();//�̵������Ϣ--���ݴ�ӡ
	static string strtoInt(int val);//int->string
	static void clear(int x,int y,int width,int height);//�ֲ����
	static void file_opear();//�����ļ�
	
};
#endif
extern page_current;//��ǰҳ��--�̵㱨��
extern page_current_2;//��ǰҳ��--����
extern page_current_3;//��ǰҳ��--������
extern page_current_4;////��ǰҳ��--����--7������
extern map<string,string>mymap_order_num;//���̵��źͳ���״̬
extern string gbl_selectNUM;//����--�̵���
extern string gbl_orderNUM;//data�������̵���
extern map<string,CGoods> map_check;//������Ϣ����
