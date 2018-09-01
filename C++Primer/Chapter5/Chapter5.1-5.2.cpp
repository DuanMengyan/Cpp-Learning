#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter5.1-5.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年09月01日 星期六
> Last edited time: 2018年9月01日 星期六
> Topic:C++Primer Chapter5.1-5.2  
************************************************************************/

#include <iostream>
#include <cstddef>
#include <cctype>
#include <string>
#include <vector>
#include <string.h>

using namespace std;


//5.1简单语句
void Fun_Simple_Statements()
{
	//ex5.3
	//int sum = 0, val = 1;
	//while (val <= 10)
	//	sum += val,++val;
	//cout << sum << endl;
}

//5.2语句作用域
void Fun_Statement_Scope()
{
	//ex5.4
	//string s = "hello";
	//string::iterator iter = s.begin();
	//while (iter != s.end());
	//bool status = true;
	//while (status = find(word)){ }
	//if (!status){	}

}


int main()
{
	//Fun_Simple_Statements();
	//Fun_Statement_Scope();
	return 0;
}