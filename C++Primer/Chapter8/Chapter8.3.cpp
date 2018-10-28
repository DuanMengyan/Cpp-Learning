#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter8.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��10��28�� ������
> Last edited time: 2018��10��28�� ������
> Topic:C++Primer Chapter8.3 string��
************************************************************************/

#include "header_include.h"

using namespace std;

//8.3 string��
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

//8.3.1ʹ��istringstream
void Fun_Using_an_istringstream()
{

	//string line, word;
	//vector<Personinfo> people;
	//ifstream input("People_info.txt");		//��ȡ������Ϣ�ļ�
	//if (!input)
	//{
	//	cerr << "No data?!" << endl;
	//}
	//else
	//{
	//	while (getline(input,line))				//���ж�ȡ��¼
	//	{										//
	//		Personinfo info;					//
	//		istringstream record(line);			//����¼�󶨵��ļ�������
	//		record >> info.name;				//��ȡ����
	//		while (record >> word)				//���ζ�ȡÿ���绰����
	//		{									//
	//			info.Phone.push_back(word);		//
	//		}									//
	//		people.push_back(info);				//
	//	}										//
	//	for (auto person : people)				//
	//	{										//
	//		person.info_print();				//��ӡ��Ϣ
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
	//		//���ַ���������istringstream����֮ǰ�������һ�¡�
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
	//��ʱ��Ҫһ���ۺ��࣬����Ӧ��û�����ڳ�ʼֵ

}


bool valid(const string &str)
{
	//�жϵ绰�����Ƿ���Ч��ȫ����������Ϊ����Ч��
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
	//��ʽ���ַ���
	string temp_str = str;
	temp_str = "111-" + temp_str;
	return temp_str;
}

//8.3.2ʹ��ostringstream
void Fun_Using_an_ostringstream()
{
	//string line, word;
	//vector<Personinfo> people;
	//ifstream input("People_info.txt");		//��ȡ������Ϣ�ļ�
	//if (!input)
	//{
	//	cerr << "No data?!" << endl;
	//}
	//else
	//{
	//	while (getline(input,line))				     //���ж�ȡ��¼
	//	{										     //
	//		Personinfo info;					     //
	//		istringstream record(line);			     //����¼�󶨵��ļ�������
	//		record >> info.name;				     //��ȡ����
	//		while (record >> word)				     //���ζ�ȡÿ���绰����
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
	//			if (!valid(nums))					  //����绰�ַ�����Ч
	//			{
	//				badName << " " << nums;
	//			}
	//			else
	//			{
	//				formatted << " " << format_phone(nums);//��ʽ���绰�ַ���
	//			}
	//			
	//		}
	//		if (badName.str().empty())	//û�д���ĵ绰
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
	//����
	//ex8.14
	//entry��nums���������ͣ������������ͣ����ø���Ч
	//������ܸı����ǵ�ֵ�����������const�޶�
}


int main()
{
	//8.3.1ʹ��istringstream
	//Fun_Using_an_istringstream();
	//8.3.2ʹ��ostringstream
	Fun_Using_an_ostringstream();
	return 0;
}