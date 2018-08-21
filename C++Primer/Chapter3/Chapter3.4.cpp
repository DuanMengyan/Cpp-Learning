#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter3.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年08月16日 星期四
> Last edited time: 2018年8月21日 星期二
> Topic:C++Primer Chapter3.4 迭代器类型
************************************************************************/


#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;


//3.4.1使用迭代器
void Fun_iterator()
{
	

	//string s("some string");
	//if (s.begin() != s.end())			//检查s是否为空
	//{
	//	auto it = s.begin();
	//	*it = toupper(*it);
	//}
	//cout << s << endl;

	//
	//if (s.begin() != s.end())
	//{		
	//	for (auto it = s.begin(); it != s.end() && !isspace(*it);++it)
	//	{
	//		*it = toupper(*it);
	//	}
	//}
	//cout << s << endl;


	//迭代器类型
	//vector<int>::iterator it;			//it 能读写vector<int>的元素

	//const vector<int> vec{1,2,3,4};
	//vector<int>::const_iterator it=vec.begin();	//it只能读元素，不能写元素
	//for (; it != vec.end(); ++it)
	//{
	//	//*it = 5;				//错误
	//	cout << *it<<"\t";
	//}


	//begin和end运算符
	//vector<int> v;
	//const vector<int> cv;
	//auto it1 = v.begin();			//it1的类型是vector<int>::iterator
	//auto it2 = cv.begin();			//it2的类型是vector<int>::const_iterator

	//auto it3 = v.cbegin();			//it3是vector<int>::const_iterator类型，只能读操作

	//结合街引用和成员访问操作 
	//箭头运算符（->）把解引用和成员访问两个操作结合在一起 
	//vector<string> text;
	//string str;
	//while (getline(cin,str))
	//{
	//	text.push_back(str);		//创建一个字符串向量
	//}
	////一次输出text中的每一行字符串，直到遇到第一个空白行或者结束
	//for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) 
	//	cout << *it << endl;


	//某些对vector对象的操作会是迭代器失效
	//但凡是适应了迭代器的循环体，都不要想迭代器所属的容器添加元素；
	//push_back操作会是vector对象的得带器失效
	

	//ex3.21
	//vector<int> v1;						//空
	//vector<int> v2(10);					//10个0
	//vector<int> v3(10, 42);				//10个42
	//vector<int> v4{ 10 };				//10
	//vector<int> v5{ 10, 42 };			//2个元素，10和42
	//vector<string> v6{ 10 };				//v6中有10个默认初始化的元素,等价于vector<string> v6{ 10 };
	//vector<string> v7(10, "hi");		//10个“hi”
	////vector<string> v8("hi");			//错误不能使用字符串字面值构建ve

	//for (auto it = v2.cbegin(); it != v2.cend(); ++it)
	//	cout << *it << "\t";
	//cout << endl;
	//for (auto it = v7.cbegin(); it != v7.cend(); ++it)
	//	cout << *it << "\t";
	//cout << endl;

	//3.22
	//vector<string> text;
	//string str;
	//while (getline(cin,str))
	//{
	//	text.push_back(str);		//创建一个字符串向量
	//}
	////一次输出text中的每一行字符串，直到遇到第一个空白行或者结束
	//for (auto it = text.begin(); it != text.end(); ++it)
	//{
	//	if (!it->empty())
	//	{
	//		for (auto sit = it->begin(); sit != it->end();++sit)
	//		{
	//			*sit = toupper(*sit);
	//		}
	//	}
	//	cout << *it << endl;
	//}
	
	//3.23
	//vector<int> vec(10,5);
	//for (auto it = vec.begin(); it != vec.end(); ++it)
	//{
	//	*it = 2 * *it;
	//	cout << *it << "\t";
	//}
	//cout << endl;
}


//3.4.2迭代器运算
void Fun_iterator_arithmetic()
{
	//二分搜索
	//vector<int> vec{ 1, 2, 3, 4, 5, 6 ,7, 8};
	//int num = 0;
	//auto begin = vec.begin();
	//auto end = vec.end();
	//auto mid = vec.begin() + vec.size() / 2;
	//cout << end - begin <<"\t"<<vec.size()/2<< endl;
	//
	//while (mid != end && *mid != num)
	//{
	//	if ( num< *mid)
	//	{
	//		end = mid;
	//	}
	//	else
	//	{
	//		begin = mid + 1;
	//	}
	//	mid = begin + (end - begin) / 2;
	//	cout << *mid << endl;
	//}
	//cout << *mid << endl;

	//ex3.24
	//vector<int> vec;//{1,2,3,4,5,6,7}
	//for (int num; cin >> num; vec.push_back(num));
	//auto pre = vec.begin();
	//auto next = pre + 1;
	////cout << *pre + *next << endl;
	//while (pre != vec.end()-1)
	//{		
	//	cout << *pre + *next << endl;		
	//	pre = next;
	//	next = pre + 1;
	//}
	//auto begin = vec.begin();
	//auto end = vec.end()-1;
	//while (begin <= end)
	//{
	//	cout << *begin + *end << endl;
	//	++begin;
	//	--end;
	//}

	//ex3.25
	vector<unsigned> scores(11, 0);
	vector<unsigned> grade{45,65,95,100,39,67,95,76,88,76,83,92,76,93};
	//for (auto g : grade)
	//{
	//	if (g <= 100)
	//		++scores[g/ 10];
	//}
	//for (auto s : scores)
	//{
	//	cout << s << "  ";
	//}
	//cout << endl;
	auto begin = scores.begin();
	for (auto g : grade)
	{
		if (g <= 100)
			++ *(begin + g / 10);
	}
	for (auto s : scores)
	{
		cout << s << "   ";
	}
	cout << endl;

}



int main()
{
	//Fun_iterator();
	Fun_iterator_arithmetic();
	return 0;
}