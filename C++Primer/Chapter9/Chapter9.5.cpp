#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年12月8日 星期六
> Last edited time: 2018年12月11日 星期二
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

//ex9.43
string &str_replace(string &s,  string const& oldVal,  string const& newVal)
{
	for (auto curr = s.begin(); curr <= (s.end() - oldVal.size());)
	{

		if (*curr==*(oldVal.begin()) && s.substr(curr-s.begin(),oldVal.size())==oldVal)
		{
			curr = s.erase(curr, curr+oldVal.size());
			curr = s.insert(curr,newVal.begin(),newVal.end());
			//s.replace(curr,curr+oldVal.size(),newVal);				//字符替换以后，curr迭代器失效
			curr += newVal.size();
		}
		else
		{
			curr++;
		}		
	}
	return s;
}

//ex9.44
string &str_replace2(string &s, string const& oldVal, string const& newVal)
{
	for (size_t curr = 0; curr <= (s.size() - oldVal.size());)
	{
		if (s[curr] == oldVal[0] && s.substr(curr, oldVal.size()) == oldVal)
		{
			//s.erase(curr, oldVal.size());
			//s.insert(curr, newVal);
			s.replace(curr, oldVal.size(), newVal);
			curr += newVal.size();
		}
		else
		{
			++curr;
		}

	}
	return s;
}

//ex9.45
string &name_edit(string &Name, string const &prev, string const &last)
{
	Name.insert(Name.begin(), prev.cbegin(), prev.cend());
	Name.append(last);
	return Name;
}

//ex9.46
string &name_edit2(string &Name, string const &prev, string const &last)
{
	Name.insert(0, prev);
	Name.insert(Name.size(), last);
	return Name;
}
 //9.5.2 改变string的其他方法
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
	//s1.insert(0, s2, 0, s2.size());		//在s1[0]之前插入s2[0]开始的s2,size()个字符
	//cout << s1 << endl;

	////append和replace函数
	//string s("C++ Primer"), s2 = s;
	//s.insert(s.size(), " 4th Ed,");
	//cout << s << endl;
	//s2.append(" 4th Ed,");
	//cout << s2 << endl;

	//s.erase(11, 3);				//从s[11]开始删除3个字符
	//s.insert(11, "5th");			
	//cout << s << endl;
	//s2.replace(11, 3, "5th");		//将s2[11]开始的3个字符替换成“5th”
	//cout << s2 << endl;

	////改变string的多种重载函数

	////ex9.43
	////replace()、insert()、erase()中范围用到迭代器的，注意之后迭代器指向问题
	//string s = "aa456456a456aa", old = "456", newstr = "---zzz=";
	//s = str_replace(s, old, newstr);
	//cout << s << endl;

	////ex9.44
	//string s = "aa456456a456", old = "456", newstr = " ---zzz ";
	//s = str_replace2(s, old, newstr);
	//cout << s << endl;

	////ex9.45
	//string name = "Bod",prev = "Mr,",last = ",Jr,";
	//name = name_edit(name, prev, last);
	//cout << name << endl;

	////ex9.46
	//string name = "Bod",prev = "Mr,",last = ",Jr,";
	//name = name_edit2(name, prev, last);
	//cout << name << endl;
}


//ex9.47
void findchar(string &str,  string const& chars)
{
	string::size_type pos = 0;
	cout << "found ekements in " << str << endl;
	while ((pos = str.find_first_of(chars, pos)) != string::npos)
	{
		cout << "index: " << pos << " is element: " << str[pos] << endl;	
		++pos;
	}
}

//ex9.49
int find_middlealphabet(string &word, string const& middle_chars)
{
	string::size_type pos = 0; int count = 0;
	while ((pos = word.find_first_of(middle_chars, pos)) != string::npos)
	{
		count++;
		++pos;
	}
	return count;
}

//9.5.3 string搜索操作
void Fun_string_Search_Operations()
{
	//find返回第一个匹配位置的下标
	//npos是const string::size_type类型
	//string numbers("0123456789"), name("r2d2");
	//auto pos = name.find_first_of(numbers);
	//auto pos2 = numbers.find_first_not_of(name);
	//cout << pos << "      " << pos2 << endl;

	//指定在那里开始搜索
	//string::size_type pos = 0;
	//string numbers("0123456789"), name("0132");
	//while ((pos = name.find_first_of(numbers, pos)) != string::npos)
	//{
	//	cout << "Found number at index: " << pos
	//		 << " element is " << name[pos] << endl;
	//	++pos;
	//}

	//逆向搜索
	//rfind成员函数搜索最后一个匹配，即子字符串最靠右的出现位置
	//string river("Mississippi");
	//auto first_pos = river.find("is");
	//auto last_pos = river.rfind("is");
	//cout << first_pos << "     " << last_pos << endl;

	//ex9.47
	//string str = "ab2c3d7R4E6";
	//string numbers = "0123456789";
	//string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZ";
	//findchar(str, numbers);
	//findchar(str, alphabet);
	
	//ex9.48
	//string name = "r2d2";
	//string numbers = "0123456789";
	//cout << numbers.find(name) << endl;
	//返回结果是string::npos

	//ex9.49
	//ifstream input("words,txt");
	//string curr_word, max_word, middle = "acemnorsuvwxz";
	//int max_count = 0, curr_count = 0;
	//while (input >> curr_word)
	//{
	//	curr_count = find_middlealphabet(curr_word, middle);
	//	//cout << curr_word << "\t\t : " << curr_count << endl;
	//	if (max_count < curr_count)
	//	{
	//		max_word = curr_word;
	//		max_count = curr_count;
	//	}
	//}
	//cout <<"The word \""<< max_word <<"\" has "<<max_count<<" middle alphabets,"<< endl;

}


//9.5.4 compare函数
void Fun_The_compare_Functions()
{
	//根据s是等于、大于还是小于参数指定的字符串，s,compare返回0、正数或负数
	string str1 = "hello", str2 = "world";
	cout << str1.compare(str2) << endl;					//hello和world比较	-1
	cout << str1.compare(4, 1, str2, 1, 1) << endl;		//o和o比较			0	
	cout << str1.compare(1, 3, str2) << endl;			//ell和world比较		-1
	
	char *str_cp = "world";
	cout << str1.compare(4, 1, str_cp + 1, 1) << endl;	//o和o比较			0
	//将s中从pos1开始的n1个字符与指针cp指向的地址开始的n2个字符进行比较
}
 

class MyData
{
public:
	MyData() {};
	MyData(string &str)
	{
		vector<string> sub_vec;
		string::size_type pos = 0;
		while ((pos = str.find_first_of(" ,/")) != string::npos)
		{
			sub_vec.push_back(str.substr(0, pos));
			str.erase(0, pos + 1);
		}
		sub_vec.push_back(str);
		if (sub_vec[0].find_first_of("0123456789") != string::npos)
		{
			month = stoi(sub_vec[0]);
		}
		else
		{
			if (sub_vec[0].find("Jan") < sub_vec[0].size())  month = 1;
			if (sub_vec[0].find("Feb") < sub_vec[0].size())  month = 2;
			if (sub_vec[0].find("Mar") < sub_vec[0].size())  month = 3;
			if (sub_vec[0].find("Apr") < sub_vec[0].size())  month = 4;
			if (sub_vec[0].find("May") < sub_vec[0].size())  month = 5;
			if (sub_vec[0].find("Jun") < sub_vec[0].size())  month = 6;
			if (sub_vec[0].find("Jul") < sub_vec[0].size())  month = 7;
			if (sub_vec[0].find("Aug") < sub_vec[0].size())  month = 8;
			if (sub_vec[0].find("Sep") < sub_vec[0].size())  month = 9;
			if (sub_vec[0].find("Oct") < sub_vec[0].size())  month = 10;
			if (sub_vec[0].find("Nov") < sub_vec[0].size())  month = 11;
			if (sub_vec[0].find("Dec") < sub_vec[0].size())  month = 12;
		}
		day = stoi(sub_vec[1]);
		year = stoi(sub_vec[2]);
	};

	void print_Data()
	{
		cout << year << " " << month << " " << day << " " << endl;
	}
private:
	unsigned year;
	unsigned month;
	unsigned day;
};



//9.5.5 数值转换
void Fun_Numeric_Conversions()
{
	//int i = 42;
	//string s = to_string(i);
	//cout << s << endl;
	//double d = stod(s);
	//cout << d << endl;

	//要转换成数值的string中第一个非空白符必须是数值中可能出现的字符
	//string s2 = "pi = 3,14";
	//cout << s2,find_first_of("+-,0123456789") << endl;
	//double d = stod(s2,substr(s2,find_first_of("+-,0123456789")));
	//cout << d << endl;

	//ex9.50
	//vector<string> ivec = { "20","30","40","10" };
	//int sum = 0;
	//for (auto s : ivec)
	//{
	//	sum += stoi(s);
	//}
	//cout << sum << endl;

	//ex9.51
	string str = "12/11/2018", str2 = "Dec 11 2018";

	MyData today(str), yesterday(str2);
	today.print_Data();
	yesterday.print_Data();


}
 






int main()
{
	//9.5.1 构造string的其他方法
	//Fun_Other_Ways_to_Construct_strings();

	//9.5.2 改变sreing的其他方法
	//Fun_Other_Ways_to_Change_a_string();

	//9.5.3 string搜索操作
	//Fun_string_Search_Operations();

	//9.5.4 compare函数
	//Fun_The_compare_Functions();
	
	//9.5.5 数值转换
	Fun_Numeric_Conversions();

	return 0;

}


