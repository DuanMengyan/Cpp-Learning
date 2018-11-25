#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��11��9�� ������
> Last edited time: 2018��11��25�� ������
> Topic:C++Primer Chapter9.3 ˳����������
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"

using namespace std;

//9.3 ˳����������
//Sequential Container Operations

//9.3.1 ��˳���������Ԫ��
void Fun_Adding_Elements_to_a_Sequential_Container()
{
	//��һ��vector ��string �� deque����Ԫ�ػ�������ָ�������ĵ����������ú�ָ��ʧЧ

	//ʹ��push_back

	//string str = "hello world";
	//str.push_back('!');			//�ȼ���str += 's'

	//��һ�������ʼ������ʱ����һ��������뵽������ʱ��ʵ���Ϸ��뵽�����е��Ƕ���ֵ��һ������
	//����������Ԫ�ص��κθı䲻��Ӱ�쵽ԭʼ���󣬷�֮��Ȼ


	//ʹ��push_front
	//list<int> ilist;
	//for (size_t ix = 0; ix != 4; ++ix)
	//	ilist.push_front(ix);

	//for (auto i : ilist)
	//{
	//	cout << i << "  ";
	//}
	
	//deque��vectorһ���ṩ���������Ԫ�ص������������ṩ��vector����֧�ֵ�push_front��
	//deque��֤��������β���в����ɾ��Ԫ�صĲ��������ѳ���ʱ��
	//��vectorһ������deque��β֮���λ�ò���Ԫ�ػ�ܺ�ʱ


	//�������е��ض�λ�����Ԫ��
	//vector��deque��list��string��֧��insert��Ա

	//���뷶Χ��Ԫ��
	//��������ʾҪ�����ķ�Χ������ָ�����Ԫ�ص�Ŀ������
	//list<int> ilist;
	//vector<int>  v = { 1, 2, 3, 4 };
	//auto i = ilist.insert(ilist.begin(), v.end() - 2, v.end());
	//cout << *i << endl;
	
	//ʹ��insert�ķ���ֵ
	//list<string> lst;
	//auto iter = lst.begin();
	//string word;
	//while (cin >> word)
	//{
	//	iter = lst.insert(iter, word);		//�ȼ���push_front
	//} 
	//for (auto str : lst)
	//{
	//	cout << str << "   " << endl;
	//}

	//ʹ��empalce����
	//����empalce��Ա������������ֵ���ݸ�Ԫ�����͵Ĺ��캯��
	//empalce��Աʹ����Щ����������������ڴ�ռ���ֱ�ӹ���Ԫ�أ��������
	//empalce�����Ĳ�������Ԫ�ص����Ͷ��仯������������Ԫ�����͵Ĺ��캯����ƥ�䡣

	//vector<Sales_data> c;
	//Sales_data item1("88-XX", 5, 30.0);
	//c.push_back(item1);					//push_back��item������c��
	//c.emplace_back();					//ʹ��Sales_data��Ĭ�Ϲ��캯����β������һ��Ԫ��
	//auto iter = c.begin();				//
	//c.emplace(iter, "897-XX");
	//c.emplace_back("896-XX");
	//for (auto item : c)
	//{
	//	print(cout, item);
	//}
	
	//ex9.18
	//deque<string> str_dq;
	//string str_temp;
	//while (cin >> str_temp)
	//{
	//	str_dq.push_back(str_temp);
	//}
	//for (auto str : str_dq)
	//{
	//	cout << str << "   ";
	//}

	//ex9.19
	//list<string> str_lst;
	//string str_temp;
	//while (cin >> str_temp)
	//{
	//	str_lst.push_back(str_temp);
	//}
	//for (auto str : str_lst)
	//{
	//	cout << str << "   ";
	//}

	//ex9.20
	//list<int> int_lst = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//deque<int> odd_dq, even_dq;
	//for (int i : int_lst)
	//{
	//	(i % 2 == 0 ? even_dq : odd_dq).push_back(i);
	//}
	//cout << "odd:\t";
	//for (int i : odd_dq)
	//{
	//	cout << i << "   ";
	//}
	//cout << "\neven:\t";
	//for (int i : even_dq)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;
	

	//ex9.21
	//vector<string> str_vec;
	//auto iter = str_vec.begin();
	//string word;
	//ifstream input;
	//input.open("Text.txt");
	//while (getline(input, word))
	//{
	//	iter = str_vec.insert(iter, word);		//�ȼ���push_front
	//}
	//for (auto str : str_vec)
	//{
	//	cout << str << "   " << endl;
	//}


	//ex9.22
	vector<int> iv = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	
	while (iter != mid)
	{
		if (*mid == 5)
		{
			mid = iv.insert(mid, 2 * 5);
			iter = iv.begin();
		}
		else
		{
			mid--;
		}
	}
	for (auto i : iv)
	{
		cout << i << "   ";
	}

}

//9.3


//9.3


//9.3




int main()
{
	//9.3.1 ��˳���������Ԫ��
	Fun_Adding_Elements_to_a_Sequential_Container();

	return 0;
}