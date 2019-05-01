#pragma once
#include "Book.h"
class BookList
{
private:
	Book* head;
	Book* cursor;
public:
	BookList();
	void insert(const Book& newItem);
	void remove();
	void search(string title) const;
	void replace(const Book& newItem);
	bool isEmpty() const;
	void gotoBeginning();
	void gotoEnd();
	bool gotoNext();
	bool gotoPrior();
	Book getCursor();
	void showStructure() const;
	~BookList();
};

