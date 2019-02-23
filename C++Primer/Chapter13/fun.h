#pragma once

#include "Sales_data.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"


extern Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
extern ostream &print(ostream &os, const Sales_data &item);
extern istream& operator >> (istream& in, Sales_data& s);
extern ostream& operator << (ostream& out, const Sales_data& s);
extern Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
extern string str_proc(string &word);

extern void printitem(vector<int> const&);
extern void printitem(vector<string> const&);
extern void printitem(list<int> const&);
extern void printitem(list<string> const&);