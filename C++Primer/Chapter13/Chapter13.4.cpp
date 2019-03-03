#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter13.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年3月1日 星期五
> Last edited time: 2019年3月2日 星期六
> Topic:C++Primer Chapter13.4 拷贝控制实例
************************************************************************/

#include "header_include.h"
//#include "Sales_data.h"
//#include "StrBlob.h"
//#include "StrBlobPtr.h"
//#include "HasPtr.h"
//#include "HasPtr2.h"
#include "Folder.h"
#include "Message.h"


using namespace std;

//Chapter13.4 拷贝控制实例
void Fun_A_Copy_Control_Example()
{
	//拷贝赋值运算符通常执行拷贝构造函数和析构函数中也要进行的工作
	//公共部分可以在private工具函数中完成

	//ex13.33
	//因为在函数中要对Folder成员进行修改，所以定义为非const引用类型；
	//避免对Folder对象的拷贝，也保证修改成功

	//ex13.34
	
	//ex13.35
	//合成的拷贝控制成员不能更新folders，包含信息会错乱

	//ex13.36

	//在定义好Folder和Message类之后，一直有报错
	//经过一天debug之后，发现是Folder的析构函数执行错误；
	//再后来发现是Folder析构时，一个范围循环语句执行错误，
	//在循环内删除了set_m中的元素，导致了迭代器失效，循环报错；
	//C++Primer 5th的315页，9.3.6节 容器操作可能是迭代器操作失效
	//向容器中添加元素或者向容器删除元素的操作可能会使指向容器元素的指针、引用或迭代器失效，引发很严重的错误。
	//因此对容器进行增删操作后要注意重新定位指针、引用或迭代器，循环中尤其重要
	
		
	Folder work("work"), study("study");
	
	
	Message m1("m1"), m2("m2"), m3("m3"), m4("m4");

	m1.save_to_Folder(work); m1.save_to_Folder(study);
	m2.save_to_Folder(work);
	m3.save_to_Folder(work); m3.save_to_Folder(study);
	m4.save_to_Folder(work);
	m1.print_folders();
	m2.print_folders();
	m3.print_folders();
	m4.print_folders();

	//打印Folder中的Message
	cout << "***** work *****" << endl;
	work.print_messages();
	cout << "***** study *****" << endl;
	study.print_messages();

	cout << endl << "=======================" << endl;

	//拷贝构造函数
	Folder work2(work);

	cout << endl << "=======================" << endl;
	
	//拷贝赋值运算符
	study = work;
	study.print_messages();

	cout << endl << "=======================" << endl;
	work2.print_messages();

	//ex13.37
	//见类文件

	//ex13.38
	//使用动态分配的内存时，复制和交换是一种优雅的方式。 
	//在Message类中，并没有涉及到动态内存分配。 
	//因此，使用这种惯用语法是没有意义的，并且由于指向后者的指针将使其更复杂。

	//在这种情况下，交换功能是特殊的。 
	//它将清除两个Message的文件夹，然后交换成员，并将自己添加到每个文件夹。 
	//但是，Message的拷贝赋值运算符只是清除自己，并复制成员，并将自己添加到每个文件夹。 
	//rhs不需要清除并添加到文件夹。 
	//因此，如果使用copy和swap来定义，那将是非常低效的。



}


int main()
{
	//Chapter13.4 拷贝控制实例
	Fun_A_Copy_Control_Example();
	return 0;
}
