#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年11月9日 星期五
> Last edited time: 2018年11月25日 星期日
> Topic:C++Primer Chapter9.3 顺序容器操作
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"

using namespace std;

//9.3 顺序容器操作
//Sequential Container Operations

//9.3.1 向顺序容器添加元素
void Fun_Adding_Elements_to_a_Sequential_Container()
{
	//向一个vector 、string 或 deque插入元素会是所有指向容器的迭代器、引用和指针失效

	//使用push_back

	//string str = "hello world";
	//str.push_back('!');			//等价于str += 's'

	//用一个对象初始化容器时，或将一个对象插入到容器中时，实际上放入到容器中的是对象值的一个拷贝
	//随后对容器中元素的任何改变不会影响到原始对象，反之亦然


	//使用push_front
	//list<int> ilist;
	//for (size_t ix = 0; ix != 4; ++ix)
	//	ilist.push_front(ix);

	//for (auto i : ilist)
	//{
	//	cout << i << "  ";
	//}
	
	//deque像vector一样提供了随机访问元素的能力，但它提供了vector所不支持的push_front。
	//deque保证在容器首尾进行插入和删除元素的操作都花费常数时间
	//与vector一样，在deque首尾之外的位置插入元素会很耗时


	//在容器中的特定位置添加元素
	//vector、deque、list和string都支持insert成员

	//插入范围内元素
	//迭代器表示要拷贝的范围，不能指向添加元素的目标容器
	//list<int> ilist;
	//vector<int>  v = { 1, 2, 3, 4 };
	//auto i = ilist.insert(ilist.begin(), v.end() - 2, v.end());
	//cout << *i << endl;
	
	//使用insert的返回值
	//list<string> lst;
	//auto iter = lst.begin();
	//string word;
	//while (cin >> word)
	//{
	//	iter = lst.insert(iter, word);		//等价于push_front
	//} 
	//for (auto str : lst)
	//{
	//	cout << str << "   " << endl;
	//}

	//使用empalce操作
	//调用empalce成员函数，将参数值传递给元素类型的构造函数
	//empalce成员使用这些参数在容器管理的内存空间中直接构造元素（创造对象）
	//empalce函数的参数根据元素的类型而变化，参数必须与元素类型的构造函数相匹配。

	//vector<Sales_data> c;
	//Sales_data item1("88-XX", 5, 30.0);
	//c.push_back(item1);					//push_back将item拷贝到c中
	//c.emplace_back();					//使用Sales_data的默认构造函数在尾部构造一个元素
	//auto iter = c.begin();				//
	//c.emplace(iter, "897-XX");
	//c.emplace_back("896-XX");
	//for (auto item : c)
	//{
	//	print(cout, item);
	//}
	
	//ex9.18
	//deque<string> str_dq;
	//string str_temp;
	//while (cin >> str_temp)
	//{
	//	str_dq.push_back(str_temp);
	//}
	//for (auto str : str_dq)
	//{
	//	cout << str << "   ";
	//}

	//ex9.19
	//list<string> str_lst;
	//string str_temp;
	//while (cin >> str_temp)
	//{
	//	str_lst.push_back(str_temp);
	//}
	//for (auto str : str_lst)
	//{
	//	cout << str << "   ";
	//}

	//ex9.20
	//list<int> int_lst = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//deque<int> odd_dq, even_dq;
	//for (int i : int_lst)
	//{
	//	(i % 2 == 0 ? even_dq : odd_dq).push_back(i);
	//}
	//cout << "odd:\t";
	//for (int i : odd_dq)
	//{
	//	cout << i << "   ";
	//}
	//cout << "\neven:\t";
	//for (int i : even_dq)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;
	

	//ex9.21
	//vector<string> str_vec;
	//auto iter = str_vec.begin();
	//string word;
	//ifstream input;
	//input.open("Text.txt");
	//while (getline(input, word))
	//{
	//	iter = str_vec.insert(iter, word);		//等价于push_front
	//}
	//for (auto str : str_vec)
	//{
	//	cout << str << "   " << endl;
	//}


	//ex9.22
	vector<int> iv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	
	while (iter != mid)
	{
		if (*mid == 5)
		{
			mid = iv.insert(mid, 2 * 5);
			iter = iv.begin();
		}
		else
		{
			mid--;
		}
	}
	for (auto i : iv)
	{
		cout << i << "   ";
	}

}

//9.3


//9.3


//9.3




int main()
{
	//9.3.1 向顺序容器添加元素
	Fun_Adding_Elements_to_a_Sequential_Container();

	return 0;
}