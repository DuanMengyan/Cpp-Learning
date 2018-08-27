#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter3.6.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年08月24日 星期五
> Last edited time: 2018年8月27日 星期一
> Topic:C++Primer Chapter3.6 多维数组
************************************************************************/

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;

void Fun_multidimensional_arrays()
{
	//int ia[3][4];
	//int arr[10][20][30] = {0};

	//int (&row)[4] = ia[0];    //row是一个引用，是一个存有4个整数数组的引用

	//const size_t rowCnt = 3, colCnt = 4;
	//int ia[rowCnt][colCnt];
	//for (size_t i = 0; i != rowCnt; ++i)
	//	for (size_t j = 0; j != colCnt; ++j)
	//	{
	//		ia[i][j] = i*colCnt + j;
	//	}



	//要使用范围for语句处理多为数组，除了最内层的循环外，其他所有循环的控制变量都应该是引用类型

	//指针和多维数组
	//int ia[3][4] = { {1,2,3,4}, {5,6,7,8}, {0,1,0,1} };
	//for (auto p = ia; p != ia + 3; ++p)
	//{
	//	for (auto q = *p; q != *p + 4; ++q)
	//		cout << *q << "  ";
	//	cout << endl;
	//}
	//for (auto p = begin(ia); p != end(ia); ++p)
	//{
	//	for (auto q = begin(*p); q != end(*p); ++q)
	//	{
	//		cout << *q << " ";
	//	}
	//	cout << endl;
	//}

	//ex3.43
	/*int ia[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 0, 1, 0, 1 } };*/
	//cout << "V1:" << endl;
	//for (int (&p)[4] : ia)
	//{
	//	for (int q : p)
	//	{
	//		cout << q << "  ";
	//	}
	//	cout << endl;
	//}
	//cout << "==================" << endl;
	//cout << "V2:" << endl;
	//for (int i = 0; i < 3;++i)
	//{
	//	for (int j = 0; j < 4; ++j)
	//	{
	//		cout << ia[i][j]<<"  ";
	//	}
	//	cout << endl;
	//}
	//cout << "==================" << endl;
	//cout << "V3:" << endl;
	//for (int (*p)[4] = ia; p < ia + 3; ++p)
	//{
	//	for (int *j = *p ; j < *p+4; ++j)
	//	{
	//		cout << *j << "  ";
	//	}
	//	cout << endl;
	//}
	
	//ex3.44
	//using int_array = int[4];
	//typedef int int_array[4];
	/*int ia[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 0, 1, 0, 1 } };*/
	//for (int_array *p = ia; p != ia + 3; ++p)
	//{
	//	for (int *q = *p; q < *p + 4; ++q)
	//	{
	//		cout << *q << "  ";
	//	}
	//		cout << endl;
	//}
	//===========================================//
	//int ia[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 0, 1, 0, 1 } };
	//using int_array = int[4];
	//for (int_array& p : ia)
	//{
	//	for (int q : p)
	//	{
	//		/*....*/
	//	}
	//}


	//ex3.45
	int ia[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 0, 1, 0, 1 } };
	for (auto p = ia; p != ia + 3; p++)
	{
		for (auto q = *p; q != *p + 4; ++q)
		{
			cout << *q << "  ";
		}
		cout << endl;
	}

}

int main()
{

	Fun_multidimensional_arrays();
	return 0;
}