#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.6.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��2�� ������
> Last edited time: 2019��1��2�� ������
> Topic:C++Primer Chapter10.6 �ض������㷨
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"
//#include "Sales_item.h"


using namespace std;

//Chapter10.6 �ض������㷨
void Fun_Container_Specific_Algorithms()
{
	//����list��forward����list��Ӧ������ʹ�ó�Ա�����汾���㷨������ͨ���㷨
	//list<int> lst1 = { 0,2,4,6,8 };
	//list<int> lst2 = { 1,3,5,7,9 };
	////lst1.merge(lst2);
	////printitem(lst1);
	//lst1.merge(lst2, [](int i, int j) {return i < j; });
	//printitem(lst1);

	//splice��Ա�����������ݽṹ�����е�
	////���뵽list����Ԫ��ǰ
	//list<int> lst1 = { 0,2,4,6,8 };
	//list<int> lst2 = { 1,3,5,7,9 };
	//lst1.splice(lst1.begin(), lst2);
	//printitem(lst1);
	////���뵽ǰ���б����ǰԪ�غ�
	//forward_list<int> lst1 = { 0,2,4,6,8 };
	//forward_list<int> lst2 = { 1,3,5,7,9 };
	//lst1.splice_after(lst1.before_begin(), lst2);
	//for (auto str : lst1)
	//{
	//	cout << str << "   ";
	//}
	//cout << endl << "=========================" << endl;

	//�������еĲ�����ı�����
	//�������а汾���㷨��ı�ײ�����


	//ex10.42
	//list<string> str_lst = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	////�����ֵ�������
	//str_lst.sort();
	//printitem(str_lst);
	////ɾ����ֵͬԪ��
	//str_lst.unique();
	//printitem(str_lst);

}




int main()
{
	//Chapter10.6 �ض������㷨
	Fun_Container_Specific_Algorithms();

	return 0;
}