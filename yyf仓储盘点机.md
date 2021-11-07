# 一.仓储盘点机-bug

## 5.31--封装类

### 1.bug带有纯虚函数的类不能实例化

1.cannot instantiate abstract class due to following members:

带有纯虚函数的类不能实例化

## 2.父类的虚函数是有意义的,在在ccp写定义

定义的时候不要加virtual,不然会重复定义,子类需要重写的时候就重写.虚函数为了父类指针指向子类对象空间的时候可以调用出子类的函数

## 3.文件写入 ofs<<

```
ofstream ofs;
//这个写法 存入文件
ofs<< a;//a不可以为类或者结构体

```

## 4.结构体 赋值

![image-20210601200712704](C:\Users\lyl\AppData\Roaming\Typora\typora-user-images\image-20210601200712704.png)

```
   struct STU
{
    char name[20];
    int age;
    char sex;
    char num[20];
};
   struct STU stu[5] = {{"小红", 22, 'F', "Z1207031"}, {"小明", 21, 'M', "Z1207035"}, {"小七", 23, 'F', "Z1207022"}, {"小欣", 20, 'F', "Z1207015"}, {"小天", 19, 'M', "Z1207024"}};
```

## 4.结构体写入文件

```
	文写入类好像会乱码
	typedef struct vs
	{
		char account[20];
		char name[20];
		char pwd[20];
	}VS;
	VS a={"虎牙直播","652823","ssss"}
	ofstream ofs;
	//打开文件
	ofs.open("user.txt",ios::out | ios::app);//默认当前路径
	//写入数据
	ofs.write((char*)&a,sizeof(VS));//写入结构体
	ofs.close();
	ifstream ifs;
	ifs.open("user.txt",ios::in);
	//关闭文件
```

## 5.窗口调用不出来--要先确定执行程序存进去了呀!!!!

# 二.项目日常笔记

## 1.  6.2日--文件操作

### a.存入文件需要存入一个类

可以用 ofs<<string str1<<" "<<string str2<<" "<<endl;

一行一行得存

### b.文件读取

这里buf为 char buf[1024];

	ifs.getline(buf,256);
	sscanf(buf,"%s %s %d",);*/

### 2.static 函数也要写作用域

## 2   6.3  map find 函数使用

用find函数来定位数据出现位置，它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器，程序说明

```
\#include <map>

\#include <string>

\#include <iostream>

Using namespace std;

Int main()

{

​    Map<int, string> mapStudent;

​    mapStudent.insert(pair<int, string>(1, “student_one”));

​    mapStudent.insert(pair<int, string>(2, “student_two”));

​    mapStudent.insert(pair<int, string>(3, “student_three”));

​    map<int, string>::iterator iter;

​    iter = mapStudent.find(1);

if(iter != mapStudent.end())

{

​    Cout<<”Find, the value is ”<<iter->second<<endl;

}

Else

{

​    Cout<<”Do not Find”<<endl;

}

}
```

## 6.4 string类型转为 int 类型

```
　显然，atoi需要的事const char*类型，而我上面给的上string类型，所以就要 多加一个函数string.c_str()。string.c_str是Borland封装的String类中的一个函数，它返回当前字符串的首字符地址。

　　c_str函数的返回值是const char*,所以我们加上c_str()函数：

　

复制代码
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
    string a="11",b="22";
    cout<<atoi(a.c_str())+atoi(b.c_str())<<endl;
    return 0;

```

3. ## 重复声明

   

```
while(1)
{
	int i;
}
```

## 6.5   int to string 转换类型

导入

#include <sstream>

```
        stringstream ss;
        int num=1998;
        string lo;
        ss<<num;
        ss>>lo;
        cout<<lo.size()<<endl;
```

## 6.6.注册未确认就退出

a.在进入任何注册窗口的时候将文本内容置空

b.在注册成功后也把文本内容置空

## 6.7.注册这里又读了一次文件写入map所以可以查到刚注册的![image-20210604145617866](C:\Users\lyl\AppData\Roaming\Typora\typora-user-images\image-20210604145617866.png)

## 6.8登入判断

文本清空清就要获取账号给全局变量

# 三/bug 

## 1.页面下标

表格1/2->2/2

这里用表格打印覆盖的

## 2.出循环 

```
while(1)
{
	winArr[0]->show();
	winArr[0]->run();

}
```

## 3.精确查询和模糊查询是修改了页数值导致在这2个界面无法翻页超出

4.好像不要设置左右翻页cout

因为无论向左还是右边翻页只要操作page基于够了 

迭代器是一直++;找到位置++

# 四.思路

1.有些东西不用全局函数因为有全局窗口 可以写在全局窗口里
