#include "fun.h"

//template<typename Container> void printitem(Container const& con)
//{
//	for (auto const &item : con)
//	{
//		cout << item << "   ";
//	}
//	cout << endl << "=============================" << endl;
//}
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
