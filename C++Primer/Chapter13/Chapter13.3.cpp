#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter13.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年2月28日 星期四
> Last edited time: 2019年2月28日 星期四
> Topic:C++Primer Chapter13.3 交换操作
************************************************************************/

#include "header_include.h"
//#include "Sales_data.h"
//#include "StrBlob.h"
//#include "StrBlobPtr.h"
//#include "HasPtr.h"
#include "HasPtr2.h"



using namespace std;



//Chapter13.3
void Fun_Swap()
{
	//与拷贝控制成员不同，swap并不是必要的，
	//但是，对于分配了资源的类(行为像值的类)，定义swap可能是一种很重要的优化手段

	//swap函数应该调用swap，而不是是std::swap;
	//如果存在类型特定的swap版本,其匹配程度会由于std中定义的版本
	//否则，会调用std中的版本（假定作用于中有using声明）

	//在赋值运算符中使用swap 拷贝并交换
	//自动异常安全，且可以正确处理自赋值；
	//有可能会在拷贝构造函数new表达式中抛出异常，但是会在改变左侧运算对象之前出现
	//HasPtr& operator=(HasPtr rhs)
	//{
	//	swap(*this, rhs);
	//	return *this;
	//}

	//ex13.29
	//int、指针、string等都会调用它们定义的自己版本的swap、HasPtr会调用自己定义的swap(HasPtr &, HasPtr &)

	//ex13.30

	//ex13.31
	HasPtr2 a("a"); 
	HasPtr2 b("b"); 
	HasPtr2 c("c"); 
	HasPtr2 d("d");
	vector<HasPtr2> vec{a,c,b,d};
	show(vec);
	sort(vec.begin(), vec.end());
	show(vec);

	//ex13.32
	//从本质上讲，避免内存分配是它提高性能的原因。
	//类指针的类版本，使用编译器自带的swap()函数即可完成目标操作，没有动态内存分配
	//并不需要自定义一个swap以交换指针所指向的值，所以并不会提升效果
}




int main()
{	

	//Chapter13.3
	Fun_Swap();
	return 0;
}
