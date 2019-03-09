#pragma once

#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include "header_include.h"
#include "QueryResult.h"
#include "fun.h"
#include "StrVec.h"

using namespace std;

class QueryResult;


class TextQuery
{

public:
	using line_no = vector<string>::size_type;

	//构造函数
	TextQuery(ifstream &);
	QueryResult query(const string&) const;
	~TextQuery();
	//成员函数
	void print();		//打印文本内容

private:
	shared_ptr<StrVec> file;		//输入文件
	map<string, shared_ptr<set<line_no>>> wm;

	//对输入的单词全部小写
	string& Str_proc(string &word);
};


#endif // !TEXTQUERY_H






