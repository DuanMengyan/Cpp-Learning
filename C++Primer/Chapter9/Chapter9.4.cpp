#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��12��8�� ������
> Last edited time: 2018��12��8�� ������
> Topic:C++Primer Chapter9.4 vector���������������
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"

using namespace std;


template <class T>
void Myprint(T & container)
{
	//��ӡ�����е�Ԫ��
	for (auto i : container)
	{
		cout << i <<endl;
	}
	cout << endl;
}

// 9.4 vector���������������
void Fun_How_a_vector_Grows()
{
	//���������ĳ�Ա����
	//capacity��size
	//vector<int> ivec;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;
	//for (vector<int>::size_type ix = 0; ix != 24; ++ix)
	//{
	//	ivec.push_back(ix);
	//}
	//cout << "=====================" << endl;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;
	//ivec.reserve(50);
	//cout << "=====================" << endl;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;
	//while (ivec.size() != ivec.capacity())
	//{
	//	ivec.push_back(0);
	//}
	//cout << "=====================" << endl;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;

	//ivec.push_back(10);
	//cout << "=====================" << endl;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;

	//ivec.shrink_to_fit();
	//cout << "=====================" << endl;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;

	//ex9.35
	//size��ָһ��vector������ǰ��������Ԫ�ظ���
	//capacity��ָ�������ڴ�����ǰ����һ��vector�������ܱ����Ԫ�ظ���

	//ex9.36
	//����

	//ex9.37
	//vector���ڴ�����������ŵģ���Ҫcapacity
	//list���ڴ��в���������ŵģ�����Ҫ
	//array��С�̶�

	//ex9.38
	//vector<int> ivec;
	//cout << "ivec:size:" << ivec.size() << endl;
	//cout << "ivec:capacity:" << ivec.capacity() << endl;
	//int val;
	//while (cin>>val)
	//{
	//	ivec.push_back(val);
	//	cout << "=====================" << endl;
	//	cout << "ivec:size:" << ivec.size() << endl;
	//	cout << "ivec:capacity:" << ivec.capacity() << endl;
	//}


	//ex9.39-ex9.40

	//����һ������1000���ַ������ļ�
	ofstream output("input.txt");
	output.clear();
	int i = 0;
	while (i != 1000)
	{
		output << "HAHAH" << endl;
		i++;
	}
	output.close();

	//�ַ�������
	vector<string> svec;
	svec.reserve(0);
	cout << "svec:size:" << svec.size() << endl;
	cout << "svec:capacity:" << svec.capacity() << endl;
	
	//���ı��ļ��ж����ַ���
	string word;
	ifstream input("input.txt");
	while (input >> word)
	{
		svec.push_back(word);	
	}

	cout << "=====================" << endl;
	cout << "svec:size:" << svec.size() << endl;
	cout << "svec:capacity:" << svec.capacity() << endl;

	svec.resize(svec.size() + svec.size() / 2);

	cout << "=====================" << endl;
	cout << "svec:size:" << svec.size() << endl;
	cout << "svec:capacity:" << svec.capacity() << endl;

}




int main()
{
	// 9.4 vector���������������
	Fun_How_a_vector_Grows();
	return 0;
}