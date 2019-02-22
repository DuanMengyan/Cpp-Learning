#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter13.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年2月18日 星期一
> Last edited time: 2019年2月22日 星期五
> Topic:C++Primer Chapter13.1 拷贝、赋值与销毁
************************************************************************/


#include "header_include.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"

using namespace std;

//ex13.5
class HasPtr
{
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &item) :ps(new string(*item.ps)), i(item.i) {}

private:
	string *ps;
	int i;
};



//Chapter13.1.1 拷贝构造函数
void Fun_The_Copy_Constructor()
{
	//合成拷贝构造函数
	//如果一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值，则此构造函数是拷贝构造函数
	//拷贝构造函数的第一个参数必须是一个引用类型。
	//一般情况而言，合成的拷贝构造函数会将其参数的成员逐个拷贝到正在创建的对象中

	//拷贝初始化
	//拷贝初始化通常使用拷贝构造函数来完成，或者使用移动构造函数来完成
	//直接初始化实际上是要求编译器使用普通的函数匹配选择与我们提供的参数最匹配的构造函数来进行初始化
	//拷贝初始化发生情况：
	//1.使用=定义变量时；
	//2.将一个对象作为实参传递给一个非引用类型的形参  void fun(int a){}   int b = 5; fun(b);
	//3.从一个返回类型为非引用类型的函数返回一个对象  int fun(int a){return a;}  int b = fun(5);
	//4.用花括号列表初始化一个数组中的元素或一个聚合类中的成员
	//5.某些类类型还会对它们所分配的对象使用拷贝初始化。初始化标准库容器或是调用其insert或push成员时，容器会对其元素进行拷贝初始化
	//	与之相对，用emplace成员创建的匀速都是进行直接初始化
	//注：（参见9.3.1节，308页）
	//当调用push或insert成员函数时，我们将元素类型的对象传递给它们，这些对象被拷贝到容器中。
	//而当我们调用一个emplace成员函数时，则是将参数传递给元素类型的构造函数
	//emplace成员使用这些参数在容器管理的内存空间中直接构造元素
	
	//参数和返回值
	//拷贝构造函数被用来初始化非引用类类型参数，因此拷贝构造函数自己的参数必须是引用类型，
	//否则，调用就会无限循环下去，不能成功

	
	//拷贝初始化的限制
	//vector<int> v1(10);
	//cout << v1.size() << endl;
	//vector<int> v2 = 10;  //错误，接受大小参数的构造函数是explicit的

	//void f(vector<int>);
	//f(10);				//错误，不能使用一个ecplicit的构造函数拷贝一个实参
	//f(vector<int>(10));	//正确，从一个int直接构造一个临时vector
	
	//编译器可以绕过拷贝构造函数
	//编译器可以跳过拷贝/移动构造函数，直接创建对象
	//编译器将：
	//string null_book = "999-99-9";	//拷贝初始化
	//改写为：
	//string null_book("999-99-9");
	//但此时，拷贝/移动构造函数必须是存在且可以访问的（public）

	//ex13.1	进行拷贝初始化时用拷贝构造函数
	//ex13.2	拷贝构造函数第一个参数必须是引用类型
	//ex13.3	
	//StrBlob拷贝复制元素，引用计数加1
	//StrBlob str({ "hello", "world" });		//调用初始化列表构造函数
	//std::cout << "before: " << str.count() << std::endl; // 1
	//StrBlob str_cp(str);					//调用编译器合成的默认拷贝构造函数
	//std::cout << "after: " << str.count() << std::endl;  // 2
	//str.print_strblob();
	////StrBlobPtr拷贝复制元素，但是弱指针计数器不变;
	//StrBlobPtr p(str);
	//std::cout << "before: " << p.count() << std::endl; // 2
	//StrBlobPtr p_cp(p);
	//std::cout << "after: " << p.count() << std::endl; // 2

	//ex13.4
	//首先foo_bar函数的参数是非引用类型，需拷贝，使用拷贝构造函数；
	//函数的返回类型非引用类型，也需要进行拷贝，使用拷贝构造函数。
	//在函数体中arg拷贝到local对象，global拷贝到heap对象，local、*heap拷贝到pa[4]中皆使用拷贝构造函数
	//使用=进行定义变量时
	
	//ex13.5 //如上


}

//Chapter13.1.2 拷贝赋值运算符
void Fun_The_Copy_Assignment_Operator()
{
	//如果类未定义拷贝复制运算符，编译器会为它定义一个；
	StrBlob str{"hello","world"};
	StrBlob str2;
	str2 = str;
	str2.print_strblob();
	//重载赋值运算符
	//赋值运算符就是一个名为operator=的函数
	//如果运算符是一个成员函数，其左侧的对象就绑定到隐式的this参数
	//赋值运算符通常返回一个指向其左侧运算对象的引用
	//标准库通常要求保存在容器中的类型要具有赋值运算符，且其返回值是左侧运算对象的引用


}

int main()
{
	//Chapter13.1.1 拷贝构造函数
	//Fun_The_Copy_Constructor();
	//Chapter13.1.2 拷贝赋值运算符
	Fun_The_Copy_Assignment_Operator();
	return 0;
}
