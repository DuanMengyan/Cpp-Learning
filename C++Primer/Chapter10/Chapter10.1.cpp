#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��12��13�� ������
> Last edited time: 2018��12��13�� ������
> Topic:C++Primer Chapter10.1 ����
************************************************************************/

#include "header_include.h"

using namespace std;

//Chapter10.1 ����
void Fun_Overview()
{
	//int val = 42;
	//vector<int> ivec = { 0,1,2,3,4,5,6,42,3,2,5,6 };
	//auto result = find(ivec.cbegin(), ivec.cend(), val);
	////find����ָ���һ�����ڸ���ֵ��Ԫ�صĵ����������û�У��򷵻ض���������c.end()��ʾ����ʧ��
	//cout << "The value " << val
	//	<< (result == ivec.cend() ? " is not present " : " is present ") << endl;

	//������find�������в���ֵ
	//ʹ�ñ�׼���е�begin��end�������ָ��ia����Ԫ�غ�βԪ��֮��λ�õ�ָ�룬�����ݸ�find
	//int ia[] = { 27,210,12,47,109,83 };
	//int val = 83;
	//int *result = find(begin(ia), end(ia), val);

	//���������㷨������������..........���㷨������Ԫ�����͵Ĳ���

	//ex.10.1
	//vector<int> ivec = { 1,2,4,5,10,25,2,4,10,15,1,2,10,2,1,0,10 };
	//int val = 10;
	//int val_count = count(ivec.cbegin(), ivec.cend(), val);
	//cout << "The value " << val
	//	<< " presents " << (val_count ? val_count : 0) << " times." << endl;

	//ex.10.2
	list<string> str_list = { "C++","Primer","hello","world","C++" };
	string str = "C++";
	int str_count = count(str_list.cbegin(), str_list.cend(), str);
	cout << "The string \"" << str
		<< "\" presents " << (str_count ? str_count : 0) << " times." << endl;



	//ex.10.

}




int main()
{

	//Chapter10.1 ����
	Fun_Overview();
	return 0;
}
