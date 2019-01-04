#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter11.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��4�� ������
> Last edited time: 2019��1��4�� ������
> Topic:C++Primer Chapter11.3 ������������
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;

// Chapter11.3 ������������

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
	map<string, size_t> word_count = { {"AAA",5},{"BBB",6},{"CCC",6} };
	auto map_it = word_count.begin();
	while (map_it != word_count.cend())
	{
		cout << map_it->first << "    " << map_it->second << endl;
		++map_it;
	}





}

//11.3.2

//11.3.3

//11.3.4

//11.3.5

//11.3.6









int main()
{
	//11.3.1 ��������������
	Fun_Associative_Container_Iterators();
	return 0;
}