#pragma once
#pragma execution_character_set("utf-8")


#ifndef BOOK_H
#define BOOK_H

#include "header_include.h"

using namespace std;
class Book;
istream &read(istream &is, Book &item);

class Book
{
public:
	//构造函数
	//Book() = default;
	//Book(string name, string author, string book_number):
	//	Name(name),Author(author),Book_number(book_number) {  }
	//Book(istream &is)
	//{
	//	read(is, *this);
	//}


	//委托构造函数
	Book(string name, string author, string book_number) :
		Name(name), Author(author), Book_number(book_number) 
	{
		cout << "Constructor_three" << endl;
	}
	Book() :Book("", "", "") { cout << "Constructor_default" << endl; }
	Book(istream &is) :Book()
	{  
		read(is, *this); 
	}

	string Name;
	string Author;
	string Book_number;
	
};


istream &read(istream &is, Book &item)
{
	is >> item.Name >> item.Author >> item.Book_number;
	return is;
}

ostream &print(ostream &os, const Book &item)
{
	os << item.Name << "\t" << item.Author << "\t" << item.Book_number << endl;
	return os;
}

#endif //BOOK