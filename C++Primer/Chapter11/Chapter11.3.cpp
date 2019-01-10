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
	//multimap<string, string> family_map;	
	//
	//for(string first_name; cout << "Last name:" << endl,cin >> first_name;)
	//{		
	//	for (string name; cout << "First name:" << endl,cin >> name&&name != "end";)
	//	{
	//		family_map.insert({first_name,name});
	//	}
	//}
	//for (auto w : family_map)
	//{
	//	cout << w.first << " " << w.second << endl;
	//}
}

//11.3.3 ɾ��Ԫ��
void Fun_Erasing_Elements()
{
	//ͨ����erase����һ����������һ������������ɾ��һ��Ԫ�ػ���һ��Ԫ�ط�Χ
	//�����erase��������һ��key_type�������˰汾ɾ������ƥ������ؼ��ֵ�Ԫ�أ�����ʵ��ɾ����Ԫ�ص�����
}

//11.3.4 map���±����
void Fun_Subscripting_a_map()
{
	//���ܶ�multi�����±��������Ϊ��Щ�������ж��ֵ��һ���ؼ��������
	//����ؼ��ֲ���map�У����Ϊ������һ��Ԫ�ز��뵽map�С�
	//ֻ�ܶԷ�const��mapʹ���±�
	//map<string, size_t> word_count;
	//word_count["Anna"] = 1;

	//ʹ���±�����ķ���ֵ
	//cout << word_count["Anna"] << endl;
	//++word_count["Anna"];
	//cout << word_count["Anna"] << endl;

	//ex11.24
	//��m�������ؼ���Ϊ0��Ԫ�أ�
	//û���ҵ�������m�����һ���ؼ���Ϊ0��Ԫ�أ�
	//����Ԫ�ظ���Ϊ1

	//ex11.25
	//vector<int> v;
	//v[0] = 1;
	//�﷨û�д��󣬵���v�Ǹ���vector���±�Խ��

	//ex11.26
	//map<int, string> m = { {1,"AAA"},{2,"BBB"} };
	//using KeyType = map<int, string>::key_type;
	//cout << " sunbscript :" << typeid(KeyType).name() << endl;		//const int
	//cout << "return" << typeid(decltype(m[1])).name() << endl;		//string
}

//11.3.5 ����Ԫ��
void Fun_Accessing_Elements()
{
	set<int> iset = { 1,2,3,4,5,6,7,8,9 };
	//auto it = iset.find(1);
	//auto it = iset.find(11);
	//if (it != iset.end()) cout << *it << endl;
	//else cout << "not find" << endl;

	//cout << iset.count(1) << endl;
	//cout << iset.count(11) << endl;
	
	//��mapʹ��find�������±����
	//���ֻ����һ�������ؼ����Ƿ���map�У�������ı�map��Ӧ����find

	//��multimap��multiset�в���Ԫ��
	//һ�ֲ�ͬ�ģ�����������Ľ������
	//���lower_bound��upper_bound������ͬ�ĵ�������������ؼ��ֲ���������
	//multimap<string, string> authors = { { "AAA","BOOK1" } ,{ "CCC","Book2" } ,{ "BBB","C++" },{ "GGG","HAHAHA" },{ "BBB","book1" },{ "CCC","hello" } };
	//for (auto beg = authors.lower_bound("GGG"), end = authors.upper_bound("GGG"); beg != end; ++beg) 
	//{
	//	cout << beg->first << "    " << beg->second << endl;
	//}
	
	//equal_range����
	//multimap<string, string> authors = { { "AAA","BOOK1" } ,{ "CCC","Book2" } ,{ "BBB","C++" },{ "GGG","HAHAHA" },{ "BBB","book1" },{ "CCC","hello" } };
	//for (auto pos = authors.equal_range("BBB");pos.first!=pos.second;++pos.first)
	//{
	//	cout << pos.first->first << "    " << pos.first->second << endl;
	//}

	//ex11.27
	//������Ҫͳ�ƹؼ��ֳ��ִ����ĵط���ʹ��count
	//����ֻ��Ҫ���ؼ����Ƿ��ڹ��������еĵط�����ʹ��find
	
	//ex11.28
	//map<string, vector<int>>::iterator it;
	
	//ex11.29
	//upper_bound()����һ����������ָ��Ӱ��ԭ��Ԫ������Ĺؼ��ֲ���λ��
	
	//ex11.30
	//��һ��������Ԫ��ƥ���Ԫ�ص�ֵ

	//ex11.31-11.32
	//multimap<string, string> authors = { { "AAA","BOOK1" } ,{ "CCC","Book2" } ,{ "BBB","C++" },{ "GGG","HAHAHA" },{ "BBB","book1" },{ "EEE","hello" } };
	//auto it = authors.find("BBB");
	//while (it != authors.end())
	//{
	//	authors.erase(it);
	//	it = authors.find("BBB");
	//}
	//for (auto item : authors)
	//{
	//	cout << item.first << "       " << item.second << endl;
	//}

	//ex11.32
}

//11.3.6 һ������ת����map
void Fun_A_Word_Transformation_Map()
{

	//ifstream map_file("map_file.txt");
	//ifstream input("input_text11.3.6.txt");
	//string str_line;
	////����ת���ֵ�
	//map<string, string> trans_map;
	//string key;		//Ҫת���ĵ���
	//string value;	//�滻�������

	//while (map_file >> key && getline(map_file,value))
	//{
	//	if (value.size() > 1)
	//	{
	//		trans_map[key] = value.substr(1);		//����ǰ���ո�
	//		cout << value.substr(1) << endl;
	//	}
	//	else
	//		cout << ("no rule for" + key) << endl;
	//}

	////����ת���ֵ�
	////while (getline(map_file, str_line))
	////{
	////	auto  space = str_line.find_first_of(' ');
	////	string key(str_line,0,space);
	////	string value(str_line, space + 1);
	////	trans_map[key] = value;
	////}


	////ת�������ı�
	//while (getline(input, str_line))
	//{
	//	istringstream stream(str_line);
	//	string word;
	//	while (stream>>word)
	//	{
	//		auto it = trans_map.find(word);
	//		if (it != trans_map.end())
	//			cout << it->second << " ";
	//		else
	//			cout << word << " ";			
	//	}
	//	cout << endl;

	//	////�Ӷ�ȡ���������δ���ÿ����
	//	//while (!str_line.empty())
	//	//{
	//	//	auto space = str_line.find_first_of(' ');
	//	//	string str_temp;
	//	//	if (space!= string::npos)
	//	//	{
	//	//		str_temp.assign(str_line, 0, space);
	//	//		str_line.erase(0, space + 1);
	//	//	}
	//	//	else
	//	//	{
	//	//		str_temp = str_line;
	//	//		str_line.clear();
	//	//	}			
	//	//	
	//	//	auto it = trans_map.find(str_temp);
	//	//	if (it != trans_map.end())
	//	//		cout << it->second << " ";
	//	//	else cout << str_temp << " ";			
	//	//}
	//	//cout << endl;
	//}

	//ex11.33
	//����
	
	//ex11.34
	//�޸ĺ�Ĵ��뽫�޷����룬��Ϊ�±���������ܻ����һ��Ԫ�أ����Ҳ������м�s��Ԫ��ʱ��
	//��������ֻ�ܽ��ڲ���const�Ĺؼ���-ֵ����ʹ���±ꡣ
	
	//ex11.35
	//���һ�����ʳ��ֶ�Σ�
	//�±�Ὣ���һ�ζ�Ӧ�Ķ�����뵽map��
	//ʹ��insert�Ὣ��һ�εĶ�Ӧ������뵽map�С�

	//ex11.36
	//�������������ֵ�Խ���{key������}��������size������> 1�����޷�������ӵ�map�С� ��ˣ���Կ���ᱻ�κ��ַ����滻��

}



int main()
{
	//11.3.1 ��������������
	//Fun_Associative_Container_Iterators();
	//11.3.2 ���Ԫ��
	//Fun_Adding_Elements();
	//11.3.3 ɾ��Ԫ��
	//Fun_Erasing_Elements();
	//11.3.4 map���±����
	//Fun_Subscripting_a_map();
	//11.3.5 ����Ԫ��
	//Fun_Accessing_Elements();
	//11.3.6 һ������ת����map
	Fun_A_Word_Transformation_Map();
	return 0;
}