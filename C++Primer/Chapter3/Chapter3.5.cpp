#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter3.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��08��21�� ���ڶ�
> Last edited time: 2018��8��24�� ������
> Topic:C++Primer Chapter3.5 ����
************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <cctype>
//#include <iterator>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::vector;
using std::string;
using std::begin;
using std::end;

//3.5.1����ͳ�ʼ������
void Fun_arrays_define_initial()
{
	 
}

//3.5.2��������Ԫ��
void Fun_arrays_element()
{
	//unsigned scores[11] = {};
	//unsigned grade;
	//while (cin >> grade)
	//{
	//	if (grade <= 100)
	//		++scores[grade / 10];
	//}
	//for (auto i : scores)
	//	cout << i << "   ";
	//cout << endl;


	//ex3.31
	//unsigned array_a[10];
	//for (unsigned i = 0; i < 10; i++)
	//{
	//	array_a[i] = i;
	//	cout << array_a[i]<<"   ";
	//}
	//cout << endl;

	//ex3.32
	//unsigned array_b[10];
	//for (unsigned i : a)
	//{
	//	array_b[i] = array_a[i];
	//	cout << array_b[i] << "   ";
	//}
	//cout << endl;

	//vector<unsigned> vec_a(10, 0);
	//unsigned i = 0;
	//for (auto &a : vec_a)
	//{
	//	a = i++;
	//	cout << a << "   ";
	//}
	//cout << endl;
	//vector<unsigned> vec_b = vec_a;
	//for (auto b : vec_b)
	//{
	//	cout << b << "   ";
	//}
	//cout << endl;
}

//3.5.3ָ�������
void Fun_pointers_arrays()
{
	//string nums[] = {"one","two","three"};
	//string *p = nums;
	//cout << *p << endl;

	//��׼�⺯��begin��end
	//int ia[] = {0,1,2,3,4,5,6,7,8,9};
	//int *beg = begin(ia);		//������std::begin
	//int *last = end(ia);		//������std::end

	//ex3.34
	//p1��p2ָ��ͬһ�������Ԫ��
	//p1 += p2 - p1;   //������佫p1�ƶ�����p2һ����λ��
	//ֻҪp1��p2�Ϸ�����ô���������ǺϷ���Ч��

	//ex3.35
	//int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int *beg = begin(arr);
	//int *last = end(arr);
	//for (; beg != last; *beg = 0, beg++);
	//for (int i : arr)
	//{
	//	cout << i << "\t";
	//}


	//ex3.36
	//int arr1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int arr2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int *beg1 = begin(arr1), *last1 = end(arr1);
	//int *beg2 = begin(arr2), *last2 = end(arr2);

	//for (; beg1 != last1 && beg2 != last2 && *beg1 == *beg2; beg1++, beg2++);
	//if (beg1 == last1 && beg2 == last2)
	//	cout << "yes" << endl;
	//else
	//	cout << "no" << endl;

	//cout << "===================" << endl;


	//vector<int> vec1 = { 0, 1, 2, 3 };
	//vector<int> vec2 = { 0, 1, 2, 3 };
	//if (vec1 == vec2)
	//	cout << "yes" << endl;
	//else
	//	cout << "no" << endl;

}

//3.5.4 C����ַ���
void Fun_C_string()
{	
	
	//C�����ַ����Ǵ���������еģ�������Կ��ַ�����\0����������
	//���㳤�ȡ��Ƚϡ����ӡ���ֵ�Ȳ�����Ҫ���ö����ڱ�׼���еĺ������
	//��C++��string����ʹ����ͨ�Ĺ�ϵ��������������������в���

	//ex3.37
	//const char ca[] = { 'h', 'e', 'l', 'l', 'o','\0' };
	//const char *cp = ca;
	//while (*cp) {
	//	cout << *cp << endl;
	//	++cp;
	//}


	//ex3.39 �Ƚ��ַ���
	//string str1 = "helloworld";
	//string str2 = "helloworld";
	//if (str1 == str2)
	//	cout << "equall" << endl;
	//else if (str1>str2)
	//	cout << "str1 is bigger" << endl;
	//else
	//	cout << "str2 is bigger" << endl;

	//const char cstr1[] = "helloworld";
	//const char cstr2[] = {'h','e','l','l','o','\0'};

	//cout << strlen(cstr1) << "   " << strlen(cstr2) << endl;

	//if (strcmp(cstr1, cstr2) == 0)
	//	cout << "equall" << endl;
	//else if (strcmp(cstr1, cstr2) > 0)
	//	cout << "cstr1 is bigger" << endl;
	//else
	//	cout << "cstr2 is bigger" << endl;

	//ex3.40
	//const char cstr1[] = "hello";
	//const char cstr2[] = "world";
	//char cstr3[12];
	//strcpy(cstr3, cstr1);
	//strcat(cstr3, " ");
	//strcat(cstr3,cstr2);
	//for (char c : cstr3)
	//{
	//	cout << c;
	//}
	//cout << endl;


}

//3.5.5��ɴ���Ľӿ�
void Fun_interface_oldcode()
{
	//ex3.41
	int int_arr[] = { 0, 1, 2, 3, 4, 5 };
	vector<int> ivec(begin(int_arr), end(int_arr));
	//for (auto n : ivec)
	//{
	//	cout << n << "  ";
	//}
	//cout << "===================" <<endl;

	//ex3.42
	int int_arr2[6];
	auto begin = ivec.begin();
	for (int &num : int_arr2)
	{
		cout << num << "  ";
	}
	cout << endl << "======================================" << endl;
	for (auto &num:int_arr2)			//Ҫ�������е�Ԫ�ظ�ֵ�����ı�����Ԫ�ص�ֵ��������Ҫ����Ϊ���ã�	
	{									//���ΰ󶨵���Ԫ�ض����ϣ��ı���ֵ��
		num = *begin++;
		cout << num << "  ";
	}
	cout << endl << "======================================" << endl;
	for (int &num : int_arr2)
	{
		cout << num << "  ";
	}
	cout << endl << "======================================" << endl;
}

int main()
{
	//Fun_arrays_element();
	//Fun_pointers_arrays();
	//Fun_C_string();
	Fun_interface_oldcode();
	return 0;
}