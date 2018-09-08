#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��09��08�� ������
> Last edited time: 2018��9��08�� ������
> Topic:C++Primer Chapter6.3 �������ͺ�return���
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::initializer_list;



//6.3.1
void swap(int &v1, int &v2)
{
	if (v1 == v2)
	{
		cout << "fun_end" << endl;
		return;
	}
	int temp = v1;
	v1 = v2;
	v2 = temp;
	cout << v1 <<"  swap  "<< v2 << endl;
}

//6.3.1 �޷���ֵ����
void Fun_function_without_return_value()
{
	//int val1 = 5, val2 = 6;
	//swap(val1, val2);
}

//���÷�����ֵ
char &get_value(string &str, string::size_type ix)
{
	return str[ix];
}

//�б��ʼ������ֵ
vector<string> process(string expected,string actual)
{
	if (expected.empty())
		return{};
	else if (expected == actual)
		return{ "functionX", "okay" };
	else
		return{ "functionX", expected, actual };
}

//�ݹ�
int factorial(int val)
{
	if (val > 1)
		return val * factorial(val - 1);
	return 1;
}

//6.3.2 �з���ֵ����
void Fun_function_with_return_value()
{
	//��������һ��ֵ�ķ�ʽ�ͳ�ʼ��һ���������βεķ�ʽ��ȫһ�������ص������ڳ�ʼ�����õ��һ����ʱ��
	//ͬ��������һ������������������ã�������ý����������ö����һ��������

	//��Ҫ���ؾֲ���������û�ָ��
	//�������֮������ռ�õĴ洢�ռ���֮���ͷŵ����ֲ����������ý�ָ������Ч���ڴ�����

	//���÷�����ֵ
	//����һ���������õĺ����õ���ֵ�������������͵õ���ֵ

	//string s("a value");
	//cout << s << endl;
	//get_value(s, 0) = 'A';
	//cout << s << endl;

	//�б��ʼ������ֵ
	//string str1 = "helloworld", str2 = "helloworld";
	//vector<string> str_vec;
	//str_vec = process(str1,str2);
	//for (auto str : str_vec)
	//{
	//	cout << str << endl;
	//}
	
	cout << factorial(5) << endl;
}

int main()
{
	//6.3.1 �޷���ֵ����
	//Fun_function_without_return_value();

	//6.3.2 �޷���ֵ����
	Fun_function_with_return_value();

	return 0;
}