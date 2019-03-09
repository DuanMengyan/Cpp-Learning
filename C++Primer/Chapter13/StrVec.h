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
	//���캯����ʹ�ó�ʼ�������б���й���
	StrVec(initializer_list<string> il);


	//�������캯��
	StrVec(const StrVec&);
	//������ֵ�����
	StrVec& operator=(const StrVec&);
	//��������
	~StrVec();

	//��Ա����
	void push_back(const string&);		//����Ԫ��
	void print_str();					//��ӡԪ��
	string *begin() const { return elements; }
	string *end() const { return first_free; }

	//��������Ԫ�ظ���
	size_t size() const { return first_free - elements; }
	//StrVec���Ա����Ԫ�ص�����
	size_t capacity() const { return cap - elements; }
	//֪ͨ������Ӧ��׼��������ٸ�Ԫ��
	void reserve(const size_t);
	//�ı�������С
	void resize(const size_t);
	void resize(const size_t, const string&);
	//�ж��Ƿ�Ϊ��
	bool empty();


private:
	//�����Ԫ�صĺ�����ʹ��
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	//���ߺ��������������캯����������ֵ�����������������ʹ��
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	//����Ԫ�ز��ͷ��ڴ�
	void free();			
	//��ø����ڴ沢��������Ԫ��
	void reallocate();		
	//�����ڴ棬��һ��������Ԫ�شӾ��ڴ��ƶ������ڴ�
	void alloc_move_n(size_t new_cap);
	//��һ����Χ�ڵ�Ԫ�ؽ��С��ڴ���䣬Ȼ���ʼ����������
	void range_initialize(const string*,const string*);
	
private:
	allocator<string> alloc;//����Ԫ��
	string *elements;		//ָ��������Ԫ�ص�ָ��
	string *first_free;		//ָ�������һ������Ԫ�ص�ָ��
	string *cap;			//ָ������β��λ�õ�ָ��

};

#endif // !STRVEC_H