#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter3.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年08月13日 星期一
> Last edited time: 2018年8月14日 星期二
> Topic:C++Primer Chapter3.3标准库类型vector
************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

//using namespace std;


using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;


//3.3.1定义和初始化vector对象
void Fun_inti_vector()
{
	//ex3.12
	//vector<vector<int>>  ivec = { {3,2,1}, {4,5,6}, {9,8,7} };
	//cout << ivec[1][2]<< endl;


	//ex3.13略

	//ex3.14
	//vector<int> int_vec;
	//int num;
	//while (cin >> num)
	//{
	//	int_vec.push_back(num);
	//}
	//for (auto &i : int_vec)
	//{
	//	cout << i << "  ";
	//}


	//ex3.15
	//vector<string> str_vec;
	//string str;
	//while (cin >> str)
	//{
	//	str_vec.push_back(str);
	//}
	//for (auto &i : str_vec)
	//{
	//	cout << i << "\n";
	//}

	//其他vector操作
	//vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 5, 8 };

	//for (auto &i : v)
	//	i *= i;
	//for (auto i : v)
	//	cout << i << " ";

	//计算vector内对象的索引
	//vector<int> int_count(11,0);
	//int grade;
	//while (cin>>grade)
	//{
	//	if (grade<=100)			//检查输入是否合法有效
	//		++int_count[grade/10];
	//}
	//for (auto &i : int_count)
	//{
	//	cout << i<<"  ";
	//}

	//ex3.16
	vector<int> v1;						//空
	vector<int> v2(10);					//10个0
	vector<int> v3(10, 42);				//10个42
	vector<int> v4{ 10 };				//10
	vector<int> v5{ 10, 42 };			//2个元素，10和42
	vector<string> v6( 10 );			//v6中有10个默认初始化的元素,等价于vector<string> v6{ 10 };
	vector<string> v7( 10, "hi" );		//10个“hi”
	//vector<string> v8("hi");			//错误不能使用字符串字面值构建vector对象
	
	//cout << "{\"v3\":{\"size:\"" << v3.size() << "\",\"value\":[";
	//for (auto &i : v6)
	//{
	//	cout << i << ",";
	//}
	//if (!v3.empty()) cout << "\b";		//退格符，去掉最后一个“,”
	//cout << "]}" << endl;
	
	//cout << "{\"v6\":{\"size:\"" << v6.size() << "\",\"value\":[";
	//for (auto &i : v6)
	//{
	//	if (!i.empty()) cout << i << ",";
	//	else cout << "(null)" << ",";
	//}
	//if(!v6.empty()) cout << "\b";
	//cout << "]}";


	//ex3.17
	//vector<string> str_vec;
	//string str;
	//while (cin>>str)
	//{
	//	str_vec.push_back(str);
	//}
	//for (auto &s:str_vec)
	//{
	//	if (!s.empty())
	//	{
	//		for (auto &c : s)
	//			c = toupper(c);
	//	}
	//	cout << s << endl;
	//}

	//ex3.18
	//vector<int> ivec{ 42 };


	//ex3.19
	//vector<int> vec1(10, 42);				//better
	//vector<int> vec2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
	//vector<int> vec3;
	//for (int i = 0; i < 10; i++)
	//{
	//	vec3.push_back(42);
	//}

	//ex3.20
	vector<int> vec;
	for (int num; cin >> num; vec.push_back(num));
	//for (decltype(vec.size()) i = 1; i < vec.size(); i++)
	//{
	//	cout << vec[i - 1] + vec[i] << "\t";
	//}
	for (decltype(vec.size()) i = 0; i < (vec.size()+1)/2; i++)
	{
		cout << vec[i] + vec[vec.size()-i-1] << " ";
	}
	cout << (vec.size() + 1) / 2;
}


//
//int main()
//{
//
//	Fun_inti_vector();
//
//	return 0;
//
//
//}