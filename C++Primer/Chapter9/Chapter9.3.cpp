#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年11月9日 星期五
> Last edited time: 2018年12月6日 星期四
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


//9.3.2 访问元素
void Fun_Accessing_Elements()
{
	//在解引用一个迭代器或调用front或back之前检查是否有元素，确保容器非空
	//front和back返回首元素和尾元素的引用
	//vector<int> c = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//if (!c.empty())
	//{
	//	auto val1 = *c.begin(), val2 = c.front();
	//	auto last = c.end();
	//	auto val3 = *(--last);
	//	auto val4 = c.back();
	//}


	//at和下标操作只适用于string、vector、deque和array
	//c.at(n)返回下标为n的元素的引用。
	
	
	//访问成员函数返回的是引用
	//vector<int> c = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//if (!c.empty())
	//{
	//	c.front() = 42;
	//	auto &v = c.back();
	//	v = 1204;
	//	auto v2 = c.back();
	//	v2 = 0;
	//}
	//for (auto i : c)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;

	//下标操作和安全的随机访问
	//vector<int> c;
	//cout << c[0] << endl;
	//cout << c.at(0) << endl;

	//ex9.23
	//vector<int> c = {1};
	//if (!c.empty())
	//{
	//	auto val1 = *c.begin(), val2 = c.front();
	//	auto last = c.end();
	//	auto val3 = *(--last);
	//	auto val4 = c.back();
	//	cout << val1 << endl;
	//	cout << val2 << endl;
	//	cout << val3 << endl;
	//	cout << val4 << endl;
	//}
	//全都是1

	//ex9.24
	//vector<int> c = { 2 };
	//if (!c.empty())
	//{
	//	cout << c.at(0) << endl;
	//	cout << c[0] << endl;
	//	cout << c.front() << endl;
	//	cout << *c.begin() << endl;
	//}

}


//9.3.3 删除元素
void Fun_Erasing_Elements()
{
	//pop_front和pop_back成员你函数
	//list<int> ilist = { 1, 2, 3, 4 };
	//while (!ilist.empty())
	//{
	//	cout << ilist.back() << "   ";
	//	ilist.pop_back();
	//}

	//从容器内部删除一个元素esrse
	//list<int> ilist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//auto iter = ilist.begin();
	//while (iter != ilist.end())
	//{
	//	if (*iter % 2)
	//		iter = ilist.erase(iter);
	//	else
	//		iter++;
	//}

	//删除多个元素
	//list<string> slist;
	//slist.clear();
	//slist.erase(slist.begin(), slist.end());

	//ex25
	//vector<string> svec = { "hello", "world", "C++", "Primer" };
	////slist.clear();
	//auto elem1 = svec.begin();
	//auto elem2 = svec.end();
	//auto iter = svec.erase(elem1, elem1);        //调用之后iter == slist.begin()
	//cout << *iter << endl;

	//ex26
	//int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	//list<int> evenlst;
	//vector<int> oddvec;
	//for (int i = 0; i != 11; ++i)
	//{
	//	evenlst.push_back(ia[i]);
	//	oddvec.push_back(ia[i]);
	//}
	//for (auto iter = evenlst.begin(); iter != evenlst.end(); )
	//{

	//	if (*iter % 2 == 0)
	//		iter = evenlst.erase(iter);
	//	else
	//	{
	//		iter++;
	//	}
	//}
	//for (auto iter = evenlst.begin(); iter != evenlst.end(); iter++)
	//{
	//	cout << *iter << "   ";
	//}
	//cout << "\n==========================" << endl;
	//for (auto iter = oddvec.begin(); iter != oddvec.end();)
	//{

	//	if (*iter % 2 != 0)
	//		iter = oddvec.erase(iter);
	//	else
	//	{
	//		iter++;
	//	}
	//}
	//for (auto iter = oddvec.begin(); iter != oddvec.end(); iter++)
	//{
	//	cout << *iter << "   ";
	//}

}


void fuc_ex9_28(forward_list<string> str_flst, string str1, string str2)
{
	auto prev = str_flst.before_begin();
	auto curr = str_flst.begin();
	while (curr != str_flst.end())
	{
		if (*curr != str1)
		{
			prev = curr;
			++curr;
		}
		else
		{
			str_flst.insert_after(curr, str2);
			break;
		}
	}
	if (curr == str_flst.end())
		str_flst.insert_after(prev, str2);

	for (auto str : str_flst)
	{
		cout << str << endl;
	}
}
//9.3.4 特殊的forward_list操作
void Fun_Specialized_forward_list_Operations()
{
	//forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	//vector<int> ivec = { 5,5,5,5,5 };
	//auto prev = flst.before_begin();			//表示flst的“首前元素”
	//auto curr = flst.begin();					//表示flst中的第一个元素
	//flst.insert_after(prev, 5);
	//flst.insert_after(prev, 5, 0);
	//flst.insert_after(prev, ivec.begin(), ivec.end());
	//flst.insert_after(prev, { 1,2,3,4,5 });

	//while (curr != flst.end())
	//{
	//	if (*curr % 2)
	//		curr = flst.erase_after(prev);
	//	else
	//	{
	//		prev = curr;
	//		++curr;
	//	}
	//}
	//for (int i : flst)
	//{
	//	cout << i << "  ";
	//}
	//cout << endl;
	//"=====================" << endl;
	
	//ex9.27
	//forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	//auto prev = flst.before_begin();
	//auto curr = flst.begin();
	//while (curr != flst.end())
	//{
	//	if (*curr % 2)
	//		curr = flst.erase_after(prev);
	//	else
	//	{
	//		prev = curr;
	//		++curr;
	//	}
	//}
	//for (int i : flst)
	//{
	//	cout << i << "  ";
	//}
	//cout << endl;

	//ex9.28
	forward_list<string> str_flst = { "hello","world","C++","5th" };
	string str1 = "C++",str2 = "primer";
	fuc_ex9_28(str_flst, str1, str2);
}


//9.3.5 改变容器大小
void Fun_Resizing_a_Container()
{
	//list<int> ilist(10, 42);
	//ilist.resize(15);
	//ilist.resize(15, 5);
	//ilist.resize(5);

	//for (auto i : ilist)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;

	//ex9.29
	//vec容器大小首先变成100，包含25个原来的值和75个0；之后变成10，后面的元素会被删除，vec变成10个原来的值

	//ex9.30
	//如果元素类型是类类型，这必须初始化，或必须有默认构造函数

}


template <class T> 
void Myprint(T & container)
{
	//打印容器中的元素
	for (auto i : container)
	{
		cout << i << "  ";
	}
	cout << endl;
}


//9.3.6 容器操作可能是迭代器失效
void Fun_Container_Operations_May_Invalidate_Iterators()
{
	//编写改变容器的循环程序
	//vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	//auto iter = vi.begin();
	//while (iter != vi.end())
	//{
	//	if (*iter % 2)
	//	{
	//		iter = vi.insert(iter, *iter);		//在iter指向的元素之前插入新元素，然后返回指向新元素的迭代器
	//		iter += 2;							//跳过当前元素和插入到它之前的迭代器
	//	}
	//	else
	//	{
	//		iter = vi.erase(iter);				//删除偶数元素，返回指向删除元素之后元素的迭代器
	//	}
	//}
	//Myprint(vi);

	//不要保存end返回的迭代器
	//auto begin = vi.begin();
	//while (begin != vi.end())					//必须在每次循环操作之后重新调用end()	
	//{
	//	++begin;
	//	begin = vi.insert(begin, 42);			//在begin之前插入42，返回的begin指向42
	//	++begin;
	//}
	//Myprint(vi);

	//ex9.31
	//list<int> ilist = { 0,1,2,3,4,5,6,7,8,9 };
	//auto iter = ilist.begin();
	//while (iter != ilist.end())
	//{
	//	if (*iter % 2)
	//	{
	//		iter = ilist.insert(iter, *iter);		
	//		advance(iter, 2);
	//	}
	//	else
	//	{
	//		iter = ilist.erase(iter);				
	//	}
	//}
	//Myprint(ilist);

	//cout << "====================================================" << endl;

	//forward_list<int> iflist = { 0,1,2,3,4,5,6,7,8,9 };
	//auto prev =iflist.before_begin(), curr = iflist.begin();
	//while (curr != iflist.end())
	//{
	//	if (*curr % 2)
	//	{
	//		curr = iflist.insert_after(prev, *curr);
	//		advance(curr, 2);
	//		advance(prev, 2);
	//	}
	//	else
	//	{
	//		curr = iflist.erase_after(prev);
	//	}
	//}
	//Myprint(iflist);

	//ex9.32
	// ++高于*解引用符号，复制的是奇数后面的一个数，
	//此处验证下，实际插入的还是奇数元素，
	
	//ex9.33
	//崩溃，插入后迭代器失效

	//ex9.34
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();
	while (iter != vi.end())
	{
		if (*iter % 2)
		{
			iter = vi.insert(iter, *iter);
			iter += 2;
		}
		else
		{
			iter++;
		}
	}
	Myprint(vi);
}

int main()
{
	//9.3.1 向顺序容器添加元素
	//Fun_Adding_Elements_to_a_Sequential_Container();
	//9.3.2 访问元素
	//Fun_Accessing_Elements();
	//9.3.3 删除元素
	//Fun_Erasing_Elements();
	//9.3.4 特殊的forward_list操作
	//Fun_Specialized_forward_list_Operations();
	//9.3.5 改变容器大小
	//Fun_Resizing_a_Container();
	//9.3.6 容器操作可能是迭代器失效
	Fun_Container_Operations_May_Invalidate_Iterators();
	return 0;
}