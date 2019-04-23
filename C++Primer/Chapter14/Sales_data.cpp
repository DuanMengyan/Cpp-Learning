#include "Sales_data.h"

//友元函数
istream& operator >> (istream &is, Sales_data& s)
{
	double price;
	is >> s.bookNo >> s.units_sold >> price;
	// check that the inputs succeeded
	if (is)
		s.revenue = s.units_sold * price;
	else
		s = Sales_data();  // input failed: reset object to default state
	return is;
}

ostream& operator<<(ostream &os, const Sales_data& s)
{
	os << s.isbn() << " " << s.units_sold << " "
		<< s.revenue << " " << s.avg_price();
	return cout;
}


//按值返回，不要返回局部对象的引用
//当函数执行完毕，程序将释放分配给局部对象的存储空间。此时，对局部对象的引用就会指向不确定的内存。
//同理，指针也是这样，返回指针的时候，不能指向局部临时变量，否则指针将变为野指针；

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum(lhs);  
	sum += rhs;            
	return sum;            
}


//拷贝构造函数
Sales_data::Sales_data(const Sales_data &lhs)
{
	bookNo = lhs.bookNo;
	revenue = lhs.revenue;
	units_sold = lhs.units_sold;
}

//拷贝赋值运算符
Sales_data& Sales_data::operator=(const Sales_data &lhs)
{
	bookNo = lhs.bookNo;
	revenue = lhs.revenue;
	units_sold = lhs.units_sold;
	return *this;
}

bool Sales_data::operator==(const Sales_data &lhs)
{
	return lhs.isbn()==isbn();
}



// assumes that both objects refer to the same ISBN
Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}



//工具函数
double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;		//把rhs的成员加到this对象的成员上
	revenue += rhs.revenue;
	return *this;						//返回调用该函数的对象
}
ostream& Sales_data::output(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price() << endl;
	return os;
}

istream& Sales_data::input(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}