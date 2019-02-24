#pragma once

#ifndef HASPTR_H
#define HASPTR_H

#include "header_include.h"

using namespace std;


class HasPtr
{
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	
	//�������캯��
	//��psָ���string��ÿ��HasPtr�������Լ��Ŀ���
	HasPtr(const HasPtr &item) :ps(new string(*item.ps)), i(item.i) 
	{ 
		cout << *ps << " ***The_Copy_Constructor" << endl;
	}
	//������ֵ�����
	HasPtr& operator=(const HasPtr &);

	//��������
	~HasPtr()
	{
		delete ps;
		//cout << *ps << " ***The_Destructor" << endl;
	}
private:
	string *ps;
	int i;
};


#endif // !HASPTR_H