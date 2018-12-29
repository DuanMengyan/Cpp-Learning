#pragma once

#include "Sales_data.h"


extern Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
extern ostream &print(ostream &os, const Sales_data &item);
//template<typename Container> void printitem(Container const& con);
extern void printitem(vector<int> const&);
extern void printitem(vector<string> const&);
extern void printitem(list<int> const&);