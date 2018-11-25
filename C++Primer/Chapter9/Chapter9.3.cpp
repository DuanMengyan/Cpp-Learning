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

//9.3.2 ����Ԫ��
void Fun_Accessing_Elements()
{
	//�ڽ�����һ�������������front��back֮ǰ����Ƿ���Ԫ�أ�ȷ�������ǿ�
	//front��back������Ԫ�غ�βԪ�ص�����
	//vector<int> c = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//if (!c.empty())
	//{
	//	auto val1 = *c.begin(), val2 = c.front();
	//	auto last = c.end();
	//	auto val3 = *(--last);
	//	auto val4 = c.back();
	//}


	//at���±����ֻ������string��vector��deque��array
	//c.at(n)�����±�Ϊn��Ԫ�ص����á�
	
	
	//���ʳ�Ա�������ص�������
	//vector<int> c = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//if (!c.empty())
	//{
	//	c.front() = 42;
	//	auto &v = c.back();
	//	v = 1204;
	//	auto v2 = c.back();
	//	v2 = 0;
	//}
	//for (auto i : c)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;

	//�±�����Ͱ�ȫ���������
	//vector<int> c;
	//cout << c[0] << endl;
	//cout << c.at(0) << endl;

	//ex9.23
	//vector<int> c = {1};
	//if (!c.empty())
	//{
	//	auto val1 = *c.begin(), val2 = c.front();
	//	auto last = c.end();
	//	auto val3 = *(--last);
	//	auto val4 = c.back();
	//	cout << val1 << endl;
	//	cout << val2 << endl;
	//	cout << val3 << endl;
	//	cout << val4 << endl;
	//}
	//ȫ����1

	//ex9.24
	//vector<int> c = { 2 };
	//if (!c.empty())
	//{
	//	cout << c.at(0) << endl;
	//	cout << c[0] << endl;
	//	cout << c.front() << endl;
	//	cout << *c.begin() << endl;
	//}

}


//9.3.3 ɾ��Ԫ��
void Fun_Erasing_Elements()
{
	//pop_front��pop_back��Ա�㺯��
	//list<int> ilist = { 1, 2, 3, 4 };
	//while (!ilist.empty())
	//{
	//	cout << ilist.back() << "   ";
	//	ilist.pop_back();
	//}

	//�������ڲ�ɾ��һ��Ԫ��esrse
	//list<int> ilist = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//auto iter = ilist.begin();
	//while (iter != ilist.end())
	//{
	//	if (*iter % 2)
	//		iter = ilist.erase(iter);
	//	else
	//		iter++;
	//}

	//ɾ�����Ԫ��
	//list<string> slist;
	//slist.clear();
	//slist.erase(slist.begin(), slist.end());

	//ex25
	//vector<string> svec = { "hello", "world", "C++", "Primer" };
	////slist.clear();
	//auto elem1 = svec.begin();
	//auto elem2 = svec.end();
	//auto iter = svec.erase(elem1, elem1);        //����֮��iter == slist.begin()
	//cout << *iter << endl;

	//ex26
	//int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	//list<int> evenlst;
	//vector<int> oddvec;
	//for (int i = 0; i != 11; ++i)
	//{
	//	evenlst.push_back(ia[i]);
	//	oddvec.push_back(ia[i]);
	//}
	//for (auto iter = evenlst.begin(); iter != evenlst.end(); )
	//{

	//	if (*iter % 2 == 0)
	//		iter = evenlst.erase(iter);
	//	else
	//	{
	//		iter++;
	//	}
	//}
	//for (auto iter = evenlst.begin(); iter != evenlst.end(); iter++)
	//{
	//	cout << *iter << "   ";
	//}
	//cout << "\n==========================" << endl;
	//for (auto iter = oddvec.begin(); iter != oddvec.end();)
	//{

	//	if (*iter % 2 != 0)
	//		iter = oddvec.erase(iter);
	//	else
	//	{
	//		iter++;
	//	}
	//}
	//for (auto iter = oddvec.begin(); iter != oddvec.end(); iter++)
	//{
	//	cout << *iter << "   ";
	//}

}


//9.3.4




int main()
{
	//9.3.1 ��˳���������Ԫ��
	//Fun_Adding_Elements_to_a_Sequential_Container();
	//9.3.2 ����Ԫ��
	//Fun_Accessing_Elements();
	//9.3.3 ɾ��Ԫ��
	Fun_Erasing_Elements();
	return 0;
}