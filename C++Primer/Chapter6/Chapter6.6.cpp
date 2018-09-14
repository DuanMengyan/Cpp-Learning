#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.6.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��9��14�� ������
> Last edited time: 2018��9��14�� ������
> Topic:C++Primer Chapter6.6 ����ƥ��
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::initializer_list;

//ex6.51
void f()
{
	cout << "f():null" << endl;
}
void f(int val)
{
	cout << "f(int): f(" << val << ")" << endl;
}
void f(int val1, int val2)
{
	cout << "f(int,int): f(" << val1 <<","<< val2 << ")" << endl;
}
void f(double val1, double val2= 3.14)
{
	cout << "f(double,double = 3.14): f(" << val1 << "," << val2 << ")" << endl;
}

// ����ƥ��
void Fun_function_matching()
{
	//��ѡ����
	//�뱻���õĺ���ͬ��
	//�������ڵ��õ�ɼ�

	//���к������ܱ�����ʵ�ε��õĺ���

	//���ж���βεĺ���ƥ��
	//�������ڿ��к��������μ��ÿ��ʵ�Σ���Ѱ�����ƥ��
	//������������ʵ��֮��û���Ǹ�������ӱ��������õ����Ǵ���ģ���������Ե��õ���Ϣ


	//ex6.50
	//(a)���ö�����
	//(b)f(int)
	//(c)f(int,int)
	//(d)f(double,double = 3.14)
	//

	//ex6.51
	//f(2.56, 42);			//���ö�����
	f(42);
	f(42, 0);
	f(2.56, 3.14);
}

//6.6.1 ʵ������ת��
void Fun_Argument_Type_Conversions()
{
	//������������ת���ļ���һ��

	//����ƥ���constʵ��

	//ex6.52
	//void mainp(int, int);
	//double dobj;
	//(a)����������char����Ϊint
	//(b)double����תΪint

	//ex6.53
	//(c)���Ϸ����βζ���char*
}


int main()
{
	Fun_function_matching();
	return 0;
}