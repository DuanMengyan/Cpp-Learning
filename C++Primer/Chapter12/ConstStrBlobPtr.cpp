#include "ConstStrBlobPtr.h"



//ConstStrBlobPtr::ConstStrBlobPtr()
//{
//}

StrBlob::~StrBlob()
{

}

ConstStrBlobPtr::~ConstStrBlobPtr()
{

}

ConstStrBlobPtr StrBlob::begin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
	return ConstStrBlobPtr(*this, data->size());
}


