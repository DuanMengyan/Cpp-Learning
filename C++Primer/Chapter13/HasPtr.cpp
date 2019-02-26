#include "HasPtr.h"




HasPtr & HasPtr::operator=(const HasPtr & hp)
{
	cout << *ps << " ***The_Copy_Assignment_Operator" << endl;
	++*hp.use;
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
	ps = hp.ps;
	i = hp.i;
	use = hp.use;
	//string *p = new string(*hp.ps);		//new返回指向分配好的内存，创建对象指针
	//delete ps;							//首先删除原内存
	//ps = p;								//赋值
	//i = hp.i;
	return *this;
}
