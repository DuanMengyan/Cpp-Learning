#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter7.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年10月11日 星期四
> Last edited time: 2018年10月12日 星期五
> Topic:C++Primer Chapter7.4 类的作用域 
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

using namespace std;

//7.4类的作用域
void Fun_Class_Scope()
{
	//ex7.33
	//见Chapter7.3
}

//用于类成员声明的名字查找
typedef double Money;
string bal;
class Accont
{
public:
	Money balance(){ return bal; }  
	//return bal在整个类可见之后才执行，bal的类型是Money;
private:
	Money bal;
};


//成员定义中的普通块作用域的名字查找
//int height ;
//class Screen
//{
//public:
//	typedef std::string::size_type pos;
//	void dumy_fcn(pos height)
//	{	
//		//显式地通过作用域运算符来请求访问外层作用域中的名字
//		//cursor = width*::height;    
//		//cursor = width * this->height;
//
//		cursor = width*Screen::height;
//		cout << "height:" << height << endl;
//	}
//private:
//	pos cursor = 0;
//	pos height = 0, width = 0;
//
//};

//在文件中名字的出现处对其进行解析
//int height;
//
//class Screen
//{
//public:
//	typedef std::string::size_type pos;
//	void setHeight(pos);
//	pos height = 0;
//};
//
//Screen::pos verify(Screen::pos);
//
//void Screen::setHeight(pos var)
//{
//	height = verify(var);
//}

//ex7.35
typedef string Type;
Type initVal();
class Exercise
{
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal()
	{
		return 5.0;
	}
private:
	Type val;
};

Exercise::Type Exercise::setVal(Type parm)
{
	val = parm + initVal();
	return val;
}



//7.4.1 名字查找与类的作用域
void Fun_Name_Lookup_and_Class_Scope()
{
	//编译器处理完类中的全部声明后才会处理成员函数的定义

	//用于类成员声明的名字查找

	//类型名要特殊处理
	//类型名的定义通常出现在类的开始处，这样确保所有使用该类型的成员都出现在类型名的定义之后

	//成员定义中的普通块作用域的名字查找

	//类作用域之后，在外围的作用域中查找

	//在文件中名字的出现处对其进行解析

	//ex7.34


	//ex7.35
	Exercise ex1;
	cout << ex1.setVal(5.0) << endl;
}



//
//int main()
//{
//	//7.4类的作用域
//	//Fun_Class_Scope();
//	//7.4.1 名字查找与类的作用域
//	Fun_Name_Lookup_and_Class_Scope();
//	return 0;
//}