#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter11.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��3�� ������
> Last edited time: 2019��1��3�� ������
> Topic:C++Primer Chapter11.2 ������������
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;

using Families = map<string, vector<string>>;

auto make_families()
{
	Families families;
	for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
		for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
			families[ln].push_back(cn);
	return families;
}

auto print(Families const& families)
{
	for (auto const& family : families)
	{
		cout << family.first << ":\n";
		for (auto const& child : family.second)
			cout << child << " ";
		cout << "\n";
	}
}


//Chapter11.2 ������������

//11.1 �����������
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
	//cout << "Last name:" << endl;
	//for(string first_name; cin >> first_name;cout<<"Last name:"<<endl)
	//{
	//	cout << "First name:" << endl;
	//	for (string name; cin >> name&&name != "end";cout<<"First name:"<<endl)
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
	vector<string> vec; 
	string str;
	while (cin>>str)
	{
		if ( find(vec.begin(),vec.end(),str) == vec.end())
		{
			vec.push_back(str);
		}
	}
	printitem(vec);


	//������ӻ���ɾ��Ԫ�أ�setʼ��������Ԫ��Ψһ
	//��vector�����Ԫ�أ����ѵ�ʱ�������е�Ԫ�ظ��������ȣ�
	//��set�����Ԫ�أ����ѵ�ʱ�������е�Ԫ�ظ�������������Ԫ����Ŀ�ܴ�ʱ�����кܴ�����

}


//11.2 �ؼ������͵�Ҫ��



//11.3 pair����




int main()
{
	//11.1 �����������
	Fun_Defining_an_Associative_Container();
	return 0;
}


