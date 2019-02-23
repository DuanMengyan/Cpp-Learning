#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter13.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年2月18日 星期一
> Last edited time: 2019年2月23日 星期六
> Topic:C++Primer Chapter13.1 拷贝、赋值与销毁
************************************************************************/


#include "header_include.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"

using namespace std;

//ex13.5/ex13.8/13.11
class HasPtr
{
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	//拷贝构造函数
	HasPtr(const HasPtr &item) :ps(new string(*item.ps)), i(item.i) 
	{ 
		cout << *ps << " ***The_Copy_Constructor" << endl;
	}
	//拷贝复制运算符
	HasPtr& operator=(const HasPtr &hp)
	{
		cout << *ps << " ***The_Copy_Assignment_Operator" << endl;
		string *p = new string(*hp.ps);		//new返回指向分配好的内存，创建对象指针
		delete ps;		//首先删除原内存
		ps = p;			//赋值
		i = hp.i;
		return *this;
	}
	//析构函数
	~HasPtr()
	{
		cout << *ps << " ***The_Destructor" << endl;
	}
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
	//StrBlob str{"hello","world"};
	//StrBlob str2;
	//str2 = str;
	//str2.print_strblob();
	//重载赋值运算符
	//赋值运算符就是一个名为operator=的函数
	//如果运算符是一个成员函数，其左侧的对象就绑定到隐式的this参数
	//赋值运算符通常返回一个指向其左侧运算对象的引用
	//标准库通常要求保存在容器中的类型要具有赋值运算符，且其返回值是左侧运算对象的引用

	//ex13.6
	//拷贝复制运算符是一个名为operator=的函数，用来进行拷贝赋值
	//拷贝赋值的时候使用，
	//合成拷贝赋值运算符将右侧运算对象的所有非static成员赋予左侧运算对象的对应成员
	//如果类内未显式定义拷贝赋值运算符，则编译器会自动生成一个合成拷贝赋值运算符

	//ex13.7
	//所有成员进行赋值，两个StrBlob中智能指针所指对象内存相同，计数器加1，
	//两个StrBlobPtr中智能指针所指对象内存相同，计数器不变

	//ex13.8
	
}

//ex13.13
void fun1(HasPtr hitem)
{
	cout << "fun1" << endl;
}

void fun2(HasPtr &hitem)
{
	cout << "fun2" << endl;
}

//Chapter13.1.3 析构函数
void Fun_The_Destructor()
{
	//构造函数初始化对象的非static数据成员，还可能做一些其他工作；
	//析构函数释放对象使用的资源，并销毁对象的非static数据成员

	//析构函数名字有波浪线接类名构成，没有返回值，也不接受参数
	//析构函数不接受参数，所以不能重载，一个给定类只能有一个析构函数

	//析构函数完成什么工作
	//构造函数有一个初始化部分和一个函数体，析构函数有一个函数体和一个析构部分
	//构造函数中，成员的初始化是在函数体执行之前完成的，按照它们在类中出现的顺序进行初始化
	//析构函数中，首先执行函数体，然后销毁成员，按初始化顺序的逆序销毁
	//通常情况，析构函数释放对象在生存期分配的所有资源
	//一个析构函数中，析构部分是隐式的，成员销毁时发生什么完全依赖于成员的类型，
	//销毁类类型成员，执行类类型成员自己的析构函数
	//内置类型没有析构函数，因此销毁内置类型不执行任何操作
	//隐式销毁一个内置指针类型，不会delete它所指向的对象
	//智能指针是类类型，会在析构阶段执行它的析构函数，被自动销毁。

	//什么时候调用析构函数，无论何时，一个对象被销毁时，就会自动调用其析构函数
	//变量在离开其作用域时被销毁；
	//当一个对象被销毁时，其成员被销毁
	//当容器被销毁时，其元素被销毁
	//对于动态分配的对象，当对指向它的指针用delete运算符时被销毁
	//对于临时对象，当创建它的完整表达式结束时被销毁
	
	//Sales_data book("book");
	//{
	//	Sales_data&r = book;
	//	Sales_data *p = new Sales_data("book1");
	//	auto p2 = make_shared<Sales_data>("book2",5,12.00);
	//	Sales_data item(*p);
	//	vector<Sales_data>vec;
	//	vec.push_back(Sales_data("book3"));		//销毁临时对象
	//	delete p;		//对p指向的对象执行析构函数
	//}
	//退出局部作用域，对item、p2和vec调用析构函数，销毁顺序与定义顺序相反
	//book3  ***Destructor***			//销毁临时对象book3
	//book1  ***Destructor***			//销毁p
	//book3  ***Destructor***			//销毁vec，销毁它的元素
	//book1  ***Destructor***			//销毁item
	//book2  ***Destructor***			//销毁p2，递减其引用计数，引用计数变为0，对象被释放

	//当指向一个对象的引用或指针离开作用域时，析构函数不会执行,引用r离开作用域，不会销毁book；

	//合成析构函数
	//析构函数体执行完毕后，成员会被自动销毁，析构函数体自身并不直接销毁成员，
	//成员是在析构函数体之后隐含的析构阶段中被销毁的

	//ex13.9
	//析构函数是类类型中用来释放对象所分配的资源，并销毁对象所有非static数据成员的函数
	//合成析构函数是类未自己定义析构函数，编译器为它定义的，用来析构类对象

	//ex13.10
	//执行析构函数体，然后销毁所有非static数据成员，StrBlob中智能指针引用计数器减1，
	//执行析构函数体，销毁所有非static数据成员，弱指针不影响计数器

	//ex13.11
	
	//ex13.12
	//析构函数执行三次：accum，item1，item2，

	//ex13.13
	//HasPtr h1("hello");
	//HasPtr h2("world");
	//HasPtr h3("C++");
	
	//作为非引用参数和引用参数传递
	//fun1(h1);
	//fun2(h2);

	//存放于容器中
	//vector<HasPtr> vec;
	//vec.push_back(h1);

	//动态分配
	//HasPtr *hp = new HasPtr("Primer");
	//fun2(*hp);
	//delete hp;

}
 
int main()
{
	//Chapter13.1.1 拷贝构造函数
	//Fun_The_Copy_Constructor();

	//Chapter13.1.2 拷贝赋值运算符
	//Fun_The_Copy_Assignment_Operator();

	//Chapter13.1.3 析构函数
	Fun_The_Destructor();
	return 0;
}
