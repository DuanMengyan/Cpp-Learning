#pragma once

#ifndef EX12_32_H
#define EX12_32_H

#include "header_include.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "fun.h"

using namespace std;

using line_no = vector<string>::size_type;

class QueryResult;

class TextQuery
{

public:
	
	TextQuery(ifstream&);
	~TextQuery();
	QueryResult query(const string&) const;
	void print_file();
private:
	StrBlob file;
	map<string, shared_ptr<set<line_no>>> wm;

};




class QueryResult
{
public:
	using ResultIter = set<line_no>::iterator;
	friend ostream &print_result(ostream &, const QueryResult&);

public:
	QueryResult(string s, shared_ptr<set<line_no>> p, StrBlob f) :sought(s), lines(p), file(f) {};
	~QueryResult();

	ResultIter begin()const { return lines->begin(); }
	ResultIter end()const { return lines->end(); }

	shared_ptr<StrBlob> get_file()const { return make_shared<StrBlob>(file); }
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	StrBlob file;
};

ostream &print_result(ostream &, const QueryResult&);

#endif // ! EX12_32_H



