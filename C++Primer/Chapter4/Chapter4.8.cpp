#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter4.8.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年08月30日 星期四
> Last edited time: 2018年8月31日 星期五
> Topic:C++Primer Chapter4.8 位运算符
************************************************************************/

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;

//位运算符
void Fun_The_Bitwise_Operators()
{
	//字面值常量，我们可以将整型字面值写作十进制数、八进制数、十六进制数的形式。
	//以0开头的证书代表八进制数
	//以0x或0X开头的代表十六进制数

	//移位运算符
	//unsigned char bits = 030;				//八进制0030，二进制为：00011000	
	//cout << (bits << 3) << endl;			//左移3位，11000000，十进制为：192

	//unsigned char bits = 30;				//十进制30，二进制为：11110
	//cout << (bits << 3) << endl;			//左移3位，11110000，十进制为：240
	////十进制数，左移n位，扩大2^n倍
	//unsigned result = bits << 5;
	//cout << result << endl;

	//位求反运算符
	//unsigned char bits = 0001;		//八进制；10010111
	//cout << ~bits << endl;

	//位与，位或，位异或运算符
	//unsigned char b1 = 0145;
	//unsigned char b2 = 0257;
	//int result1 = b1 & b2;
	//int result2 = b1 | b2;
	//int result3 = b1 ^ b2;
	//cout << result1 << endl;
	//cout << result2 << endl;
	//cout << result3 << endl;

	//00000000 00000000 00000000 00000000				// quizl = 0	
	//00001000 00000000 00000000 00000000				// (1UL << 27) 134217728   
	//00001000 00000000 00000000 00000000				// quizl | 1UL << 27;  134217728   学生27通过了测验
	//11110111 11111111 11111111 11111111				// ~(1UL << 27) 4160749567
	//00000000 00000000 00000000 00000000				// quizl & ~(1UL << 27);  0    学生27没有通过测验

	//使用位运算符
	//unsigned long quizl = 0;				//二进制：00000000 00000000 00000000 00000000；十进制0
	////quizl |= 1UL << 27;
	//quizl = quizl | 1UL << 27;				//学生27通过了测验
	//cout << (1UL << 27) << endl;			//134217728
	//cout << quizl << endl;					//134217728
	//bool status = quizl & (1UL << 27);		//1
	//cout << status << endl;
	
	
	
	//quizl = 0;
	//quizl = quizl & ~(1UL << 27);			//学生27没有通过测验
	//cout << ~(1UL << 27) << endl;			//4160749567	
	//cout << quizl << endl;				//0
	//bool status = quizl & (1UL << 27);
	//cout << status << endl;				//


	//移位运算符(IO运算符)满足左结合律
	//比算数运算符优先级底，比关系运算符优先级高
	//cout << 10 + 42 << endl;
	//cout << (10 < 42) << endl;

	//ex4.25
	//'q':		00000000 00000000 00000000 01110001
	//char类型的运算对象首先提升成int类型，高位添加0
	//~'q':		11111111 11111111 11111111 10001110
	//~'q'<< 6:	11111111 11111111 11100011 10000000		-7296
	
	//ex4.26
	//至少需要32位，某些机器上 unsigned int 可能不是32位

	//ex4.27
	//ul1: 00000000 00000000 00000000 00000011			3
	//ul2: 00000000 00000000 00000000 00000111			7	
	//(a): 00000000 00000000 00000000 00000011			3
	//(b): 00000000 00000000 00000000 00000111			7
	unsigned long ul1 = 3, ul2 = 7;
	cout << (ul1 & ul2) << endl;					//3
	cout << (ul1 | ul2) << endl;					//7
	cout << (ul1 && ul2) << endl;					//1
	cout << (ul1 || ul2) << endl;					//1

}

int main()
{

	Fun_The_Bitwise_Operators();
	return 0;
}


