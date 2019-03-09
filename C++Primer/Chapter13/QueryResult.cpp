#include "QueryResult.h"


QueryResult::~QueryResult()
{
}

ostream & print(ostream & os, const QueryResult &qr)
{
	//����ҵ��˵��ʣ���ӡ���ִ��������г��ֵ�λ��
	os << qr.sought << " occurs " << qr.lines->size() << " time" << ((qr.lines->size() > 1) ? "s: " : ": ") << endl;
	//��ӡ���ʳ��ֵ�ÿһ��
	for (auto num : *qr.lines)
		os << "(Line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	return os;
}
