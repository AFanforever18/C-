#ifndef CTIPS_CHECK_WIN_H
#define CTIPS_CHECK_WIN_H
#include "CWindow.h"
#include <fstream>
class CTips_Check_Win:public CWindow
{
public:
	 CTips_Check_Win(int x,int y,int width,int height);//���ι���
	void doAction();//��д���ി�麯��
	void change_chcek_data();//�ı���Ʒ������Ϣ
	int get_check_state();//����״̬ 1--δ����  2--������ 3--�ѳ���
	void change_order_num_and_state(string mycheck_state);//�����̵��źͳ���״̬����������

	//��ť
	CButton* ok_Button;//ȷ��
	CButton* cal_Button;//ȡ��

	//�༭��
	CEdit* border;//�������߿�
	CEdit* edit_num;
	CEdit* edit_season;
	//��ǩ
	CLabel* title;
	CLabel* title_num;
	CLabel* title_season;
};
#endif