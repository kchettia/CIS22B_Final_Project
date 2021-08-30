//Done By Madhumita Mondal
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <iostream>
using namespace std;


void Book::setIsbn(std::string a) { isbn = a; }
void Book::setTitle(std::string b) { title = b; }
void Book::setAuthor(std::string c) { author = c; }
void Book::setPublisher(std::string d) { publisher = d; }
void Book::setDate(std::string e) { date = e; }
void Book::setQty(int f) // Throws error if qty is set to less than 0
{
	if (f < 0)
		throw "Error Quantity\n";
	else
		qty = f;
}
void Book::setPrice(double g) // Throws error if price is set to less than 0
{
	if (g < 0)
		throw "Error Price\n";
	else
		price = g;
}
void Book::setCost(double h) // Throws error is cost is set to less than 0
{
	if (h < 0)
		throw "Error cost\n";
	else
		cost = h;
}

std::string Book::getIsbn() { return isbn; }
std::string Book::getTitle() { return title; }
std::string Book::getAuthor() { return author; }
std::string Book::getPublisher() { return publisher; }
std::string Book::getDate() { return date; }
int Book::getQty() { return qty; }
double Book::getPrice() { return price; }
double Book::getCost() { return cost; }


Book::Book(string a, string b, string c, string d, string e)
{
	isbn = "";
	title = "";
	author = "";
	publisher = "";
	date = "";

}

Book::Book(string i, string t, string a, string p, string d, int q, double pr, double wc)
{
	isbn = i;
	title = t;
	author = a;
	publisher = p;
	date = d;

	try {									//Exception Handling, Tries Setting qty,price and cost. if less than zero, throw an error.
		setQty(q);
	}
	catch (exception &exp)
	{
		cout << exp.what();
	}
	try {
		setPrice(pr);
	}
	catch (exception &exp)
	{
		cout << exp.what();
	}

	try {
		setCost(wc);
	}
	catch (exception &exp)
	{
		cout << exp.what();
	}
}

Book::Book() {}
Book::~Book() {}