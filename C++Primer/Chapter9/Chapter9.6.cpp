#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.6.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年12月12日 星期三
> Last edited time: 2018年12月12日 星期三
> Topic:C++Primer Chapter9.6 容器适配器
************************************************************************/

#include "header_include.h"

using namespace std;

// 9.6 容器适配器
void Fun_Container_Adaptors()
{
	//定义一个适配器

	//deque<int> dqe;
	//stack<int> stk(dqe); //从dqe拷贝元素到stk
	//在vector上实现的空栈
	//stack<string, vector<string>> str_stk;
	//str_stk2在vector上实现，初始化时保存svec的拷贝
	//vector<string> svec = { "hello", "world" };
	//stack<string, vector<string>> str_stk2<svec>;     //报错
	
	//栈适配器
	//栈默认基于deque实现，也可以在list或vector之上实现
	//只可以使用适配器操作，而不能使用底层容器类型的操作
	//stack<int> intStack;//空栈
	//for (size_t ix = 0; ix < 10; ++ix)
	//{
	//	intStack.push(ix);
	//}
	//while (!intStack.empty())
	//{
	//	int value = intStack.top();
	//	intStack.pop();
	//}

	//队列适配器
	
	
	//ex9.52
	
	string str = "This is (abcd)";
	bool flag = false;
	stack<char> cstack;
	for (auto &c : str)
	{
		if (c == '(') 
		{
			flag = true;
			continue;
		}
		else if (c == ')')
		{
			flag = false;
		}

		if (flag) cstack.push(c);
	}
	string str_sub;
	while (!cstack.empty())
	{
		str_sub += cstack.top();
		cstack.pop();
	}
	str.replace(str.find("(") + 1, str_sub.size(), str_sub);
	cout << str << endl;

}




int main()
{
	// 9.6 容器适配器
	Fun_Container_Adaptors();
	return 0;
}