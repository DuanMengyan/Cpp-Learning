#pragma once

#ifndef STRBLOB_H
#define STRBLOB_H

#include "header_include.h"

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{

public:
	typedef vector<string>::size_type size_type;
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;


	StrBlobPtr begin();
	StrBlobPtr end();

	StrBlob() :data(make_shared<vector<string>>()) {};
	StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {};

	//explicit StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)){};
	~StrBlob();
	
	size_type size()const { return data->size(); }
	bool empty()const { return data->empty(); }
	
	//��Ӻ�ɾ��Ԫ��
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	
	//Ԫ�ط���
	string &front();
	const string &front()const;
	string &back();
	const string &back()const;
	
	//���
	void print_strblob();

	long count() 
	{
		return data.use_count(); // and wptr.use_count();
	}

private:
	//���data[i]���Ϸ����׳�һ���쳣
	void check(size_type i, const string &msg) const;

private:
	shared_ptr<vector<string>> data;
};


#endif STRBLOB_H

