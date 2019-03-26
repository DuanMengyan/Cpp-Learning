#pragma once

#ifndef MYSTRING_H
#define MYSTRING_H

#include "header_include.h"

using namespace std;

class MyString
{
	friend void printstr(ostream& os,MyString& str);
public:
	//���캯��
	MyString() = default;
	//����c����ַ��������Ĺ��캯��
	MyString(const char *s);

	//�������캯��
	MyString(const MyString&);
	
	//������ֵ�����
	MyString& operator=(const MyString&);
	
	//��������
	~MyString();

	//�ƶ����캯��
	MyString(MyString&&) noexcept;

	//�ƶ���ֵ�����
	MyString& operator=(MyString &&) noexcept;

	
	size_t strlen() { return end_after_char - first_char; }
	char* begin() const { return first_char; }
	char* end() const { return end_after_char; }


private:
	//һЩ���ߺ���
	//������㹻���ڴ������������Χ��Ԫ�أ�������ЩԪ�ؿ������·�����ڴ���
	pair<char*, char*>alloc_n_copy(const char*begin, const char*end);
	
	//��һ����Χ�ڵ�Ԫ�ؽ��г�ʼ����������
	void range_initialize(const char*,const char*);

	//�ͷ��ڴ�
	void free();


private:
	//���ݳ�Ա
	allocator<char> alloc;  //�����ڴ�

	char *first_char;
	char *end_after_char;

};
#endif // !MYSTRING_H




