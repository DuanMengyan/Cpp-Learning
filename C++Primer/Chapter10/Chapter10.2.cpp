#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��12��13�� ������
> Last edited time: 2018��12��13�� ������
> Topic:C++Primer Chapter10.2 ��ʶ�����㷨
************************************************************************/

#include "header_include.h"

using namespace std;

//Chapter10.2 ��ʶ�����㷨

//Chapter10.2.1 ֻ���㷨
void Fun_Read_Only_Algorithms()
{
	//accumulate�㷨������ͷ�ļ�numeric�У�accumulate������������������ǰ����ָ������Ҫ��͵�Ԫ�ط�Χ��������ֵ�Ǻ͵ĳ�ֵ��
	//���������������;����˺�����ʹ���ĸ��ӷ������������ֵ�����͡�

	//�㷨��Ԫ������
	//accumulate()�������������ַ���������������Ҫ��ʽ����һ��string��
	//����ֻ��ȡ�����ı�Ԫ�ص��㷨��ͨ�����ʹ��cbegin()��cend()��
	
	//�����������е��㷨
	//equal����ȷ�����������Ƿ񱣴���ͬ��ֵ����������ǰ������ʾ��һ�����е�Ԫ�ط�Χ�����һ����ʾ�ڶ������е���Ԫ��
	//Ԫ�����Ͳ���һ����ֻҪ����==���Ƚ�����Ԫ�����ͼ���

	//ex10.3
	//vector<int> ivec = { 1,2,3,4,5,6,7,8,9,10 };
	//int sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
	//cout << sum << endl;

	//ex10.4
	//double�Զ���������ת�������int���ͣ���ʧ���ȡ�

	//ex10.5
	//һ������������C����ַ����ıȽ���û�������strcmp()
	

}

//Chapter10.2.2 д����Ԫ�ص��㷨
void Fun_Algorithms_That_Write_Container_Elements()
{
	//fill����һ�Ե���������������ֵ�������������е�ÿ��Ԫ��
	//vector<int> ivec(10);
	//fill(ivec.begin(), ivec.end(), 10);
	//for (auto i : ivec)
	//{
	//	cout << i << endl;
	//}

	//�㷨�����д����
	//vector<int> ivec(10);
	//fill_n(ivec.begin(), ivec.size(), 10);
	//for (auto i : ivec)
	//{
	//	cout << i << endl;
	//}

	//����back_inserter��������ͷ�ļ�iterater
	//�����������һ�����������Ԫ�صĵ�������������ͨ��һ�������������ֵʱ��һ���븳ֵ���Ҳ�ֵ��ȵ�Ԫ����ӽ�����
	//vector<int> vec;
	//fill_n(back_inserter(vec), 10, 5);
	//for (auto i : vec)
	//{
	//	cout << i << endl;
	//}

	//�����㷨
	//copy�����뷶Χ�е�Ԫ�ؿ��������������,���ص�����Ŀ��λ�õ�����(������)��ֵ�����������βԪ�غ��ֵ��
	//int a1[] = { 0,1,2,3,4,5,6,7,8,9 };
	//cout << sizeof(a1) << endl;
	//int a2[sizeof(a1) / sizeof(*a1)];		//a2��a1��Сһ��(40/4=10)

	//auto ret = copy(begin(a1), end(a1), a2);		//��a1�����ݿ�����a2

	//replace�㷨����һ�����У������������е��ڸ���ֵ��Ԫ�ض���Ϊ��һ��ֵ
	//vector<int> ivec;
	//list<int> ilist = { 0,1,2,4,0,2,3,0,1,2,5 };
	//replace(ilist.begin(), ilist.end(), 0, 42);
	//ivec����һ��ilist�Ŀ���������������֮�����������еı���λ��
	//replace_copy(ilist.cbegin(), ilist.cend(), back_inserter(ivec), 0, 9);
	//for (auto i : ilist)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;
	//for (auto i : ivec)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;

	//ex10.6
	//vector<int> ivec = { 0,1,2,4,0,2,3,0,1,2,5 };
	//fill_n(ivec.begin(), ivec.size(), 0);

	//ex10.7
	//(a)
	//vector<int> vec; list<int> lst; int i;
	//while (cin >> i)
	//{
	//	lst.push_back(i);
	//}
	//vec.resize(lst.size());			//��Ҫ���µ���һ��������С
	//copy(lst.cbegin(), lst.cend(), vec.begin());
	//for (auto i : vec)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;

	//(b)
	//vector<int> vec;
	//vec.resize(10);					//reverse�����ڴ棬���ǲ�������������С
	//fill_n(vec.begin(), 10, 2);
	//for (auto i : vec)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;
	//ex10.8
	//back_inserter����ͷ�ļ�iterater,������algorithm

}

//Chapter10.2.3



int main()
{
	//Chapter10.2.1
	//Fun_Read_Only_Algorithms();
	//Chapter10.2.2 д����Ԫ�ص��㷨
	Fun_Algorithms_That_Write_Container_Elements();

	
	return 0;
}
