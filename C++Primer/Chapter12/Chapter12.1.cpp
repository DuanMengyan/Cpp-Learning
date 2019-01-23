#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter12.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月10日 星期四
> Last edited time: 2019年1月22日 星期二
> Topic:C++Primer Chapter12.1 动态内存与智能指针
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"
#include "StrBlob.h"


using namespace std;

//Chapter12.1 动态内存与智能指针
//Dynamic_Memory_and_Smart_Pointers


shared_ptr<int> factory(int i)
{
	return make_shared<int>(i);
}

shared_ptr<int> factory2(int i)
{
	shared_ptr<int> p = factory(i);
	return p;
}//p离开了作用于，但它指向的内存不会被释放掉

//12.1.1 shared_ptr类
void Fun_The_shared_ptr_Class()
{
	//shared_ptr<string> p1;
	//shared_ptr<list<int>> p2;
	//string str = "HI";
	//if (p1 && p1->empty())
	//{
	//	*p1 = str;
	//}


	//make_shares函数,安全地使用和分配动态内存
	//此函数在动态内存中分配一个对象并初始化它，返回指向此对象的shared_ptr。
	//shared_ptr<int> p3 = make_shared<int>(42);
	//shared_ptr<string> p4 = make_shared<string>(10, '9');
	//cout << p3 << "   " << *p3 << endl;
	//shared_ptr<int> p5 = make_shared<int>();
	//cout << p5 << "   " << *p5 << endl;
	//vector<string> vec{ "C++","hello" };
	//auto p6 = make_shared<vector<string>>(vec);
	//cout << p6 << "   " << *((*p6).begin()) << endl;
	
	//shared_ptr的拷贝和赋值
	//auto p = make_shared<int>(42);
	//auto q(p);
	//cout << *q << endl;
	//cout << p.use_count() << endl;			//2,返回与p共享对象的智能指针数量,引用计数
	////一旦一个shared_ptr的计数器变为0，它就会自动释放自己所管理的对象
	//auto r = make_shared<int>(50);
	//cout << r.use_count() << endl;			//1，此时只有r指向了在动态内存中分配的int 50
	//r = q;									//r被赋予一个新值，原来的int50自动被销毁
	//cout << p.use_count() << endl;			//3，q赋值给了r，引用计数+1
	//cout << r.use_count() << endl;			//3，r和p、q都指向int 42，引用计数为3

	//shared_ptr自动销毁所管理的对象
	//析构函数控制此类型对象销毁时做什么操作，析构函数一般用来释放对象所分配的资源
	
	//shared_ptr还会自动释放相关联的内存

	//auto q = factory2(42);
	//cout << q << "  " << *q << "  " << q.use_count() << endl;
	//如果将shared_ptr存放在一个容器中，随后重排了容器，从而不再需要某些元素。
	//在这种情况下，应该确保用erase删除那些不再需要的shared_ptr元素。
	
	//使用了动态生存期的资源的类。
	//程序使用动态内存的原因：
	//1.程序不知道自己需要使用多少对象；
	//2.程序不知道所需对象的准确类型；
	//3.程序需要在多个对象间共享数据；
	//vector<string> v1;
	//{
	//	//新作用域
	//	vector<string> v2 = { "a","an","the" };
	//	v1 = v2;
	//}
	
	//使用动态内存的一个常见原因是允许多个对象共享相同的状态
	
	//定义StrBlob类
	//元素访问成员函数
	//StrBlob的拷贝、赋值和销毁

	//ex12.
	//StrBlob b1;
	//{
	//	StrBlob b2 = { "a","an","the" };
	//	b1 = b2;
	//	b2.push_back("about");
	//}
	//cout << b1.size() << endl;  //4，b2不存在了

	//ex12.2
	//略

	//ex12.3
	//可以，但是没有必要。StrBlob只是一个指针，因为push_back和pop_back并不修改数据，它们修改数据指向的vector<string>;

	//ex12.4
	//因为i是vector<string>::size_type类型，是unsigned，当i小于0时，会自动转换成大于0的数	

	//ex12.5
	//StrBlob item2 = { "C++","hello","primer","python" };
	//构造函数只能直接初始化，不能使用上面拷贝形式的初始化过程
}



//ex12.6
vector<int> *fun1()
{
	vector<int> *p_vec = new vector<int>;
	return p_vec;
}

vector<int> fun2(vector<int>*p_vec)
{
	int num;
	ifstream input("Text1.txt");
	while (input >> num)
	{
		p_vec->push_back(num);
	}
	return *p_vec;
}

void fun_print(vector<int> vec)
{
	printitem(vec);
}

//ex12.7
using Sptr = shared_ptr<vector<int>>;

Sptr fun3()
{
	Sptr p_vec = make_shared<vector<int>>() ;
	return p_vec;
}

Sptr fun4(Sptr p_vec)
{
	int num;
	ifstream input("Text1.txt");
	while (input >> num)
	{
		p_vec->push_back(num);
	}
	return p_vec;
}

void fun_print2(Sptr p_vec)
{
	printitem(*p_vec);
}

//12.1.2 直接管理内存
void Fun_Managing_Memory_Directly()
{
	//运算符new分配内存，delete释放new分配的内存
	//使用new动态分配和初始化对象。
	//自由空间分配的内存是无名的，new返回一个指向该对象的指针。
	
	//int *pi = new int;						//*pi未定义
	//string *ps = new string(10, '9');		//值初始化
	//值初始化的内置类型对象有着良好定义的值，而默认初始化的对象的值则是未定义的
	//类中依赖于编译器合成的默认构造函数的内置类型成员，如果它们未在类内被初始化，那么他们的值也是未定义的。
	//当括号中仅有单一初始化器时才可以使用auto

	//动态分配const对象
	//一个动态分配的const对象必须进行初始化
	//const int *pci = new const int(1024);
	//cout << *pci << endl;
	//const string *pcs = new const string("hello world!");
	//cout << *pcs << endl;

	//内存耗尽
	//定位new表达式允许我们向new传递额外的参数。
	//int *p2 = new (nothrow) int;			//如果内存分配失败，new返回一个空指针
	
	//释放动态内存
	//我们通过delete表达式来将动态内存归还给系统。
	//delete表达式接受一个指针，指针我们想要释放的对象。
	//销毁对象，释放内存

	//指针值和delete
	//传递给delete的指针必须指向动态分配的内存，或者是一个空指针。
	//释放一块非new分配的内存，或者将相同的指针值释放多次，其行为是未定义的。
	//int i, *pi1 = &i, *pi2 = nullptr;
	//double *pd = new double(33), *pd2 = pd;
	//cout << *pd2 << endl;	
	//delete pd;
	//cout << *pd2 << endl;  //异常值(不是33)

	//动态对象的生存期直到被释放时为止
	//由内置指针(而不是智能指针)管理的动态内存在被显示释放前一直都会存在
	
	//动态内存的管理非常容易出错：因此要坚持使用智能指针。
	//1.忘记delete内存；
	//2.使用已经释放掉的对象；
	//3.同一块内存释放两次

	//delete之后重置指针值
	//可以在delete只有将nullptr赋予指针，表示指针不指向任何对象
	//在实际系统中，查找指向相同内存的所有指针是异常困难的

	//ex12.6
	//vector<int> *temp_vec = fun1();
	//fun_print(fun2(temp_vec));
	//delete temp_vec;

	//ex12.7
	//Sptr temp_vec = fun3();
	//fun_print2(fun4(temp_vec));
	
	//ex12.8
	//p将转换为bool型，动态分配的内存将无法释放，最终会造成内存泄漏
	
	//ex12.9
	//int *q = new int(42), *r = new int(100);
	//r = q;		//内存泄漏r指向动态内存中的42，保存100的内存还未被释放，需要delete r，否则会造成内存泄漏;
	//cout << *r << endl;		
	//auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
	//r2 = q2;	//安全，最后一个指向动态内存中100的智能指针r2指向42，保存100的内存被自动释放；
	//cout << *r2 << endl;


}

void process(shared_ptr<int> ptr)
{
	cout << "=========" << endl;
	cout << ptr.use_count() << endl;	//输出此时ptr的引用计数
	cout << "process:" << *ptr << endl;
	cout << "=========" << endl;
}

//12.1.3 shared_ptr和new结合使用
void Fun_Using_shared_ptrs_with_new()
{
	//用new返回的指针来初始化智能指针
	//接受指针参数的智能指针构造函数是explicit的，不能将一个内置指针隐式转换为一个智能指针，因此必须使用直接初始化
	//一个返回shared_ptr的函数不能在其返回语句中隐式转换一个普通指针
	//shared_ptr<int> p2(new int(42));	
	//cout << *p2 << endl;
	
	//不要混合使用普通指针和智能指针
	//当将一个shared_ptr绑定到一个普通指针时，我们就将内存的管理责任交给了这个shared_ptr。
	//这样就不应该在使用内置指针来访问shared_ptr指向的内存了。
	//shared_ptr<int> p(new int(42));
	//cout << p.use_count() << endl;			//1
	//process(p);
	//cout << p.use_count() << endl;			//1
	//int i = *p;			



	//int *x(new int(1024));
	////普通指针x显示转换为shared_ptr智能指针，传递给process，引用计数为1
	////process结束，临时对象被销毁，引用计数变为0，所指向的保存了1024的动态内存被释放
	////但是普通指针x仍然指向（已经被释放的）内存，变成一个空悬指针。
	//process(shared_ptr<int>(x));
	//int j = *x;				//使用x的值，行为未定义
	//cout << j << endl;


	//不要使用get初始化另一个智能指针或为智能指针赋值
	
	//shared_ptr<int> p(new int(42));
	//cout << p.use_count() << endl;
	//int *q = p.get();
	//{
	//	shared_ptr<int>(q);
	//}
	//cout << p.use_count() << endl;
	//int foo = *p;				//未定义，p是一个空悬指针
	//cout << foo << endl;

	//其他shared_ptr操作
	//用reset来讲一个新的指针赋予一个shared_ptr
	//reset和uique一起使用，用来控制多个shared_ptr共享的对象
	//shared_ptr<int> p(new int(42));
	//auto p2 = p;
	//cout << *p << "   " << p.use_count() << endl;			// 42   2
	//cout << *p2 << "   " << p.use_count() << endl;			// 42   2    
	//if (!p.unique())
	//{
	//	p.reset(new int(1024));			//p指向一个新的对象	
	//}	
	//cout << *p << "   " << p.use_count() << endl;			// 1024  1
	//cout << *p2 << "   " << p.use_count() << endl;			// 42    1
	
	/*=============================================
	理解变量的销毁与其内存的释放之间的关系：
	内置类型的指针在离开作用域时，本身会被销毁，但是其指向的内存空间什么都不会发生，必须以显式的delete进行释放空间。
	智能指针在离开作用域时，本身也会被销毁，并且计数器减一，当其计数器为0且只有一个智能指针指向该对象时，该对象的内存空间会被释放。
	如若用智能指针的get()函数得到的一个内置指针来初始化一个临时的智能指针，
	一旦该内置指针被释放，指向的内存也会被释放，原来的智能指针就会变成空指针
	=============================================*/


	//ex12.10
	//shared_ptr<int> p(new int(42));
	//process(shared_ptr<int>(p));
	//cout << p.use_count() << endl;			//1


	//ex12.11
	//p变成一个空悬指针，主函数结束，会再一次释放内存，造成双重释放
	//shared_ptr<int> p(new int(42));
	//process(shared_ptr<int>(p.get()));
	
	//ex12.12
	//auto p = new int();
	//auto sp = make_shared<int>();		//默认初始化0
	//process(sp);
	//process(new int());				//参数必须是智能指针
	//process(p);						//同上
	//process(shared_ptr<int>(sp));
	//cout << sp.use_count() << endl;


	//ex12.13
	//auto sp = make_shared<int>();
	//auto p = sp.get();
	//delete p;					//默认初始化为0的动态内存被释放掉，sp变成一个空悬指针，报错

}

struct connection
{
	//表示使用连接所需的信息
	string ip;
	int port;
	connection(string ip_, int port_) :ip(ip_), port(port_) {}
};

struct destination
{
	//表示正在连接什么
	string ip;
	int port;
	destination(string ip_, int port_) :ip(ip_), port(port_) {}
};

connection connect(destination *pDest)
{	//打开连接
	shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	cout << "creating connection...(" << pConn.use_count() << ")" << endl;
	return *pConn;
}

void disconnect(connection pConn) 
{
	//关闭给定连接
	cout << "connect close...(" << pConn.ip << " : " << pConn.port << ")" << endl;
}

void end_connection(connection *pConn)
{
	disconnect(*pConn);
}

void f(destination &d /* 其他参数 */)
{
	//获得一个连接，记住使用完以后要关闭它
	connection c = connect(&d);
	//shared_ptr<T> p(q, d) p接管了内置指针q所指向的对象的所有权，p将使用可调用对象d来代替delete
	
	shared_ptr<connection> p(&c, end_connection);
	//shared_ptr<connection> p(&c, [](connection *a) {return disconnect(*a); });
	cout << "connecting now...(" << p.use_count() << ")" << endl;
	//使用连接
	//退出前忘记调用disconnect，就无法关闭c了
}

//12.1.4 智能指针和异常
void Fun_Smart_Pointers_and_Exceptions()
{
	//使用智能指针，正常处理结束或者发生异常导致函数退出，局部对象都会被销毁，内存会被释放
	//使用内置指针管理内存，在new之后对应的delete之前发生异常，内存不会被释放

	//智能指针和哑类（没有定义析构函数）
	//使用我们自己的释放操作
	//当一个share_ptr被销毁时，它默认地对它管理的指针进行delete操作，
	//我们定义一个函数来代替delete ，这个删除器函数必须能够完成对shared_ptr中保存的指针进行释放的操作


	//智能指针陷阱：使用智能指针坚持的基本规范
	//不使用相同的内置指针值初始化（或reset）多个智能指针
	//不delete get()返回的指针
	//不使用get()初始化或reset另一个智能指针
	//如果使用get()返回的指针，当最后一个对应的智能指针销毁后，指针就无效了
	//如果使用智能指针管理的资源不是new分配的内存，记住传递给它一个删除器

	//ex12.14
	
	//ex12.15
	//destination dest("202.118.176.67", 3316);
	//f(dest);
}

void f_uniqptr(destination &d)
{
	connection c = connect(&d);
	unique_ptr<connection, decltype(end_connection)*> uni_p(&c, end_connection);
	//使用连接
	//当f_uniqptr退出时，即使是由于异常退出，connection会被正确关闭
}

//12.1.5 unique_ptr
void Fun_unique_ptr()
{
	//某个时刻只能有一个unique_ptr指向一个给定对象
	//定义unique_ptr时，需要将其绑定到一个new返回的指针上，初始化必须采用直接初始化
	//unique_ptr不支持普通的拷贝或赋值操作
	//unique_ptr<string> p1(new string("hello"));
	//cout << *p1 << endl;						//
	//unique_ptr<string> p2(p1.release());		//p1放弃对指针的控制权，返回指针，内存所有权转向p2，并将p1置为空
	//cout << *p2 << endl;
	//unique_ptr<string> p3(new string("Trex"));
	//p2.reset(p3.release());						//reset释放了p2原来指向的内存，保存Trex的内存所有权从p3转向了p2
	//cout << *p2 << endl;
	////p3 = nullptr;		//释放p3所指向的对象，将p3置为空
	////release返回的指针通常用来初始化另一个智能指针或给另一个智能指针赋值
	////p2.release();		//p2不会释放内存，而且我们丢失了指针
	//auto p = p2.release();	//一个普通指针保存release返回的指针，程序要负责资源的释放
	//delete p;

	//传递unique_ptr参数和返回unique_ptr
	//我们可以拷贝或赋值一个将要被销毁的unique_ptr

	//向unique_ptr传递删除器
	//我们必须在尖括号中unique_ptr指向的类型之后提供删除器类型
	//在创建或reset一个这种unique_ptr类型的对象时，必须提供一个指定类型的可调用对象（删除器）

	//ex12.16
	//unique_ptr<int> p1(new int(5));
	//unique_ptr<int> p2;
	////p2 = p1;
	////p2.reset(p1.release());
	//cout << *p2 << endl;
	
	//ex12.17
	//int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	//typedef unique_ptr<int> IntP;
	//IntP p0(ix);  //不能用int类型初始化unique_ptr<int>
	//IntP p1(pi);	//可以通过编译，但是超出p1作用范围，p1被销毁，将调用delete释放该对象，但是1024并不是动态内存，会报错
	//IntP p2(pi2);	//可以编译，但是会导致空悬指针（pi2）
	//IntP p3(&ix);	//但是超出p3作用范围,会调用delete销毁一个不是动态内存的对象
	//IntP P4(new int(2048));  //正确
	//IntP p5(p2.get());		//会造成双重释放

	//ex12.18
	//因为unique_ptr“拥有”它所指向的对象，shared_ptr可以与其他智能指针共享对象，不需要释放

}

int main()
{
	//12.1.1 shared_ptr类
	//Fun_The_shared_ptr_Class();
	//12.1.2 直接管理内存
	//Fun_Managing_Memory_Directly();
	//12.1.3 shared_ptr和new结合使用
	//Fun_Using_shared_ptrs_with_new();
	//12.1.4 智能指针和异常
	//Fun_Smart_Pointers_and_Exceptions();
	//12.1.5 unique_ptr
	Fun_unique_ptr();

	return 0;
}
