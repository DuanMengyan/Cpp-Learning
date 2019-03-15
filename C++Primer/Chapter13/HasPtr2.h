#pragma once

#ifndef HASPTR_H
#define HASPTR_H

#include "header_include.h"

using namespace std;
class HasPtr2
{
public:
	friend void swap(HasPtr2 &, HasPtr2 &);
	friend bool operator<(const HasPtr2&, const HasPtr2 &);
	friend void show(vector<HasPtr2>&);

	HasPtr2(const string &s = string()) :ps(new string(s)), i(0){}

	//�������캯��
	//��psָ���string��ÿ��HasPtr�������Լ��Ŀ���
	HasPtr2(const HasPtr2 &item) :ps(new string(*item.ps)), i(item.i)
	{
		cout << *ps << " ***The_Copy_Constructor" << endl;
	}
	//������ֵ�����
	HasPtr2& operator=(const HasPtr2 &);

	//��ӵ��ƶ����캯��
	HasPtr2(HasPtr2 && p)noexcept:ps(p.ps), i(p.i) { p.ps = nullptr; }
	
	//��ֵ����������ƶ���ֵ�������Ҳ�ǿ�����ֵ�����
	HasPtr2& operator=(HasPtr2 rhs)
	{
		swap(*this, rhs);
		return *this;
	}


	//��������
	~HasPtr2()
	{
		delete ps;		//�ͷ�string�ڴ�
		//cout << *ps << " ***The_Destructor" << endl;
	}
private:
	string *ps;
	int i;

};


#endif // !HASPTR_H