#pragma once

#include "Sales_data.h"


extern Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
extern ostream &print(ostream &os, const Sales_data &item);
extern std::istream& operator >> (std::istream& in, Sales_data& s);
extern std::ostream& operator << (std::ostream& out, const Sales_data& s);
extern Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);


extern void printitem(vector<int> const&);
extern void printitem(vector<string> const&);
extern void printitem(list<int> const&);
extern void printitem(list<string> const&);