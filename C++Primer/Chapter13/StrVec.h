#pragma once

#ifndef STRVEC_H
#define STRVEC_H

#include "header_include.h"

using namespace std;


class StrVec
{
public:
	//���캯����allocator��Ա����Ĭ�ϳ�ʼ��
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}				
	//�������캯��
	StrVec(const StrVec&);
	//������ֵ�����
	StrVec& operator=(const StrVec&);
	//��������
	~StrVec();

	//��Ա����
	void push_pack(const string&);		//����Ԫ��
	string *begin() const { return elements; }
	string *end() const { return first_free; }

	//��������Ԫ�ظ���
	size_t size() const { return first_free - elements; }
	//StrVec���Ա����Ԫ�ص�����
	size_t capacity() const { return cap - elements; }

private:
	static allocator<string> alloc;		//����Ԫ��
	//�����Ԫ�صĺ�����ʹ��
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	//���ߺ��������������캯����������ֵ�����������������ʹ��
	pair<string*, string*> alloc_n_copy(const string*, const string*);

	void free();			//����Ԫ�ز��ͷ��ڴ�
	void reallocate();		//��ø����ڴ沢��������Ԫ��
	string *elements;		//ָ��������Ԫ�ص�ָ��
	string *first_free;		//ָ�������һ������Ԫ�ص�ָ��
	string *cap;			//ָ������β��λ�õ�ָ��

};

#endif // !STRVEC_H