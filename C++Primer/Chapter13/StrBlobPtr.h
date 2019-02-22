#pragma once

#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H


#include "header_include.h"
#include "StrBlob.h"

using namespace std;


//���ڷ���һ��������Ԫ�صĳ��ԣ�StrBlobPtr�׳�һ���쳣
class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) { }

	StrBlobPtr(const StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) { }
	
	bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }

	string & deref() const;
	StrBlobPtr& incr();	  //ǰ׺����
	
	~StrBlobPtr();

	long count()
	{
		return wptr.use_count(); // and wptr.use_count();
	}
private:
	//�����ɹ���check����һ��ָ��vector��shared_ptr
	shared_ptr<vector<string>> check(size_t, const string&)const;

private:
	//����һ��weak_ptr����ζ�ŵײ�vector���ܻᱻ����
	weak_ptr<vector<string>> wptr;
	//�������еĵ�ǰλ��
	size_t curr;
};

#endif STRBLOBPTR_H
