#include "fun.h"


void printitem(vector<int> const& con)
{
	for (auto const &item : con)
	{
		cout << item << "   ";
	}
	cout << endl << "=============================" << endl;
}

void printitem(list<int> const& con)
{
	for (auto const &item : con)
	{
		cout << item << "   ";
	}
	cout << endl << "=============================" << endl;
}

void printitem(list<string> const& con)
{
	for (auto const &item : con)
	{
		cout << item << "   ";
	}
	cout << endl << "=============================" << endl;
}

void printitem(vector<string> const& con)
{
	for (auto const &item : con)
	{
		cout << item << "   ";
	}
	cout << endl << "=============================" << endl;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price() << endl;
	return os;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::istream &operator >> (std::istream& in, Sales_data& s)
{
	double price;
	in >> s.bookNo >> s.units_sold >> price;
	// check that the inputs succeeded
	if (in)
		s.revenue = s.units_sold * price;
	else
		s = Sales_data();  // input failed: reset object to default state
	return in;
}

std::ostream &operator<<(std::ostream& out, const Sales_data& s)
{
	out << s.isbn() << " " << s.units_sold << " "
		<< s.revenue << " " << s.avg_price();
	return out;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data ret(lhs);  // copy (|lhs|) into a local object that we'll return
	ret += rhs;           // add in the contents of (|rhs|) 
	return ret;           // return (|ret|) by value
}

