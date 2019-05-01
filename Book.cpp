#include "Book.h"



Book::Book(int id, string title, float price, Book* next)
{
	this->id = id;
	this->title = title;
	this->price = price;
	this->next = next;
}

Book::~Book()
{
}
