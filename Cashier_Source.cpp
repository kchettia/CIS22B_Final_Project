//Done By My Quach
#define _CRT_SECURE_NO_WARNINGS
#include "Cashier.h"
#include "Book.h"
#include"Inventory.h"
#include<iostream>
#include<iomanip>
using namespace std;

//default constructor - dynamically allocates an array of Book objects sets numOfBookCheckout,subtotal, total = 0;
Cashier::Cashier()
{

	booksInCart = new Book*[20];
	numOfBookCheckout = 0;
	subtotal = total = 0;
}

//destructor
Cashier::~Cashier()
{
	delete[] booksInCart;

}

// Prompts user if they wish to add book to cart
// if they choose to add, it will prompt for quantity
// The qty is then updated in the inventory and the numberofBookCheckout is incremented
// Else, returned to menu
void Cashier::addToCart(Book* check)
{

	string choice;

	cout << "Add book to cart? (1 for Yes /2 for N)" << endl;
	cin >> choice;

	if (atoi(choice.c_str()) == 1 && numOfBookCheckout<20)
	{
		cout << "Enter quantity:";
		cin >> quantity[numOfBookCheckout];
		remainQty[numOfBookCheckout] = check->getQty() - quantity[numOfBookCheckout];

		if (remainQty >= 0)
		{
			getInfo.updateQtyByISBN(check->getIsbn(), remainQty[numOfBookCheckout]);

			booksInCart[numOfBookCheckout] = check;
			numOfBookCheckout++; //Book checkout counter. Max Books 20

		}
		else
			cout << " Please enter a lower quantity" << endl;

	}
	else if (atoi(choice.c_str()) != 1)
	{

	}
	else if (numOfBookCheckout >= 20)
	{
		cout << "Invalid input or Max number of items for checkout reached" << endl;
		system("pause");
	}



}

// Prints receipt
void Cashier::checkoutBooks()
{

	system("CLS");
	string i_date;
	i_date = getInfo.getDateNow();

	cout << "\n" << setw(66) << right << "Serendipity Booksellers" << endl;
	cout << setw(66) << right << "123 Stevens Creek Blvd" << endl;
	cout << setw(60) << right << i_date << endl << endl;
	cout << left << setw(6) << "S/N" << setw(20) << "ISBN" << setw(53) << "Book Title" <<
		setw(12) << "Quantity" << showpoint << setprecision(4) << setw(12) << "Price" << setw(12) << "Total" << endl;

	for (int j = 0; j < 110; j++)
		cout << "-";
	cout << "\n";


	for (int x = 0; x < numOfBookCheckout; x++)
	{
		cout << left << setw(6) << x + 1 << setw(20) << booksInCart[x]->getIsbn() << setw(53) << booksInCart[x]->getTitle()
			<< setw(12) << quantity[x] << fixed << showpoint << setprecision(2) << setw(12) << booksInCart[x]->getPrice()
			<< fixed << showpoint << setprecision(2) << setw(12) << booksInCart[x]->getPrice()*quantity[x] << endl << endl;

		subtotal += booksInCart[x]->getPrice()*quantity[x];

	}
	total = subtotal + subtotal * tax;
	cout << right << setw(102) << "Subtotal: $" << right << setw(6) << fixed << showpoint << setprecision(2) << subtotal << endl;
	cout << right << setw(102) << "Tax: $" << right << setw(6) << fixed << showpoint << setprecision(2) << subtotal * tax << endl;
	cout << right << setw(102) << "Total: $" << right << setw(6) << fixed << showpoint << setprecision(2) << total << endl << endl;
	cout << right << setw(75) << "Thank you for shopping at Serendipity!" << endl;

	system("pause");
}

// searches for books by ISBN/Title and returns a bool
bool Cashier::search(string a, int b)
{

	if (b == 1)
		booklist = getInfo.searchByISBN(a);
	else
	{
		booklist = getInfo.searchBytittle(a);
	}


	if (booklist == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}

}

// Prompts user to choose an option from the menu
//
void Cashier::menu()
{
	string choice;
	string input;
	bool flag;
	do
	{
		system("CLS");
		cout << "Serendipity Booksellers\n";
		cout << "Cashier Module\n\n";



		cout << "1. Add book to cart using ISBN.\n";
		cout << "2. Add book to cart using book title.\n";
		cout << "3. Checkout.\n";
		cout << "4. Return to Main\n";
		cout << "Enter your choice";
		cin >> choice;

		switch (atoi(choice.c_str()))
		{
		case 1:
		case 2:
			if (atoi(choice.c_str()) == 1)
			{
				cout << "\nEnter ISBN: ";
			}
			else
			{
				cout << "\nEnter Book Title: ";
			}
			cin.ignore();
			getline(cin, input);
			flag = search(input, atoi(choice.c_str()));
			if (flag == true)
			{
				system("CLS");
				cout << "Book Found!\n" << endl;
				cout << *booklist;
				addToCart(booklist);
			}
			else
			{
				cout << "Book not found!" << endl;
				system("pause");
			}

			break;

		case 3:
			cout << "\nCheckout\n\n";
			checkoutBooks();
			break;

		}

	} while (atoi(choice.c_str()) != 4);

}

//overloaded function, allows printing of Book objects 
ostream& operator << (ostream& ot, const Book& d)
{
	ot << "Book isbn number: " << d.isbn << endl
		<< "Book tittle: " << d.title << endl
		<< "Book author name: " << d.author << endl
		<< "Book publisher: " << d.publisher << endl
		<< "Book date: " << d.date << endl
		<< "Book qty: " << d.qty << endl
		<< "Book price: " << d.price << endl
		<< "Book cost: " << d.cost << endl << endl;

	return ot;
}
