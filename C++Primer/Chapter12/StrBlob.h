#pragma once

#ifndef STRBLOB_H
#define STRBLOB_H

#include "header_include.h"
using namespace std;


class StrBlob
{

public:
	typedef vector<string>::size_type size_type;
	StrBlob() :data(make_shared<vector<string>>()) {};
	StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {};
	~StrBlob();
	size_type dize()const { return data->size(); }
	bool empty()const { return data->empty(); }
	//添加和删除元素
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	//元素访问
	string &front();
	const string &front()const;
	string &back();
	const string &back()const;

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
	void 
};


#endif STRBLOB_H

