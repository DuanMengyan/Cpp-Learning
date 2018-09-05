#pragma once
#pragma execution_character_set("utf-8")

#include "Chapter6.1.h"
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

void myfact()
{
	for (int val, num; cout << "Enter val:" << endl, cin >> val;)
	{
		if (val < 0)
		{
			runtime_error err("Val cannot bo a negative number!");
			cout << err.what() << endl;
		}
		else
		{
			num = val;
			unsigned long long result = 1;
			while (num > 1)
				result *= num--;
			cout << val << "! = " << result << endl;
		}
	}

}