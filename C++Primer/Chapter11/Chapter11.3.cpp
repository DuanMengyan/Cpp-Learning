#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter11.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月4日 星期五
> Last edited time: 2019年1月4日 星期五
> Topic:C++Primer Chapter11.3 关联容器操作
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;

// Chapter11.3 关联容器操作

//11.3.1 关联容器迭代器
void Fun_Associative_Container_Iterators()
{
	//当解引用一个关联容器迭代器是，我们会得到一个类型为容器的value_type的值得引用
	//一个map的value_type是一个pair，我们可以改变pair的值，但是不能改变关键字成员的值，关键字成员是const的
	//map<string, size_t> word_count = { {"AAA",5},{"BBB",6},{"CCC",6} };
	//auto map_it = word_count.begin();
	//cout << map_it->first << "   " << map_it->second << endl;

	//set的迭代器是const的，
	//set的两种类型迭代器都只能只读访问set中的元素
	//一个set中的关键字也是const的
	//set<int> iset = { 0,1,2,3,4,5,6,7,8,9 };
	//set<int>::iterator set_it = iset.begin();
	//if (set_it != iset.end())
	//{
	//	cout<<*set_it <<endl;
	//}
	
	//遍历关联容器
	map<string, size_t> word_count = { {"AAA",5},{"BBB",6},{"CCC",6} };
	auto map_it = word_count.begin();
	while (map_it != word_count.cend())
	{
		cout << map_it->first << "    " << map_it->second << endl;
		++map_it;
	}





}

//11.3.2

//11.3.3

//11.3.4

//11.3.5

//11.3.6









int main()
{
	//11.3.1 关联容器迭代器
	Fun_Associative_Container_Iterators();
	return 0;
}