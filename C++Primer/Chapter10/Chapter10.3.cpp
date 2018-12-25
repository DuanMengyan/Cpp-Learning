#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��12��17�� ����һ
> Last edited time: 2018��12��25�� ���ڶ�
> Topic:C++Primer Chapter10.3 ���Ʋ���
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"

using namespace std;

//10.3 ���Ʋ���
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
	//���Ȱ����ֵ�������֮��ȥ�����������ظ�����ɾ�����������ظ�Ԫ��
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


//10.3.1 ���㷨���ݺ���
void Fun_Passing_a_Function_to_an_Algorithm()
{
	//ν��
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	//printitem(words);
	////�ǵ����г���Ϊ3�ĵ������ڳ���Ϊ4�ĵ���֮ǰ��Ȼ���ǳ���Ϊ5�ĵ��ʣ��������ơ�
	//sort(words.begin(), words.end());
	//printitem(words);
	//sort(words.begin(), words.end(), isShorter);
	//printitem(words);
	
	
	//�����㷨
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	////��word���ֵ����������򣬲������ظ�����
	//MyelimDups(words);
	//printitem(words);
	////���ճ����������򣬳�����ͬ�ĵ���ά���ֵ���
	////����stable_sort�ȶ������㷨ά�����Ԫ�ص�ԭ��˳��
	//stable_sort(words.begin(), words.end(), isShorter);
	//printitem(words);
	
	//ex10.11
	
	//ex10.12
	//vector<Sales_data> vec;
	//Sales_data item;
	////���ļ��ж�ȡSales_data���ݲ����浽vec��
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
	////�Ƚ����������isbn��ʹ�øú�����������
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
	MyelimDups(words);	//��words���ֵ�������ɾ���ظ�����
	cout << "dict_sorted:\t"; printitem(words);
	//���������򣬳�����ͬ�ĵ���ά���ֵ���
	stable_sort(words.begin(), words.end(), [](const string &str1, const string &str2) {return str1.size() < str2.size(); });
	cout << "stable_sorted:\t"; printitem(words);
	//����һ��lambda
	auto f = [sz](const string &str) {return str.size() >= sz; };
	//��ȡһ����������ָ���һ������size()>=sz��Ԫ��
	auto wc = find_if(words.begin(), words.end(), f);
	//auto wc = stable_partition(words.begin(), words.end(), f);
	//��������size()>=sz��Ԫ����Ŀ
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer " << endl;
	cout << "=============================" << endl;
	//��ӡ���ȴ��ڵ��ڸ���ֵ�ĵ��ʣ�ÿ�����ʺ����һ���ո�
	for_each(wc, words.end(), [](const string &str) {cout << str << "   "; });
	cout << endl << "=============================" << endl;
}

//10.3.2 Lambda���ʽ
void Fun_Lambda_Expressions()
{

	//find_if�㷨����һ�Ե���������ʾһ����Χ��������������һ��ν�ʡ�
	//���ص�һ��ʹν�ʷ��ط�0ֵ��Ԫ�أ���������ڣ�����β������

	//����lambda
	//һ��lambda���ʽ��ʾһ���ɵ��õĴ��뵥Ԫ�����ǿ��Խ������Ϊһ��δ��������������
	//lambda���κκ������ƣ����ǿ��Զ����ں����ڲ���lambda����ʹ��β�÷���
	//���ǿ��Ժ��Բ����б�ͷ������ͣ���������Զ���������б�(ͨ��Ϊ��)�ͺ�����
	//auto f = []() -> int { return 42; };
	//cout << f() << endl;		//��ӡ42
	//������Է������ͣ���lambda�ĺ�����ֻ��һ��return��䣬�򷵻����ʹӷ��صı��ʽ�������ƶ϶�����������Ϊvoid
	//lambda�ĺ���������κε�һreturn���֮������ݣ���δָ���������ͣ��򷵻�void

	//��lambda���ݲ���
	//lambda������Ĭ�ϲ�����һ��lambda���õ�ʵ����Ŀ��Զ�����β���Ŀ
	//һ����isShorter���������ͬ���ܵ�lambda
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

	//ʹ�ò����б�
	//һ��lambdaֻ�����䲶���б��в���һ�������ں����ľֲ������������ں�������ʹ�øñ���

	//����find_if
	//ʹ�ô�lambda�����ǾͿ��Բ��ҵ�һ�����ȴ��ڵ���sz��Ԫ��
	//��ȡһ����������ָ���һ������size()>=sz��Ԫ��
	//for_each�㷨

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
	////�Ƚ����������isbn��ʹ�øú�����������
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

//���ò�������
void biggies2(vector<string> &words, vector<string>::size_type sz, ostream &os , char c = ' ')
{
	MyelimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &str1, const string &str2) {return str1.size() < str2.size(); });
	cout << "stable_sorted:\t"; printitem(words);
	//����һ��lambda
	auto f = [sz](const string &str) {return str.size() >= sz; };
	//��ȡһ����������ָ���һ������size()>=sz��Ԫ��
	auto wc = find_if(words.begin(), words.end(), f);
	//auto wc = stable_partition(words.begin(), words.end(), f);
	//��������size()>=sz��Ԫ����Ŀ
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
	//����һ��lambda
	auto f = [sz](const string &str) {return str.size() >= sz; };
	//ͳ��size()>=szΪ��Ĵ���
	auto num = count_if(words.begin(), words.end(), f);
	//��������size()>=sz��Ԫ����Ŀ
	cout << num << " " << make_plural(num, "word", "s")
		<< " of length " << sz << " or longer " << endl;
	cout << "=============================" << endl;
}

//10.3.3 lambda����ͷ���
void Fun_Lambda_Captures_and_Returns()
{
	//ֵ����
	//�����������ֵ����lambda����ʱ����������������޸Ĳ���Ӱ�쵽lambda�ڱ�����ֵ
	//size_t v1 = 42;
	//auto f = [v1] {return v1; };
	//v1 = 0;
	//auto j = f();
	//cout << j << endl;
	//
	////���ò���
	////����ȷ�������õĶ�����lambdaִ�е�ʱ����Ȼ����
	//size_t v2 = 42;
	//auto f2 = [&v2] {return v2; };
	//v2 = 0;
	//auto j2 = f2();
	//cout << j2 << endl;

	//lambda����һ��ostream������
	//IO�����޿�����ֵ������IO�����ĺ���ͨ�������÷�ʽ���ݺͷ�������
	//lambda��Ҳ�����,����os��Ψһ�������ǲ��������ã���ָ��os��ָ�룩
	
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

	//�����������lambda����lambdaҲ���ܰ������ò���
	//�������÷�ʽ����һ������ʱ�����뱣֤lambdaִ��ʱ�����Ǵ��ڵ�

	//��ʽ����
	//�ɱ�lambda
	//�ڲ����б��׼��Ϲؼ���mutable�����Ըı䱻���������ֵ
	//size_t v1 = 42;
	//auto f = [v1]() mutable {return ++v1; };
	//v1 = 0;
	//auto j = f();
	//cout << j << "   " << v1<<endl;				//43   0
	//���ò���ı����Ƿ�����޸������ڴ�����ָ�����һ��const���ͻ���һ����const���͡�

	//ָ��lambda��������
	//vector<int> vi = { -1,2,-3,4,-5,6,-7,8,-9,8 };
	//transform(vi.begin(), vi.end(), vi.begin(), [](int i) {return i < 0 ? -i : i; });
	//printitem(vi);

	//lambda���巵������ʱ������ʹ��β�÷�������
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
	//10.3.1 ���㷨���ݺ���
	//Fun_Passing_a_Function_to_an_Algorithm();
	//10.3.2 Lambda���ʽ
	//Fun_Lambda_Expressions();
	//10.3.3 lambda����ͷ���
	//Fun_Lambda_Captures_and_Returns();
	return 0;
}