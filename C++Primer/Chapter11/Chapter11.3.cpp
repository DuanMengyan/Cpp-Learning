#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter11.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月4日 星期五
> Last edited time: 2019年1月9日 星期三
> Topic:C++Primer Chapter11.3 关联容器操作
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;

// Chapter11.3 关联容器操作



//bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
//{
//	return lhs.isbn() < rhs.isbn();
//}

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
	//当使用一个迭代器便利一个map、multimap、set或multiset时，迭代器按关键字升序遍历元素。
	//map<string, size_t> word_count = { {"BBB",6},{"AAA",5},{"CCC",6} };
	//auto map_it = word_count.cbegin();
	//while (map_it != word_count.cend())
	//{
	//	cout << map_it->first << "    " << map_it->second << endl;
	//	++map_it;
	//}

	//关联容器和算法
	//我们一般不对关联容器使用泛型算法，因为关键字是const
	//关联容器可用于只读取元素的算法。或者使用关联容器专门定义的专用find成员
	//对一个关联容器使用算法，要么是将它当做一个源序列，要么是当做一个目的位置。

	//ex11.15
	//map<int, vector<int>> int_to_vector;
	//key_type是int，mapped_type是vector<int>，value_type是pair<const int,vector<int>>

	//ex11.16
	//map<int, string> int_to_string_map = { {5,""},{6,""},{7,""} };
	//vector<string> str_vec = { "AAA","BBB","CCC" };
	//auto iter = str_vec.begin();
	//auto map_iter = int_to_string_map.begin();
	//while (map_iter != int_to_string_map.end())
	//{
	//	map_iter->second = *iter;
	//	++map_iter; ++iter;
	//}
	//auto map_it = int_to_string_map.cbegin();
	//while (map_it != int_to_string_map.cend())
	//{
	//	cout << map_it->first << "    " << map_it->second << endl;
	//	++map_it;
	//}
	
	//ex11.17
	//都合法
	
	//ex11.18
	//map<string, size_t>::const_iterator
	
	//ex11.19
	//using compare = bool(*)(const Sales_data &lhs, const Sales_data &rhs);
	//multiset<Sales_data, compare> bookstore(compareIsbn);
	//multiset<Sales_data, compare>::iterator c_it = bookstore.begin();
}

//11.3.2 添加元素
void Fun_Adding_Elements()
{
	//因为map和set（以及对应的无序类型）包含不重复的关键字，
	//插入一个已经存在的元素对容器没有任何影响
	//vector<int> ivec = { 2,4,6,8,2,4,6,8 };
	//set<int> set2;
	//set2.insert(ivec.cbegin(), ivec.cend());
	//set2.insert({ 1,3,5,7,1,3,5,7 });
	//for (auto i:set2)
	//{
	//	cout << i << "  ";
	//}

	//向map添加元素
	//map<string, size_t> word_count = { { "BBB",6 },{ "AAA",5 },{ "CCC",6 } };
	//word_count.insert({ "word",1 });
	//word_count.insert(make_pair("word",1 ));
	//word_count.insert(pair<string,size_t>{ "word",1 });
	//word_count.insert(map<string,size_t>::value_type { "word",1 });

	//检测insert的返回值
	//map<string, size_t> word_count;
	//string word;
	//ifstream input("Chapter11.1.txt");
	//while (input >> word)
	//{
	//	cout << word<<"\t\t:";
	//	auto ret = word_count.insert({ word,1 });
	//	//旧版声明和初始化
	//	//pair<map<string, size_t>::iterator, bool> ret = word_count.insert(make_pair(word, 1));
	//	if (!ret.second)
	//	{
	//		++ret.first->second;
	//		cout <<"has exsit";
	//	}
	//	cout << endl;
	//}

	//展开递增语句
	//向multiset或multimap添加元素
	//multimap<string, string> authors;
	//authors.insert({ "Barth,John","Sot-Weed Factor" });
	//authors.insert({ "Barth,John","Lost in the Funhouse" });
	//auto map_it = authors.cbegin();
	//while (map_it != authors.cend())
	//{
	//	cout << map_it->first << "    " << map_it->second << endl;
	//	++map_it;
	//} 

	//ex11.20
	//map<string, size_t> word_count;
	//string word;
	//ifstream input("Chapter11.1.txt");
	//while (input >> word)
	//{
	//	auto ret_item = word_count.insert({ word,1 });
	//	if (!ret_item.second)
	//	{
	//		++ret_item.first->second;
	//	}
	//}
	//for (const auto &w : word_count)
	//{
	//	cout << w.first << " \t: " << w.second << ((w.second > 1) ? "times" : "time") << endl;
	//}

	//ex11.21
	//while (input >> word)
	//{
	//	++word_count.insert({ word,1 }).first->second;
	//}


	//ex11.22
	//参数类型：pair<string, vector<int>>;
	//返回类型：pair<map<string, vector<int>>::iterator, bool>;

	//ex11.23
	multimap<string, string> family_map;	
	
	for(string first_name; cout << "Last name:" << endl,cin >> first_name;)
	{		
		for (string name; cout << "First name:" << endl,cin >> name&&name != "end";)
		{
			family_map.insert({first_name,name});
		}

	}
	for (auto w : family_map)
	{
		cout << w.first << " " << w.second << endl;
	}
}




//11.3.3

//11.3.4

//11.3.5

//11.3.6









int main()
{
	//11.3.1 关联容器迭代器
	//Fun_Associative_Container_Iterators();
	//11.3.2 添加元素
	Fun_Adding_Elements();
	return 0;
}