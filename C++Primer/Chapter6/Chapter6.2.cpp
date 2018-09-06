#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��09��06�� ������
> Last edited time: 2018��9��06�� ������
> Topic:C++Primer Chapter6.2 ��������
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;

//ex6.10
void swap(int *num1,int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//6.2.1 ��ֵ����
void Fun_Passing_Arguments_by_Value()
{
	//ָ���β�
	//int n = 0, i = 42;
	//int *p = &n, *q = &i;
	//*p = 42;
	//p = q;
	//cout << n << endl;
	//cout << *p << "   " << *q << endl;


	//ex6.10
	//int i = 42, j = 30;
	//int *p1 = &i, *p2 = &j;
	//swap(p1, p2);
	//cout << "i = " << i << "    j = " << j << endl;
}

//6.2.2 ʹ�����ñ��⿽��
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() > s2.size();
}

//6.2.2 ʹ�������βη��ض�����Ϣ
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto pos = s.size();
	occurs = 0;
	for (decltype(pos) i = 0; i != s.size(); ++i)
	{
		if (s[i] == c)
		{
			if (pos == s.size()) pos = i;
			++occurs;
		}
	}
	return pos+1;
}

//6.2.2 �����ò���
void Fun_Passing_Arguments_by_Reference()
{

	//int n = 0, i = 42;
	//int &r = n;
	//r = 42;				//n = 42
	//r = i;				//n = 42;
	//i = r;				//i = 42;
	//cout << n << "   " << i << endl;
	

	//ʹ�����ñ��⿽��
	//string  str1 = "hello", str2 = "world";
	//cout << std::boolalpha << isShorter(str1, str2) << endl;


	//ʹ�������βη��ض�����Ϣ
	string str1 = "helloworldhelloworldhelloworld";
	char c = 'o';
	string::size_type ctr = 0;
	//string::size_type &num = ctr;
	
	cout << c << " first occors at " << find_char(str1, c, ctr) << "," << endl;
	cout<<"and totally occors "<< ctr << " times" << endl;			//��ֵ˳��

}

int main()
{

	//Fun_Passing_Arguments_by_Value();
	Fun_Passing_Arguments_by_Reference();
	return 0;
}