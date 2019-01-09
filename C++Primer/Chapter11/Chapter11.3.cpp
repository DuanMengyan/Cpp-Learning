#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter11.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��4�� ������
> Last edited time: 2019��1��9�� ������
> Topic:C++Primer Chapter11.3 ������������
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;

// Chapter11.3 ������������



//bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
//{
//	return lhs.isbn() < rhs.isbn();
//}

//11.3.1 ��������������
void Fun_Associative_Container_Iterators()
{
	//��������һ�����������������ǣ����ǻ�õ�һ������Ϊ������value_type��ֵ������
	//һ��map��value_type��һ��pair�����ǿ��Ըı�pair��ֵ�����ǲ��ܸı�ؼ��ֳ�Ա��ֵ���ؼ��ֳ�Ա��const��
	//map<string, size_t> word_count = { {"AAA",5},{"BBB",6},{"CCC",6} };
	//auto map_it = word_count.begin();
	//cout << map_it->first << "   " << map_it->second << endl;

	//set�ĵ�������const�ģ�
	//set���������͵�������ֻ��ֻ������set�е�Ԫ��
	//һ��set�еĹؼ���Ҳ��const��
	//set<int> iset = { 0,1,2,3,4,5,6,7,8,9 };
	//set<int>::iterator set_it = iset.begin();
	//if (set_it != iset.end())
	//{
	//	cout<<*set_it <<endl;
	//}
	
	//������������
	//��ʹ��һ������������һ��map��multimap��set��multisetʱ�����������ؼ����������Ԫ�ء�
	//map<string, size_t> word_count = { {"BBB",6},{"AAA",5},{"CCC",6} };
	//auto map_it = word_count.cbegin();
	//while (map_it != word_count.cend())
	//{
	//	cout << map_it->first << "    " << map_it->second << endl;
	//	++map_it;
	//}

	//�����������㷨
	//����һ�㲻�Թ�������ʹ�÷����㷨����Ϊ�ؼ�����const
	//��������������ֻ��ȡԪ�ص��㷨������ʹ�ù�������ר�Ŷ����ר��find��Ա
	//��һ����������ʹ���㷨��Ҫô�ǽ�������һ��Դ���У�Ҫô�ǵ���һ��Ŀ��λ�á�

	//ex11.15
	//map<int, vector<int>> int_to_vector;
	//key_type��int��mapped_type��vector<int>��value_type��pair<const int,vector<int>>

	//ex11.16
	//map<int, string> int_to_string_map = { {5,""},{6,""},{7,""} };
	//vector<string> str_vec = { "AAA","BBB","CCC" };
	//auto iter = str_vec.begin();
	//auto map_iter = int_to_string_map.begin();
	//while (map_iter != int_to_string_map.end())
	//{
	//	map_iter->second = *iter;
	//	++map_iter; ++iter;
	//}
	//auto map_it = int_to_string_map.cbegin();
	//while (map_it != int_to_string_map.cend())
	//{
	//	cout << map_it->first << "    " << map_it->second << endl;
	//	++map_it;
	//}
	
	//ex11.17
	//���Ϸ�
	
	//ex11.18
	//map<string, size_t>::const_iterator
	
	//ex11.19
	//using compare = bool(*)(const Sales_data &lhs, const Sales_data &rhs);
	//multiset<Sales_data, compare> bookstore(compareIsbn);
	//multiset<Sales_data, compare>::iterator c_it = bookstore.begin();
}

//11.3.2 ���Ԫ��
void Fun_Adding_Elements()
{
	//��Ϊmap��set���Լ���Ӧ���������ͣ��������ظ��Ĺؼ��֣�
	//����һ���Ѿ����ڵ�Ԫ�ض�����û���κ�Ӱ��
	//vector<int> ivec = { 2,4,6,8,2,4,6,8 };
	//set<int> set2;
	//set2.insert(ivec.cbegin(), ivec.cend());
	//set2.insert({ 1,3,5,7,1,3,5,7 });
	//for (auto i:set2)
	//{
	//	cout << i << "  ";
	//}

	//��map���Ԫ��
	//map<string, size_t> word_count = { { "BBB",6 },{ "AAA",5 },{ "CCC",6 } };
	//word_count.insert({ "word",1 });
	//word_count.insert(make_pair("word",1 ));
	//word_count.insert(pair<string,size_t>{ "word",1 });
	//word_count.insert(map<string,size_t>::value_type { "word",1 });

	//���insert�ķ���ֵ
	//map<string, size_t> word_count;
	//string word;
	//ifstream input("Chapter11.1.txt");
	//while (input >> word)
	//{
	//	cout << word<<"\t\t:";
	//	auto ret = word_count.insert({ word,1 });
	//	//�ɰ������ͳ�ʼ��
	//	//pair<map<string, size_t>::iterator, bool> ret = word_count.insert(make_pair(word, 1));
	//	if (!ret.second)
	//	{
	//		++ret.first->second;
	//		cout <<"has exsit";
	//	}
	//	cout << endl;
	//}

	//չ���������
	//��multiset��multimap���Ԫ��
	//multimap<string, string> authors;
	//authors.insert({ "Barth,John","Sot-Weed Factor" });
	//authors.insert({ "Barth,John","Lost in the Funhouse" });
	//auto map_it = authors.cbegin();
	//while (map_it != authors.cend())
	//{
	//	cout << map_it->first << "    " << map_it->second << endl;
	//	++map_it;
	//} 

	//ex11.20
	//map<string, size_t> word_count;
	//string word;
	//ifstream input("Chapter11.1.txt");
	//while (input >> word)
	//{
	//	auto ret_item = word_count.insert({ word,1 });
	//	if (!ret_item.second)
	//	{
	//		++ret_item.first->second;
	//	}
	//}
	//for (const auto &w : word_count)
	//{
	//	cout << w.first << " \t: " << w.second << ((w.second > 1) ? "times" : "time") << endl;
	//}

	//ex11.21
	//while (input >> word)
	//{
	//	++word_count.insert({ word,1 }).first->second;
	//}


	//ex11.22
	//�������ͣ�pair<string, vector<int>>;
	//�������ͣ�pair<map<string, vector<int>>::iterator, bool>;

	//ex11.23
	multimap<string, string> family_map;	
	
	for(string first_name; cout << "Last name:" << endl,cin >> first_name;)
	{		
		for (string name; cout << "First name:" << endl,cin >> name&&name != "end";)
		{
			family_map.insert({first_name,name});
		}

	}
	for (auto w : family_map)
	{
		cout << w.first << " " << w.second << endl;
	}
}




//11.3.3

//11.3.4

//11.3.5

//11.3.6









int main()
{
	//11.3.1 ��������������
	//Fun_Associative_Container_Iterators();
	//11.3.2 ���Ԫ��
	Fun_Adding_Elements();
	return 0;
}