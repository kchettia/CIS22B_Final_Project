#pragma once
#pragma once
#include "Menu.h"
#include "Book.h"
#include "Inventory.h"
#ifndef CASHIER_H
#define CASHIER_H



class Cashier : public Menu {
private:
	const double tax = 0.0925;
	Book * booklist;
	Book **booksInCart;
	Inventory getInfo;
	int numOfBookCheckout;
	double subtotal;
	double total;
	int quantity[20]; // For checkout
	int remainQty[20];
public:
	Cashier();
	~Cashier();

	bool search(std::string, int);
	void menu();
	void checkoutBooks();
	void addToCart(Book*);
	friend ostream& operator << (ostream& os, const Book& obj);
};
#endif