#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年12月17日 星期一
> Last edited time: 2018年12月25日 星期二
> Topic:C++Primer Chapter10.3 定制操作
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"

using namespace std;

//10.3 定制操作
template<typename Container>
void printitem(Container const& con)
{
	for (auto const &item : con)
	{
		cout << item << "   ";
	}
	cout << endl << "=============================" << endl;;
}

inline bool 
isShorter(const string &s1,const string &s2)
{
	return s1.size() < s2.size();
}

//ex10.11
void MyelimDups(vector<string> &words)
{
	//首先按照字典序排序，之后去除消除相邻重复项，最后删除排在最后的重复元素
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

//ex10.12
inline bool
compareIsbn(const Sales_data &item1,const Sales_data &item2)
{
	return item1.isbn() < item2.isbn();
}

//ex10.13
inline bool
stringsize(const string &str)
{
	return str.size() >= 5;
}


//10.3.1 向算法传递函数
void Fun_Passing_a_Function_to_an_Algorithm()
{
	//谓词
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	//printitem(words);
	////是的所有长度为3的单词排在长度为4的单词之前，然后是长度为5的单词，依次类推。
	//sort(words.begin(), words.end());
	//printitem(words);
	//sort(words.begin(), words.end(), isShorter);
	//printitem(words);
	
	
	//排序算法
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	////将word按字典序重新排序，并消除重复单词
	//MyelimDups(words);
	//printitem(words);
	////按照长度重新排序，长度相同的单词维持字典序
	////类似stable_sort稳定排序算法维持相等元素的原有顺序
	//stable_sort(words.begin(), words.end(), isShorter);
	//printitem(words);
	
	//ex10.11
	
	//ex10.12
	//vector<Sales_data> vec;
	//Sales_data item;
	////从文件中读取Sales_data数据并保存到vec中
	//ifstream input("Text10.3.txt");
	//while (read(input,item))
	//{
	//	vec.push_back(item);
	//}
	//for (auto &book : vec)
	//{
	//	print(cout, book);
	//}
	//cout << "==========================" << endl;
	////比较两个对象的isbn，使用该函数进行排序
	//sort(vec.begin(), vec.end(), compareIsbn);
	//for (auto &book : vec)
	//{
	//	print(cout, book);
	//}
	//cout << "==========================" << endl;

	//ex10.13
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	//printitem(words);
	//auto flag = partition(words.begin(), words.end(), stringsize);
	//printitem(words);
	//auto iter = words.cbegin();
	//while (iter != flag)
	//{
	//	cout << *iter << "   ";
	//	++iter;
	//}
	//cout << endl;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	MyelimDups(words);	//将words按字典序排序，删除重复单词
	cout << "dict_sorted:\t"; printitem(words);
	//按长度排序，长度相同的单词维持字典序
	stable_sort(words.begin(), words.end(), [](const string &str1, const string &str2) {return str1.size() < str2.size(); });
	cout << "stable_sorted:\t"; printitem(words);
	//定义一个lambda
	auto f = [sz](const string &str) {return str.size() >= sz; };
	//获取一个迭代器，指向第一个满足size()>=sz的元素
	auto wc = find_if(words.begin(), words.end(), f);
	//auto wc = stable_partition(words.begin(), words.end(), f);
	//计算满足size()>=sz的元素数目
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer " << endl;
	cout << "=============================" << endl;
	//打印长度大于等于给定值的单词，每个单词后面接一个空格
	for_each(wc, words.end(), [](const string &str) {cout << str << "   "; });
	cout << endl << "=============================" << endl;
}

//10.3.2 Lambda表达式
void Fun_Lambda_Expressions()
{

	//find_if算法接受一对迭代器，表示一个范围，第三个参数是一个谓词。
	//返回第一个使谓词返回非0值得元素，如果不存在，返回尾迭代器

	//介绍lambda
	//一个lambda表达式表示一个可调用的代码单元。我们可以将其理解为一个未命名的内联函数
	//lambda与任何函数类似，但是可以定义在函数内部，lambda必须使用尾置返回
	//我们可以忽略参数列表和返回类型，但必须永远包含捕获列表(通常为空)和函数体
	//auto f = []() -> int { return 42; };
	//cout << f() << endl;		//打印42
	//如果忽略返回类型，且lambda的函数体只是一个return语句，则返回类型从返回的表达式的类型推断而来；否则。则为void
	//lambda的函数体包含任何单一return语句之外的内容，且未指定返回类型，则返回void

	//向lambda传递参数
	//lambda不能有默认参数，一个lambda调用的实参数目永远等于形参数目
	//一个与isShorter函数完成相同功能的lambda
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	//printitem(words);
	//auto lambda_f = [](const string &str1, const string &str2) {return str1.size() < str2.size(); };
	//
	//MyelimDups(words);
	//printitem(words);
	//stable_sort(words.begin(), words.end(), lambda_f);
	//printitem(words);

	//使用捕获列表
	//一个lambda只有在其捕获列表中捕获一个它所在函数的局部变量，才能在函数体中使用该变量

	//调用find_if
	//使用此lambda，我们就可以查找第一个长度大于等于sz的元素
	//获取一个迭代器，指向第一个满足size()>=sz的元素
	//for_each算法

	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	//cout << "original:\t"; printitem(words);
	//biggies(words, 5);

	//ex10.14
	//auto f = [](const int &num1, const int &num2) -> int {return num1 + num2; };
	
	//ex10.15
	//int value = 5;
	//[value](const int &num) {return num + value; };
	
	//ex10.16
	
	//ex10.17
	//ifstream input("Text10.3.txt");
	//Sales_data item;
	//vector<Sales_data> vec;
	//while (read(input,item))
	//{
	//	vec.push_back(item);
	//}
	//for (auto book : vec)
	//{
	//	print(cout, book);
	//}
	//cout << "==========================" << endl;
	////比较两个对象的isbn，使用该函数进行排序
	//auto lam = [](const Sales_data &item1, const Sales_data &item2) {return item1.isbn() < item2.isbn(); };
	//sort(vec.begin(), vec.end(), lam);
	//for (auto &book : vec)
	//{
	//	print(cout, book);
	//}
	//cout << "==========================" << endl;

	//ex10.18
	
	//ex10.19
	
}

//引用捕获例子
void biggies2(vector<string> &words, vector<string>::size_type sz, ostream &os , char c = ' ')
{
	MyelimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &str1, const string &str2) {return str1.size() < str2.size(); });
	cout << "stable_sorted:\t"; printitem(words);
	//定义一个lambda
	auto f = [sz](const string &str) {return str.size() >= sz; };
	//获取一个迭代器，指向第一个满足size()>=sz的元素
	auto wc = find_if(words.begin(), words.end(), f);
	//auto wc = stable_partition(words.begin(), words.end(), f);
	//计算满足size()>=sz的元素数目
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer " << endl;
	cout << "=============================" << endl;
	for_each(words.begin(), words.end(), [&os, c](const string &s) { os << s << c << endl; });
}

//ex10.20
void biggies3(vector<string> &words, vector<string>::size_type sz)
{
	MyelimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &str1, const string &str2) {return str1.size() < str2.size(); });
	cout << "stable_sorted:\t"; printitem(words);
	//定义一个lambda
	auto f = [sz](const string &str) {return str.size() >= sz; };
	//统计size()>=sz为真的次数
	auto num = count_if(words.begin(), words.end(), f);
	//计算满足size()>=sz的元素数目
	cout << num << " " << make_plural(num, "word", "s")
		<< " of length " << sz << " or longer " << endl;
	cout << "=============================" << endl;
}

//10.3.3 lambda捕获和返回
void Fun_Lambda_Captures_and_Returns()
{
	//值捕获
	//被捕获变量的值是在lambda创建时拷贝，因此随后对其修改不会影响到lambda内变量的值
	//size_t v1 = 42;
	//auto f = [v1] {return v1; };
	//v1 = 0;
	//auto j = f();
	//cout << j << endl;
	//
	////引用捕获
	////必须确保被引用的对象在lambda执行的时候仍然存在
	//size_t v2 = 42;
	//auto f2 = [&v2] {return v2; };
	//v2 = 0;
	//auto j2 = f2();
	//cout << j2 << endl;

	//lambda接受一个ostream的引用
	//IO对象无拷贝或赋值，进行IO操作的函数通常以引用方式传递和返回流，
	//lambda中也是如此,捕获os的唯一方法就是捕获其引用（或指向os的指针）
	
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	//cout << "original:\t"; printitem(words);
	//ofstream  output("Text10.2.2.txt");
	//biggies2(words, 5, output);
	//output.close();

	//如果函数返回lambda，此lambda也不能包含引用捕获
	//当以引用方式捕获一个变量时，必须保证lambda执行时变量是存在的

	//隐式捕获
	//可变lambda
	//在参数列表首加上关键字mutable，可以改变被捕获变量的值
	//size_t v1 = 42;
	//auto f = [v1]() mutable {return ++v1; };
	//v1 = 0;
	//auto j = f();
	//cout << j << "   " << v1<<endl;				//43   0
	//引用捕获的变量是否可以修改依赖于此引用指向的是一个const类型还是一个非const类型。

	//指定lambda返回类型
	//vector<int> vi = { -1,2,-3,4,-5,6,-7,8,-9,8 };
	//transform(vi.begin(), vi.end(), vi.begin(), [](int i) {return i < 0 ? -i : i; });
	//printitem(vi);

	//lambda定义返回类型时，必须使用尾置返回类型
	//vector<int> vi = { -1,2,-3,4,-5,6,-7,8,-9,8 };
	//transform(vi.begin(), vi.end(), vi.begin(), [](int i) -> int { if (i < 0)return  -i; else return i; });
	//printitem(vi);


	//ex10.20
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	//cout << "original:\t"; printitem(words); 
	//biggies3(words, 5);
	
	
	
	//ex10.21
	//int num = 10;
	//auto f = [&num]()->bool { if (num == 0) return true; else { num--; return false; }};
	//for (int i = 0; i < 13; i++)
	//{
	//	cout << f() << "  " << num << endl;
	//}

}




int main()
{
	//10.3.1 向算法传递函数
	//Fun_Passing_a_Function_to_an_Algorithm();
	//10.3.2 Lambda表达式
	//Fun_Lambda_Expressions();
	//10.3.3 lambda捕获和返回
	//Fun_Lambda_Captures_and_Returns();
	return 0;
}