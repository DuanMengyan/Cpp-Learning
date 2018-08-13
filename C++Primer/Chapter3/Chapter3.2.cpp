#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter3.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��08��7�� ���ڶ�
> Last edited time: 2018��8��13�� ����һ
> Topic:C++Primer Chapter3.2��׼������string
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

//3.2.1����ͳ�ʼ��string����
void Fun_string_init()
{
	string s1("AAAA");		//ֱ�ӳ�ʼ��
	string s2 = s1;			//������ʼ��  
	cout << s1 <<"   "<< s2 << endl;
	string s3(10,'B');
	cout << s3 << endl;
}

//3.2.2string�����ϵĲ���
void Fun_string_operate()
{
	//��дstring����
	//string s1, s2;
	//cin >> s1 >> s2;
	//cout << s1 << s2 << endl;

	//string word;
	//while (cin >>word)	//�����հ׾�ִ��
	//{
	//	cout << word << endl;
	//}
	
	
	//ʹ��getline��ȡһ����string����
	//string line;
	//while (getline(cin, line)) //һ��һ�ж�ȡ����������з�����string���󲻱��滻�з�
	//{
	//	if (!line.empty())		//�ж��ַ����Ƿ�Ϊ��
	//		cout << line <<"	"<< line.size() << " chars" <<endl ;
	//}

	//�ַ����Ƚ�
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

//3.2.3����string�����е��ַ�
void Fun_chars_in_string_operate()
{
	//��Χfor��䴦��ÿ���ַ�
	//string str("Hello World!!!");
	//decltype(str.size()) punct_cnt = 0;		//str.size()����������string::size_type����
	//for (auto c : str)
	//{	
	//	if (ispunct(c))
	//	{
	//		++punct_cnt;
	//	}		
	//}
	//cout << punct_cnt << endl;


	//string str("Hello World!!!");
	//for (auto &c : str)			//���ﶨ�����һ���ַ�����
	//{	
	//	c = toupper(c);			//ȫ��תΪ��д
	//}
	//cout << str << endl;


	//ʹ���±�ִ�е���
	//string str("Hello World!!!");
	//for (decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index)
	//	str[index] = toupper(str[index]);
	//cout << str << endl;


	//ʹ���±�ִ���������
	//const string hexdigits = "0123456789ABCDEF";
	//string result;
	//string::size_type n;
	//while (cin>>n)
	//{
	//	if (n < hexdigits.size())		//nС��16
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
	//for (auto c : str)		//c���ַ����ͣ��������ַ����ã����ܸı�ԭ���ַ����е��ַ�
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

	//ex3.9  //��Ч
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
	for (auto &c : s)	              //c��һ�������ַ�����,���򣬾Ϳ���ͨ��c�ı��ַ�����ֵ
	{
		cout << c;			//�Ϸ�
		//c = 'X';			//���Ϸ�	
	}
		

}

int main()
{
	//Fun_string_init();
	//Fun_string_operate();
	Fun_chars_in_string_operate();

	return 0;
}