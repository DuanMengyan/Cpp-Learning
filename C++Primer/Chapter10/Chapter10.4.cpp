#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年12月28日 星期五
> Last edited time: 2018年12月29日 星期六
> Topic:C++Primer Chapter10.4 再探迭代器
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"
//#include "Sales_item.h"


using namespace std;
using namespace std::placeholders;		//引用占位符


//10.4 再探迭代器
//在头文件iterator中还定义了几种额外的迭代器




//ex10.4.1 插入迭代器
void Fun_Insert_Iterators()
{
	//插入迭代器用来向容器插入元素
	//vector<int> vec;
	//auto it = vec.begin();
	//for (int i = 0; i < 5; ++i)
	//{
	//	it = vec.insert(it, i);
	//	//it++;
	//}	
	//printitem(vec);

	//list<int> lst = { 1,2,3,4 };
	//list<int> lst2 = { 5,6 }, lst3 = { 5,6 }, lst4 = { 5,6 };
	//copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
	//copy(lst.cbegin(), lst.cend(), back_inserter(lst3));
	//copy(lst.cbegin(), lst.cend(), inserter(lst4,lst4.begin()));
	//printitem(lst2);		//4   3   2   1   5   6
	//printitem(lst3);		//5   6   1   2   3   4
	//printitem(lst4);		//1   2   3   4   5   6


	//ex10.26
	//front_iterator将元素插入容器开头，变成新的首元素
	//back_iterator将元素插入容器末尾
	//insert将元素插入到指定迭代器表示的元素之前


	//ex10.27
	//vector<int> vec = { 1,2,3,4,5,5,1,6,6,7,8,2 };
	//list<int> lst;
	//sort(vec.begin(),vec.end()); printitem(vec);
	//unique_copy(vec.cbegin(), vec.cend(), back_inserter(lst));	//相同连续的元素，只复制一个
	//printitem(lst);

	//ex10.28
	//vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	//vector<int> vec1, vec2;
	//list<int> lst3;
	//copy(vec.cbegin(), vec.cend(), inserter(vec1, vec1.begin()));		//123456789	
	//printitem(vec1);
	//copy(vec.cbegin(), vec.cend(), back_inserter(vec2));				//123456789
	//printitem(vec2);
	////front_inserter不能用于vector
	//copy(vec.cbegin(), vec.cend(), front_inserter(lst3));				//987654321
	//printitem(lst3);
}


//ex10.33
void NumFilter(const string &input_file, const string &odd_file, const string &even_file)
{
	ifstream input(input_file);
	ofstream odd(odd_file);
	ofstream even(even_file);
	istream_iterator<int> iter_input(input), eof;
	ostream_iterator<int> iter_odd(odd, " ");
	ostream_iterator<int> iter_even(even, " ");
	while (iter_input != eof)
	{
		(((*iter_input) % 2 == 1) ? *iter_odd : *iter_even) = *iter_input++;
	}
}



//ex10.4.2 iostream迭代器
void Fun_iostream_Iterators()
{
	//istream_iterator操作
	//创建流迭代器必须制定迭代器将要读写的对象类型
	//istream_iterator使用>>来读取流，因此istream_iterator要读取的类型必须定义了输入运算符
	//vector<int> vec;
	//istream_iterator<int> in_iter(cin);
	//istream_iterator<int> eof;
	//while (in_iter != eof)
	//{
	//	vec.push_back(*in_iter++);
	//}
	//printitem(vec);

	//从输入流cin读取int值，存进vec

	//istream_iterator<int> in_iter(cin), eof;		//
	//vector<int> vec(in_iter, eof);					//从迭代器范围构造vec
	//printitem(vec);			
	
	//使用算法操作流迭代器
	//ifstream input("Text10.4.txt");
	//istream_iterator<int> in(input), eof;
	//cout << accumulate(in, eof, 0) << endl;

	//istream_iterator允许使用懒惰求值

	//ostream_iterator操作
	//ifstream input("Text10.4.txt");
	//istream_iterator<int> in_iter(input), eof;		
	//vector<int> vec(in_iter, eof);	
	////输出每个元素后打印第二个字符串（C风格字符串，一个字符串字面常量或者一个指向以空字符结尾的字符数组的指针）
	//ostream_iterator<int> out_iter(cout, "  ");  
	//for (auto e : vec)
	//{
	//	*out_iter++ = e;      //cout<<e,每次向out_iter赋值，写操作就会被提交
	//}
	//cout << endl;

	//调用copy来打印vec中的元素
	//copy(vec.cbegin(), vec.cend(), out_iter);
	//cout << endl;

	//使用流迭代器处理类类型
	//ifstream input("Text10.3.txt");
	//istream_iterator<Sales_data> item_iter(input), eof;
	//ostream_iterator<Sales_data> out_iter(cout, "\n");
	//Sales_data sum = *item_iter++;
	//while (item_iter != eof)
	//{
	//	if (item_iter->isbn() == sum.isbn())
	//	{
	//		sum.combine(*item_iter);
	//		item_iter++;
	//	}
	//	else
	//	{
	//		out_iter = sum;
	//		sum = *item_iter++;
	//	}
	//}
	//out_iter = sum;

	//ex10.29
	//ifstream input("Text10.2.txt");
	//istream_iterator<string> iter(input), eof;
	//vector<string> str_vec(iter, eof);
	//printitem(str_vec);
	
	//ex10.30
	//ifstream input("Text10.4.txt");
	//istream_iterator<int> iter(input), eof;
	//vector<int> vec(iter, eof);
	//sort(vec.begin(), vec.end());
	//ostream_iterator<int> out_iter(cout," ");
	//copy(vec.begin(), vec.end(), out_iter);
	//cout << endl << "==========================" << endl;


	//ex10.31
	//ifstream input("Text10.4.txt");
	//istream_iterator<int> iter(input), eof;
	//vector<int> vec(iter, eof);
	//sort(vec.begin(), vec.end());
	//ostream_iterator<int> out_iter(cout," ");
	//unique_copy(vec.begin(), vec.end(), out_iter);
	//cout << endl << "==========================" << endl;

	//ex10.32
	//方法一：
	//ifstream input("Text10.3.txt");
	//vector<Sales_data> books;
	//istream_iterator<Sales_data> item_iter(input), eof;
	//ostream_iterator<Sales_data> out_iter(cout, "\n");
	////第一个对象先存进books
	//Sales_data temp = *item_iter++; books.push_back(temp);
	//while (item_iter != eof)
	//{
	//	//每读取一个对象，就在vector中检查是否已经存在
	//	temp = *item_iter;
	//	auto f = [temp](Sales_data &cur) {return cur.isbn() == temp.isbn(); };
	//	auto curr = find_if(books.begin(), books.end(), f);
	//	//如果已经存在，就combine，否则就存进vector
	//	if (curr != books.end())
	//	{
	//		curr->combine(temp);
	//	}
	//	else
	//	{
	//		books.push_back(temp);		
	//	}
	//	item_iter++;
	//}
	////按照isbn进行排序
	//auto lam = [](const Sales_data &item1, const Sales_data &item2) {return item1.isbn() < item2.isbn(); };
	//sort(books.begin(), books.end(), lam);
	//for (auto book : books)
	//{
	//	print(cout, book);
	//}


	//方法二：
	//ifstream input("Text10.3.txt");
	//std::istream_iterator<Sales_data> in_iter(input), in_eof;
	//std::vector<Sales_data> vec;

	//while (in_iter != in_eof)
	//vec.push_back(*in_iter++);
	//auto lam = [](const Sales_data &item1, const Sales_data &item2) {return item1.isbn() < item2.isbn(); };
	//sort(vec.begin(), vec.end(), lam);

	//for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end)
	//{
	//	end = find_if(beg, vec.cend(), [beg](const Sales_data &item) { return item.isbn() != beg->isbn(); });
	//	std::cout << std::accumulate(beg, end, Sales_data(beg->isbn())) << std::endl;
	//}



	//ex10.33
	
	NumFilter("Text10.4.txt","Text10.4.2.txt","Text10.4.3.txt");


}



//ex10.4.3





int main()
{
	//ex10.4.1 插入迭代器
	//Fun_Insert_Iterators();
	//ex10.4.2 iostream迭代器
	Fun_iostream_Iterators();
	//return 0;


}




