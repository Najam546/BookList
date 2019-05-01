#include <iostream>
#include "BookList.h"
using namespace std;
void main()
{
	Book a1(01, "abc", 100, nullptr);
	Book b(02, "def", 200, nullptr);
	Book c(03, "ghi", 300, nullptr);
	Book d(04, "jkl", 400, nullptr);
	BookList a;
	a.insert(a1);
	a.insert(b);
	a.insert(c);
	a.gotoPrior();
	a.remove();
	a.insert(d);
	a.showStructure();

}