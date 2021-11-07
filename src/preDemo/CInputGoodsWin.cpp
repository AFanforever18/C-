#include "CInputGoodsWin.h"
//带参构造
CInputGoodsWin::CInputGoodsWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	search_word="";//一开始为空
	string str="欢迎使用仓储盘点机系统!";//更改主题
	//标签
	//为了标签随窗口大小位置变动
	title=new CLabel(this->getX()+(this->getWidth()-str.size())/2+1,this->getY()+1,8,5,1,1,1,LABEL,str);
	managername=new CLabel(this->getX()+2,this->getY()+5,20,2,1,1,0,LABEL,"");
	mydate=new CLabel(this->getX()+this->getWidth()-20,this->getY()+5,20,2,1,1,0,LABEL,"日期: "+data);
	inputNum_label=new CLabel(this->getX()+2,this->getY()+7,20,2,1,1,0,LABEL,"请输入商品查询的编号:");
	inputGoods_label=new CLabel(this->getX()+70,this->getY()+12 ,20,2,1,1,0,LABEL,"请输入入库数量[1-10000]:");
	goods_Name=new CLabel(this->getX()+10,this->getY()+12,20,2,1,1,0,LABEL,"商品名称:");
	goods_Type=new CLabel(this->getX()+10,this->getY()+15,20,2,1,1,0,LABEL,"商品类型:");
	goods_Price=new CLabel(this->getX()+10,this->getY()+18,20,2,1,1,0,LABEL,"商品价格:");
	goods_NUm=new CLabel(this->getX()+10,this->getY()+21,21,2,1,1,0,LABEL,"库存数量:");
	goods_WarehouseNum=new CLabel(this->getX()+10,this->getY()+24,20,2,1,1,0,LABEL,"仓位编号:");
	//编辑框
	inputNum_edit=new CEdit(this->getX()+28,this->getY()+7,46,2,10,1,3,EDIT,"");
	inputoutGoods_edit=new CEdit(this->getX()+70,this->getY()+15 ,28 ,2,10,1,2,EDIT,"");
	//按钮
	find_Btn=new CButton(this->getX()+76,this->getY()+7,10,2,1,1,0,BUTTON,"查询");
	import_Btn=new CButton(this->getX()+70,this->getY()+20,12,2,1,1,0,BUTTON,"确定");
	myexit=new CButton(this->getX()+86,this->getY()+20,12,2,1,1,0,BUTTON,"返回[Esc]");

	//表格
	table=new CTable(this->getX()+8,this->getY()+12,6,6,1,1,0,LABEL,"查询");	
	//添加控件
	addControl(title);
	addControl(managername);
	addControl(mydate);
	addControl(inputNum_label);
	addControl(inputGoods_label);
	addControl(goods_Name);
	addControl(goods_Type);
	addControl(goods_Price);
	addControl(goods_NUm);
	addControl(goods_WarehouseNum);
	addControl(inputNum_edit);//商品查询编辑框--10
	addControl(find_Btn);//商品查询按钮--11
	addControl(inputoutGoods_edit);//输入入库数量--12
	addControl(import_Btn);//确定入库按钮--13
	addControl(myexit);//取消--14

}

//默认构造
CInputGoodsWin::~CInputGoodsWin()
{
	
}
//获取输入的商品编码
string CInputGoodsWin::get_Search_word()
{
	return this->search_word;
}
//获取输入未查找的编码
string CInputGoodsWin::get_search_null()
{
	return this->search_null;
}
//获取输入的入库数量--入库窗口
int CInputGoodsWin::get_input_Goods_Num()
{
	return this->input_Goods_Num;
}
//查询打印商品信息
void CInputGoodsWin::search(string word)
{
	map<string,CGoods>::iterator iter;
	iter=mymap_goods.find(word);
	if(iter==mymap_goods.end())
	{
		//清空文本
		this->inputNum_edit->setContentNull();
		this->inputoutGoods_edit->setContentNull();
		CTool::clear(41,12,36,16);//局部清空
		CTool::paintBorder(42,12,36,14);//边框
		winArr[13]->CWindow_Show();
		winArr[13]->winRun();
		return;
	}else
	{
		CTool::gotoxy(this->getX()+23,this->getY()+13);
		cout<<iter->second.getGoodsName()<<"          ";//商品名称
		CTool::gotoxy(this->getX()+23,this->getY()+16);
		cout<<iter->second.getGoodsType()<<"          ";//商品类型
		CTool::gotoxy(this->getX()+23,this->getY()+19);
		cout<<iter->second.getGoodsPrice()<<"          ";//商品价格
		CTool::gotoxy(this->getX()+23,this->getY()+22);
		cout<<iter->second.getInventory()<<"          ";//库存数量
		CTool::gotoxy(this->getX()+23,this->getY()+25);
		cout<<iter->second.getWarehouseNum()<<"         ";//仓位编号
	}
}
//商品入库--将商品的数量变为入库后的数量
void CInputGoodsWin::goodsOut()
{
	map<string,CGoods>::iterator iter;
	iter=mymap_goods.find(search_word);//找到要出库的商品
	string goodsNum=iter->second.getGoodsNum();//获取商品编号
	string goodsName=iter->second.getGoodsName();//获取商品名称
	string goodsTyp=iter->second.getGoodsType();//获取商品类型
	string goodsPrice=iter->second.getGoodsPrice();//获取商品价格
	string inventory=iter->second.getInventory();//获取库存数量
	string warehouseNum=iter->second.getWarehouseNum();//获取仓位编号

	//入库后: 库存=原先库存+入库数量input_Goods_Num
	int inventory_temp=atoi(inventory.c_str())+input_Goods_Num;
	//int->string
	stringstream ss;
	ss<<inventory_temp;
	ss>>inventory;//得到入库后的库存
	//删除容器里这个商品的信息
	mymap_goods.erase(iter);
	//商品容器插入新商品信息
	CGoods mygoods(goodsNum,goodsName,goodsTyp,goodsPrice,inventory,warehouseNum);
	mymap_goods.insert(make_pair(goodsNum,mygoods));

	ofstream ofs;
	ofs.open("./data/goods.txt");
	ofs.flush();
	ofs.close();
	for(map<string,CGoods>::iterator it=mymap_goods.begin();it!=mymap_goods.end();it++)
	{
		CFile::goodsWrite(it->second.getGoodsNum(),it->second.getGoodsName(),it->second.getGoodsType(),it->second.getGoodsPrice(),it->second.getInventory(),it->second.getWarehouseNum());
	}
	//新商品容器写入文件后,再读一次商品文件
	CFile::goodsWrite(goodsNum,goodsName,goodsTyp,goodsPrice,inventory,warehouseNum);
	CFile::goodsFileRead();
}
//窗口的操作 每个都不一样 纯虚 所有子类重写
void CInputGoodsWin::doAction()
{
	int i=this->getFocus();
	map<string,CGoods>::iterator iter;
	switch(i)
	{
	case 11://查询
		if(this->inputNum_edit->getContent()!="")
		{
			iter=mymap_goods.find(this->inputNum_edit->getContent());
		}else
		{
			iter=mymap_goods.find(search_word);
		}
		if(iter==mymap_goods.end())//未找到商品
		{
			search_null=inputNum_edit->getContent();//未查询到的商品编号--新增商品
			//清空文本
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			CTool::clear(41,12,36,16);//局部清空
			CTool::paintBorder(42,12,36,14);//边框
			winArr[13]->CWindow_Show();//进入未找到商品--提示窗口
			winArr[13]->winRun();
		}
		search_word=inputNum_edit->getContent();//存下商品编码
		if(inputNum_edit->getContent()=="")
		{
			search(search_word);//查询打印商品信息
		}else
		{
			search(inputNum_edit->getContent());//查询打印商品信息
		}
		
		break;
	case 13://入库
		input_Goods_Num=atoi(inputoutGoods_edit->getContent().c_str());//存下入库数量
		if(atoi(inputoutGoods_edit->getContent().c_str())>10000 || inputoutGoods_edit->getContent()=="")//出库数量为空或者大于10000
		{
			//清空文本
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			winArr[8]->getArr(0)->setTitle("入库数量有误!");//更改提示消息
			winArr[8]->setTitleType("入库数量有误");//更改提示窗口类型
			winArr[8]->CWindow_Show();
			winArr[8]->winRun(); 
		}
		else//入库数量正常
		{
			//清空文本
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			goodsOut();//商品出库--将商品的数量变为出库后的数量
			winArr[8]->getArr(0)->setTitle("入库成功!");//更改提示消息
			winArr[8]->setTitleType("入库成功");//更改提示窗口类型
			winArr[8]->CWindow_Show();
			winArr[8]->winRun(); 
		}
		break;
	case 14:
			//清空文本
			this->inputNum_edit->setContentNull();
			this->inputoutGoods_edit->setContentNull();
			system("cls");
			winArr[11]->CWindow_Show();//进入入库菜单界面
			winArr[11]->winRun();
		break;
	}
}