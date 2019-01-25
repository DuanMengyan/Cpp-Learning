#pragma once
#pragma execution_character_set("utf-8")
#pragma  warning (disable:4996) 


/*************************************************************************
> File Name: Chapter12.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��24�� ������
> Last edited time: 2019��1��25�� ������
> Topic:C++Primer Chapter12.2 ��̬����
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"
//#include "StrBlob.h"
//#include "StrBlobPtr.h"
//#include "ConstStrBlobPtr.h"

using namespace std;

//Chapter12.2 ��̬����
//Dynamic_Arrays


//ex12.23
void str_connection(char str1[] , char str2[])
{
	cout << strlen(str1) + strlen(str2) << endl;
	char *cp = new char[strlen(str1)+strlen(str2)]();
	strcat(cp, str1);
	strcat(cp, str2);
	cout << cp ;
	cout << "================" << endl;
	
}

void str_connection(string &str1, string &str2)
{
	cout << str1 + str2;
	cout << "================" << endl;
}


//12.3.1 new������
void Fun_new_and_Arrays()
{
	//�������еĴ�С���������ͣ��������ǳ���
	//int *pia = new int[5];     //piaָ���һ��int
	////Ҳ������һ����ʾ�������͵����ͱ���������һ������
	//typedef int arrT[42];
	//int *p = new arrT;
	////�ȼ���
	//int *p2 = new int[42];

	//����һ�������õ�һ��Ԫ�����͵�ָ��
	//���ڷ�����ڴ沢����һ���������ͣ���˲��ܶԶ�̬�������begin��end��
	//Ҳ����ʹ�÷�Χfor���������̬�����е�Ԫ��

	//��ʼ����̬������������
	//�ڴ�С֮���һ�Կ����Ŷ��������ֵ��ʼ��
	//�ṩһ��Ԫ�س�ʼ�������г�ʼ��
	//�����������и�����ʼ����������ʹ��auto��������
	//int *pia3 = new int[10]{ 0,1,2,3,4,5,6,7,8,9 };

	//��̬����һ���������ǺϷ���
	//char arr[0];   //��������Ĵ�С�������0
	//char *cp = new char[0];		//��ȷ������cp��ָ���κ�Ԫ�أ����ܽ�����

	//�ͷŶ�̬���飬�����е�Ԫ����������
	//delete p;			//p����ָ��һ����̬����Ķ����Ϊ��
	//delete []cp;		//cp����ָ��һ����̬����������Ϊ��

	//���ܶ���ʱ��ʽ��Σ�cpָ��һ�������������Ԫ�أ�������ĳ�����͵�һ����һ����������ͷ�����ʱ��������Ϸ�����

	//����ָ��Ͷ�̬����
	//unique_ptrָ��һ����̬����������ǣ�����ʹ�õ�ͼ�ͷ��Ա�����������ʹ���±����������Ԫ��
	//unique_ptr<int[]> up(new int[10]);
	//���ϣ��ʹ��shared_ptr����һ����̬���飬�����ṩ�Լ������ɾ����
	//shared_ptr<int> sp(new int[10], [](int*p) {delete p; });
	//shared_ptrδ�����±��������ʹ��get��ȡһ������ָ�룬����������Ԫ��
	
	//ex12.23
	//string str1 = "hello", str2 = "world";
	//str_connection("hello", "world");
	//str_connection(str1, str2);

	//ex12.24
		
	//cout << "How long do you want the string? ";
	//int size = 0;
	//cin >> size;
	//char *input = new char[size+1]();
	//cin.ignore();
	//cout << "input the string: ";
	//cin.get(input, size+1);
	//cout << input;
	//delete[] input;
	
	//ex12.25
	//int *pa = new int[10];
	//delete[] pa;
}


//12.3.2 allocator��
void Fun_The_allocator_Class()
{
	//û��Ĭ�Ϲ��캯�����಻�ܶ�̬��������
	
	//allocator�ཫ�ڴ����Ͷ�������뿪��
	//����һ��ԭʼ�ġ�δ��������ڴ�
	//allocator����Ϊ������ڴ�
	//allocator<string> alloc;
	//auto p = alloc.allocate(10);
	//auto q = p;			//qָ��������Ԫ��֮���λ�ã�
	//alloc.construct(q++);
	//alloc.construct(q++, 10, 'c');
	//alloc.construct(q++, "hello");
	//
	//while (q!=p)
	//{
	//	cout << *(--q) << endl;
	//	//��ָ��Ķ���ִ������������ֻ�ܶ����������˵�Ԫ��ִ��destroy����
	//	alloc.destroy(q);	
	//}
	////Ԫ�ر������Ժ󣬿�������ʹ���ⲿ���ڴ棬Ҳ���Խ���黹��ϵͳ��
	////����deallocateǰ�������ÿ��Ԫ��ִ��destroy
	//alloc.deallocate(q, 10);//ͳһ���䣬ͳһ�ͷ�

	//���������δ��ʼ���ڴ���㷨
	
	//vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	//allocator<int> alloc;
	//auto p = alloc.allocate(vec.size() * 2);
	////ÿ�ε���uninitialized_copy����һ������Ԫ��֮��λ�õ�ָ��
	//auto q = uninitialized_copy(vec.begin(), vec.end(), p);
	//auto m = uninitialized_fill_n(q, vec.size(), 42);
	//while (m != p)
	//{
	//	cout << *(--m) << "   ";
	//}

	//ex12.26
	//allocator<string> alloc;
	//auto p = alloc.allocate(10);
	//ifstream input("Text2.txt");
	//string str;
	//auto q = p;
	//for (; q != p + 10 && getline(input, str); q++)
	//{
	//	alloc.construct(q, str);
	//}
	//while (q != p)
	//{
	//	cout << *(--q) << endl;
	//}
}

int main()
{
	//12.3.1 new������
	//Fun_new_and_Arrays();
	//12.3.2 allocator��
	Fun_The_allocator_Class();

	return 0;
}