#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年12月8日 星期六
> Last edited time: 2018年12月8日 星期六
> Topic:C++Primer Chapter9.5 额外的string操作
************************************************************************/

#include "header_include.h"

using namespace std;

//9.5.1 构造string的其他方法
void Fun_Other_Ways_to_Construct_strings()
{
	//const char *cp = "Hello World!!!";			//空字符‘\0’结束的数组
	//char noNull[] = { 'H','i' };				//不是以空字符结束
	//string s1(cp);								//拷贝cp，直到遇到空字符
	//string s2(noNull, 2);						//拷贝noNull中的前两个字符
	//string s3(noNull);							//noNull不是以空字符结束，行为未定义
	//string s4(cp + 6, 5);						//从cp[6]开始拷贝5个字符
	//string s5(s1, 6, 5);						//从s1[6]开始拷贝5个字符
	//string s6(s1, 6);							//从s1[6]开始拷贝，直到s1末尾
	//string s7(s1, 6, 20);						//从s1[6]开始拷贝，只拷贝到s1末尾
	//string s8(s1, 16);						//抛出异常

	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;
	//cout << s5 << endl;
	//cout << s6 << endl;
	//cout << s7 << endl;

	//sunstr操作
	//string s("hello world");					 
	//string s2 = s.substr(0, 5);					 //从s[0]开始拷贝5个字符
	//string s3 = s.substr(6);					 //从s[6]开始拷贝到结束
	//string s4 = s.substr(6, 11);				 //从s[6]开始拷贝11个字符，但是只能到结尾
	////string s5 = s.substr(12);					 //超出范围，抛出异常
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;

	//ex9.41
	//vector<char>  cvec{ 'h','e','l','l','o',' ','w','o','r','l','d' };
	//string s(cvec.begin(),cvec.end());
	//cout << s << endl;

	//ex9.42
	//reverse()预留够足够的内存
}


 //9.5.2 改变sreing的其他方法
void Fun_Other_Ways_to_Change_a_string()
{
	//const char *cp = "Stately, plump Buck";
	//string s = "hello world";
	//s.assign(cp, 7);					//将s中的字符替换成cp中前7个字符
	//cout << s << endl;
	//s.insert(s.size(), cp + 7, 6);		//在s末尾插入cp[7]开始6个字符
	//cout << s << endl;

	//string s1 = "some string", s2 = "some other string";
	//s1.insert(0, s2);					//在s1[0]之前插入s2的拷贝
	//cout << s1 << endl;
	//s1.insert(0, s2, 0, s2.size());		//在s1[0]之前插入s2[0]开始的s2.size()个字符
	//cout << s1 << endl;

	//append和replace函数
	//string s("C++ Primer"), s2 = s;
	//s.insert(s.size(), " 4th Ed.");
	//cout << s << endl;
	//s2.append(" 4th Ed.");
	//cout << s2 << endl;

	//s.erase(11, 3);				//从s[11]开始删除3个字符
	//s.insert(11, "5th");			
	//cout << s << endl;
	//s2.replace(11, 3, "5th");	//将s2[11]开始的3个字符替换成“5th”
	//cout << s2 << endl;

	//改变string的多种重载函数

	//ex9.43

	//ex9.44
	
	//ex9.45
	
	//ex9.46


}
 //9.5.3
 
 //9.5.4
 
 //9.5.5
 






int main()
{
	//9.5.1 构造string的其他方法
	//Fun_Other_Ways_to_Construct_strings();
	//9.5.2 改变sreing的其他方法
	Fun_Other_Ways_to_Change_a_string();

	return 0;

}