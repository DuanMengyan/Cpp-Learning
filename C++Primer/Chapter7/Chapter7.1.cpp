#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter7.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年9月15日 星期六
> Last edited time: 2018年9月15日 星期六
> Topic:C++Primer Chapter7.1 定义抽象数据类型
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>
#include "Sales_item.h"


using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::initializer_list;

//Defining Abstract Data Types


struct Sales_data
{
	string bookNo;
	unsigned unitis_sold = 0;
	double revenue = 0.0;
};

//7.1.1 设计Sales_data类
void Fun_Designing_the_Sales_data_Class()
{
	Sales_data total;
	if (cin >> total.bookNo >> total.unitis_sold >> total.revenue)
	{
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.unitis_sold >> trans.revenue)
		{
			if (total.bookNo == trans.bookNo)
			{
				total.unitis_sold += trans.unitis_sold;
				total.revenue += trans.revenue;
			}
			else
			{
				cout << total.bookNo << " " << total.unitis_sold << " " << total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.unitis_sold << " " << total.revenue << endl;
	}
	else
	{
		std::cerr << "No data?!" << endl;
	}
}






int main()
{
	//7.1.1 设计Sales_data类
	Fun_Designing_the_Sales_data_Class();
	return 0;
}