#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter5.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年09月02日 星期日
> Last edited time: 2018年9月02日 星期日
> Topic:C++Primer Chapter5.4 迭代语句
************************************************************************/

#include <iostream>
#include <cstddef>
#include <cctype>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

//判断较短的vec1是不是较长的vec2的前缀
bool is_pre(vector<int> &vec1, vector<int> &vec2)
{
	if (vec1.size() > vec2.size())
		return is_pre(vec2,vec1);
	else
	{
		for (decltype(vec1.size()) i = 0; i != vec1.size(); ++i)
		{
			if (vec1[i] != vec2[i])
				return false;
		}
		return true;
	}
}


//5.4 迭代语句
void Fun_Iterative_Statements()
{
	//5.4.1 while语句
	//vector<int> v;
	//int i;
	//while (cin >> i)
	//	v.push_back(i);
	//auto beg = v.begin();
	//while (beg != v.end() && *beg > 0)
	//{
	//	++beg;
	//}
	//if (beg == v.end())
	//	cout << "end";

	//ex5.14
	//unsigned i = 0, str_cnt = 1, maxcnt = 1;
	//vector<string> str_vec;
	//string con_str, max_str;
	//while (cin >> con_str)
	//{
	//	str_vec.push_back(con_str);
	//	++i;
	//	if (i > 1 )
	//		if(con_str == str_vec[i - 2])
	//		{
	//			++str_cnt;
	//		}
	//		else
	//		{
	//			if (str_cnt > maxcnt)
	//				max_str = str_vec[i-2];
	//				maxcnt = str_cnt;
	//			str_cnt = 1;
	//		}
	//}
	//cout << max_str << " occurred " << maxcnt << "times" << endl;
	//pair<string, int> max_duplicated;
	//int count = 0;
	//for (string str, prestr; cin >> str; prestr = str)
	//{
	//	if (str == prestr) ++count;
	//	else count = 0;
	//	if (count > max_duplicated.second) max_duplicated = { prestr, count };
	//}

	//if (max_duplicated.first.empty()) cout << "There's no duplicated string." << endl;
	//else cout << "the word " << max_duplicated.first << " occurred " << max_duplicated.second + 1 << " times. " << endl;

	//5.4.2  传统的for语句
	//ex5.15
	//(a) 在for循环与巨头定义的ix只在for循环体内可见
	//(b) 

	//ex5.16

	//ex5.17
	//vector<int> vec1 = { 0, 1, 1, 2 };
	//vector<int> vec2 = { 0, 1, 1, 2, 3, 5, 8 };
	//decltype(vec1.size()) i;
	//for (i = 0; i < (vec1.size() < vec2.size() ? vec1.size() : vec2.size()); i++)
	//{
	//	if (vec1[i] != vec2[i])
	//		break;
	//}
	//if (i == (vec1.size() < vec2.size() ? vec1.size() : vec2.size()))
	//	cout << "True" << endl;
	//else
	//{
	//	cout << "False" << endl;
	//}
	//cout << (is_pre(vec1, vec2) ? "yes" : "no") << endl;

	//5.4.3范围for语句

	//5.4.4 do while 语句
	//ex5.19
	//string str1, str2, flag;
	//do
	//{
	//	cout << "input two string:" << endl;
	//	cin >> str1 >> str2;
	//	cout << (str1.size() <= str2.size() ? str1 : str2) << endl;
	//	cout << "continue? yes or no." << endl;
	//	cin >> flag;
	//} while (!flag.empty() && *flag.begin() != 'n');



}

int main()
{
	Fun_Iterative_Statements();
	return 0;
}