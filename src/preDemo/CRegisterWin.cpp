#include "CRegisterWin.h"
//Ĭ�Ϲ���
CRegisterWin::CRegisterWin()
{
	manager=new CButton(12,9,20,2,1,1,0,BUTTON,"�ֿ����Ա");
	orderman=new CButton(12,11,20,2,1,1,0,BUTTON,"�̵�Ա");
	addControl(manager);	
	addControl(orderman);
}
//���ι���
CRegisterWin::CRegisterWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	

	//��ǩ
	string str="��ӭ�����û�ע��ҳ��!";//Ϊ�˱�ǩ�洰�ڴ�Сλ�ñ䶯
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	
	label_account=new CLabel(34,10,40,2,20,MODE_TEXT,0,LABEL,"��    �� :");
	label_name=new CLabel(34,14,40,2,20,MODE_TEXT,0,LABEL,"��    �� :");
	label_pwd=new CLabel(34,18,40,2,20,MODE_PWD,0,LABEL,"��    �� :");
	label_check_pwd=new CLabel(34,22,40,2,20,MODE_TEXT,0,LABEL,"ȷ������ :");

	//��ť
	manager=new CButton(this->getX()+2,this->getY()+5,20,2,1,1,0,BUTTON,"[Enter]ѡ������");
	orderman=new CButton(this->getX()+this->getWidth()-20,this->getY()+5,18,2,1,1,0,BUTTON,"�̵�Ա");
	check=new CButton(this->getX()+10,this->getY()+24,18,2,1,1,0,BUTTON,"ȷ��[Enter]");
	myexit=new CButton(this->getX()+this->getWidth()-28,this->getY()+24,18,2,1,1,0,BUTTON,"ȡ��[Esc]");
		
	//�༭��              //������� 0�޿��� 1��ĸ 2���� 3���ּ���ĸ
	account=new CEdit(48,10,40,2,20,MODE_TEXT,0,LABEL,"");
	name=new CEdit(48,14,40,2,12,MODE_TEXT,1,EDIT,"");
	pwd=new CEdit(48,18,40,2,10,MODE_PWD,2,EDIT,"");
	check_pwd=new CEdit(48,22,40,2,10,MODE_PWD,2,EDIT,"");

	//��ӿؼ�
	addControl(manager);	
	addControl(account);//1
	addControl(label_account);
	addControl(label_name);
	addControl(label_pwd);
	addControl(label_check_pwd);
	addControl(title);
	addControl(name);//����--7
	addControl(pwd);//����--8
	addControl(check_pwd);//ȷ������--9
	addControl(check);//ȷ��--10
	addControl(myexit);//�˳�--11


}

//Ĭ�Ϲ���
CRegisterWin::~CRegisterWin()
{
	
}
//��д���ി�麯��
void CRegisterWin::doAction()
{
	int i=this->getFocus();
	bool ret;
	switch(i)
	{
	case 10://ע��ɹ� ����������
		if(this->getArr(0)->getContent()=="[Enter]ѡ������" && i==10)
		{
			//��ձ༭��������ı�
			account->setContentNull();
			name->setContentNull();
			pwd->setContentNull();
			check_pwd->setContentNull();
			winArr[8]->getArr(0)->setTitle("��ѡ��ע������!");//������ʾ��Ϣ
			winArr[8]->setTitleType("ע�����--��ѡ��ע������");//������ʾ��������
			CTool::clear(52,16,20,8);//�ֲ�ˢ��
			winArr[8]->CWindow_Show();//��ʾ����
			winArr[8]->winRun(); 
		}
		else if(this->getArr(0)->getContent()=="�̵�Ա")
		{
			ret=reg();
			if(ret)
			{
				//����ı�
							
				this->name->setContentNull();
				this->pwd->setContentNull();
				this->check_pwd->setContentNull();
				this->getArr(1)->changeAccount(1);//�˺�����
				winArr2[2]->getArr(1)->changeAccount(0);
				CTool::gotoxy(this->getX()+46,this->getY()+25);
				cout<<"ע��ɹ�!"<<endl;
				system("cls");
				winArr[2]->CWindow_Show();
				winArr[2]->winRun();	
			}else{//reg��������false�����--�ػ�ע�����
				//����ı�
				this->name->setContentNull();
				this->pwd->setContentNull();
				this->check_pwd->setContentNull();
				system("cls");
				winArr2[1]->CWindow_Show();//�̵�Ա--ע�����
				winArr2[1]->winRun();//�̵�Ա--ע�����
			}
		}
		else if(this->getArr(0)->getContent()=="�ֿ����Ա")
		{
			ret=reg();
			if(ret)
			{

				//����ı�
				this->name->setContentNull();
				this->pwd->setContentNull();
				this->check_pwd->setContentNull();
				this->getArr(1)->changeAccount(1);//�˺�����
				winArr2[1]->getArr(1)->changeAccount(0);

				CTool::gotoxy(this->getX()+46,this->getY()+25);
				cout<<"ע��ɹ�!"<<endl;
				CTool::gotoxy(this->getX()+46,this->getY()+26);
				system("pause");
				system("cls");
				winArr[2]->CWindow_Show();
				winArr[2]->winRun();	
			}else{//reg��������false�����--�ػ�ע�����
				//����ı�
				this->name->setContentNull();
				this->pwd->setContentNull();
				this->check_pwd->setContentNull();
				system("cls");
				winArr2[2]->CWindow_Show();//�ֿ������--ע�����
				winArr2[2]->winRun();//�ֿ������--ע�����
			}
		}
	
		break;
	case 11://�˳� ����������
		//����ı�
		this->name->setContentNull();
		this->pwd->setContentNull();
		this->check_pwd->setContentNull();
		system("cls");
		winArr[0]->CWindow_Show();
		winArr[0]->winRun();
		break;
	}
}

bool CRegisterWin::reg()//ע�����
{
	int x;//�ж��û�����
	if(this->getArr(0)->getContent()=="�̵�Ա")
	{
		x=1;
	}
	else if(this->getArr(0)->getContent()=="�ֿ����Ա")
	{
		x=2;
	}
	if(this->name->getContent()=="" || this->pwd->getContent()=="")//�˺����벻��Ϊ��
	{
		CTool::gotoxy(this->getX()+46,this->getY()+25);
		cout<<"�˺����벻��Ϊ��!"<<endl;
		CTool::gotoxy(this->getX()+46,this->getY()+26);
		system("pause");
		
		return false;
	}
	else if(this->name->getContent()!="" && this->pwd->getContent()!="" && this->check_pwd->getContent()=="")//������֤����
	{
		CTool::gotoxy(this->getX()+46,this->getY()+25);
		cout<<"��֤���벻��Ϊ��!"<<endl;
		CTool::gotoxy(this->getX()+46,this->getY()+26);
		system("pause");
		return false;	
	}else if(this->pwd->getContent()!=this->check_pwd->getContent())//������������벻һ��
	{
		CTool::gotoxy(this->getX()+46,this->getY()+25);
		cout<<"��֤���벻һ��!"<<endl;
		CTool::gotoxy(this->getX()+46,this->getY()+26);
		system("pause");
		return false;
	}else//ע��ɹ�
	{
		//����˳�� �˺�id--����--����
		CFile::userWrite(this->getArr(1)->getContent(),this->name->getContent(),this->pwd->getContent(),x);
		return true;
	}

}

