#include "CAddGoods.h"
CAddGoods::CAddGoods(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	string str="欢迎使用仓储盘点机系统!";//更改主题
	//编辑框
	Name=new CEdit(this->getX()+28,this->getY()+11,46,2,10,1,3,EDIT,"");
	Type=new CEdit(this->getX()+28,this->getY()+14,46,2,10,1,3,EDIT,"");
	Price=new CEdit(this->getX()+28,this->getY()+17,46,2,10,1,4,EDIT,"");
	warehouseNum=new CEdit(this->getX()+28,this->getY()+20,46,2,10,1,0,LABEL,"");//跳过  并且无控制输入

	//标签
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"日期: "+data);
	goods_Num=new CLabel(this->getX()+16,this->getY()+8,20,2,1,1,0,LABEL,"商品编号:");
	goods_Num_content=new CLabel(this->getX()+27,this->getY()+8,20,2,1,1,0,LABEL,"");//编号
	goods_Name=new CLabel(this->getX()+16,this->getY()+11,20,2,1,1,0,LABEL,"商品名称:");
	goods_Type=new CLabel(this->getX()+16,this->getY()+14,20,2,1,1,0,LABEL,"商品类型:");
	goods_Price=new CLabel(this->getX()+16,this->getY()+17,20,2,1,1,0,LABEL,"商品价格:");
	goods_warehouseNum=new CLabel(this->getX()+16,this->getY()+20,20,2,1,1,0,LABEL,"仓位编号:");
	
	//按钮
	enter_Button=new CButton(this->getX()+22,this->getY()+24,18,2,1,1,0,BUTTON,"确定[Enter]");//确定
	esc_Button=new CButton(this->getX()+50,this->getY()+24,18,2,1,1,0,BUTTON,"取消[Esc]");//取消

	//添加控件
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(goods_Num);//3
	addControl(goods_Num_content);//4
	addControl(goods_Name);
	addControl(goods_Type);
	addControl(goods_Price);
	addControl(goods_warehouseNum);
	addControl(Name);
	addControl(Type);
	addControl(Price);
	addControl(warehouseNum);
	addControl(enter_Button);//13
	addControl(esc_Button);//14
}
//商品添加函数
void CAddGoods::addGoods()
{
	//新增商品写入商品文件
	CFile::goodsWrite(goods_Num_content->getContent(),Name->getContent(),this->Type->getContent(),this->Price->getContent(),"0",this->warehouseNum->getContent());
	//重新读入容器
	CFile::goodsFileRead();
}
//重写父类纯虚函数
void CAddGoods::doAction()
{
	int i=this->getFocus();
	switch(i)
	{
	case 13://确定
		if(this->Name->getContent()=="" || this->Type->getContent()=="" || this->Price->getContent()=="" || this->warehouseNum->getContent()=="")
		{
			winArr[8]->getArr(0)->setTitle("请完善内容!");//更改提示消息
			winArr[8]->setTitleType("请完善内容");//更改提示窗口类型
			CTool::clear(52,16,20,8);
			winArr[8]->CWindow_Show();
			winArr[8]->winRun(); 
		}else
		{
			addGoods();//商品添加函数
			//清空文本
			this->Name->setContentNull();
			this->Type->setContentNull();
			this->Price->setContentNull();
			this->warehouseNum->setContentNull();
			winArr[8]->getArr(0)->setTitle("商品添加成功!");//更改提示消息
			winArr[8]->setTitleType("商品添加成功");//更改提示窗口类型
			CTool::clear(52,16,20,8);//局部清空
			winArr[8]->CWindow_Show();
			winArr[8]->winRun(); 
		}
		break;
	case 14://返回Esc
			//清空文本
			this->Name->setContentNull();
			this->Type->setContentNull();
			this->Price->setContentNull();
			this->warehouseNum->setContentNull();
			system("cls");
			winArr[11]->CWindow_Show();//商品入库菜单界面
			winArr[11]->winRun(); 
		break;
	}
}



