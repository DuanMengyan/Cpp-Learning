#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年12月13日 星期四
> Last edited time: 2018年12月13日 星期四
> Topic:C++Primer Chapter10.2 初识泛型算法
************************************************************************/

#include "header_include.h"

using namespace std;

//Chapter10.2 初识泛型算法

//Chapter10.2.1 只读算法
void Fun_Read_Only_Algorithms()
{
	//accumulate算法定义在头文件numeric中，accumulate函数接受三个参数，前两个指出了需要求和的元素范围，第三个值是和的初值。
	//第三个参数的类型决定了函数中使用哪个加法运算符及返回值得类型。

	//算法和元素类型
	//accumulate()函数用来连接字符串，第三个参数要显式创建一个string。
	//对于只读取而不改变元素的算法，通常最好使用cbegin()和cend()。
	
	//操作两个序列的算法
	//equal用于确定两个序列是否保存相同的值；三个参数前两个表示第一个序列的元素范围，最后一个表示第二个序列的首元素
	//元素类型不必一样，只要能用==来比较两个元素类型即可

	//ex10.3
	//vector<int> ivec = { 1,2,3,4,5,6,7,8,9,10 };
	//int sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
	//cout << sum << endl;

	//ex10.4
	//double自动进行类型转换，变成int类型，损失精度。

	//ex10.5
	//一切正常，但是C风格字符串的比较最好还是利用strcmp()
	

}

//Chapter10.2.2 写容器元素的算法
void Fun_Algorithms_That_Write_Container_Elements()
{
	//fill接受一对迭代器，将给定的值赋予输入序列中的每个元素
	//vector<int> ivec(10);
	//fill(ivec.begin(), ivec.end(), 10);
	//for (auto i : ivec)
	//{
	//	cout << i << endl;
	//}

	//算法不检查写操作
	//vector<int> ivec(10);
	//fill_n(ivec.begin(), ivec.size(), 10);
	//for (auto i : ivec)
	//{
	//	cout << i << endl;
	//}

	//介绍back_inserter，定义在头文件iterater
	//插入迭代器是一种向容器添加元素的迭代器，当我们通过一个插入迭代器赋值时，一个与赋值号右侧值相等的元素添加进容器
	//vector<int> vec;
	//fill_n(back_inserter(vec), 10, 5);
	//for (auto i : vec)
	//{
	//	cout << i << endl;
	//}

	//拷贝算法
	//copy将输入范围中的元素拷贝到输出序列中,返回的是其目的位置迭代器(递增后)的值，即输出序列尾元素后的值。
	//int a1[] = { 0,1,2,3,4,5,6,7,8,9 };
	//cout << sizeof(a1) << endl;
	//int a2[sizeof(a1) / sizeof(*a1)];		//a2与a1大小一致(40/4=10)

	//auto ret = copy(begin(a1), end(a1), a2);		//把a1的内容拷贝给a2

	//replace算法读入一个序列，并将其中所有等于给定值的元素都改为另一个值
	//vector<int> ivec;
	//list<int> ilist = { 0,1,2,4,0,2,3,0,1,2,5 };
	//replace(ilist.begin(), ilist.end(), 0, 42);
	//ivec包含一份ilist的拷贝，第三个参数之处调整后序列的保存位置
	//replace_copy(ilist.cbegin(), ilist.cend(), back_inserter(ivec), 0, 9);
	//for (auto i : ilist)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;
	//for (auto i : ivec)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;

	//ex10.6
	//vector<int> ivec = { 0,1,2,4,0,2,3,0,1,2,5 };
	//fill_n(ivec.begin(), ivec.size(), 0);

	//ex10.7
	//(a)
	//vector<int> vec; list<int> lst; int i;
	//while (cin >> i)
	//{
	//	lst.push_back(i);
	//}
	//vec.resize(lst.size());			//需要重新调整一下容器大小
	//copy(lst.cbegin(), lst.cend(), vec.begin());
	//for (auto i : vec)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;

	//(b)
	//vector<int> vec;
	//vec.resize(10);					//reverse分配内存，但是并不调整容器大小
	//fill_n(vec.begin(), 10, 2);
	//for (auto i : vec)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;
	//ex10.8
	//back_inserter来自头文件iterater,而不是algorithm

}

//Chapter10.2.3



int main()
{
	//Chapter10.2.1
	//Fun_Read_Only_Algorithms();
	//Chapter10.2.2 写容器元素的算法
	Fun_Algorithms_That_Write_Container_Elements();

	
	return 0;
}
