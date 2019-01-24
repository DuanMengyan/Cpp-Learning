#include "StrBlob.h"
#include "StrBlobPtr.h"

#include "fun.h"




StrBlob::~StrBlob()
{
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

void StrBlob::pop_back()
{
	//如果vector为空，check会抛出一个异常
	check(0, "pop_back on empty StrBlob");
}

string & StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const string & StrBlob::front() const
{

	check(0, "front on empty StrBlob");
	return data->front();
}

string & StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const string & StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::print_strblob()
{
	printitem(*data);
}



void StrBlob::check(size_type i, const string & msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}
