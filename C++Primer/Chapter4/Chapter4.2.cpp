#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter4.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年08月27日 星期一
> Last edited time: 2018年8月27日 星期一
> Topic:C++Primer Chapter4.1+4.2  算术运算符
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

void Fun_fundamentals()
{
	//求值顺序
	//int i = 0;
	//cout << i << "  " << ++i << endl;   //结果：1   1，先自加，后输出
	//cout << i << "  " << i++ << endl;	//结果：1   0，输出0以后自加，前一个结果为1

}

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


int main()
{
	//Fun_fundamentals();
	Fun_Arithmetic_Operators();
	return 0;
}