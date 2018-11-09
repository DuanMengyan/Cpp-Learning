#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter9.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��10��29�� ����һ
> Last edited time: 2018��11��9�� ������
> Topic:C++Primer Chapter9.2 ���������
************************************************************************/

#include "header_include.h"

using namespace std;


//9.2 ���������
void Fun_Container_Library_Overview()
{
	//ex9.2
	list<deque<int>> int_deque_list{ {0,1,2}, {1,2,3}, {2,3,4} };
	for (auto &a : int_deque_list)
	{
		a.push_front(5);	//	����һ������5
	}
	for (auto a : int_deque_list)
	{
		for (auto b : a)
		{
			cout << b << "  ";		//��ӡ
		}
		cout << endl;
	}

}

//ex.9.4 -9.5
vector<int>::const_iterator SearchKey(vector<int>::const_iterator left, vector<int>::const_iterator right, int key)
{
	if (left > right)
	{
		cout << "Error!" << endl;
		return right;
	}
	else
	{
		while (left != right)
		{
			if (*left == key)
			{
				return left;
			}
			++left;
		}
		return right;

	}
}


//9.2.1 ������
void Fun_Iterators()
{
	//��������Χ����պ�����[begin,end��
	//end������begin֮ǰ
	//ʹ����պϷ�Χ�̺��ı�̼ٶ�
	
	//ex.9.3
	//begin��endָ��ͬһ�����е�Ԫ��
	//begin������������end

	//ex.9.4
	//vector<int> int_vec{ 1, 3, 5, 6, 8, 9, 7 };
	//auto begin = int_vec.cbegin(), end = int_vec.cend();
	//cout << SearchKey(begin, end, 6) << endl;
	
	//ex.9.5
	//vector<int> int_vec{ 1, 3, 5, 6, 8, 9, 7 };
	//auto begin = int_vec.cbegin(), end = int_vec.cend();
	//auto result = SearchKey(begin, end, 2);
	//if (result != end)
	//{
	//	cout << *result << endl;
	//}
	//else
	//{
	//	cout << "Can not find value!" << endl;
	//}

	//ex.9.6
	//list<int> lst1;
	//list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
	//while (iter1 != iter2)
	//{
	//	/*
	//	�����<δ��list��ʵ�֣�list��˫����������ڵ�ĵ�ַ��һ����������
	//	*/
	//}
}

//9.2.2 �������ͳ�Ա
void Fun_Container_Type_Members()
{
	////ex.9.7
	//vector<int>::size_type;
	////ex.9.8
	//list<string>::const_iterator;		//to read
	//list<string>::iterator;				//to write
}

//9.2.3 begin��end��Ա
void Fun_begin_and_end_Members()
{
	//begin()��end()�����������;���γ�һ����������������Ԫ�صĵ�������Χ
	//��r�İ汾���ط������������c��ͷ�İ汾����const������

	//��c��ͷ�İ汾��C++�±�׼����ģ�����֧��auto��begin��end�������ʹ�á�
	//����Ҫд����ʱ��Ӧʹ��cbegin��cend

	//ex.9.9
	//cbegin��һ��const��Ա������������const_iterator����
	//begin����ͨ��Ա������������iterator����

	//ex.9.10
	//vector<int> v1; //
	//const vector<int> v2;
	//auto it1 = v1.begin();		//vector<int>::iterator
	//auto it2 = v2.begin();		//vector<int>::const_iterator
	//auto it3 = v1.cbegin();		//vector<int>::const_iterator
	//auto it4 = v2.cbegin();		//vector<int>::const_iterator
}

class Person
{
public:
	Person() :age(10), name("Tom"){ };
	Person(int a, string n) :age(a), name(n){ };
	void print()
	{
		cout << name << " is " << age << " years old." << endl;
	}

private:
	string name;
	int age;

};

//9.2.4 ��������ͳ�ʼ��
void Fun_Defining_and_Initializing_a_Container()
{
	//��һ��������ʼ��Ϊ��һ�������Ŀ���
	//��һ������������Ϊ��һ�������Ŀ����ķ��������֣�
	//����ֱ�ӿ��������������������������ͼ�Ԫ�����ͱ���ƥ�䣩
	//���߿�����һ����������ָ����Ԫ�ط�Χ����Ҫ����ͬ��

	//list<string> authors = { "Milton", "Shakespaeare", "Austen" };
	//vector<const char*> articles = { "a", "an", "the" };

	//list<string> list2(authors);
	////deque<string> authList(authors);			//�������Ͳ�ƥ��
	////vector<string> words(articles);			//����Ԫ�����Ͳ�ƥ��
	//
	////���Խ�const char*Ԫ��ת��Ϊstring
	//forward_list<string> words(articles.begin(), articles.end());

	//for (auto i : words)
	//{
	//	cout << i << endl;
	//}


	//�б��ʼ��
	//������array֮����������ͣ���ʼ���б��������ƶ��������Ĵ�С

	//��˳��������С��صĹ��캯��
	//���Ԫ��������û��Ĭ�Ϲ��캯���������ͣ����˴�С������������ָ��һ����ʾ��Ԫ�س�ʼֵ
	//vector<Person> people1(5);
	//vector<Person> people2(5, Person(20, "Bob"));

	//for (auto i : people1)
	//{
	//	i.print();
	//}
	//cout << "=========================" << endl;
	//for (auto i : people2)
	//{
	//	i.print();
	//}

	//��׼��array���й̶���С
	//������һ��arrayʱ������ָ��Ԫ�����ͣ���Ҫָ��������С
	//��array�����б��ʼ������ʼֵ����Ŀ������ڻ�С��array�Ĵ�С
	//����ʣ�µ�Ԫ�ض������ֵ��ʼ��;
	//����������£����Ԫ��������һ�������ͣ���ô���������һ��Ĭ�Ϲ��캯��
	//���Զ�array���п��������ֵ�����������������Ͳ��У�
	//��������Ҫ���ʼֵ���ͺ�Ҫ����������������ͬ����Ҫ��Ԫ�����ͺʹ�СҲ��һ��

	//array<int, 42> int_arr;
	//array<string, 10> str_arr;

	//array<Person, 10> Per_arr;
	//for (auto i:Per_arr)
	//{ 
	//	i.print();	
	//}
	
	//ex9.11
	//vector<int> other_vec;								//��
	//vector<int> vec(10);									//10��0
	//vector<int> vec = {10};								//1��10
	//vector<int> vec(10, 1);								//10��1
	//vector<int> vec{ 1, 2, 3, 4, 5 };						//1,2,3,4,5
	//vector<int> vec(other_vec);							//other_vec�Ŀ���
	//vector<int> vec(other_vec.begin(), other_vec.end());	//��other_vecһ��

	//ex9.12
	//��������������Ҫ�����������Լ�Ԫ������һ�£����������е�����Ԫ��
	//���ܵ��������������Ĺ��캯����Ҫ�����������Լ�Ԫ������һ�£�����ת�����ɣ���������������Χ���Ԫ��

	//ex9.13
	//list<int> int_list(5,4);
	//vector<double> dou_vec1(int_list.begin(),int_list.end());

	//vector<int> int_vec(5,5);
	//vector<double> dou_vec2(int_vec.begin(),int_vec.end());
	//for (double i : dou_vec2)
	//{
	//	cout << i << "  ";
	//}

}


//9.2.5 ��ֵ��swap
void Fun_Assignment_and_swap()
{
	//��׼��array��������ֵ����ֵ���������ߵ����������������ͬ�����ͣ���СҲ����ΪԪ�����ͣ�
	//array<int, 10> a1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//cout << a1.size() << endl;
	//array<int, 10> a2 = { 0 };
	//a1 = a2;
	//cout << a1.size() << endl;

	//ʹ��assign����˳��������
	//���ھ�Ԫ�ر��滻�����ת�ݸ�assign�ĵ���������ָ�����assign������
	//list<string> names;
	//vector<const char*> oldstyle = { 5, "ABC" };
	//for (const char* c : oldstyle)
	//{
	//	//c��ָ���ַ�����ABC�������ַ����ַ�ָ��
	//	cout << c << endl;
	//}
	////names = oldstyle;			//�������Ͳ�ƥ�䣬����
	//cout << "========================" << endl;
	//names.assign(oldstyle.begin(),oldstyle.end());
	//for (auto s: names)
	//{ 
	//	cout << s << endl;
	//}
	//assign�ڶ����汾
	//list<string> slist1(1);
	//slist1.assign(10, "ABC");
	////�ȼ���
	//slist1.clear();
	//slist1.insert(slist1.begin(), 10, "ABC");


	//ʹ��swap,����������ͬ�������������ݡ�
	//��array�⣬swap�����κ�Ԫ�ؽ��п�����ɾ������������
	//Ԫ�ر���δ������ֻ�ǽ����������������ڲ����ݽṹ
	//��˿��Ա�֤�ڳ���ʱ�������
	//swap����array�������������ǵ�Ԫ�ء�

	//ex9.14
	//list<const char*> char_list = { "ABC", "BBB" };
	//vector<string> str_vec;
	//str_vec.assign(char_list.cbegin(),char_list.cend());
	//for (auto s : str_vec)
	//{
	//	cout << s << endl;
	//}
}

//9.2.7	��ϵ�����
void Fun_Relational_Operators()
{
	//ÿ���������Ͷ�֧������������==�ͣ�=����
	//����������������������������֧�ֹ�ϵ�������>��>=��<��<=��

	//�������������������һ��������ǰ׺�����У������ǵıȽϽ��ȡ���ڵ�һ�������Ԫ�صıȽϽ��

	//vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
	//vector<int> v2 = { 1, 3, 9 };
	//vector<int> v3 = { 1, 3, 5, 7 };
	//vector<int> v4 = { 1, 3, 5, 7, 9, 12 };

	//cout << std::boolalpha << (v1 < v2) << endl;
	//cout << (v1 < v3) << endl;
	//cout << (v1 == v4) << endl;
	//cout << (v1 == v2) << endl;

	//�����Ĺ�ϵ�����ʹ��Ԫ�صĹ�ϵ�������ɱȽ�
	//���Ԫ�ص����Ͳ�֧���������������ô��������Ԫ�ص������Ͳ���ʹ����Ӧ�Ĺ�ϵ���㡣

	//ex9.15
	vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
	vector<int> v2 = { 1, 3, 9 };
	cout << std::boolalpha << (v1 == v2) << endl;
	//ex9.16
	vector<int> v3 = { 1, 3, 5, 7, 9, 12 };
	list<int> l4 = { 1, 3, 9 };
	cout << (vector<int> (l4.begin(), l4.end()) > v3 ? "true" : "false") << endl;
	//ex9.17
	//c1��c2������ͬһ�������Ұ�����ͬ��Ԫ������
	//Ԫ�ص�����֧�ֹ�ϵ����
	//c1 �� c2���ǳ������������֮����������� 
}



int main()
{
	//9.2 ���������
	//Fun_Container_Library_Overview();

	//9.2.1 ������
	//Fun_Iterators();

	//9.2.2 �������ͳ�Ա
	//Fun_Container_Type_Members();

	//9.2.3 begin��end��Ա
	//Fun_begin_and_end_Members();

	//9.2.4 ��������ͳ�ʼ��
	//Fun_Defining_and_Initializing_a_Container();

	//9.2.5 ��ֵ��swap
	//Fun_Assignment_and_swap();

	//9.2.7 ��ϵ�����
	Fun_Relational_Operators();

	return 0;
}