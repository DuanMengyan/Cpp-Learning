#pragma once
#pragma execution_character_set("utf-8")
/*************************************************************************
> File Name: Chapter7.6.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年10月24日 星期三
> Last edited time: 2018年10月25日 星期四
> Topic:C++Primer Chapter7.6 类的静态成员
************************************************************************/

#include "header_include.h"

using namespace std;

class Account
{
public:
	//成员函数不用通过作用域运算符就能使用静态成员
	void claculate(){ amount += amount*interestRate; }
	static double rate(){ return interestRate; }
	static void rate(double);		//静态成员函数不包含this指针
									//static关键字只出现在类内部的声明语句中

private:
	string owner;
	double amount;
	static constexpr double todayRate = 42.42;	//const用于提供整数类型类内初始值，其他字面值常量用constexpr
	static double interestRate;		//该静态成员被所有Account对象共享
	static double initRate(){ return todayRate; };
	
	//static constexpr int period = 30;		//period是常量表达式
	//double daily_tbl[period];
};

Account::Account()
{
}

Account:: ~Account()
{
}

//在类的外部定义静态成员函数
void Account::rate(double newRate)
{
	interestRate = newRate;
}

//定义并初始化静态数据成员，从类名开始，该语句剩余部分就都位于类的作用域内了
//确保对象只定义一次，把静态数据成员的定义和其他非内联函数的定义放在同一个文件中
double Account::interestRate = initRate();
//静态成员类内初始化，通常情况下也应在外部定义一下该成员
//constexpr int Account::period;


//ex7.58
class Example
{
public:
	static constexpr double rate = 6.5;
	static const int vecSize = 20;
	//类内初始化，必须是字面值静态常量，vector string都不是字面值静态常量
	static vector<double> vec;
};

//类内初始化，类的外部定义
constexpr double Example::rate;

vector<double> Example::vec(Example::vecSize);



//7.6 类的静态成员
void Fun_static_Class_Members()
{
	//使用类的静态成员
	double r = Account::rate();		//使用作用域运算符直接访问静态成员
	//Account ac1;
	//Account *ac2 = &ac1;
	//r = ac1.rate();					
	//r = ac2->rate();

	//定义静态成员
	//一般来说，我们不能在类的内部初始化静态成员
	//相反，必须在类的外部定义和初始化每个静态成员，一个静态数据成员只能定义一次。

	//静态成员的类内初始化
	//要求必须是字面值常量才能在类内初始化



	//静态成员能用于某些场景，而普通成员不能
	//1.静态数据成员可以是不完全类型；数据成员必须是完全类型
	//2.我们可以使用静态成员作为默认实参；非静态数据成员不能作为默认实参

	//ex7.56
	//静态数据成员是与类关联的类成员，不属于任何一个类对象；
	
	//每个类对象不需要存储一个完全相同的公共数据；
	//如果该静态数据成员发生了变化，每个类都可以使用新值

	//区别：
	//1.静态数据成员不能使用构造函数进行初始化
	//2.静态数据成员可以是不完全类型，普通数据成员不行；
	//3.静态数据成员可以作为默认实参；普通数据成员不行；

	//ex7.57
	
	//ex7.58	
}

int main()
{

	return 0;
}