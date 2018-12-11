#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��12��8�� ������
> Last edited time: 2018��12��11�� ���ڶ�
> Topic:C++Primer Chapter9.5 �����string����
************************************************************************/

#include "header_include.h"

using namespace std;

//9.5.1 ����string����������
void Fun_Other_Ways_to_Construct_strings()
{
	//const char *cp = "Hello World!!!";			//���ַ���\0������������
	//char noNull[] = { 'H','i' };				//�����Կ��ַ�����
	//string s1(cp);								//����cp��ֱ���������ַ�
	//string s2(noNull, 2);						//����noNull�е�ǰ�����ַ�
	//string s3(noNull);							//noNull�����Կ��ַ���������Ϊδ����
	//string s4(cp + 6, 5);						//��cp[6]��ʼ����5���ַ�
	//string s5(s1, 6, 5);						//��s1[6]��ʼ����5���ַ�
	//string s6(s1, 6);							//��s1[6]��ʼ������ֱ��s1ĩβ
	//string s7(s1, 6, 20);						//��s1[6]��ʼ������ֻ������s1ĩβ
	//string s8(s1, 16);						//�׳��쳣

	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;
	//cout << s5 << endl;
	//cout << s6 << endl;
	//cout << s7 << endl;

	//sunstr����
	//string s("hello world");					 
	//string s2 = s.substr(0, 5);					 //��s[0]��ʼ����5���ַ�
	//string s3 = s.substr(6);					 //��s[6]��ʼ����������
	//string s4 = s.substr(6, 11);				 //��s[6]��ʼ����11���ַ�������ֻ�ܵ���β
	////string s5 = s.substr(12);					 //������Χ���׳��쳣
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;

	//ex9.41
	//vector<char>  cvec{ 'h','e','l','l','o',' ','w','o','r','l','d' };
	//string s(cvec.begin(),cvec.end());
	//cout << s << endl;

	//ex9.42
	//reverse()Ԥ�����㹻���ڴ�
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
			//s.replace(curr,curr+oldVal.size(),newVal);				//�ַ��滻�Ժ�curr������ʧЧ
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
 //9.5.2 �ı�string����������
void Fun_Other_Ways_to_Change_a_string()
{
	//const char *cp = "Stately, plump Buck";
	//string s = "hello world";
	//s.assign(cp, 7);					//��s�е��ַ��滻��cp��ǰ7���ַ�
	//cout << s << endl;
	//s.insert(s.size(), cp + 7, 6);		//��sĩβ����cp[7]��ʼ6���ַ�
	//cout << s << endl;

	//string s1 = "some string", s2 = "some other string";
	//s1.insert(0, s2);					//��s1[0]֮ǰ����s2�Ŀ���
	//cout << s1 << endl;
	//s1.insert(0, s2, 0, s2.size());		//��s1[0]֮ǰ����s2[0]��ʼ��s2,size()���ַ�
	//cout << s1 << endl;

	////append��replace����
	//string s("C++ Primer"), s2 = s;
	//s.insert(s.size(), " 4th Ed,");
	//cout << s << endl;
	//s2.append(" 4th Ed,");
	//cout << s2 << endl;

	//s.erase(11, 3);				//��s[11]��ʼɾ��3���ַ�
	//s.insert(11, "5th");			
	//cout << s << endl;
	//s2.replace(11, 3, "5th");		//��s2[11]��ʼ��3���ַ��滻�ɡ�5th��
	//cout << s2 << endl;

	////�ı�string�Ķ������غ���

	////ex9.43
	////replace()��insert()��erase()�з�Χ�õ��������ģ�ע��֮�������ָ������
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

//9.5.3 string��������
void Fun_string_Search_Operations()
{
	//find���ص�һ��ƥ��λ�õ��±�
	//npos��const string::size_type����
	//string numbers("0123456789"), name("r2d2");
	//auto pos = name.find_first_of(numbers);
	//auto pos2 = numbers.find_first_not_of(name);
	//cout << pos << "      " << pos2 << endl;

	//ָ�������￪ʼ����
	//string::size_type pos = 0;
	//string numbers("0123456789"), name("0132");
	//while ((pos = name.find_first_of(numbers, pos)) != string::npos)
	//{
	//	cout << "Found number at index: " << pos
	//		 << " element is " << name[pos] << endl;
	//	++pos;
	//}

	//��������
	//rfind��Ա�����������һ��ƥ�䣬�����ַ�����ҵĳ���λ��
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
	//���ؽ����string::npos

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


//9.5.4 compare����
void Fun_The_compare_Functions()
{
	//����s�ǵ��ڡ����ڻ���С�ڲ���ָ�����ַ�����s,compare����0����������
	string str1 = "hello", str2 = "world";
	cout << str1.compare(str2) << endl;					//hello��world�Ƚ�	-1
	cout << str1.compare(4, 1, str2, 1, 1) << endl;		//o��o�Ƚ�			0	
	cout << str1.compare(1, 3, str2) << endl;			//ell��world�Ƚ�		-1
	
	char *str_cp = "world";
	cout << str1.compare(4, 1, str_cp + 1, 1) << endl;	//o��o�Ƚ�			0
	//��s�д�pos1��ʼ��n1���ַ���ָ��cpָ��ĵ�ַ��ʼ��n2���ַ����бȽ�
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



//9.5.5 ��ֵת��
void Fun_Numeric_Conversions()
{
	//int i = 42;
	//string s = to_string(i);
	//cout << s << endl;
	//double d = stod(s);
	//cout << d << endl;

	//Ҫת������ֵ��string�е�һ���ǿհ׷���������ֵ�п��ܳ��ֵ��ַ�
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
	//9.5.1 ����string����������
	//Fun_Other_Ways_to_Construct_strings();

	//9.5.2 �ı�sreing����������
	//Fun_Other_Ways_to_Change_a_string();

	//9.5.3 string��������
	//Fun_string_Search_Operations();

	//9.5.4 compare����
	//Fun_The_compare_Functions();
	
	//9.5.5 ��ֵת��
	Fun_Numeric_Conversions();

	return 0;

}


