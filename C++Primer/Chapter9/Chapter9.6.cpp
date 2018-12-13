#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.6.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��12��12�� ������
> Last edited time: 2018��12��12�� ������
> Topic:C++Primer Chapter9.6 ����������
************************************************************************/

#include "header_include.h"

using namespace std;

// 9.6 ����������
void Fun_Container_Adaptors()
{
	//����һ��������

	//deque<int> dqe;
	//stack<int> stk(dqe); //��dqe����Ԫ�ص�stk
	//��vector��ʵ�ֵĿ�ջ
	//stack<string, vector<string>> str_stk;
	//str_stk2��vector��ʵ�֣���ʼ��ʱ����svec�Ŀ���
	//vector<string> svec = { "hello", "world" };
	//stack<string, vector<string>> str_stk2<svec>;     //����
	
	//ջ������
	//ջĬ�ϻ���dequeʵ�֣�Ҳ������list��vector֮��ʵ��
	//ֻ����ʹ��������������������ʹ�õײ��������͵Ĳ���
	//stack<int> intStack;//��ջ
	//for (size_t ix = 0; ix < 10; ++ix)
	//{
	//	intStack.push(ix);
	//}
	//while (!intStack.empty())
	//{
	//	int value = intStack.top();
	//	intStack.pop();
	//}

	//����������
	
	
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
	// 9.6 ����������
	Fun_Container_Adaptors();
	return 0;
}