#include "HasPtr.h"




HasPtr & HasPtr::operator=(const HasPtr & hp)
{
	cout << *ps << " ***The_Copy_Assignment_Operator" << endl;
	string *p = new string(*hp.ps);		//new����ָ�����õ��ڴ棬��������ָ��
	delete ps;		//����ɾ��ԭ�ڴ�
	ps = p;			//��ֵ
	i = hp.i;
	return *this;
}
