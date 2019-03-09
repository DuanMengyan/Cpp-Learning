#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter13.6.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年3月9日 星期六
> Last edited time: 2019年3月9日 星期六
> Topic:C++Primer Chapter13.6 对象移动
************************************************************************/

#include "header_include.h"
//#include "Sales_data.h"
//#include "StrBlob.h"
//#include "StrBlobPtr.h"
//#include "HasPtr.h"
//#include "HasPtr2.h"
//#include "Folder.h"
//#include "Message.h"
//#include "StrVec.h"
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
	////int &&rr = i;				//错误，不能讲一个右值引用绑定到一个左值上
	////int &r2 = i * 42;			//错误，i*42是一个右值
	//const int &r3 = i * 42;		//正确，我们可以将一个const引用绑定到一个右值上
	//int &&rr2 = i * 42;			//正确，讲一个右值引用绑定到乘法结果（右值）上

	//返回左值引用的函数，连同赋值、下标、解引用和前置递增/递减运算符，都是返回左值的表达式
	//我们可以将一个左值引用绑定到这类表达式的结果上
	
	//返回非引用类型的函数，连同算数、关系、、位以及后置递增/递减运算符，都生成右值
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



int main()
{
	//Chapter13.6.1 右值引用
	Fun_Rvalue_References();

	return 0;
}