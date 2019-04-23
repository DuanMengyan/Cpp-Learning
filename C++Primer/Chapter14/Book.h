#pragma once

#ifndef BOOK_H
#define BOOK_H

#include "header_include.h"

using namespace std;

class Book
{
	friend istream& operator >> (istream &in, Book &b);
	friend ostream& operator << (ostream &in, const Book &b);
	friend bool operator==(const Book &b1, const Book &b2);
	friend bool operator!=(const Book &b1, const Book &b2);


public:
	//默认构造函数
	Book() = default;
	//接受四个string的构造函数
	Book(string &BookNum, string &Book_name, string &Author, string &Publish_data);

	Book(istream &in) { in >> *this; };
	//析构函数
	~Book();

private:
	string book_num;
	string book_name;
	string author;
	string publish_date;
};
#endif // BOOK_H





