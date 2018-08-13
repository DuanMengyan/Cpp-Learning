#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter3.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年08月7日 星期二
> Last edited time: 2018年8月13日 星期一
> Topic:C++Primer Chapter3.2标准库类型string
************************************************************************/

#include <iostream>
#include <string>
#include <cctype>

//using namespace std;

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

//3.2.1定义和初始化string对象
void Fun_string_init()
{
	string s1("AAAA");		//直接初始化
	string s2 = s1;			//拷贝初始化  
	cout << s1 <<"   "<< s2 << endl;
	string s3(10,'B');
	cout << s3 << endl;
}

//3.2.2string对象上的操作
void Fun_string_operate()
{
	//读写string对象
	//string s1, s2;
	//cin >> s1 >> s2;
	//cout << s1 << s2 << endl;

	//string word;
	//while (cin >>word)	//遇到空白就执行
	//{
	//	cout << word << endl;
	//}
	
	
	//使用getline读取一整行string对象
	//string line;
	//while (getline(cin, line)) //一行一行读取。会读进换行符，但string对象不保存换行符
	//{
	//	if (!line.empty())		//判断字符串是否为空
	//		cout << line <<"	"<< line.size() << " chars" <<endl ;
	//}

	//字符串比较
	//string str = "Hello ";
	//string phrase = "Hello World";
	//string slang = "Hiya";
	//if (str > phrase)
	//{
	//	cout << str << " > " << phrase << endl;
	//}
	//else if (str < phrase)
	//{
	//	cout << str << " < " << phrase << endl;
	//}
	//else
	//{
	//	cout << str << " = " << phrase << endl;
	//}

	//ex3.2
	//string str;
	//while (cin >>str)
	//{
	//	cout << str << endl;
	//}
	//for (string str; getline(cin, str); cout << str << endl);
	//for (string str; cin >> str; cout << str << endl);
	//for (string str; getline(cin,str,'h'); cout << str << endl);


	//ex3.4
	//string str1, str2;
	//cin >> str1 >> str2;
	//if (str1.size() != str2.size())
	//{
	//	cout << ((str1.size() > str2.size()) ? str1 : str2) << endl;
	//}


	//ex3.5
	//string str,long_str;
	//while (cin >> str)
	//{
	//	long_str += str;
	//}
	//cout << long_str << endl;
	//string Lstr;
	//for (string str; cin >> str; Lstr += str);
	//cout << Lstr << endl;
	//string str;
	//for (string buff; cin >> buff; str += (str.empty() ? "" : " ") + buff);
	//cout << "The concatenated string is " << str << endl;

}

//3.2.3处理string对象中的字符
void Fun_chars_in_string_operate()
{
	//范围for语句处理每个字符
	//string str("Hello World!!!");
	//decltype(str.size()) punct_cnt = 0;		//str.size()返回类型是string::size_type类型
	//for (auto c : str)
	//{	
	//	if (ispunct(c))
	//	{
	//		++punct_cnt;
	//	}		
	//}
	//cout << punct_cnt << endl;


	//string str("Hello World!!!");
	//for (auto &c : str)			//这里定义的是一个字符引用
	//{	
	//	c = toupper(c);			//全部转为大写
	//}
	//cout << str << endl;


	//使用下标执行迭代
	//string str("Hello World!!!");
	//for (decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index)
	//	str[index] = toupper(str[index]);
	//cout << str << endl;


	//使用下标执行随机访问
	//const string hexdigits = "0123456789ABCDEF";
	//string result;
	//string::size_type n;
	//while (cin>>n)
	//{
	//	if (n < hexdigits.size())		//n小于16
	//		result += hexdigits[n];		
	//}
	//cout << result<<endl;

	//ex3.6
	//string str = "hello world";
	//cout << str << endl;
	//for (auto &c : str)
	//{
	//	c = 'X';
	//}
	//cout << str << endl;

	//ex3.7
	//string str = "hello world";
	//cout << str << endl;
	//for (auto c : str)		//c是字符类型，而不是字符引用，不能改变原有字符串中的字符
	//{
	//	c = 'X';
	//}
	//cout << str << endl;

	//ex3.8
	//string str = "hello world";
	//cout << str << endl;
	//decltype(str.size()) index = 0;
	//while (index!=str.size())
	//{
	//	str[index++] = 'X';
	//}
	//cout << str << endl;
	
	//for (decltype(str.size()) i = 0; i < str.size(); ++i)
	//{
	//	str[i] = 'X';
	//}
	//cout << str << endl;

	//ex3.9  //无效
	//string s;
	//cout << s[0] << endl;

	//ex3.10
	//string str = "hello,w.orld!",result;
	//for (auto i:str)
	//{
	//	if (!ispunct(i))
	//		result += i;
	//}
	//cout << result << endl;

	//ex3.11
	const  string s = "Keep out!";		
	for (auto &c : s)	              //c是一个常量字符引用,否则，就可以通过c改变字符串的值
	{
		cout << c;			//合法
		//c = 'X';			//不合法	
	}
		

}

int main()
{
	//Fun_string_init();
	//Fun_string_operate();
	Fun_chars_in_string_operate();

	return 0;
}