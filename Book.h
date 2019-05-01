#pragma once
#include <string>
using namespace std;
class Book
{
	friend class BookList;
private:
	int id;
	string title;
	float price;
	Book* next;
public:
	Book(int id, string title,float price,Book* next);
	~Book();
};

