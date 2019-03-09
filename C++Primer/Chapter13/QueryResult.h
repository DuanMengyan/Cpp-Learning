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
	//友元函数，打印查询结果
	friend ostream &print(ostream &, const QueryResult&);

	using line_no = vector<string>::size_type;
	
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<StrVec>f) :
		sought(s), lines(p), file(f) {}
	~QueryResult();

private:
	string sought;			//查询单词；
	shared_ptr<set<line_no>> lines;			//出现的行号
	shared_ptr<StrVec> file;		//输入文件
};

ostream &print(ostream &, const QueryResult&);

#endif // !QUERYRESULT_H


