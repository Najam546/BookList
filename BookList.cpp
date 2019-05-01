#include "BookList.h"
#include <iostream>;


BookList::BookList()
{
	head = cursor = nullptr;
}

void BookList::insert(const Book& newItem)
{
	Book* t = new Book(newItem.id, newItem.title, newItem.price, nullptr);
	if (head == nullptr)
	{
		head = t;
		cursor = t;
		
	}
	else
	{
		Book* cur = head;
		while (cur->next != nullptr)
			cur = cur->next;
		cur->next = t;
		cursor = t;
	}
}

void BookList::remove()
{
	if (head == nullptr)
		cout << "Sorry! List is empty\n";
	else if(cursor->next==nullptr)
	{
		Book* t = head;
		Book* a = nullptr;
		while (t->next != nullptr)
		{
			a = t; //To keep record of previous entry in LL
			t = t->next; // To move forward in LL
		}
		if (t->next == cursor->next)
		{
			delete cursor;
			cursor = a;
			cursor->next = nullptr;
			cout << "Last Element Deleted\n";
		}
		
	}
	else if (cursor->next != nullptr && cursor!=head)
	{
		Book* cur = head;
		while (cur->next != cursor)
			cur = cur->next;
		Book * temp = cursor;
		cur->next = cursor->next;
		cursor = cursor->next;
		delete temp;
		cout << "Middle Element Deleted\n";
	}
	else if (cursor->next != nullptr && cursor == head)
	{
		head = cursor->next;
		delete cursor;
		cursor = head;
		cout << "First Element Deleted\n";
	}
}

void BookList::search(string title) const
{
	if (head == nullptr)
		cout << "List is empty!\n";
	else
	{
		Book* a = head;
		while (a != nullptr && a->title != title)
		{
			a = a->next;
		}
		if (a == nullptr)
			cout << "No Data Found!\n";
		cout << a->id << " " << a->title << " " << a->price << endl;
	}
}

void BookList::replace(const Book& newItem)
{
	if (head == nullptr)
		cout << "Empty List\n";
	else
	{
		cursor->id = newItem.id;
		cursor->title = newItem.title;
		cursor->price = newItem.price;
	}
}

bool BookList::isEmpty() const
{
	return !head;
}

void BookList::gotoBeginning()
{
	cursor = head;
}

void BookList::gotoEnd()
{
	Book* temp = head;
	while (temp->next != nullptr)
		temp = temp->next;
	cursor = temp;
}

bool BookList::gotoNext()
{
	if (cursor->next == nullptr)
		return false;
	cursor = cursor->next;
	return true;
}


bool BookList::gotoPrior()
{
	if (cursor == head)
		return false;
	Book* cur = head; Book* prev = head;
	while (cur->next != cursor->next)
	{
		prev = cur;
		cur = cur->next;
	}
	cursor = prev;
	return true;
}

Book BookList::getCursor()
{
	return *cursor;
}



void BookList::showStructure() const
{
	if (cursor == nullptr)
		cout << "List is empty\n";
	else
	{
		Book* cur = head;
		while (cur != nullptr)
		{
			cout << cur->id << " " << cur->title << " " << cur->price << endl;
			cur = cur->next;
		}
	}
}

BookList::~BookList()
{

	Book* t = head;
	Book* a = nullptr;
	if (head != nullptr)
	{
		do
		{
			a = t->next;
			delete t;
			t = a;
		} while (a != nullptr);
	}
}
