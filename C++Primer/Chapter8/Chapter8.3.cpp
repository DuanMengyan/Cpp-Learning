#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter8.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年10月28日 星期日
> Last edited time: 2018年10月28日 星期日
> Topic:C++Primer Chapter8.3 string流
************************************************************************/

#include "header_include.h"

using namespace std;

//8.3 string流
//8.3 string Streams

class Personinfo
{
public:
	void info_print()
	{
		cout << name << " :\t";
		for (string str : phones)
		{
			cout << str << "  ";
		}
		cout << endl;
	}
	string name;
	vector<string> phones;

};

//8.3.1使用istringstream
void Fun_Using_an_istringstream()
{

	//string line, word;
	//vector<Personinfo> people;
	//ifstream input("People_info.txt");		//读取人物信息文件
	//if (!input)
	//{
	//	cerr << "No data?!" << endl;
	//}
	//else
	//{
	//	while (getline(input,line))				//按行读取记录
	//	{										//
	//		Personinfo info;					//
	//		istringstream record(line);			//将记录绑定到文件流对象
	//		record >> info.name;				//读取名字
	//		while (record >> word)				//依次读取每个电话号码
	//		{									//
	//			info.Phone.push_back(word);		//
	//		}									//
	//		people.push_back(info);				//
	//	}										//
	//	for (auto person : people)				//
	//	{										//
	//		person.info_print();				//打印信息
	//	}										//
	//	input.close();
	//}

	

	//ex8.9

	//ex8.10-ex8.11
	//ifstream input("word_file.txt");
	//if (!input)
	//{
	//	cerr << "No data?!" << endl;
	//}
	//else
	//{
	//	string str_line, temp_word;
	//	vector<string> vec_str;
	//	while (getline(input, str_line))
	//	{
	//		vec_str.push_back(str_line);
	//	}
	//	istringstream record;
	//	for (auto line : vec_str)
	//	{
	//		//istringstream record(line);
	//		//将字符串拷贝到istringstream对象之前，先清空一下。
	//		record.clear();
	//		record.str(line);
	//		while (record >> temp_word)
	//		{
	//			cout << temp_word << endl;
	//		}
	//		
	//	}
	//}

	//ex8.12
	//此时需要一个聚合类，所以应该没有类内初始值

}


bool valid(const string &str)
{
	//判断电话号码是否有效，全是数字则认为是有效的
	bool flag = true;
	for (char c : str)
	{
		if (!isdigit(c))
			flag = false;
	}
	return flag;
}

string format_phone(const string &str)
{
	//格式化字符串
	string temp_str = str;
	temp_str = "111-" + temp_str;
	return temp_str;
}

//8.3.2使用ostringstream
void Fun_Using_an_ostringstream()
{
	//string line, word;
	//vector<Personinfo> people;
	//ifstream input("People_info.txt");		//读取人物信息文件
	//if (!input)
	//{
	//	cerr << "No data?!" << endl;
	//}
	//else
	//{
	//	while (getline(input,line))				     //按行读取记录
	//	{										     //
	//		Personinfo info;					     //
	//		istringstream record(line);			     //将记录绑定到文件流对象
	//		record >> info.name;				     //读取名字
	//		while (record >> word)				     //依次读取每个电话号码
	//		{									     //
	//			info.phones.push_back(word);	     //
	//		}									     //
	//		people.push_back(info);				     //
	//	}										     //
	//	input.close();							     //
	//	for (const auto &entry : people)		     //		
	//	{										     //
	//		ostringstream formatted, badName;
	//		for (const auto &nums : entry.phones)
	//		{
	//			if (!valid(nums))					  //如果电话字符串无效
	//			{
	//				badName << " " << nums;
	//			}
	//			else
	//			{
	//				formatted << " " << format_phone(nums);//格式化电话字符串
	//			}
	//			
	//		}
	//		if (badName.str().empty())	//没有错误的电话
	//		{
	//			cout << entry.name << " " << formatted.str() << endl;
	//		}
	//		else
	//		{
	//			cerr << "input error: " << entry.name
	//				<< " invalid number(s) " << badName.str() << endl;
	//		}				
	//	}											
	//}


	//ex8.13
	//如上
	//ex8.14
	//entry和nums都是类类型，不是内置类型，引用更高效
	//输出不能改变他们的值，所以添加了const限定
}


int main()
{
	//8.3.1使用istringstream
	//Fun_Using_an_istringstream();
	//8.3.2使用ostringstream
	Fun_Using_an_ostringstream();
	return 0;
}