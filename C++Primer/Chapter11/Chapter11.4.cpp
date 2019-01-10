#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter11.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��10�� ������
> Last edited time: 2019��1��10�� ������
> Topic:C++Primer Chapter11.4 ��������
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;

size_t hasher(const Sales_data &sd)
{
	return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}


// Chapter11.4 ��������
void Fun_The_Unordered_Containers()
{
	//ʹ����������
	//unordered_map<string, size_t> word_count;
	//string word;
	//ifstream input("Chapter11.1.txt");
	//while (input >> word)
	//{
	//	++word_count[word];
	//}
	//for (const auto &item : word_count)
	//{
	//	cout << item.first << "\t\t occurs " << item.second << (item.second > 1 ? " times " : " time ") << endl;
	//}

	//����Ͱ
	//�������������������ڹ�ϣ������������Ͱ�������ʹ�С

	//cout << word_count.bucket_count() << endl;		//����ʹ�õ�Ͱ������
	//cout << word_count.max_bucket_count() << endl;	//�����������ɵ�����Ͱ������
	////for (decltype(word_count.bucket_count()) i = 0; i < word_count.bucket_count(); ++i)
	////{
	////	cout << word_count.bucket_size(i) << endl;	//��n��ͬ�е�Ԫ��
	////}
	//cout << word_count.bucket("a") << endl;			//�ؼ��֡�a�����ĸ�Ͱ��
	//cout << word_count.size() << endl;				//�����е�Ԫ�ظ���		
	//cout << word_count.load_factor() << endl;		//ÿ��Ͱ��ƽ��Ԫ�ظ���
	//cout << word_count.max_load_factor() << endl;
	//word_count.rehash(120);
	//cout << "===============================" << endl;
	//cout << word_count.bucket_count() << endl;		//����ʹ�õ�Ͱ������
	//cout << word_count.max_bucket_count() << endl;	//�����������ɵ�����Ͱ������

	//cout << word_count.size() << endl;				//�����е�Ԫ�ظ���		
	//cout << word_count.load_factor() << endl;		//ÿ��Ͱ��ƽ��Ԫ�ظ���
	//cout << word_count.max_load_factor() << endl;
	

	//���������Թؼ������͵�Ҫ��

	//using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
	//������Ͱ�Ĵ�С����ϣ����ָ���������ж������ָ��
	//SD_multiset bookstore(42, hasher, eqOp);
	//������ǵ��ඨ����==������������ֻ���ع�ϣ����
	//unordered_set<Sales_data, decltype(hasher)*> bookstore(42, hasher);

	//ex11.37
	//����v�����������
	//�����������
	//	��׼����������˳�����Ԫ��
	//	����ָ������ν��
	//	Ĭ��˳��ν���ǡ�С�ڡ���ʹ��operator<ΪԪ�����Ͷ���
	//	���е�ʵ�֣�OrderedVector��BinarySearchTree
	//	����������Ҫ����O��log n������ʱ��
	//	���룬ɾ������Ӧ�ú���ʹ�û����O��log n������ʱ
	//�����������
	//	��׼������δָ����˳�����Ԫ��
	//	���������룬ɾ������Ӧ����ƽ����Сд��������ʱ
	//	���е�ʵ��ʹ��ɢ�У�hash��

	//ex11.38
	ifstream map_file("map_file.txt");
	ifstream input("input_text11.3.6.txt");
	string str_line;
	//����ת���ֵ�
	unordered_map<string, string> trans_map;
	string key;		//Ҫת���ĵ���
	string value;	//�滻�������

	while (map_file >> key && getline(map_file,value))
	{
		if (value.size() > 1)
			trans_map[key] = value.substr(1);		//����ǰ���ո�
	}

	//ת�������ı�
	while (getline(input, str_line))
	{
		istringstream stream(str_line);
		string word;
		while (stream>>word)
		{
			auto it = trans_map.find(word);
			if (it != trans_map.end())
				cout << it->second << " ";
			else
				cout << word << " ";			
		}
		cout << endl;
	}
}


int main()
{
	// Chapter11.4 ��������
	Fun_The_Unordered_Containers();
	return 0;
}