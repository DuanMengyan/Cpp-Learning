#pragma once

#ifndef HASPTR_H
#define HASPTR_H

#include "header_include.h"

using namespace std;


class HasPtr
{
public:
	friend void swap(HasPtr &, HasPtr &);
	friend bool operator<(const HasPtr&, const HasPtr &);
	friend void show(vector<HasPtr>&);

	HasPtr(const string &s = string()) :ps(new string(s)), i(0),use(new size_t(1)) {}
	
	//�������캯��
	//��psָ���string��ÿ��HasPtr�������Լ��Ŀ���
	HasPtr(const HasPtr &item) :ps(new string(*item.ps)), i(item.i),use(item.use)
	{ 
		++*use;
		cout << *ps << " ***The_Copy_Constructor" << endl;
	}
	//������ֵ�����
	HasPtr& operator=(const HasPtr &);
	
	

	//��������
	~HasPtr()
	{
		if (--*use == 0)
		{
			delete ps;		//�ͷ�string�ڴ�
			delete use;		//�ͷż������ڴ�
		}
		
		//cout << *ps << " ***The_Destructor" << endl;
	}
private:
	string *ps;
	int i;
	size_t *use;
};


#endif // !HASPTR_H