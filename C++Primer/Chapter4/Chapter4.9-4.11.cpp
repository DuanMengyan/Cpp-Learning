#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter4.9-4.11.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��08��31�� ������
> Last edited time: 2018��8��31�� ������
> Topic:C++Primer Chapter4.9-4.11 
************************************************************************/

#include <iostream>
#include <cstddef>
#include <cctype>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
//using std::cout;
//using std::cin;
//using std::endl;
//using std::getline;
//using std::string;
//using std::vector;
//using std::begin;
//using std::end;


//4.9 sizeof�����
void Fun_sizeof()
{
	//ex4.28
	//cout << "==================================================" << endl;
	//cout << "short:\t\t" << sizeof(short) << " Bytes\t\t" << 8 * sizeof(short) << " bits" << endl;
	//cout << "int:\t\t" << sizeof(int) << " Bytes\t\t" << 8 * sizeof(int) << " bits" << endl;
	//cout << "long:\t\t" << sizeof(long) << " Bytes\t\t" << 8 * sizeof(long) << " bits" << endl;
	//cout << "long long:\t" << sizeof(long long) << " Bytes\t\t" << 8 * sizeof(long long) << " bits" << endl;
	//cout << "==================================================" << endl;
	//cout << "float:\t\t" << sizeof(float) << " Bytes\t\t" << 8 * sizeof(float) << " bits" << endl;
	//cout << "double:\t\t" << sizeof(double) << " Bytes\t\t" << 8 * sizeof(double) << " bits" << endl;
	//cout << "long double:\t" << sizeof(long double) << " Bytes\t\t" << 8 * sizeof(long double) << " bits" << endl;
	//cout << "==================================================" << endl;
	//cout << "char:\t\t" << sizeof(char) << " Bytes\t\t" << 8 * sizeof(char) << " bits" << endl;
	//cout << "wchar_t:\t" << sizeof(wchar_t) << " Bytes\t\t" << 8 * sizeof(wchar_t) << " bits" << endl;
	//cout << "char16_t:\t" << sizeof(char16_t) << " Bytes\t\t" << 8 * sizeof(char16_t) << " bits" << endl;
	//cout << "char32_t:\t" << sizeof(char32_t) << " Bytes\t\t" << 8 * sizeof(char32_t) << " bits" << endl;
	//cout << "==================================================" << endl;
	//cout << "bool:\t\t" << sizeof(bool) << " Bytes\t\t" << 8 * sizeof(bool) << " bits" << endl;
	//cout << "void:nullptr_t:\t" << sizeof(nullptr_t) << " Bytes\t\t" << 8 * sizeof(nullptr_t) << " bits" << endl;

	//cout << "==================================================" << endl;
	// Fixed width integers
	//cout << "int8_t:\t\t" << sizeof(int8_t) << " bytes" << endl;
	//cout << "uint8_t:\t" << sizeof(uint8_t) << " bytes" << endl;
	//cout << "int16_t:\t" << sizeof(int16_t) << " bytes" << endl;
	//cout << "uint16_t:\t" << sizeof(uint16_t) << " bytes" << endl;
	//cout << "int32_t:\t" << sizeof(int32_t) << " bytes" << endl;
	//cout << "uint32_t:\t" << sizeof(uint32_t) << " bytes" << endl;
	//cout << "int64_t:\t" << sizeof(int64_t) << " bytes" << endl;
	//cout << "uint64_t:\t" << sizeof(uint64_t) << " bytes" << endl;


	//ex4.29
	//int x[10]; int *p = x;
	//cout << sizeof(x) / sizeof(*x) << endl;			//10,	40/4��������Ԫ�صĸ���
	//cout << sizeof(p) / sizeof(*p) << endl;			//1		4/4 32λ����

	//4.30
	//(sizeof x) + y
	//sizeof (p->men[i])
	//sizeof(a) < b
	//sizeof f()

}

//4.10 ���������
void Fun_Comma_Operator()
{
	//ex4.31
	//vector<int> ivec(10, 0);
	//vector<int>::size_type cnt = ivec.size();
	//for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
	//	ivec[ix] = cnt;
	//for (auto i : ivec)
	//{
	//	cout << i << "  ";
	//}


	//ex4.32
	//const int size = 5;
	//int ia[size] = { 1, 2, 3, 4, 5 };
	//for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr);

	//ex4.33
	//����
	//int x = 1, y = 1;
	//bool someValue = 0;
	//someValue ? ++x, ++y : --x, --y;			//(someValue ? ++x, ++y : --x), --y;
	//cout << "x: " << x << "\ty: " << y << endl;	//0   0

	//bool someValue = 1;
	//someValue ? ++x, ++y : --x, --y;			//(someValue ? ++x, ++y : --x), --y;
	//cout << "x: " << x << "\ty: " << y << endl;	//2   1
}

//4.11 ����ת��
void Fun_Type_Conversions()
{
	//4.11.1����ת��
	//4.34
	//bool	flag;		char			cval;
	//short	sval;		unsigned short	usval;
	//int		ival;		unsigned int	uival;
	//long	lval;		unsigned long	ulval;
	//float	fval;		double			dval;
	//if (fval)				//floatת��Ϊbool��
	//dval = fval + ival;	//ival ת��Ϊfloat��֮����ӵĽ��ת��Ϊdouble��
	//dval + ival * cval;	//cvalת��Ϊint����ival��ˣ����ת��Ϊdouble����dval���


	//4.35
	//(a)'a'ת��Ϊint������3��ӣ���ӽ��ת��Ϊchar����
	//(b)ivalת��Ϊfloat���ͣ���˽��ת��Ϊint���ͣ������ת��Ϊfloat����
	//(c)uiת��Ϊfloat���ͣ���˽��ת��Ϊdouble����
	//(d)ivalת��Ϊfloat������fval��ӣ����ת��Ϊdouble������dval��ӣ������ת��Ϊchar����


	//4.11.2������ʽ����ת��
	//ת���ɳ���
	//int i;
	//const int &j = i;
	//const int *p = &i;
	//int &r = j, *q = p;			//��ͼ�����޶���������

	//4.11.3��ʾת��
	//char c = 'A';
	//const char *pc = &c;
	//char *p = const_cast< char* >(pc);		//const_cast��ȥ��const����
	//*p = 'B';		//��������һ��������ʹ��ǿ������ץ�����дȨ���ǺϷ���Ϊ
	//cout << *pc << "    " << *p << endl;		//��� B  B��

	//ֻ��const_cast�ܸı���ʽ�ĳ������ԣ�ʹ��������ʽ������ǿ������ת���ı���ʽ�ĳ������Խ���������������
	//ͬ��Ҳ������const_cast�ı���ʽ������
	//const char *cp = &c;
	//char *q = static_cast<char*>(cp);			//stactic_cast�޷��������������������޶���
	//string str = static_cast<string>(cp);					//�ַ�������ֵת��Ϊstring����
	//cout << str << endl;			//����е�����

	//int *ip;
	//char *pc = reinterpret_cast<char*>(ip);		//pc��ָ����ʵ����ʱһ��int�����ַ�
	//string str(pc);
	//ʹ��reinterpret_cast�ǳ�Σ�գ������������ڻ�����������漰�����ͺͱ�����ʵ��ת���Ĺ��̶��ǳ��˽�

	//ex4.36
	//int i = 1; double d = 3.0;
	//i *=static_cast<int>(d);
	//cout << i;

	//ex4.37
	//int i; double d; const string *ps; char *pc; void *pv;
	//pv = const_cast<string*>(ps);
	//pv = static_cast<void*>(const_cast<string*>(ps));
	//i = int(*pc);
	//i = static_cast<int>(*pc);
	//pv = &d;
	//pv = static_cast<void*>(&d);
	//pc = (char*)pv;
	//pc = static_cast<char*>(pv);

	//ex4.38
	//double slope = static_cast<double>(j / i);//��������j/i��ת��Ϊdouble���ͳ�ʼ��slope
}


int main()
{
	//Fun_sizeof();
	//Fun_Comma_Operator();
	Fun_Type_Conversions();
	return 0;
}