#include "HasPtr2.h"



HasPtr2 & HasPtr2::operator=(const HasPtr2 &hp)
{
	cout << *ps << " ***The_Copy_Assignment_Operator" << endl;
	string *p = new string(*hp.ps);		//new����ָ�����õ��ڴ棬��������ָ��
	delete ps;							//����ɾ��ԭ�ڴ�
	ps = p;								//��ֵ
	i = hp.i;
	return *this;
}


void swap(HasPtr2 &lhs, HasPtr2 &rhs)
{
	cout << "call HasPtr swap()" << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);		//����ָ�룬������string����
	swap(lhs.i, rhs.i);			//����int��Ա
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

