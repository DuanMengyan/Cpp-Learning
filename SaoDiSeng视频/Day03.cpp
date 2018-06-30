/*************************************************************************
> File Name: C++基础Day03.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年06月30日 星期六
> Topic:C++对C语言的增强
************************************************************************/




#include "iostream"
using namespace std;

//实用性增强
/*
C语⾔中的变量都必须在作⽤域开始的位置定义！！
C++中更强调语⾔的“实⽤性”，所有的变量都可以在需要使⽤时再定义。
*/

//register增强
/*
1.
C++中依然支持register关键字
C++中可以取得register变量的地址
2.
C++编译器发现程序中需要去register变量的地址时，register对变量的声明变得无效
*/

//变量检测增强
/*
C++中不允许定义多个同名的全局变量
int a;
int a = 10;//C++编译器报错：变量a重定义
*/

//struct关键字增强
/*
C语⾔的struct定义了⼀组变量的集合， C编译器并不认为这是⼀种新的类型
struct Teacher
{
	char name[100];
	int age = 25;	
};

//使用时需如下：
struct Teacher t1;
C++中的struct是⼀个新类型的定义声明
struct 关键字和class关键在完成的功能是一样的，但仍有区别


struct Student
{
	char name[100];
	int age;
};



int main()
{
	Student s1 = {"wang",12};//C++中的struct是⼀个新类型的定义声明
	cout << s1.name << endl;
	return 0;
}
*/


//C++中所有变量和函数都必须有类型
/*
C++中所有的变量和函数都必须有类型
C语⾔中的默认类型在C++中是不合法的
函数f的返回值是什么类型，参数⼜是什么类型？
函数g可以接受多少个参数
C++更加强调类型，任意的程序元素都必须显示指明类型

f(i)
{
	printf("i=%d\n",i);
}
g()
{
	return 5;
}

int main()
{
	f(10);
	printf("g()=%d\n",g(1,2,3,4,5));

	return 0;
}
*/



//新增数据类型bool类型
/*
*
C++中的布尔类型
C++在C语⾔的基本类型系统之上增加了bool
C++中的bool可取的值只有true和false
理论上bool只占⽤⼀个字节，
如果多个bool变量定义在⼀起，可能会各占⼀个bit，这取决于编译器的实现
true代表真值，编译器内部⽤1来表⽰
false代表⾮真值，编译器内部⽤0来表⽰
bool类型只有true（⾮0）和false（0）两个值
C++编译器会在赋值时将⾮0值转换为true， 0值转换为false
*/

int main()
{
	bool b1 = true;
	bool b2 = true;
	int a,b,c = 1;
	a = b = c = 2;
	cout << "sizeof(bool):" << sizeof(bool) << endl; //告诉C++编译器给分配1个字节的内存
	
	//bool变量值1或者0，非true即false
	//b1 = 10;
	cout << "b1:" << b1 << endl; 
	cout << "b2:" << b2 << endl;

	system("pause");
	return 0;

}