#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter6.7.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��9��14�� ������
> Last edited time: 2018��9��15�� ������
> Topic:C++Primer Chapter6.6 ����ָ��
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

bool lengthCompare(const string &, const string &);

//void ff(int*);
//void ff(unsigned int);
//void (*pf1)(unsigned int) = ff;

//�������β��Ǻ������ͣ������Զ�ת����ָ������ָ��
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &)); 
//�ȼ���������ʽ�ؽ��βζ����ָ������ָ��
void useBigger(const string &s1, const string &s2, bool(*pf)(const string &, const string &));


//Func��Func2�Ǻ�������
typedef bool Func(const string&, const string &);
typedef decltype(lengthCompare) Func2;
//FuncP��FuncP2��ָ������ָ��
typedef bool(*FuncP)(const string&,const string&);
typedef decltype(lengthCompare) *FuncP2;

void useBigger(const string &s1,const string &s2,Func);//�������Զ���Func��ʾ�ĺ�������ת����ָ��
void useBigger(const string &s1, const string &s2, FuncP2);

//ʹ�����ͱ���������һ�����غ���ָ��ĺ���
using F = int(int*, int*);
using PF = int(*)(int*, int);

int(*f1(int)) (int*, int);  
auto f1(int)->int(*)(int * ,int);

PF f1(int);
F* f2(int);
//F f3(int);   //������ʹ�÷��غ����ĺ���


//ex6.54
int func(int a, int b)
{
	cout << "hello" << endl;
	return a + b;
}

using pFunc1 = decltype(func);			//����
typedef decltype(func) *pFunc2;			//����ָ��
using pFunc3 = int(*)(int a, int b);	//����ָ��
using pFunc4 = int(int a, int b);		//����
typedef int(*pFunc5)(int a, int b);		//����ָ��
using pFunc6 = decltype(func);			//����

//ex6.55
int add(int a, int b)
{
	cout << "add:" << endl;
	return a + b;
}

int subtract(int a, int b)
{
	cout << "subtract:" << endl;
	return a - b;
}
int multiply(int a, int b)
{
	cout << "multiply:" << endl;
	return a * b;
}
int divide(int a, int b)
{
	cout << "divide:" << endl;
	return (b == 0) ? 0 : a / b;
}


//����ָ��
void Fun_Pointers_to_Functions()
{
	//Ҫ����һ������ָ������ָ�룬ֻ��Ҫ��ָ���滻����������

	//ʹ�ú���ָ��
	//���Ѻ�������Ϊһ��ֵʹ��ʱ���ú����Զ���ת����ָ��
	//����ֱ��ʹ��ָ������ָ����øú�����������ǰ������ָ��

	//���غ�����ָ��
	//ʹ�����غ���ʱ�������ı��������ؽ綨����Ӧ��ѡ���ĸ�����
	//������ͨ��ָ�����;���ѡ���ĸ�������ָ�����ͱ��������غ����е�ĳһ����ȷƥ��

	//����ָ���β�
	//����ֱ�ӰѺ�����Ϊʵ��ʹ�ã���ʱ�����Զ�ת����ָ��

	//����ָ������ָ��

	//��auto��decltype���ں���ָ������

	//ex6.54
	//vector<int(*)(int, int)> fun_vec;
	//fun_vec.push_back(func);

	//vector<pFunc6*>fun_vec2;
	//fun_vec2.push_back(func);

	//vector<pFunc5> fun_vec3;
	//fun_vec3.push_back(func);

	//int sum = fun_vec2[0](5, 6);
	//cout << sum << endl;


	//ex6.55-ex6.56
	vector<int(*)(int, int)> fun_vec;
	fun_vec.push_back(add);
	fun_vec.push_back(subtract);
	fun_vec.push_back(multiply);
	fun_vec.push_back(divide);
	cout << fun_vec[0](5, 6) << endl;
	cout << fun_vec[1](8, 6) << endl;
	cout << fun_vec[2](5, 6) << endl;
	cout << fun_vec[3](30, 6) << endl;
}



int main()
{
	Fun_Pointers_to_Functions();
	return 0;
}