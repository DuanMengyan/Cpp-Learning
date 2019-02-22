#pragma once

#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H


#include "header_include.h"
#include "StrBlob.h"

using namespace std;


//对于访问一个不存在元素的尝试，StrBlobPtr抛出一个异常
class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) { }

	StrBlobPtr(const StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) { }
	
	bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }

	string & deref() const;
	StrBlobPtr& incr();	  //前缀递增
	
	~StrBlobPtr();

	long count()
	{
		return wptr.use_count(); // and wptr.use_count();
	}
private:
	//若检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<string>> check(size_t, const string&)const;

private:
	//保存一个weak_ptr，意味着底层vector可能会被销毁
	weak_ptr<vector<string>> wptr;
	//在数组中的当前位置
	size_t curr;
};

#endif STRBLOBPTR_H
