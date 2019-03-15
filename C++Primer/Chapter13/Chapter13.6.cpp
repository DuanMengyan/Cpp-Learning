#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter13.6.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年3月9日 星期六
> Last edited time: 2019年3月15日 星期五
> Topic:C++Primer Chapter13.6 对象移动
************************************************************************/

#include "header_include.h"
//#include "Sales_data.h"
//#include "StrBlob.h"
//#include "StrBlobPtr.h"
#include "HasPtr.h"
//#include "HasPtr2.h"
#include "Folder.h"
#include "Message.h"
#include "StrVec.h"
//#include "QueryResult.h"
//#include "TextQuery.h"
#include "MyString.h"


using namespace std;

//Chapter13.6 对象移动
//标准库容器、string和shared_ptr类既支持移动也支持拷贝。
//IO类和unique_ptr类可以移动但不能拷贝

//Chapter13.6.1 右值引用
void Fun_Rvalue_References()
{
	//右值引用就是必须绑定到右值的引用，使用&&来获得右值引用。
	//右值引用只能绑定到一个将要销毁的对象
	//int i = 42;
	//int &r = i;
	////int &&rr = i;				//错误，不能将一个右值引用绑定到一个左值上
	////int &r2 = i * 42;			//错误，i*42是一个右值
	//const int &r3 = i * 42;		//正确，我们可以将一个const引用绑定到一个右值上
	//int &&rr2 = i * 42;			//正确，讲一个右值引用绑定到乘法结果（右值）上

	//返回左值引用的函数，连同赋值、下标、解引用和前置递增/递减运算符，都是返回左值的表达式
	//我们可以将一个左值引用绑定到这类表达式的结果上
	
	//返回非引用类型的函数，连同算数、关系、位以及后置递增/递减运算符，都生成右值
	//我们可以将一个const的左值引用或者一个右值引用绑定到这类表达式上

	//左值持久，右值短暂
	//右值引用只能绑定到临时对象，所以它所引用的对象将要被销毁或者该对象没有其他用户
	//使用右值引用的代码可以自由地接管所引用的对象的资源

	//变量是左值
	//变量表达式都是左值,我们不能将一个右值引用绑定到一个右值引用类型的变量上

	//int &&rr1 = 42;
	//int &&rr2 = rr1;  //错误，表达式rr1是左值

	//标准库move函数，定义在头文件utility中
	//int &&rr1 = 42;
	//我们有一个左值rr1，但我们希望像一个右值一样处理它
	//我们直接调用std::move,避免潜在的名字冲突
	//int &&rr3 = std::move(rr1);	
	//cout << rr3 << endl;		//42
	//除了对rr1赋值或销毁它外，我们将不再使用它
	//我们不能对移后源对象的值做任何假设，不能使用一个移后源对象

	//ex13.45
	//左值引用绑定到左值上，是长久持续存在的
	//右值引用或者const类型的引用可以绑定在右值上，短暂的
	
	//ex13.46
	//右值，左值，左值，右值
	
	//ex13.47
	//见MyString.cpp

	//ex13.48
	vector<MyString> str_vec;
	str_vec.push_back("hello");
	str_vec.push_back("hello1");


}

//从输入流构造StrVec对象
StrVec getVec(istream & is)
{
	string str;
	StrVec str_vec;
	while (is >> str)
	{
		str_vec.push_back(str);
	}
	cout << "input ending....." << endl;
	return str_vec;
}

//Chapter13.6.2 移动构造函数和移动赋值运算符
void Fun_Move_Constructor_and_Move_Assignment()
{
	//类似拷贝构造函数，移动构造函数的第一个参数是该类类型的一个引用。
	//不同于拷贝构造函数，这个引用参数在移动构造函数中是一个右值引用。
	//与拷贝构造函数一样，其他任何额外的参数都必须有默认实参。

	//确保移后源对象处于这样一个状态——销毁它是无害的

	//移动操作、标准库容器和异常
	//在一个构造函数中，noexcept出现在参数列表和初始化列表开始的冒号之间
	//我们必须在类头文件的声明中和定义中（如果定义在类外的话）都制定noexcept
	//不抛出异常的移动构造函数和移动赋值运算符必须标记为noexcept

	//我们通过将移动构造函数（以及移动赋值运算符）标记为noexcept来显式地告诉标准库移动构造函数可以安全使用
	//使得标准库容器在重新分配内存时对我们自定义类型的对象进行移动而不是拷贝。

	//移后源对象必须可析构
	//在移动操作之后，移后源对象必须保持有效的、可析构的状态，但是用户不能对其值进行任何假设

	//合成的移动操作
	//只有当一个类没有定义任何自己版本的拷贝控制成员，且类的每个非static数据成员都可以移动时，
	//编译器才会为它合成移动构造函数或移动赋值运算符。
	//编译器可以移动内置类型的成员，如果一个成员是类类型，且该类有对应的移动操作，编译器也能够移动这个成员

	//如果类定义了一个移动构造函数和/或一个移动赋值运算符，则该类的合成拷贝构造函数和拷贝赋值运算符会被定义为删除的。



	//移动右值，拷贝左值
	//StrVec v1, v2;
	//
	////StrVec getVec(istream &);		//getVec返回一个右值
	//v1 = v2 = getVec(cin);				//getVec(cin)返回一个右值，使用移动赋值
	//cout << "V2 : ";
	//v2.print_str();

	//cout << "============================" << endl;

	//v1 = v2;			//v2是左值；使用拷贝赋值
	//cout << "V1 : ";
	//v1.print_str();


	//移动右值，拷贝左值，但如果没有移动构造函数，右值也被拷贝
	//使用拷贝构造函数代替移动构造函数几乎肯定是安全的（赋值运算符的情况类似）。
	//一般情况下，拷贝构造函数满足对应的移动构造函数的要求：他会拷贝给定对象，并将原对象置于有效状态
		
	//拷贝并交换赋值运算符和移动操作
	//拷贝并交换赋值运算符，此函数接受一个非引用参数，要进行拷贝初始化；
	//左值被拷贝，右值被移动，单一的赋值运算符就实现了拷贝赋值运算符和移动赋值运算符两种功能

	//所有拷贝控制成员应当看做一个整体，如果一个类定义了任何一个拷贝控制成员，就应当定义所有五个操作

	//Message类的移动操作




}




int main()
{
	//Chapter13.6.1 右值引用
	//Fun_Rvalue_References();
	//Chapter13.6.2 移动构造函数和移动赋值运算符
	Fun_Move_Constructor_and_Move_Assignment();

	return 0;
}