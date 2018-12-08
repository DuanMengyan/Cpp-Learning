#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年12月8日 星期六
> Last edited time: 2018年12月8日 星期六
> Topic:C++Primer Chapter9.4 vector对象是如何增长的
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"

using namespace std;


template <class T>
void Myprint(T & container)
{
	//打印容器中的元素
	for (auto i : container)
	{
		cout << i <<endl;
	}
	cout << endl;
}

// 9.4 vector对象是如何增长的
void Fun_How_a_vector_Grows()
{
	//管理容量的成员函数
	//capacity和size
	//vector<int> ivec;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;
	//for (vector<int>::size_type ix = 0; ix != 24; ++ix)
	//{
	//	ivec.push_back(ix);
	//}
	//cout << "=====================" << endl;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;
	//ivec.reserve(50);
	//cout << "=====================" << endl;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;
	//while (ivec.size() != ivec.capacity())
	//{
	//	ivec.push_back(0);
	//}
	//cout << "=====================" << endl;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;

	//ivec.push_back(10);
	//cout << "=====================" << endl;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;

	//ivec.shrink_to_fit();
	//cout << "=====================" << endl;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;

	//ex9.35
	//size是指一个vector容器当前所包含的元素个数
	//capacity是指不进行内存分配的前提下一个vector容器所能保存的元素个数

	//ex9.36
	//不能

	//ex9.37
	//vector在内存中是连续存放的，需要capacity
	//list在内存中不是连续存放的，不需要
	//array大小固定

	//ex9.38
	//vector<int> ivec;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;
	//int val;
	//while (cin>>val)
	//{
	//	ivec.push_back(val);
	//	cout << "=====================" << endl;
	//	cout << "ivec:size:" << ivec.size() << endl;
	//	cout << "ivec:capacity:" << ivec.capacity() << endl;
	//}


	//ex9.39-ex9.40

	//生成一个含有1000个字符串的文件
	ofstream output("input.txt");
	output.clear();
	int i = 0;
	while (i != 1000)
	{
		output << "HAHAH" << endl;
		i++;
	}
	output.close();

	//字符串容器
	vector<string> svec;
	svec.reserve(0);
	cout << "svec:size:" << svec.size() << endl;
	cout << "svec:capacity:" << svec.capacity() << endl;
	
	//从文本文件中读入字符串
	string word;
	ifstream input("input.txt");
	while (input >> word)
	{
		svec.push_back(word);	
	}

	cout << "=====================" << endl;
	cout << "svec:size:" << svec.size() << endl;
	cout << "svec:capacity:" << svec.capacity() << endl;

	svec.resize(svec.size() + svec.size() / 2);

	cout << "=====================" << endl;
	cout << "svec:size:" << svec.size() << endl;
	cout << "svec:capacity:" << svec.capacity() << endl;

}




int main()
{
	// 9.4 vector对象是如何增长的
	Fun_How_a_vector_Grows();
	return 0;
}