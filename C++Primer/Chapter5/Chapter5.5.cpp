#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter5.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年09月02日 星期日
> Last edited time: 2018年9月03日 星期一
> Topic:C++Primer Chapter5.5 跳转语句
************************************************************************/

#include <iostream>
#include <cstddef>
#include <cctype>
#include <string>
#include <vector>
#include <string.h>
#include <stdexcept>

using namespace std;


//5.5跳转语句
void Fun_Jump_Statements()
{
	//5.5.1 break语句
	//ex5.20
	//string prestr, curstr;
	//if (cin >> curstr && !curstr.empty() && !cin.eof())
	//{
	//	prestr = curstr;
	//	while ( cin >> curstr && !curstr.empty())
	//	{
	//		if (prestr == curstr)
	//		{
	//			cout << curstr << endl;
	//			break;
	//		}			
	//		else
	//			prestr = curstr;
	//	}
	//}

	//string read, tmp;
	//while (cin >> read)
	//	if (read == tmp) break; else tmp = read;

	//if (cin.eof())  cout << "no word was repeated." << endl;
	//else            cout << read << " occurs twice in succession." << endl;

	//5.5.2 continue语句
	//ex5.21
	//string prestr, curstr;
	//if (cin >> curstr && !curstr.empty())
	//{
	//	prestr = curstr;
	//	while ( cin >> curstr && !curstr.empty())
	//	{
	//		if (curstr[0] < 65 || curstr[0] > 90) continue;
	//		
	//		if (prestr == curstr)
	//		{
	//			cout << curstr << endl;
	//			break;
	//		}			
	//		else
	//			prestr = curstr;
	//	}
	//}

	//5.5.3 goto语句
	//ex5.22
	//do
	//{
	//	int sz = get_size();
	//} while (sx > 0);

	//for (int sz = get_size(); sz <= 0;sz = get_size())



}


//5.6 try语句块和异常处理
void Fun_try_Blocks_and_Exception_Handling()
{
	//throw表达式
	//unsigned num1, num2;
	//cin >> num1 >> num2;
	//if (num1 != num2)
	//	throw runtime_error("Data must refer to same ISBN");
	//cout << num1 << "   " << num2 << endl;


	//try 语句块
	//unsigned num1, num2;
	//while (cin >> num1 >> num2)
	//{
	//	try
	//	{
	//		if (num1 != num2)
	//			throw runtime_error("input incorrectly!");
	//		else
	//		{
	//			throw logic_error("input correctly!");
	//			cout << num1 + num2 << endl;
	//		}
	//	}
	//	catch (runtime_error err)
	//	{
	//		cout << err.what()
	//			<< "\nTry Again? Entry y or n" << endl;
	//		char c;
	//		cin >> c;
	//		if (!cin || c == 'n')
	//			break;
	//	}
	//	catch (logic_error err2)
	//	{
	//		cout << err2.what()
	//			<< "\nTry Again? Entry y or n" << endl;
	//		char c;
	//		cin >> c;
	//		if (!cin || c == 'n')
	//			break;
	//	}
	//}

	//ex5.23-5.25
	unsigned num1, num2;
	while (cin >> num1 >> num2)
	{
		try
		{
			if (num2 == 0)
			{
				throw runtime_error("divisor is zero");
			}
			else
			{
				cout << "result:" << num1 / num2 << endl;
				break;
			}
		}
		catch (runtime_error err)
		{
			cout << err.what() << endl
				<< "Try Again? Entry y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
		}
	}



	
}




int main()
{
	//Fun_Jump_Statements();
	Fun_try_Blocks_and_Exception_Handling();
	return 0;
}