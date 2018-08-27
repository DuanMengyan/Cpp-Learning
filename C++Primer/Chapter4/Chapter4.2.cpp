#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter4.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��08��27�� ����һ
> Last edited time: 2018��8��27�� ����һ
> Topic:C++Primer Chapter4.1+4.2  ���������
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

void Fun_fundamentals()
{
	//��ֵ˳��
	//int i = 0;
	//cout << i << "  " << ++i << endl;   //�����1   1�����Լӣ������
	//cout << i << "  " << i++ << endl;	//�����1   0�����0�Ժ��Լӣ�ǰһ�����Ϊ1

}

void Fun_Arithmetic_Operators()
{
	//ex4.4
	//int num = ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2);
	//num = 16 + 75 + 0;
	//cout << num << endl;

	//%ȡ�������������������������ദ���õ�����������ȡ���������������������������

	//C++11�±�׼�涨��һ����0ȡ������ֱ���г�С�����֣�

	//cout << 21 % 6 << endl;				//3
	//cout << 21 % 7 << endl;				//0
	//cout << -21 % -8 << endl;			//-5
	//cout << 21 % -5 << endl;			//1
	//cout << -21 % 5 << endl;			//-1
	//cout << "================" << endl;
	//cout << 21 / 6 << endl;				//3
	//cout << 21 / 7 << endl;				//3
	//cout << -21 / -8 << endl;			//2
	//cout << 21 / -5 << endl;			//-4
	//cout << -21 / 5 << endl;			//-4

	////ex4.4
	//cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;				//91


	//ex4.7
	//short svalue = 32767; 
	//++svalue;
	//cout << svalue << endl;			// -32768
	//unsigned uivalue = 0;
	//--uivalue;
	//cout << uivalue << endl;		// 4294967295
	//unsigned short usvalue = 65535; 
	//++usvalue;
	//cout << usvalue << endl;		// 0
}


int main()
{
	//Fun_fundamentals();
	Fun_Arithmetic_Operators();
	return 0;
}