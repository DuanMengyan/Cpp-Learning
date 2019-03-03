#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter13.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年3月3日 星期日
> Last edited time: 2019年3月3日 星期日
> Topic:C++Primer Chapter13.5 动态内存管理类
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

//Chapter13.5 动态内存管理类
void Fun_Classes_That_Manage_Dynamic_Memory()
{
	//某些类需要自己进行内存分配，一般来说必须定义自己的拷贝控制成员来管理所分配的内存
	//实现标准库vector类的简化版本，只适用于string，命名为：StrVec

	//StrVec类的设计
	//每个StrVec有三个指针成员指向其元素所使用的内存
	
	//移动构造函数和std::move


}


int main()
{
	//Chapter13.5 动态内存管理类
	Fun_Classes_That_Manage_Dynamic_Memory();

	return 0;
}