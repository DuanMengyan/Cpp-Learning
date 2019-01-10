#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter11.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月10日 星期四
> Last edited time: 2019年1月10日 星期四
> Topic:C++Primer Chapter11.4 无序容器
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;

size_t hasher(const Sales_data &sd)
{
	return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}


// Chapter11.4 无序容器
void Fun_The_Unordered_Containers()
{
	//使用无序容器
	//unordered_map<string, size_t> word_count;
	//string word;
	//ifstream input("Chapter11.1.txt");
	//while (input >> word)
	//{
	//	++word_count[word];
	//}
	//for (const auto &item : word_count)
	//{
	//	cout << item.first << "\t\t occurs " << item.second << (item.second > 1 ? " times " : " time ") << endl;
	//}

	//管理桶
	//无序容器的性能依赖于哈希函数的质量和桶的数量和大小

	//cout << word_count.bucket_count() << endl;		//正在使用的桶的数量
	//cout << word_count.max_bucket_count() << endl;	//容器所能容纳的最多的桶的数量
	////for (decltype(word_count.bucket_count()) i = 0; i < word_count.bucket_count(); ++i)
	////{
	////	cout << word_count.bucket_size(i) << endl;	//第n个同中的元素
	////}
	//cout << word_count.bucket("a") << endl;			//关键字“a”在哪个桶中
	//cout << word_count.size() << endl;				//容器中的元素个数		
	//cout << word_count.load_factor() << endl;		//每个桶的平均元素个数
	//cout << word_count.max_load_factor() << endl;
	//word_count.rehash(120);
	//cout << "===============================" << endl;
	//cout << word_count.bucket_count() << endl;		//正在使用的桶的数量
	//cout << word_count.max_bucket_count() << endl;	//容器所能容纳的最多的桶的数量

	//cout << word_count.size() << endl;				//容器中的元素个数		
	//cout << word_count.load_factor() << endl;		//每个桶的平均元素个数
	//cout << word_count.max_load_factor() << endl;
	

	//无序容器对关键字类型的要求

	//using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
	//参数是桶的大小，哈希函数指针和相等性判断运算符指针
	//SD_multiset bookstore(42, hasher, eqOp);
	//如果我们的类定义了==运算符，则可以只重载哈希函数
	//unordered_set<Sales_data, decltype(hasher)*> bookstore(42, hasher);

	//ex11.37
	//有序v无序关联容器
	//有序关联容器
	//	标准遍历按排序顺序查找元素
	//	可以指定排序谓词
	//	默认顺序谓词是“小于”，使用operator<为元素类型定义
	//	流行的实现：OrderedVector，BinarySearchTree
	//	搜索操作需要具有O（log n）运行时间
	//	插入，删除操作应该很少使用或具有O（log n）运行时
	//无序关联容器
	//	标准遍历以未指定的顺序查找元素
	//	搜索，插入，删除操作应具有平均大小写常量运行时
	//	流行的实现使用散列（hash）

	//ex11.38
	ifstream map_file("map_file.txt");
	ifstream input("input_text11.3.6.txt");
	string str_line;
	//建立转换字典
	unordered_map<string, string> trans_map;
	string key;		//要转换的单词
	string value;	//替换后的内容

	while (map_file >> key && getline(map_file,value))
	{
		if (value.size() > 1)
			trans_map[key] = value.substr(1);		//跳过前导空格
	}

	//转换输入文本
	while (getline(input, str_line))
	{
		istringstream stream(str_line);
		string word;
		while (stream>>word)
		{
			auto it = trans_map.find(word);
			if (it != trans_map.end())
				cout << it->second << " ";
			else
				cout << word << " ";			
		}
		cout << endl;
	}
}


int main()
{
	// Chapter11.4 无序容器
	Fun_The_Unordered_Containers();
	return 0;
}