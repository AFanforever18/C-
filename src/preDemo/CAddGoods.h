#ifndef CADDGOODS_H
#define CADDGOODS_H
#include "CWindow.h"
class CAddGoods:public CWindow
{
public:
	CAddGoods(int x,int y,int width,int height);//���ι���
	void doAction();//��д���ി�麯��
	void addGoods();//��Ʒ��Ӻ���

	//��ť
	CButton* enter_Button;//ȷ��
	CButton* esc_Button;//ȡ��

	//�༭��
	CEdit* Name;//��Ʒ����
	CEdit* Type;//��Ʒ����
	CEdit* Price;//��Ʒ�۸�
	CEdit* warehouseNum;//��λ���
	//��ǩ
	CLabel* managername;//�û���
	CLabel* mydate;//����
	CLabel* title;//����
	CLabel* goods_Num;//��Ʒ���
	CLabel* goods_Num_content;//�������
	CLabel* goods_Name;//��Ʒ����
	CLabel* goods_Type;//��Ʒ����
	CLabel* goods_Price;//��Ʒ�۸�
	CLabel* goods_warehouseNum;//��λ���
};
#endif
