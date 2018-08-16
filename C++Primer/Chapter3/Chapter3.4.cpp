#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter3.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��08��16�� ������
> Last edited time: 2018��8��16�� ������
> Topic:C++Primer Chapter3.4 ����������
************************************************************************/


#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;


//3.4.1ʹ�õ�����
void Fun_iterator()
{
	

	//string s("some string");
	//if (s.begin() != s.end())			//���s�Ƿ�Ϊ��
	//{
	//	auto it = s.begin();
	//	*it = toupper(*it);
	//}
	//cout << s << endl;

	//
	//if (s.begin() != s.end())
	//{		
	//	for (auto it = s.begin(); it != s.end() && !isspace(*it);++it)
	//	{
	//		*it = toupper(*it);
	//	}
	//}
	//cout << s << endl;


	//����������
	//vector<int>::iterator it;			//it �ܶ�дvector<int>��Ԫ��

	//const vector<int> vec{1,2,3,4};
	//vector<int>::const_iterator it=vec.begin();	//itֻ�ܶ�Ԫ�أ�����дԪ��
	//for (; it != vec.end(); ++it)
	//{
	//	//*it = 5;				//����
	//	cout << *it<<"\t";
	//}


	//begin��end�����
	//vector<int> v;
	//const vector<int> cv;
	//auto it1 = v.begin();			//it1��������vector<int>::iterator
	//auto it2 = cv.begin();			//it2��������vector<int>::const_iterator

	//auto it3 = v.cbegin();			//it3��vector<int>::const_iterator���ͣ�ֻ�ܶ�����

	//��Ͻ����úͳ�Ա���ʲ��� 
	//��ͷ�������->���ѽ����úͳ�Ա�����������������һ�� 
	//vector<string> text;
	//string str;
	//while (getline(cin,str))
	//{
	//	text.push_back(str);		//����һ���ַ�������
	//}
	////һ�����text�е�ÿһ���ַ�����ֱ��������һ���հ��л��߽���
	//for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) 
	//	cout << *it << endl;


	//ĳЩ��vector����Ĳ������ǵ�����ʧЧ
	//��������Ӧ�˵�������ѭ���壬����Ҫ��������������������Ԫ�أ�
	//push_back��������vector����ĵô���ʧЧ
	

	//ex3.21
	//vector<int> v1;						//��
	//vector<int> v2(10);					//10��0
	//vector<int> v3(10, 42);				//10��42
	//vector<int> v4{ 10 };				//10
	//vector<int> v5{ 10, 42 };			//2��Ԫ�أ�10��42
	//vector<string> v6{ 10 };				//v6����10��Ĭ�ϳ�ʼ����Ԫ��,�ȼ���vector<string> v6{ 10 };
	//vector<string> v7(10, "hi");		//10����hi��
	////vector<string> v8("hi");			//������ʹ���ַ�������ֵ����ve

	//for (auto it = v2.cbegin(); it != v2.cend(); ++it)
	//	cout << *it << "\t";
	//cout << endl;
	//for (auto it = v7.cbegin(); it != v7.cend(); ++it)
	//	cout << *it << "\t";
	//cout << endl;

	//3.22
	//vector<string> text;
	//string str;
	//while (getline(cin,str))
	//{
	//	text.push_back(str);		//����һ���ַ�������
	//}
	////һ�����text�е�ÿһ���ַ�����ֱ��������һ���հ��л��߽���
	//for (auto it = text.begin(); it != text.end(); ++it)
	//{
	//	if (!it->empty())
	//	{
	//		for (auto sit = it->begin(); sit != it->end();++sit)
	//		{
	//			*sit = toupper(*sit);
	//		}
	//	}
	//	cout << *it << endl;
	//}
	
	//3.23
	//vector<int> vec(10,5);
	//for (auto it = vec.begin(); it != vec.end(); ++it)
	//{
	//	*it = 2 * *it;
	//	cout << *it << "\t";
	//}
	//cout << endl;
}


//3.4.2������ԭ��
void Fun_iterator_arithmetic()
{


}



int main()
{
	Fun_iterator();
	return 0;
}