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
	//string *p = new string(*hp.ps);		//new����ָ�����õ��ڴ棬��������ָ��
	//delete ps;							//����ɾ��ԭ�ڴ�
	//ps = p;								//��ֵ
	//i = hp.i;
	return *this;
}
