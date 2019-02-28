#include "HasPtr2.h"



HasPtr2 & HasPtr2::operator=(const HasPtr2 &hp)
{
	cout << *ps << " ***The_Copy_Assignment_Operator" << endl;
	string *p = new string(*hp.ps);		//new返回指向分配好的内存，创建对象指针
	delete ps;							//首先删除原内存
	ps = p;								//赋值
	i = hp.i;
	return *this;
}


void swap(HasPtr2 &lhs, HasPtr2 &rhs)
{
	cout << "call HasPtr swap()" << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);		//交换指针，而不是string数据
	swap(lhs.i, rhs.i);			//交换int成员
}



bool operator<(const HasPtr2 &hp1, const HasPtr2 &hp2)
{
	cout << "call operator< (" << *hp1.ps << " , " << *hp2.ps << ")" << endl;
	return *hp1.ps < *hp2.ps;
}


void show(vector<HasPtr2>& vec)
{
	auto iter = vec.begin();
	for (iter;iter!=vec.end();++iter)
	{
		cout << *(iter->ps) << "  ";
	}
	cout << "====================" << endl;
}

