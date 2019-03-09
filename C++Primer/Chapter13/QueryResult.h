#pragma once

#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include "header_include.h"
#include "TextQuery.h"
#include "fun.h"
#include "StrVec.h"

using namespace std;

class QueryResult
{
public:
	//��Ԫ��������ӡ��ѯ���
	friend ostream &print(ostream &, const QueryResult&);

	using line_no = vector<string>::size_type;
	
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<StrVec>f) :
		sought(s), lines(p), file(f) {}
	~QueryResult();

private:
	string sought;			//��ѯ���ʣ�
	shared_ptr<set<line_no>> lines;			//���ֵ��к�
	shared_ptr<StrVec> file;		//�����ļ�
};

ostream &print(ostream &, const QueryResult&);

#endif // !QUERYRESULT_H


