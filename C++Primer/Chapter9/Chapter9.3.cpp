#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��11��9�� ������
> Last edited time: 2018��12��6�� ������
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


void fuc_ex9_28(forward_list<string> str_flst, string str1, string str2)
{
	auto prev = str_flst.before_begin();
	auto curr = str_flst.begin();
	while (curr != str_flst.end())
	{
		if (*curr != str1)
		{
			prev = curr;
			++curr;
		}
		else
		{
			str_flst.insert_after(curr, str2);
			break;
		}
	}
	if (curr == str_flst.end())
		str_flst.insert_after(prev, str2);

	for (auto str : str_flst)
	{
		cout << str << endl;
	}
}
//9.3.4 �����forward_list����
void Fun_Specialized_forward_list_Operations()
{
	//forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	//vector<int> ivec = { 5,5,5,5,5 };
	//auto prev = flst.before_begin();			//��ʾflst�ġ���ǰԪ�ء�
	//auto curr = flst.begin();					//��ʾflst�еĵ�һ��Ԫ��
	//flst.insert_after(prev, 5);
	//flst.insert_after(prev, 5, 0);
	//flst.insert_after(prev, ivec.begin(), ivec.end());
	//flst.insert_after(prev, { 1,2,3,4,5 });

	//while (curr != flst.end())
	//{
	//	if (*curr % 2)
	//		curr = flst.erase_after(prev);
	//	else
	//	{
	//		prev = curr;
	//		++curr;
	//	}
	//}
	//for (int i : flst)
	//{
	//	cout << i << "  ";
	//}
	//cout << endl;
	//"=====================" << endl;
	
	//ex9.27
	//forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	//auto prev = flst.before_begin();
	//auto curr = flst.begin();
	//while (curr != flst.end())
	//{
	//	if (*curr % 2)
	//		curr = flst.erase_after(prev);
	//	else
	//	{
	//		prev = curr;
	//		++curr;
	//	}
	//}
	//for (int i : flst)
	//{
	//	cout << i << "  ";
	//}
	//cout << endl;

	//ex9.28
	forward_list<string> str_flst = { "hello","world","C++","5th" };
	string str1 = "C++",str2 = "primer";
	fuc_ex9_28(str_flst, str1, str2);
}


//9.3.5 �ı�������С
void Fun_Resizing_a_Container()
{
	//list<int> ilist(10, 42);
	//ilist.resize(15);
	//ilist.resize(15, 5);
	//ilist.resize(5);

	//for (auto i : ilist)
	//{
	//	cout << i << "   ";
	//}
	//cout << endl;

	//ex9.29
	//vec������С���ȱ��100������25��ԭ����ֵ��75��0��֮����10�������Ԫ�ػᱻɾ����vec���10��ԭ����ֵ

	//ex9.30
	//���Ԫ�������������ͣ�������ʼ�����������Ĭ�Ϲ��캯��

}


template <class T> 
void Myprint(T & container)
{
	//��ӡ�����е�Ԫ��
	for (auto i : container)
	{
		cout << i << "  ";
	}
	cout << endl;
}


//9.3.6 �������������ǵ�����ʧЧ
void Fun_Container_Operations_May_Invalidate_Iterators()
{
	//��д�ı�������ѭ������
	//vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	//auto iter = vi.begin();
	//while (iter != vi.end())
	//{
	//	if (*iter % 2)
	//	{
	//		iter = vi.insert(iter, *iter);		//��iterָ���Ԫ��֮ǰ������Ԫ�أ�Ȼ�󷵻�ָ����Ԫ�صĵ�����
	//		iter += 2;							//������ǰԪ�غͲ��뵽��֮ǰ�ĵ�����
	//	}
	//	else
	//	{
	//		iter = vi.erase(iter);				//ɾ��ż��Ԫ�أ�����ָ��ɾ��Ԫ��֮��Ԫ�صĵ�����
	//	}
	//}
	//Myprint(vi);

	//��Ҫ����end���صĵ�����
	//auto begin = vi.begin();
	//while (begin != vi.end())					//������ÿ��ѭ������֮�����µ���end()	
	//{
	//	++begin;
	//	begin = vi.insert(begin, 42);			//��begin֮ǰ����42�����ص�beginָ��42
	//	++begin;
	//}
	//Myprint(vi);

	//ex9.31
	//list<int> ilist = { 0,1,2,3,4,5,6,7,8,9 };
	//auto iter = ilist.begin();
	//while (iter != ilist.end())
	//{
	//	if (*iter % 2)
	//	{
	//		iter = ilist.insert(iter, *iter);		
	//		advance(iter, 2);
	//	}
	//	else
	//	{
	//		iter = ilist.erase(iter);				
	//	}
	//}
	//Myprint(ilist);

	//cout << "====================================================" << endl;

	//forward_list<int> iflist = { 0,1,2,3,4,5,6,7,8,9 };
	//auto prev =iflist.before_begin(), curr = iflist.begin();
	//while (curr != iflist.end())
	//{
	//	if (*curr % 2)
	//	{
	//		curr = iflist.insert_after(prev, *curr);
	//		advance(curr, 2);
	//		advance(prev, 2);
	//	}
	//	else
	//	{
	//		curr = iflist.erase_after(prev);
	//	}
	//}
	//Myprint(iflist);

	//ex9.32
	// ++����*�����÷��ţ����Ƶ������������һ������
	//�˴���֤�£�ʵ�ʲ���Ļ�������Ԫ�أ�
	
	//ex9.33
	//����������������ʧЧ

	//ex9.34
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();
	while (iter != vi.end())
	{
		if (*iter % 2)
		{
			iter = vi.insert(iter, *iter);
			iter += 2;
		}
		else
		{
			iter++;
		}
	}
	Myprint(vi);
}

int main()
{
	//9.3.1 ��˳���������Ԫ��
	//Fun_Adding_Elements_to_a_Sequential_Container();
	//9.3.2 ����Ԫ��
	//Fun_Accessing_Elements();
	//9.3.3 ɾ��Ԫ��
	//Fun_Erasing_Elements();
	//9.3.4 �����forward_list����
	//Fun_Specialized_forward_list_Operations();
	//9.3.5 �ı�������С
	//Fun_Resizing_a_Container();
	//9.3.6 �������������ǵ�����ʧЧ
	Fun_Container_Operations_May_Invalidate_Iterators();
	return 0;
}