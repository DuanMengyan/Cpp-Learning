#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter11.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月3日 星期四
> Last edited time: 2019年1月3日 星期四
> Topic:C++Primer Chapter11.2 关联容器概述
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;

using Families = map<string, vector<string>>;

auto make_families()
{
	Families families;
	for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
		for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
			families[ln].push_back(cn);
	return families;
}

auto print(Families const& families)
{
	for (auto const& family : families)
	{
		cout << family.first << ":\n";
		for (auto const& child : family.second)
			cout << child << " ";
		cout << "\n";
	}
}


//Chapter11.2 关联容器概述

//11.1 定义关联容器
void Fun_Defining_an_Associative_Container()
{
	map<string, size_t> word_count;
	//初始化multimap或multiset
	//multimap或multiset允许有多个元素具有相同的关键字
	//vector<int> ivec;
	//for (vector<int>::size_type i = 0; i != 10; ++i)
	//{
	//	ivec.push_back(i);
	//	ivec.push_back(i);
	//}
	//set<int> iset(ivec.cbegin(), ivec.cend());
	//multiset<int> miset(ivec.cbegin(), ivec.cend());
	//cout << ivec.size() << endl;
	//cout << iset.size() << endl;
	//cout << miset.size() << endl;

	//ex11.5
	//map存放关键字-值对，set存放关键字，
	//需要对应关系的时候用map，需要存储序列时用set


	//ex11.6
	//list
	//元素有序，可以重复，
	//set
	//元素无序，不可重复

	//ex11.7
	//map<string, vector<string>> name_map;	
	//vector<string> kids_name;
	//cout << "Last name:" << endl;
	//for(string first_name; cin >> first_name;cout<<"Last name:"<<endl)
	//{
	//	cout << "First name:" << endl;
	//	for (string name; cin >> name&&name != "end";cout<<"First name:"<<endl)
	//	{

	//		kids_name.push_back(name);
	//	}
	//	name_map[first_name] = kids_name;
	//	kids_name.clear();
	//}
	//
	//for (auto w : name_map)
	//{
	//	for (auto str : w.second)
	//	{
	//		cout << w.first << str << " ";
	//	}
	//	cout << endl << "========================" << endl;
	//}

	//ex11.8
	vector<string> vec; 
	string str;
	while (cin>>str)
	{
		if ( find(vec.begin(),vec.end(),str) == vec.end())
		{
			vec.push_back(str);
		}
	}
	printitem(vec);


	//无论添加或者删除元素，set始终有序，且元素唯一
	//向vector中添加元素，花费的时间与已有的元素个数成正比；
	//向set中添加元素，花费的时间与已有的元素个数正比例，当元素数目很大时，会有很大提升

}


//11.2 关键字类型的要求



//11.3 pair类型




int main()
{
	//11.1 定义关联容器
	Fun_Defining_an_Associative_Container();
	return 0;
}


