#include "StrBlobPtr.h"

//StrBlobPtr::StrBlobPtr()
//{
//
//}

StrBlobPtr::~StrBlobPtr()
{

}

string & StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr & StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}


shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string & msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		cout << "unbonud StrBlobPtr" << endl;
		//throw runtime_error("unbonud StrBlobPtr");
	if (i >= ret->size())
		cout << msg << endl;
		//throw out_of_range(msg);
	//否则，返回指向vector的shared_ptr
	return ret;
}
