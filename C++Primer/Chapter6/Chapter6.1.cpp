#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��09��03�� ����һ
> Last edited time: 2018��9��05�� ������
> Topic:C++Primer Chapter6.1 ��������
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include "Chapter6.1.h"

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;

//ex6.3
int fact(int i)
{
	if (i<0)
	{
		runtime_error err("Input cannot be a negative number");
		cout << err.what() << endl;
	}
	return i > 1 ? i * fact(i - 1) : 1;
}

//ex6.4
void myfact()
{
	for (int val, num; cout << "Enter val:" << endl, cin >> val;)
	{
		if (val < 0)
		{
			runtime_error err("Val cannot bo a negative number!");
			cout << err.what() << endl;
		}
		else
		{
			num = val;
			unsigned long long result = 1;
			while (num > 1)
				result *= num--;
			cout << val << "! = " << result << endl;
		}
	}

}

//ex6.5
void myabs(int val)
{
	cout << (val < 0 ? -val : val) << endl;
}

//Chapter6.1.1 �ֲ���̬����
size_t const_calls()
{
	static size_t ctr = 0;  //�ֲ���̬���󣬷��ظú��������ô���
	return ++ctr;
}

//ex6.7
size_t calls_count()
{
	static size_t num = 0;
	return num++;
}

//Chapter6.1 ��������
void Fun_function_basics()
{
	//ex6.3
	//std::boolalpha ��������н�bool����Ϊ����true, false.
	//std::cout << std::boolalpha << (120 == fact(-1)) << std::endl;
	
	//ex6.4
	//myfact();

	//ex6.5
	//myabs(-5);

	//Chapter6.1.1 �ֲ�����Local Objects��
	//for (size_t i = 0; i != 10; ++i)
	//{
	//	cout << const_calls() << endl;
	//}

	//ex6.7
	//for (int i = 0; i < 5; ++i)
	//{
	//	cout << i + 1 << "  " << calls_count() << endl;
	//}

	//Chapter6.1.2 ����������Function Declarations��
	//Chapter6.1.3 ����ʽ���루Separate Compilation��

	cout << "hahah" << endl;


}




int main()
{
	Fun_function_basics();
	return 0;
}

