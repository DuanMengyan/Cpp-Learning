#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年09月06日 星期四
> Last edited time: 2018年9月07日 星期五
> Topic:C++Primer Chapter6.2 参数传递
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;

//ex6.10
void swap_pointer(int *num1,int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//ex6.12
void swap_reference(int &num1,int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

//6.2.1 传值参数
void Fun_Passing_Arguments_by_Value()
{
	//指针形参
	//int n = 0, i = 42;
	//int *p = &n, *q = &i;
	//*p = 42;
	//p = q;
	//cout << n << endl;
	//cout << *p << "   " << *q << endl;


	//ex6.10
	//int i = 42, j = 30;
	//int *p1 = &i, *p2 = &j;
	//swap_reference(i,j);		//通过引用交换值
	//swap_pointer(p1, p2);		//通过指针交换值
	//cout << "i = " << i << "    j = " << j << endl;
}

//6.2.2 使用引用避免拷贝
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() > s2.size();
}

//6.2.2 使用引用形参返回额外信息
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto pos = s.size();
	occurs = 0;
	for (decltype(pos) i = 0; i != s.size(); ++i)
	{
		if (s[i] == c)
		{
			if (pos == s.size()) pos = i;
			++occurs;
		}
	}
	return pos+1;
}

//6.2.2 传引用参数
void Fun_Passing_Arguments_by_Reference()
{

	//int n = 0, i = 42;
	//int &r = n;
	//r = 42;				//n = 42
	//r = i;				//n = 42;
	//i = r;				//i = 42;
	//cout << n << "   " << i << endl;
	

	//使用引用避免拷贝
	//string  str1 = "hello", str2 = "world";
	//cout << std::boolalpha << isShorter(str1, str2) << endl;


	//使用引用形参返回额外信息
	//string str1 = "helloworldhelloworldhelloworld";
	//char c = 'o';
	//string::size_type ctr = 0;
	////string::size_type &num = ctr;
	//
	//cout << c << " first occors at " << find_char(str1, c, ctr) << "," << endl;
	//cout<<"and totally occors "<< ctr << " times" << endl;			//求值顺序


	//ex6.14
	//在肯定会修改实参内容，而这种修改又不能影响原变量的情况下，形参不适合用引用。
	//bool read_file_in(string path, const string &file, string &out)
	//{
	//	path += "/" + file;
	//	return read_file(path, out);
	//}
	//第一个参数path不用引用更好一点
	
	//vector<int> ivec = { 0, 1, 2, 3, 4, 5, 6 };
	//print(ivec.begin(), ivec.end());
}


//ex6.17判断大写字母
bool any_capital(const string & str)
{
	for (auto c : str)
	{
		if (isupper(c)) return true;
	}
	return false;
}
//ex6.17改写小写形式
void to_lowercase(string &str)
{
	for (auto &c : str)
	{
		if (isupper(c)) c = tolower(c);
	}
}

//6.2.3 const形参和实参
void Fun_const_Parameters_and_Arguments()
{
	//const int ci = 42;
	//int i = ci;
	//int * const p = &i;
	//*p = 0;

	//指针或引用形参与const
	//和其他初始化过程一样，当用实参初始化形参时会忽略掉顶层const。
	//当形参有顶层const时，传给常量对象或者非常量对象都是可以的
	//不能使用字面值初始化一个非常量引用

	//尽量使用常量引用
	//函数不会改变的形参定义成普通引用会给函数调用者带来可以修改该形参的值得误导
	//会限制函数所能接受的实参类型


	//ex6.17
	string str = "Hello World";
	to_lowercase(str);
	cout << str << endl;
	cout << std::boolalpha << any_capital(str) << endl;

	//ex6.18
	//bool compare(matrix &m1, matrix &m2);
	//vector<int>::iterator change_val(int, vector<int>::iterator);

	//ex6.20
	//当函数不改变形参值时，应该是常量引用；
	//会误导函数调用者以为可以修改形参的值；
}

//6.2.4 显示传递一个表示数组大小的形参
void print_array(const int ia[],size_t size)
{
	for (size_t i = 0; i != size; ++i)
	{
		cout << ia[i] << endl;
	}

}

//ex6.21
int int_compare(const int val, const int *p)
{
	return (val > *p ? val : *p);
}

//ex6.22
void change_pointer(int* &p1,int * &p2)
{
	int* temp = p1;
	p1 = p2;
	p2 = temp;
}

//ex6.23
//void print(const int *p)
//{
//	cout << "print1:  ";
//	if (p)
//		cout << *p << endl;
//}

void print(const char *p)
{
	cout << "print2:  ";
	if (p)
		while (*p) cout << *p++<<"  ";
	cout << endl;
}

void print(const int (&arr)[2])
{
	cout << "print3:  ";
	for (auto beg = begin(arr) ; beg != end(arr); ++beg)
	{
		cout << *beg << "  ";
	}
	cout << endl;
}

void print(const int *beg, const int *end)
{
	cout << "print4:  ";
	while (beg != end)
	{
		cout << *beg++ << "  ";
	}
	cout << endl; 
}

void print(const int arr[], size_t size)
{
	cout << "print5:  ";
	for (size_t i = 0; i != size; ++i)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
//6.2.4 数组形参
void Fun_Array_Parameters()
{
	//因为数组会被转换成指针，所以当我们为函数传递一个数组时，实际上传递的是指向数组首元素的指针
	//尽管不能以值传递的方式传递数组，但是我们可以把形参写成类似数组的形式

	//如果传给函数的是一个数组，则实参自动转换成指向数组首元素的指针，数组的大小对函数的调用没有影响

	//使用标记指定数组长度(C风格字符串的结尾空白字符)
	//使用标准库规范(begin(a),end(a))
	//显示传递一个表示数组大小的形参
	//int j[] = { 0, 1 };
	//print_array(j, end(j) - begin(j));


	//数组形参和const
	//只有当函数确实要改变元素值的时候，才把形参定义为指向非常量的指针

	//数组引用形参
	//传递多维数组
	//matrix指向数组的首元素，该数组的元素是由10个整数构成的数组
	//void print(int(*matrix)[10], int rowSize);
	//等价定义 matrix看起来是一个二维数组，实际上形参是指向含有10个整数的数组的指针
	//void print(int matrix[][10], int rowSize);

	//ex6.21
	//int num1 = 5, num2 = 6;
	//int *p = &num2;
	//cout << int_compare(num1, p) << endl;


	//ex6.22
	//int val1 = 5, val2 = 6;
	//auto p1 = &val1, p2 = &val2;
	//change_pointer(p1, p2);
	//cout << *p1 << "   " << *p2 << endl;

	//ex6.23
	int i = 0, j[2] = { 0, 1 };
	char ch[5] = "pezy";

	//print(&i);				//void print(const int *p)
	print(ch);					//void print(const char *p)
	print(j);					//void print(const int (&arr)[2])
	print(begin(j), end(j));	//void print(const int *beg, const int *end)
	print(j,2);					//void print(const int arr[], size_t size)
	
}



int main()
{
	//6.2.1 传值参数
	//Fun_Passing_Arguments_by_Value();
	//6.2.2 传引用参数
	//Fun_Passing_Arguments_by_Reference();
	//6.2.3 const形参和实参
	//Fun_const_Parameters_and_Arguments();
	//6.2.4 数组形参
	Fun_Array_Parameters();

	return 0;
}