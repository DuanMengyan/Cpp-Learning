#pragma once

#ifndef ConstStrBlobPtr_H
#define ConstStrBlobPtr_H

//#include "StrBlob.h"
#include "header_include.h"

using namespace std;

class ConstStrBlobPtr;

class  StrBlob
{
public:
	using size_type = vector<string>::size_type;
	friend class ConstStrBlobPtr;

	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

	StrBlob() :data(make_shared<vector<string>>()) {}
	StrBlob(initializer_list<string>& il) :data(make_shared<vector<string>>(il)) {}
	~StrBlob();

	size_type size()const { return data->size(); }
	bool empty() const { return data->empty(); }

	//添加和删除元素
	void push_back(const string &t)
	{
		data->push_back(t);
	}
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
	
	string& front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	string& back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	const string& front()const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	const string& back()const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
	

	//const string 

private:
	void check(size_type i,const string &msg) const
	{
		if (i >= data->size())
			throw out_of_range(msg);	
	}

private:
	shared_ptr<vector<string>> data;

};



class ConstStrBlobPtr
{

public:
	ConstStrBlobPtr() :curr(0) {};
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {};
	~ConstStrBlobPtr();

	bool operator!= (ConstStrBlobPtr &p) { return p.curr != curr; }

	const string& deref()const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}

	const ConstStrBlobPtr& incr()
	{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
private:
	shared_ptr<vector<string>> check(size_t i, const string &msg)const
	{
		auto ret = wptr.lock();
		if (!ret)
			throw runtime_error("unbound StrBlobPtr");
		if (i >= ret->size())
			throw out_of_range(msg);
		return ret;
		
	}

private:
	size_t curr; //在数组中当前的位置
	weak_ptr<vector<string>> wptr;


};


#endif // !ConstStrBlobPtr_H



