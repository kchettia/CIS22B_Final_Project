#pragma once
#ifndef BOOK_H   // if not define 
#define BOOK_H
#include<string>
#include<iostream>
using namespace std;

class Book
{
protected:
	std::string isbn;
	std::string title;
	std::string author;
	std::string publisher;
	std::string date;
	int qty;
	double price;
	double cost;


public:
	void setIsbn(std::string);
	void setTitle(std::string);
	void setAuthor(std::string);
	void setPublisher(std::string);
	void setDate(std::string);
	void setQty(int);
	void setPrice(double);
	void setCost(double);

	std::string getIsbn();
	std::string getTitle();
	std::string getAuthor();
	std::string getPublisher();
	std::string getDate();
	int getQty();
	double getPrice();
	double getCost();
	friend ostream& operator << (ostream& ot, const Book& d);

	Book(std::string, std::string, std::string, std::string, std::string);
	Book(std::string i, std::string t, std::string a, std::string p, std::string d, int q, double pr, double wc);
	Book();
	~Book();


};

#endif