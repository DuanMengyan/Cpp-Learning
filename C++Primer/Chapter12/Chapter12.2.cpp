#pragma once
#pragma execution_character_set("utf-8")
#pragma  warning (disable:4996) 


/*************************************************************************
> File Name: Chapter12.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月24日 星期四
> Last edited time: 2019年1月25日 星期五
> Topic:C++Primer Chapter12.2 动态数组
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"
//#include "StrBlob.h"
//#include "StrBlobPtr.h"
//#include "ConstStrBlobPtr.h"

using namespace std;

//Chapter12.2 动态数组
//Dynamic_Arrays


//ex12.23
void str_connection(char str1[] , char str2[])
{
	cout << strlen(str1) + strlen(str2) << endl;
	char *cp = new char[strlen(str1)+strlen(str2)]();
	strcat(cp, str1);
	strcat(cp, str2);
	cout << cp ;
	cout << "================" << endl;
	
}

void str_connection(string &str1, string &str2)
{
	cout << str1 + str2;
	cout << "================" << endl;
}


//12.3.1 new和数组
void Fun_new_and_Arrays()
{
	//方括号中的大小必须是整型，但不必是常量
	//int *pia = new int[5];     //pia指向第一个int
	////也可以用一个表示数组类型的类型别名来分配一个数组
	//typedef int arrT[42];
	//int *p = new arrT;
	////等价于
	//int *p2 = new int[42];

	//分配一个数组会得到一个元素类型的指针
	//由于分配的内存并不是一个数组类型，因此不能对动态数组调用begin或end，
	//也不能使用范围for语句来处理动态数组中的元素

	//初始化动态分配对象的数组
	//在大小之后跟一对空括号对数组进行值初始化
	//提供一个元素初始化器进行初始化
	//不能再括号中给出初始化器，不能使用auto分配数组
	//int *pia3 = new int[10]{ 0,1,2,3,4,5,6,7,8,9 };

	//动态分配一个空数组是合法的
	//char arr[0];   //报错：数组的大小必须大于0
	//char *cp = new char[0];		//正确，但是cp不指向任何元素，不能解引用

	//释放动态数组，数组中的元素逆序销毁
	//delete p;			//p必须指向一个动态分配的对象或为空
	//delete []cp;		//cp必须指向一个动态分配的数组或为空

	//不管定义时形式如何，cp指向一个对象数组的首元素，而不是某个类型的一个单一对象，因此在释放数组时，必须加上方括号

	//智能指针和动态数组
	//unique_ptr指向一个动态分配的数组是，不能使用点和箭头成员运算符，可以使用下标运算符访问元素
	//unique_ptr<int[]> up(new int[10]);
	//如果希望使用shared_ptr管理一个动态数组，必须提供自己定义的删除器
	//shared_ptr<int> sp(new int[10], [](int*p) {delete p; });
	//shared_ptr未定义下标运算符，使用get获取一个内置指针，访问数组中元素
	
	//ex12.23
	//string str1 = "hello", str2 = "world";
	//str_connection("hello", "world");
	//str_connection(str1, str2);

	//ex12.24
		
	//cout << "How long do you want the string? ";
	//int size = 0;
	//cin >> size;
	//char *input = new char[size+1]();
	//cin.ignore();
	//cout << "input the string: ";
	//cin.get(input, size+1);
	//cout << input;
	//delete[] input;
	
	//ex12.25
	//int *pa = new int[10];
	//delete[] pa;
}


//12.3.2 allocator类
void Fun_The_allocator_Class()
{
	//没有默认构造函数的类不能动态分配数组
	
	//allocator类将内存分配和对象构造分离开来
	//分配一段原始的、未被构造的内存
	//allocator分配为构造的内存
	//allocator<string> alloc;
	//auto p = alloc.allocate(10);
	//auto q = p;			//q指向最后构造的元素之后的位置；
	//alloc.construct(q++);
	//alloc.construct(q++, 10, 'c');
	//alloc.construct(q++, "hello");
	//
	//while (q!=p)
	//{
	//	cout << *(--q) << endl;
	//	//对指向的对象执行析构函数，只能对真正构造了的元素执行destroy操作
	//	alloc.destroy(q);	
	//}
	////元素被销毁以后，可以重新使用这部分内存，也可以将其归还给系统，
	////调用deallocate前，必须对每个元素执行destroy
	//alloc.deallocate(q, 10);//统一分配，统一释放

	//拷贝和填充未初始化内存的算法
	
	//vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	//allocator<int> alloc;
	//auto p = alloc.allocate(vec.size() * 2);
	////每次调用uninitialized_copy返回一个构造元素之后位置的指针
	//auto q = uninitialized_copy(vec.begin(), vec.end(), p);
	//auto m = uninitialized_fill_n(q, vec.size(), 42);
	//while (m != p)
	//{
	//	cout << *(--m) << "   ";
	//}

	//ex12.26
	//allocator<string> alloc;
	//auto p = alloc.allocate(10);
	//ifstream input("Text2.txt");
	//string str;
	//auto q = p;
	//for (; q != p + 10 && getline(input, str); q++)
	//{
	//	alloc.construct(q, str);
	//}
	//while (q != p)
	//{
	//	cout << *(--q) << endl;
	//}
}

int main()
{
	//12.3.1 new和数组
	//Fun_new_and_Arrays();
	//12.3.2 allocator类
	Fun_The_allocator_Class();

	return 0;
}