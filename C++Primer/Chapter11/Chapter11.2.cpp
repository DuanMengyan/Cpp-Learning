#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter11.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��3�� ������
> Last edited time: 2019��1��4�� ������
> Topic:C++Primer Chapter11.2 ������������
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;


//Chapter11.2 ������������

//11.2.1 �����������
void Fun_Defining_an_Associative_Container()
{
	map<string, size_t> word_count;
	//��ʼ��multimap��multiset
	//multimap��multiset�����ж��Ԫ�ؾ�����ͬ�Ĺؼ���
	//vector<int> ivec;
	//for (vector<int>::size_type i = 0; i != 10; ++i)
	//{
	//	ivec.push_back(i);
	//	ivec.push_back(i);
	//}
	//set<int> iset(ivec.cbegin(), ivec.cend());
	//multiset<int> miset(ivec.cbegin(), ivec.cend());
	//cout << ivec.size() << endl;
	//cout << iset.size() << endl;
	//cout << miset.size() << endl;

	//ex11.5
	//map��Źؼ���-ֵ�ԣ�set��Źؼ��֣�
	//��Ҫ��Ӧ��ϵ��ʱ����map����Ҫ�洢����ʱ��set


	//ex11.6
	//list
	//Ԫ�����򣬿����ظ���
	//set
	//Ԫ�����򣬲����ظ�

	//ex11.7
	//map<string, vector<string>> name_map;	
	//vector<string> kids_name;
	//
	//for(string first_name; cout << "Last name:" << endl,cin >> first_name;)
	//{
	//	
	//	for (string name; cout << "First name:" << endl,cin >> name&&name != "end";)
	//	{

	//		kids_name.push_back(name);
	//	}
	//	name_map[first_name] = kids_name;
	//	kids_name.clear();
	//}
	//
	//for (auto w : name_map)
	//{
	//	for (auto str : w.second)
	//	{
	//		cout << w.first << str << " ";
	//	}
	//	cout << endl << "========================" << endl;
	//}

	//ex11.8
	//vector<string> vec; 
	//string str;
	//while (cin>>str)
	//{
	//	if ( find(vec.begin(),vec.end(),str) == vec.end())
	//	{
	//		vec.push_back(str);
	//	}
	//}
	//printitem(vec);


	//������ӻ���ɾ��Ԫ�أ�setʼ��������Ԫ��Ψһ
	//��vector�����Ԫ�أ����ѵ�ʱ�������е�Ԫ�ظ��������ȣ�
	//��set�����Ԫ�أ����ѵ�ʱ�������е�Ԫ�ظ�������������Ԫ����Ŀ�ܴ�ʱ�����кܴ�����

}


bool compareIsbn(const Sales_data &lhs,const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

//11.2.2 �ؼ������͵�Ҫ��
void Fun_Requirements_on_Key_Type()
{
	//���������ؼ������ͱ��붨��Ԫ�رȽϵķ���

	//���������Ĺؼ�������
	//���һ�����Ͷ����ˡ���Ϊ��������<��������������������ؼ�������

	//ʹ�ùؼ������͵ıȽϺ���,�ṩһ��ָ��ָ��������ָ��
	//multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);

	//ex11.9
	//map<string, list<size_t>> words_map;

	//ex11.10
	//map<vector<int>::iterator, int> vec_map;
	//map<list<int>::iterator, int> lst_map;

	////vector���ԣ�list���У�list<int>::iterator��˫���������û�ж���<�Ƚ������
	//vector<int> vi;
	//vec_map.insert(pair<vector<int>::iterator, int>(vi.begin(), 0));


	//ex11.11
	//����ָ��
	//using com = bool(*)(const Sales_data &lhs, const Sales_data &rhs);
	//multiset<Sales_data, com>bookstore(compareIsbn);
}

pair<string, int> proceess(vector<string> &v)
{
	if (!v.empty())
		return{ v.back(),v.back().size() };		//�б��ʼ��
		//return make_pair(v.back(), v.back().size());
		//return pair<string, int>(v.back(), v.back().size());
	else
		return pair<string, int>();				//��ʽ���췵��ֵ
}

//ex11.14
class MyFamilies
{
public:
	
	MyFamilies() {};
	
	using person   = pair<string, string>;
	using people   = vector<person>;
	using Families = map<string, people>;

	void add(string const &last_name, string const &first_name, string const &birth)
	{
		auto temp_person = person(first_name, birth);
		families[last_name].push_back(temp_person);
	}

	void print()const&
	{
		for (auto family : families)
		{
			cout << "Family���� "<<family.first << " : " << endl;
			for (auto person : family.second)
			{
				cout << person.first << "  " << person.second << endl;
			}
			cout << "==============" << endl;
		}
	}
private:
	Families families;
};

//11.2.3 pair����
void Fun_The_pair_Type()
{
	//pair������ͷ�ļ�utility��
	//pair�����ݳ�Ա��public��
	//auto item = make_pair(1, "hello");		//item��������<int,string>

	//����pair����ĺ���


	//ex11.12
	//vector<pair<string, int>> p_vec;
	//string str; int i;
	//while (cin >> str && cin >> i)
	//{
	//	pair<string, int>temp(str, i);
	//	//pair<string, int>temp = { str,i };
	//	//auto temp = make_pair(str, i);
	//	p_vec.push_back(temp);
	//}

	//cout << "=================================" << endl;
	//
	//for (auto item : p_vec)
	//{
	//	cout << item.first << "  " << item.second << endl;
	//}



	//ex11.13
	//����


	//ex11.14
	//map<string, vector<pair<string,string>>> name_map;	
	//
	//for(string first_name; cout << "Last name:" << endl,cin >> first_name;)
	//{		
	//	for (string name,birth; cout << "First name:" << endl,cin >> name >> birth && name != "end";)
	//	{
	//		auto temp = make_pair(name, birth);
	//		name_map[first_name].push_back(temp);
	//	}
	//}
	//
	//for (auto w : name_map)
	//{
	//	for (auto item : w.second)
	//	{
	//		cout << w.first << "  " << item.first << " " << item.second << endl;
	//	}
	//	cout << endl << "========================" << endl;
	//}

	MyFamilies families;
	auto msg = "Please enter last name, first name and birthday of every person:\n";
	for (string l, f, b; cout << msg, cin >> l >> f >> b; families.add(l, f, b));
	families.print();
}



int main()
{
	//11.1 �����������
	//Fun_Defining_an_Associative_Container();
	//11.2.2 �ؼ������͵�Ҫ��
	//Fun_Requirements_on_Key_Type();
	//11.2.3 pair����
	Fun_The_pair_Type();
	return 0;
}


