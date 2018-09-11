#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��9��11�� ���ڶ�
> Last edited time: 2018��9��11�� ���ڶ�
> Topic:C++Primer Chapter6.5 ������;��������
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

//#define NDEBUG 
using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::initializer_list;

typedef string::size_type sz;

sz ht = 60;
sz wd = 80;
char def = ' ';

//Ĭ��ʵ�γ�ʼֵ
void screen(sz = ht, sz = wd, char = def)
{
	cout << "ht: " << ht << endl;
	cout << "wd: " << wd << endl;
	cout << "def: " << def << endl;
}

//ex6.42
inline string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

//6.5.1Ĭ��ʵ��
void Fun_Default_Arguments()
{
	//���ú���Ĭ��ʵ�εĺ���ʱ�����԰�����ʵ�Σ�Ҳ����ʡ�Ը�ʵ��
	//һ��ĳ���βα�������Ĭ��ֵ��������������βζ�������Ĭ��ֵ

	//��������ʱʵ�ΰ���λ�ý�����Ĭ��ʵ�θ������������ȱ�ٵ�β��ʵ��
	//����ƺ���Ĭ��ʵ�εĺ���ʱ������һ�������Ǻ��������βε�˳��
	//�����ò���ôʹ��Ĭ��ֵ���βγ�����ǰ�棬������Щ����ʹ��Ĭ��ֵ���βγ����ں���

	//Ĭ��ʵ������
	//�����ĺ�������ֻ��Ϊ֮ǰ��Щû��Ĭ��ֵ���β����Ĭ��ֵ��
	//���Ҹ��β��Ҳ�������βα��붼��Ĭ��ֵ��

	//Ĭ��ʵ�γ�ʼֵ
	//����Ĭ��ʵ�ε������ں����������ڵ��������ڽ�����
	//����Щ���ֵ���ֵ���̷����ں�������ʱ
	//ht = 120;
	//wd = 100;
	//def = '*';	
	//screen();

	//ex6.40
	//char *init(int wd, char, char bckgrnd, int he = 24);

	//6.41
	//(a)�Ƿ�
	//(b)�Ϸ�
	//(c)�Ϸ������������Ա���Բ�����wd������ֵΪ*

	//ex6.42
	cout << make_plural(1, "success", "es") << endl;
	cout << make_plural(1, "failure") << endl;
	cout << make_plural(2, "success", "es") << endl;
	cout << make_plural(2, "failure") << endl;


}

//ex6.44
inline bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

//6.5.2����������constexpr����
void Fun_Inline_and_constexpr_Functions()
{
	//���������ɱ��⺯�����õĿ���
	//����������ÿ�����õ��ϡ������ء�չ��
	//�ں�����������ǰ����Ϲؼ���inline,�����Ϳ��Խ�������������������
	//�������������Ż���ģ��С������ֱ�ӡ�Ƶ�����õĺ�����

	//constexpr�����������������ڳ������ʽ�ĺ���
	//��ѭԼ���������ķ������ͼ������βε����Ͷ���������ֵ���ͣ�
	//���Һ������б�������ֻ��һ��return���
	//constexpr��������ʽ��ָ��Ϊ��������
	//����constexpr�����ķ���ֵ����һ��������������һ�����س������ʽ

	//����������constexpr����ͨ��������ͷ�ļ���

	//ex6.44
	cout << std::boolalpha << isShorter("hello,C++", "hello,python") << endl;

	//ex6.46

}

//ex6.5.3
void printVec(vector<int> &vec)
{
#ifndef NDEBUG
	cout<< "vector size: "<< vec.size() <<endl;
#endif
	if (!vec.empty())
	{
		auto tmp = vec.back();
		vec.pop_back();
		printVec(vec);
		cout << tmp << " ";
	}
}

//6.5.3���԰���
void Fun_Aids_for_Debugging()
{
	//assertԤ�����
	//assert��ʹ��һ�����ʽ��Ϊ����������
	//������ʽΪ0�������Ϣ����ֹ����ִ��
	//����assertʲôҲ����
	//assert�곣���ڼ�顰���ܷ�����������

	//NDEBUGԤ�������
	//ʹ��assertԤ����ꡣassert(expt); ��exprΪ�٣��������Ϣ����ֹ���������ͷ�ļ�cassert��
	//ʹ��Ԥ��������#define NDEBUG(����cassert֮ǰ)���Թر�assert�жϡ�
	//assert���ֻ��Debug����Ч��Release�²��ᱻִ��

	vector<int> val_vec = { 1, 2, 3, 4, 5, 6 };
	printVec(val_vec);
}


int main()
{
	//6.5.1Ĭ��ʵ��
	//Fun_Default_Arguments();

	//6.5.2����������constexpr����
	//Fun_Inline_and_constexpr_Functions();

	//6.5.3���԰���
	Fun_Aids_for_Debugging();

	return 0;
}