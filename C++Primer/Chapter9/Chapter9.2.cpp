#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter9.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年10月29日 星期一
> Last edited time: 2018年11月9日 星期五
> Topic:C++Primer Chapter9.2 容器库概览
************************************************************************/

#include "header_include.h"

using namespace std;


//9.2 容器库概览
void Fun_Container_Library_Overview()
{
	//ex9.2
	list<deque<int>> int_deque_list{ {0,1,2}, {1,2,3}, {2,3,4} };
	for (auto &a : int_deque_list)
	{
		a.push_front(5);	//	插入一个整数5
	}
	for (auto a : int_deque_list)
	{
		for (auto b : a)
		{
			cout << b << "  ";		//打印
		}
		cout << endl;
	}

}

//ex.9.4 -9.5
vector<int>::const_iterator SearchKey(vector<int>::const_iterator left, vector<int>::const_iterator right, int key)
{
	if (left > right)
	{
		cout << "Error!" << endl;
		return right;
	}
	else
	{
		while (left != right)
		{
			if (*left == key)
			{
				return left;
			}
			++left;
		}
		return right;

	}
}


//9.2.1 迭代器
void Fun_Iterators()
{
	//迭代器范围：左闭合区间[begin,end）
	//end不能在begin之前
	//使用左闭合范围蕴含的编程假定
	
	//ex.9.3
	//begin和end指向同一容器中的元素
	//begin反复递增到达end

	//ex.9.4
	//vector<int> int_vec{ 1, 3, 5, 6, 8, 9, 7 };
	//auto begin = int_vec.cbegin(), end = int_vec.cend();
	//cout << SearchKey(begin, end, 6) << endl;
	
	//ex.9.5
	//vector<int> int_vec{ 1, 3, 5, 6, 8, 9, 7 };
	//auto begin = int_vec.cbegin(), end = int_vec.cend();
	//auto result = SearchKey(begin, end, 2);
	//if (result != end)
	//{
	//	cout << *result << endl;
	//}
	//else
	//{
	//	cout << "Can not find value!" << endl;
	//}

	//ex.9.6
	//list<int> lst1;
	//list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
	//while (iter1 != iter2)
	//{
	//	/*
	//	运算符<未在list中实现，list是双向链表，链表节点的地址不一定是连续的
	//	*/
	//}
}

//9.2.2 容器类型成员
void Fun_Container_Type_Members()
{
	////ex.9.7
	//vector<int>::size_type;
	////ex.9.8
	//list<string>::const_iterator;		//to read
	//list<string>::iterator;				//to write
}

//9.2.3 begin和end成员
void Fun_begin_and_end_Members()
{
	//begin()和end()操作最常见的用途是形成一个包含容器中所有元素的迭代器范围
	//带r的版本返回反向迭代器；以c开头的版本返回const迭代器

	//以c开头的版本是C++新标准引入的，用以支持auto与begin和end函数结合使用。
	//不需要写访问时，应使用cbegin和cend

	//ex.9.9
	//cbegin是一个const成员，返回容器的const_iterator类型
	//begin是普通成员，返回容器的iterator类型

	//ex.9.10
	//vector<int> v1; //
	//const vector<int> v2;
	//auto it1 = v1.begin();		//vector<int>::iterator
	//auto it2 = v2.begin();		//vector<int>::const_iterator
	//auto it3 = v1.cbegin();		//vector<int>::const_iterator
	//auto it4 = v2.cbegin();		//vector<int>::const_iterator
}

class Person
{
public:
	Person() :age(10), name("Tom"){ };
	Person(int a, string n) :age(a), name(n){ };
	void print()
	{
		cout << name << " is " << age << " years old." << endl;
	}

private:
	string name;
	int age;

};

//9.2.4 容器定义和初始化
void Fun_Defining_and_Initializing_a_Container()
{
	//将一个容器初始化为另一个容器的拷贝
	//将一个新容器创建为另一个容器的拷贝的方法有两种：
	//可以直接拷贝整个容器（两个容器的类型及元素类型必须匹配）
	//或者拷贝由一个迭代器对指定的元素范围（不要求相同）

	//list<string> authors = { "Milton", "Shakespaeare", "Austen" };
	//vector<const char*> articles = { "a", "an", "the" };

	//list<string> list2(authors);
	////deque<string> authList(authors);			//容器类型不匹配
	////vector<string> words(articles);			//容器元素类型不匹配
	//
	////可以将const char*元素转换为string
	//forward_list<string> words(articles.begin(), articles.end());

	//for (auto i : words)
	//{
	//	cout << i << endl;
	//}


	//列表初始化
	//除对于array之外的容器类型，初始化列表还隐含地制定了容器的大小

	//与顺序容器大小相关的构造函数
	//如果元素类型是没有默认构造函数的类类型，除了大小参数，还必须指定一个显示的元素初始值
	//vector<Person> people1(5);
	//vector<Person> people2(5, Person(20, "Bob"));

	//for (auto i : people1)
	//{
	//	i.print();
	//}
	//cout << "=========================" << endl;
	//for (auto i : people2)
	//{
	//	i.print();
	//}

	//标准库array具有固定大小
	//当定义一个array时，除了指定元素类型，还要指定容器大小
	//对array进行列表初始化，初始值的数目必须等于或小于array的大小
	//所有剩下的元素都会进行值初始化;
	//这两种情况下，如果元素类型是一个类类型，那么该类必须有一个默认构造函数
	//可以对array进行拷贝或对象赋值操作（内置数组类型不行）
	//拷贝操作要求初始值类型和要创建的容器类型相同，还要求元素类型和大小也都一样

	//array<int, 42> int_arr;
	//array<string, 10> str_arr;

	//array<Person, 10> Per_arr;
	//for (auto i:Per_arr)
	//{ 
	//	i.print();	
	//}
	
	//ex9.11
	//vector<int> other_vec;								//空
	//vector<int> vec(10);									//10个0
	//vector<int> vec = {10};								//1个10
	//vector<int> vec(10, 1);								//10个1
	//vector<int> vec{ 1, 2, 3, 4, 5 };						//1,2,3,4,5
	//vector<int> vec(other_vec);							//other_vec的拷贝
	//vector<int> vec(other_vec.begin(), other_vec.end());	//与other_vec一样

	//ex9.12
	//接受容器拷贝的要求容器类型以及元素类型一致；拷贝容器中的所有元素
	//接受迭代器创建拷贝的构造函数不要求容器类型以及元素类型一致，可以转化即可，仅拷贝迭代器范围类的元素

	//ex9.13
	//list<int> int_list(5,4);
	//vector<double> dou_vec1(int_list.begin(),int_list.end());

	//vector<int> int_vec(5,5);
	//vector<double> dou_vec2(int_vec.begin(),int_vec.end());
	//for (double i : dou_vec2)
	//{
	//	cout << i << "  ";
	//}

}


//9.2.5 赋值和swap
void Fun_Assignment_and_swap()
{
	//标准库array类型允许赋值，赋值号左右两边的运算对象必须具有相同的类型（大小也是作为元素类型）
	//array<int, 10> a1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//cout << a1.size() << endl;
	//array<int, 10> a2 = { 0 };
	//a1 = a2;
	//cout << a1.size() << endl;

	//使用assign（仅顺序容器）
	//由于旧元素被替换，因此转递给assign的迭代器不能指向调用assign的容器
	//list<string> names;
	//vector<const char*> oldstyle = { 5, "ABC" };
	//for (const char* c : oldstyle)
	//{
	//	//c是指向字符串“ABC”的首字符的字符指针
	//	cout << c << endl;
	//}
	////names = oldstyle;			//容器类型不匹配，报错
	//cout << "========================" << endl;
	//names.assign(oldstyle.begin(),oldstyle.end());
	//for (auto s: names)
	//{ 
	//	cout << s << endl;
	//}
	//assign第二个版本
	//list<string> slist1(1);
	//slist1.assign(10, "ABC");
	////等价于
	//slist1.clear();
	//slist1.insert(slist1.begin(), 10, "ABC");


	//使用swap,交换两个相同类型容器的内容。
	//除array外，swap不对任何元素进行拷贝、删除或插入操作，
	//元素本身并未交换，只是交换了两个容器的内部数据结构
	//因此可以保证在常数时间内完成
	//swap两个array会真正交换他们的元素。

	//ex9.14
	//list<const char*> char_list = { "ABC", "BBB" };
	//vector<string> str_vec;
	//str_vec.assign(char_list.cbegin(),char_list.cend());
	//for (auto s : str_vec)
	//{
	//	cout << s << endl;
	//}
}

//9.2.7	关系运算符
void Fun_Relational_Operators()
{
	//每个容器类型都支持相等运算符（==和！=）；
	//除了无序关联容器外的所有容器都支持关系运算符（>、>=、<、<=）

	//如果两个容器都不是另一个容器的前缀子序列，则他们的比较结果取决于第一个不相等元素的比较结果

	//vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
	//vector<int> v2 = { 1, 3, 9 };
	//vector<int> v3 = { 1, 3, 5, 7 };
	//vector<int> v4 = { 1, 3, 5, 7, 9, 12 };

	//cout << std::boolalpha << (v1 < v2) << endl;
	//cout << (v1 < v3) << endl;
	//cout << (v1 == v4) << endl;
	//cout << (v1 == v2) << endl;

	//容器的关系运算符使用元素的关系运算符完成比较
	//如果元素的类型不支持所需运算符，那么保存这种元素的容器就不能使用相应的关系运算。

	//ex9.15
	vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
	vector<int> v2 = { 1, 3, 9 };
	cout << std::boolalpha << (v1 == v2) << endl;
	//ex9.16
	vector<int> v3 = { 1, 3, 5, 7, 9, 12 };
	list<int> l4 = { 1, 3, 9 };
	cout << (vector<int> (l4.begin(), l4.end()) > v3 ? "true" : "false") << endl;
	//ex9.17
	//c1和c2必须是同一种容器且包含相同的元素类型
	//元素的类型支持关系操作
	//c1 和 c2都是除无需关联容器之外的容器类型 
}



int main()
{
	//9.2 容器库概览
	//Fun_Container_Library_Overview();

	//9.2.1 迭代器
	//Fun_Iterators();

	//9.2.2 容器类型成员
	//Fun_Container_Type_Members();

	//9.2.3 begin和end成员
	//Fun_begin_and_end_Members();

	//9.2.4 容器定义和初始化
	//Fun_Defining_and_Initializing_a_Container();

	//9.2.5 赋值和swap
	//Fun_Assignment_and_swap();

	//9.2.7 关系运算符
	Fun_Relational_Operators();

	return 0;
}