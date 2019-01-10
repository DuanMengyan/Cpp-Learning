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
	//multimap<string, string> family_map;	
	//
	//for(string first_name; cout << "Last name:" << endl,cin >> first_name;)
	//{		
	//	for (string name; cout << "First name:" << endl,cin >> name&&name != "end";)
	//	{
	//		family_map.insert({first_name,name});
	//	}
	//}
	//for (auto w : family_map)
	//{
	//	cout << w.first << " " << w.second << endl;
	//}
}

//11.3.3 删除元素
void Fun_Erasing_Elements()
{
	//通过给erase传递一个迭代器或一个迭代器对来删除一个元素或者一个元素范围
	//额外的erase操作接受一个key_type参数，此版本删除所有匹配给定关键字的元素，返回实际删除的元素的数量
}

//11.3.4 map的下标操作
void Fun_Subscripting_a_map()
{
	//不能对multi进行下标操作，因为这些容器中有多个值与一个关键字相关联
	//如果关键字不在map中，则会为它创建一个元素插入到map中。
	//只能对非const的map使用下标
	//map<string, size_t> word_count;
	//word_count["Anna"] = 1;

	//使用下标操作的返回值
	//cout << word_count["Anna"] << endl;
	//++word_count["Anna"];
	//cout << word_count["Anna"] << endl;

	//ex11.24
	//在m中搜索关键字为0的元素；
	//没有找到，则向m中添加一个关键字为0的元素；
	//给该元素复制为1

	//ex11.25
	//vector<int> v;
	//v[0] = 1;
	//语法没有错误，但是v是个空vector，下标越界

	//ex11.26
	//map<int, string> m = { {1,"AAA"},{2,"BBB"} };
	//using KeyType = map<int, string>::key_type;
	//cout << " sunbscript :" << typeid(KeyType).name() << endl;		//const int
	//cout << "return" << typeid(decltype(m[1])).name() << endl;		//string
}

//11.3.5 访问元素
void Fun_Accessing_Elements()
{
	set<int> iset = { 1,2,3,4,5,6,7,8,9 };
	//auto it = iset.find(1);
	//auto it = iset.find(11);
	//if (it != iset.end()) cout << *it << endl;
	//else cout << "not find" << endl;

	//cout << iset.count(1) << endl;
	//cout << iset.count(11) << endl;
	
	//对map使用find来代替下标操作
	//如果只想检测一个给定关键字是否在map中，而不想改变map，应该是find

	//在multimap或multiset中查找元素
	//一种不同的，面向迭代器的解决方法
	//如果lower_bound和upper_bound返回相同的迭代器，则给定关键字不在容器中
	//multimap<string, string> authors = { { "AAA","BOOK1" } ,{ "CCC","Book2" } ,{ "BBB","C++" },{ "GGG","HAHAHA" },{ "BBB","book1" },{ "CCC","hello" } };
	//for (auto beg = authors.lower_bound("GGG"), end = authors.upper_bound("GGG"); beg != end; ++beg) 
	//{
	//	cout << beg->first << "    " << beg->second << endl;
	//}
	
	//equal_range函数
	//multimap<string, string> authors = { { "AAA","BOOK1" } ,{ "CCC","Book2" } ,{ "BBB","C++" },{ "GGG","HAHAHA" },{ "BBB","book1" },{ "CCC","hello" } };
	//for (auto pos = authors.equal_range("BBB");pos.first!=pos.second;++pos.first)
	//{
	//	cout << pos.first->first << "    " << pos.first->second << endl;
	//}

	//ex11.27
	//对于需要统计关键字出现次数的地方，使用count
	//对于只需要检查关键字是否在关联容器中的地方，则使用find
	
	//ex11.28
	//map<string, vector<int>>::iterator it;
	
	//ex11.29
	//upper_bound()返回一个迭代器，指向不影响原来元素排序的关键字插入位置
	
	//ex11.30
	//第一个与搜索元素匹配的元素的值

	//ex11.31-11.32
	//multimap<string, string> authors = { { "AAA","BOOK1" } ,{ "CCC","Book2" } ,{ "BBB","C++" },{ "GGG","HAHAHA" },{ "BBB","book1" },{ "EEE","hello" } };
	//auto it = authors.find("BBB");
	//while (it != authors.end())
	//{
	//	authors.erase(it);
	//	it = authors.find("BBB");
	//}
	//for (auto item : authors)
	//{
	//	cout << item.first << "       " << item.second << endl;
	//}

	//ex11.32
}

//11.3.6 一个单词转换的map
void Fun_A_Word_Transformation_Map()
{

	//ifstream map_file("map_file.txt");
	//ifstream input("input_text11.3.6.txt");
	//string str_line;
	////建立转换字典
	//map<string, string> trans_map;
	//string key;		//要转换的单词
	//string value;	//替换后的内容

	//while (map_file >> key && getline(map_file,value))
	//{
	//	if (value.size() > 1)
	//	{
	//		trans_map[key] = value.substr(1);		//跳过前导空格
	//		cout << value.substr(1) << endl;
	//	}
	//	else
	//		cout << ("no rule for" + key) << endl;
	//}

	////建立转换字典
	////while (getline(map_file, str_line))
	////{
	////	auto  space = str_line.find_first_of(' ');
	////	string key(str_line,0,space);
	////	string value(str_line, space + 1);
	////	trans_map[key] = value;
	////}


	////转换输入文本
	//while (getline(input, str_line))
	//{
	//	istringstream stream(str_line);
	//	string word;
	//	while (stream>>word)
	//	{
	//		auto it = trans_map.find(word);
	//		if (it != trans_map.end())
	//			cout << it->second << " ";
	//		else
	//			cout << word << " ";			
	//	}
	//	cout << endl;

	//	////从读取的行中依次处理每个词
	//	//while (!str_line.empty())
	//	//{
	//	//	auto space = str_line.find_first_of(' ');
	//	//	string str_temp;
	//	//	if (space!= string::npos)
	//	//	{
	//	//		str_temp.assign(str_line, 0, space);
	//	//		str_line.erase(0, space + 1);
	//	//	}
	//	//	else
	//	//	{
	//	//		str_temp = str_line;
	//	//		str_line.clear();
	//	//	}			
	//	//	
	//	//	auto it = trans_map.find(str_temp);
	//	//	if (it != trans_map.end())
	//	//		cout << it->second << " ";
	//	//	else cout << str_temp << " ";			
	//	//}
	//	//cout << endl;
	//}

	//ex11.33
	//以上
	
	//ex11.34
	//修改后的代码将无法编译，因为下标运算符可能会插入一个元素（当找不到具有键s的元素时）
	//并且我们只能仅在不是const的关键字-值对上使用下标。
	
	//ex11.35
	//如果一个单词出现多次：
	//下标会将最后一次对应的短语插入到map中
	//使用insert会将第一次的对应短语插入到map中。

	//ex11.36
	//如果是这样，键值对将是{key，“”}（“”。size（）！> 1），无法将其添加到map中。 因此，密钥不会被任何字符串替换。

}



int main()
{
	//11.3.1 关联容器迭代器
	//Fun_Associative_Container_Iterators();
	//11.3.2 添加元素
	//Fun_Adding_Elements();
	//11.3.3 删除元素
	//Fun_Erasing_Elements();
	//11.3.4 map的下标操作
	//Fun_Subscripting_a_map();
	//11.3.5 访问元素
	//Fun_Accessing_Elements();
	//11.3.6 一个单词转换的map
	Fun_A_Word_Transformation_Map();
	return 0;
}