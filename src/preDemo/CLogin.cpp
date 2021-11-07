#include "CLogin.h"
//Ĭ�Ϲ���
CLogin::CLogin()
{

}
//���ι���
CLogin::CLogin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	

	//��ǩ
	string str="�û�����";//Ϊ�˱�ǩ�洰�ڴ�Сλ�ñ䶯
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
//	CTool::paintBorder(this->getX(),this->getY(),this->getWidth(),4);
	label_account=new CLabel(34,12,40,2,20,MODE_TEXT,0,LABEL,"��    �� :");
	label_pwd=new CLabel(34,18,40,2,20,MODE_PWD,0,LABEL,"��    �� :");

	//��ť
	check=new CButton(this->getX()+10,this->getY()+24,18,2,1,1,0,BUTTON,"ȷ��[Enter]");
	myexit=new CButton(this->getX()+this->getWidth()-28,this->getY()+24,18,2,1,1,0,BUTTON,"ȡ��[Esc]");
		
	//�༭��         //������� 0�޿��� 1��ĸ 2���� 3���ּ���ĸ
	account=new CEdit(48,12,40,2,20,MODE_TEXT,2,EDIT,"");
	pwd=new CEdit(48,18,40,2,10,MODE_PWD,2,EDIT,"");

	//��ӿؼ�
	addControl(account);//0
	addControl(label_account);
	addControl(label_pwd);
	addControl(title);
	addControl(pwd);
	addControl(check);//��5���ؼ�
	addControl(myexit);//��6���ؼ�
}

//Ĭ������
CLogin::~CLogin()
{
	
}
//��д���ി�麯��
void CLogin::doAction()
{
	int i=this->getFocus();//�ڵڼ����ؼ�
	bool ret;
	switch(i)//ѡ�����ڿؼ���ɲ�ͬ�Ĳ���
	{
		case 5:
			ret=login();
			if(ret)//����ɹ�
			{
				map<int,CUser>::iterator iter=mymap.find(current_Account);//ȥ�û�����mymap����--��ǰ�����˺�
				if(iter->second.getrole()==1)//�̵�Ա
				{
					CTool::gotoxy(this->getX()+48,this->getY()+26);//��ʾ��Ϣλ��
					system("pause");
					system("cls");
					winArr[4]->getArr(1)->setTextConcent("��ӭ:"+user_name);
					winArr[4]->CWindow_Show();//�̵�Ա--������--4
					winArr[4]->winRun();
				}else if(iter->second.getrole()==2)//�ֿ����Ա
				{
					CTool::gotoxy(this->getX()+48,this->getY()+26);//��ʾ��Ϣλ��
					system("pause");
					system("cls");
					winArr[3]->getArr(1)->setTextConcent("��ӭ:"+user_name);
					winArr[3]->CWindow_Show();//�ֿ����Ա--������--
					winArr[3]->winRun();
				}



				winArr[3]->CWindow_Show();
				winArr[3]->winRun();
			}else//����ʧ��
			{
				CTool::gotoxy(this->getX()+46,this->getY()+26);//��ʾ��Ϣλ��
				system("pause");
				system("cls");
				winArr[2]->CWindow_Show();//�������
				winArr[2]->winRun();		
			}
			break;
			case 6://�ص���ʼ����
			CTool::gotoxy(this->getX()+42,this->getY()+25);//��ʾ��Ϣλ��
			system("pause");//�����������
			system("cls");//����
			//��������Ҳ���accout��pwd�ı�
			account->setContentNull();
			pwd->setContentNull();
			winArr[0]->CWindow_Show();
			winArr[0]->winRun();
			break;
	}
}

bool CLogin::login()//�������
{
	map<int,CUser>::iterator iter;

	string str=this->account->getContent();
	int a=atoi(str.c_str());//ID��Ϊint��
	iter=mymap.find(a);//mymap.find() �ҵ�key ����Ϊ������ iter   û�ҵ� ���ص�����iter ָ��mymap.end() ĩβԪ��  
	 if(this->pwd->getContent()=="" || this->account->getContent()=="")//�˺Ż����벻��Ϊ��
	{
		//����ʧ�ܳɹ������accout��pwd�ı�
		account->setContentNull();
		pwd->setContentNull();
		winArr[8]->getArr(0)->setTitle("�˺����벻��Ϊ��!");//������ʾ��Ϣ
		winArr[8]->setTitleType("�������--�˺Ż����벻��Ϊ��");//������ʾ��������
		CTool::clear(52,16,20,8);//�ֲ�ˢ��
		winArr[8]->CWindow_Show();//��ʾ����
		winArr[8]->winRun(); 
		return false;
	}
	if(iter!=mymap.end())
	{
		if(iter->second.getID()==str && iter->second.getPwd()==this->pwd->getContent())
		{
			current_Account=atoi(account->getContent().c_str());//��ȡ�˺Ÿ�ȫ�ֱ���--�ж��ĸ��û�������
			user_name=iter->second.getName();//��ӭxxx�õ�
			account->setContentNull();//����ʧ�ܳɹ���accout��pwd�ı�
			pwd->setContentNull();
			CTool::gotoxy(this->getX()+48,this->getY()+25);//��ť�������Ա�
			cout<<"����ɹ�!"<<endl;
			return true;
		}
		else if(iter->second.getID()!=str || iter->second.getPwd()!=this->pwd->getContent())//�˺Ż��������
		{
			//����ʧ�ܳɹ������accout��pwd�ı�
			account->setContentNull();
			pwd->setContentNull();
			winArr[8]->getArr(0)->setTitle("�˺Ż��������!");//������ʾ��Ϣ
			winArr[8]->setTitleType("�������--�˺��������");//������ʾ��������
			CTool::clear(52,16,20,8);//�ֲ�ˢ��
			winArr[8]->CWindow_Show();//��ʾ����
			winArr[8]->winRun(); 
			return false;
		}
	}
	else{
		//δ�ҵ��û�ID!
		//����ʧ�ܳɹ������accout��pwd�ı�
		account->setContentNull();
		pwd->setContentNull();
		winArr[8]->getArr(0)->setTitle("δ�ҵ��û�ID!");//������ʾ��Ϣ
		winArr[8]->setTitleType("�������--δ�ҵ��û�");//������ʾ��������
		CTool::clear(52,16,20,8);//�ֲ�ˢ��
		winArr[8]->CWindow_Show();//��ʾ����
		winArr[8]->winRun(); 
		return false;
	}
	return false;
}