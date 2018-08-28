#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter4.1————4.7.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年08月27日 星期一
> Last edited time: 2018年8月28日 星期二
> Topic:C++Primer Chapter4.1————4.7
************************************************************************/

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;

//4.1基础
void Fun_fundamentals()
{
	//求值顺序
	//int i = 0;
	//cout << i << "  " << ++i << endl;   //结果：1   1，先自加，后输出
	//cout << i << "  " << i++ << endl;	//结果：1   0，输出0以后自加，前一个结果为1

}

//4.2算术运算符
void Fun_Arithmetic_Operators()
{
	//ex4.4
	//int num = ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2);
	//num = 16 + 75 + 0;
	//cout << num << endl;

	//%取余运算符，负责计算两个整数相处所得的余数，参与取余运算的运算对象必须是整数类型

	//C++11新标准规定商一律向0取整（即直接切除小数部分）

	//cout << 21 % 6 << endl;				//3
	//cout << 21 % 7 << endl;				//0
	//cout << -21 % -8 << endl;			//-5
	//cout << 21 % -5 << endl;			//1
	//cout << -21 % 5 << endl;			//-1
	//cout << "================" << endl;
	//cout << 21 / 6 << endl;				//3
	//cout << 21 / 7 << endl;				//3
	//cout << -21 / -8 << endl;			//2
	//cout << 21 / -5 << endl;			//-4
	//cout << -21 / 5 << endl;			//-4

	////ex4.4
	//cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;				//91


	//ex4.7
	//short svalue = 32767; 
	//++svalue;
	//cout << svalue << endl;			// -32768
	//unsigned uivalue = 0;
	//--uivalue;
	//cout << uivalue << endl;		// 4294967295
	//unsigned short usvalue = 65535; 
	//++usvalue;
	//cout << usvalue << endl;		// 0
}

//4.3逻辑和关系运算符
void Fun_Logical_and_Relational_Operators()
{
	//ex4.9
	//const char *cp = "Hello World";
	//if (cp &&*cp)

	//ex4.10
	//int num;
	//while (cin >> num&&num != 42)
	//{
	//	cout << num << "  ";
	//}

	//ex4.11
	//a > b && b > c && c > d

	//ex4.12
	//int i = 0, j = 2, k = 3;
	//if (i != (j < k))
	//{
	//	cout << i << endl;
	//}
}

//4.4赋值运算符
void Fun_Assignment_Operators()
{
	//ex4.13
	//int i; double d;
	//d = i = 3.5;    //i = 3; d = 3
	//cout << "i:"<< i << "   " << "d:" <<d << endl;
	//i = d = 3.5;	//i = 3; d = 3.5
	//cout << "i:" << i << "   " << "d:" << d << endl;


	//ex4.16
	//if ((p = getptr()) !=0 )
	//if (i == 1024)

}

//4.5递增合递减运算符
void Fun_Increment_and_Decrement_Operators()
{	
	//ex4.19
	//int ival = -1;
	//if (ival++ && ival)   //if( -1 && 0)
	//{
	//	cout << "===========" << endl;
	//}
}

//ex4.6成员访问运算符
void Fun_The_Member_Access_Operators()
{
	//string s1 = "a string ", *p = &s1;
	//auto n = s1.size();
	//n = (*p).size();			//解引用运算符优先级低于点运算符
	//cout << n << endl;
	//n = p->size();
	//cout << n << endl;

	//箭头运算符作用于一个指针类型的运算对象，结果是一个左值。
	//点运算符分两种情况：
	//(1)如果成员所属的对象是左值，那么结果是左值；
	//(2)如果成员所属的对象是右值，那么结果是右值
	
	//ex4.20
	//vector<string> vec = {"","hahah","world"};
	//vector<string>::iterator iter = vec.begin();	
	//cout << "(a):" << *iter++ << endl;				//输出hello
	//cout << "(b)" << (*iter)++ << endl;				//错误
	//cout << "(c)" << *iter.empty() << endl;			//错误
	//cout << "(d)" << iter->empty() << endl;			//判断当前字符串是否为空
	//cout << "(e)" << ++*iter << endl;;				//错误
	//while (iter != vec.end())
	//{
	//	cout << "(f)" << iter++->empty() << endl;			//箭头运算符优先级高于自增运算符
	//}
	

}

//ex4.7条件运算符
void Fun_The_Conditional_Operator()
{
	//int grade = 100;
	//string finalgrade = (grade < 60) ? "fail" : "pass";
	//cout << finalgrade << endl;

	//条件运算符嵌套
	//string finalgrade = (grade > 90) ? "High pass" : ((grade > 60) ? "pass" : "fail");
	//cout << finalgrade << endl;


	//条件运算符优先级非常低
	//string str = cout << (grade < 60) ? "fail" : "pass";
	//cout << endl<<str<<endl;

	//ex4.21
	//vector<int> vec{ 1, 2, 3, 4, 5, 6 };
	//for (auto &i : vec)
	//{
	//	(i & 0x1) ? (i) : (i = 2 * i);			//判断i是否为偶数
	//}
	//for (auto i : vec)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;

	//ex4.22
	//int grade = 80;
	//string finalgrade = (grade > 90) ? "High pass" : ((grade < 60) ?  "fail":(grade<75)?"low pass":"pass");
	//cout << finalgrade << endl;

	//if (grade > 90)			cout << "High pass";
	//else if (grade < 60)	cout << "fail";
	//else if (grade < 75)	cout << "low pass";
	//else					cout << "pass";

	//ex4.23
	string s = "word";
	string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
	cout << p1 << endl;

	//ex4.24

}

int main()
{
	//Fun_fundamentals();
	//Fun_Arithmetic_Operators();
	//Fun_Logical_and_Relational_Operators();
	//Fun_Assignment_Operators();
	//Fun_Increment_and_Decrement_Operators();
	//Fun_The_Member_Access_Operators();
	Fun_The_Conditional_Operator();
	return 0;
}