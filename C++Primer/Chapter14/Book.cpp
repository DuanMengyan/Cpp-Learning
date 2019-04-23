#include "Book.h"

//接受四个string的构造函数
Book::Book(string & BookNum, string & BookName, string & Author, string & PublishData)
{
	book_num = BookNum;
	book_name = BookName;
	author = Author;
	publish_date = PublishData;
}

Book::~Book()
{
}

istream & operator >> (istream & in, Book & b)
{
	in >> b.book_num >> b.book_name >> b.author >> b.publish_date;
	return in;
}

ostream & operator<<(ostream & out, const Book & b)
{
	out << b.book_num << "   " << b.book_name << "   " << b.author << "   " << b.publish_date << endl;
	return out;
}

bool operator==(const Book & b1, const Book & b2)
{

	return (b1.book_num == b2.book_num&&b1.book_name==b2.book_name);
}

bool operator!=(const Book & b1, const Book & b2)
{
	return !(b1 == b2);
}
