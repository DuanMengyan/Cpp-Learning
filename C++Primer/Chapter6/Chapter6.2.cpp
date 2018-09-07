#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��09��06�� ������
> Last edited time: 2018��9��07�� ������
> Topic:C++Primer Chapter6.2 ��������
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

//6.2.1 ��ֵ����
void Fun_Passing_Arguments_by_Value()
{
	//ָ���β�
	//int n = 0, i = 42;
	//int *p = &n, *q = &i;
	//*p = 42;
	//p = q;
	//cout << n << endl;
	//cout << *p << "   " << *q << endl;


	//ex6.10
	//int i = 42, j = 30;
	//int *p1 = &i, *p2 = &j;
	//swap_reference(i,j);		//ͨ�����ý���ֵ
	//swap_pointer(p1, p2);		//ͨ��ָ�뽻��ֵ
	//cout << "i = " << i << "    j = " << j << endl;
}

//6.2.2 ʹ�����ñ��⿽��
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() > s2.size();
}

//6.2.2 ʹ�������βη��ض�����Ϣ
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

//6.2.2 �����ò���
void Fun_Passing_Arguments_by_Reference()
{

	//int n = 0, i = 42;
	//int &r = n;
	//r = 42;				//n = 42
	//r = i;				//n = 42;
	//i = r;				//i = 42;
	//cout << n << "   " << i << endl;
	

	//ʹ�����ñ��⿽��
	//string  str1 = "hello", str2 = "world";
	//cout << std::boolalpha << isShorter(str1, str2) << endl;


	//ʹ�������βη��ض�����Ϣ
	//string str1 = "helloworldhelloworldhelloworld";
	//char c = 'o';
	//string::size_type ctr = 0;
	////string::size_type &num = ctr;
	//
	//cout << c << " first occors at " << find_char(str1, c, ctr) << "," << endl;
	//cout<<"and totally occors "<< ctr << " times" << endl;			//��ֵ˳��


	//ex6.14
	//�ڿ϶����޸�ʵ�����ݣ��������޸��ֲ���Ӱ��ԭ����������£��ββ��ʺ������á�
	//bool read_file_in(string path, const string &file, string &out)
	//{
	//	path += "/" + file;
	//	return read_file(path, out);
	//}
	//��һ������path�������ø���һ��
	
	//vector<int> ivec = { 0, 1, 2, 3, 4, 5, 6 };
	//print(ivec.begin(), ivec.end());
}


//ex6.17�жϴ�д��ĸ
bool any_capital(const string & str)
{
	for (auto c : str)
	{
		if (isupper(c)) return true;
	}
	return false;
}
//ex6.17��дСд��ʽ
void to_lowercase(string &str)
{
	for (auto &c : str)
	{
		if (isupper(c)) c = tolower(c);
	}
}

//6.2.3 const�βκ�ʵ��
void Fun_const_Parameters_and_Arguments()
{
	//const int ci = 42;
	//int i = ci;
	//int * const p = &i;
	//*p = 0;

	//ָ��������β���const
	//��������ʼ������һ��������ʵ�γ�ʼ���β�ʱ����Ե�����const��
	//���β��ж���constʱ����������������߷ǳ��������ǿ��Ե�
	//����ʹ������ֵ��ʼ��һ���ǳ�������

	//����ʹ�ó�������
	//��������ı���βζ������ͨ���û�����������ߴ��������޸ĸ��βε�ֵ����
	//�����ƺ������ܽ��ܵ�ʵ������


	//ex6.17
	string str = "Hello World";
	to_lowercase(str);
	cout << str << endl;
	cout << std::boolalpha << any_capital(str) << endl;

	//ex6.18
	//bool compare(matrix &m1, matrix &m2);
	//vector<int>::iterator change_val(int, vector<int>::iterator);

	//ex6.20
	//���������ı��β�ֵʱ��Ӧ���ǳ������ã�
	//���󵼺�����������Ϊ�����޸��βε�ֵ��
}

//6.2.4 ��ʾ����һ����ʾ�����С���β�
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
//6.2.4 �����β�
void Fun_Array_Parameters()
{
	//��Ϊ����ᱻת����ָ�룬���Ե�����Ϊ��������һ������ʱ��ʵ���ϴ��ݵ���ָ��������Ԫ�ص�ָ��
	//���ܲ�����ֵ���ݵķ�ʽ�������飬�������ǿ��԰��β�д�������������ʽ

	//���������������һ�����飬��ʵ���Զ�ת����ָ��������Ԫ�ص�ָ�룬����Ĵ�С�Ժ����ĵ���û��Ӱ��

	//ʹ�ñ��ָ�����鳤��(C����ַ����Ľ�β�հ��ַ�)
	//ʹ�ñ�׼��淶(begin(a),end(a))
	//��ʾ����һ����ʾ�����С���β�
	//int j[] = { 0, 1 };
	//print_array(j, end(j) - begin(j));


	//�����βκ�const
	//ֻ�е�����ȷʵҪ�ı�Ԫ��ֵ��ʱ�򣬲Ű��βζ���Ϊָ��ǳ�����ָ��

	//���������β�
	//���ݶ�ά����
	//matrixָ���������Ԫ�أ��������Ԫ������10���������ɵ�����
	//void print(int(*matrix)[10], int rowSize);
	//�ȼ۶��� matrix��������һ����ά���飬ʵ�����β���ָ����10�������������ָ��
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
	//6.2.1 ��ֵ����
	//Fun_Passing_Arguments_by_Value();
	//6.2.2 �����ò���
	//Fun_Passing_Arguments_by_Reference();
	//6.2.3 const�βκ�ʵ��
	//Fun_const_Parameters_and_Arguments();
	//6.2.4 �����β�
	Fun_Array_Parameters();

	return 0;
}