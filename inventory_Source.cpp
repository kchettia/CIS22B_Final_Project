//Done By Madhumita Mondal
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include "inventory.h"
#include<fstream>
#include<string>
#include<ctime>

using namespace std;


//Constructor for Inventory objeect. Here we are reading  file content to the object.
Inventory::Inventory()
{
	bookArrSize = 100;
	//This 'Book'type arry will hold all the book info at the very biginig .
	bookArr = new Book *[bookArrSize];
	currBookCnt = 0;

	//calling readfile function for reading file cotent
	readfromfile();
}


//Destructor for inventory object. Here we are deleting inventory object for clearing alocated memory sapce for books.
Inventory::~Inventory()
{
	writeToFile();
	for (int i = 0; i < currBookCnt; i++) {
		if (bookArr[i] != NULL)
			delete bookArr[i];
	}
	delete[] bookArr;
}
// This member function writing contaent to file.
void Inventory::writeToFile()
{
	ofstream outfile;
	outfile.open("Book.txt");
	for (int i = 0; i < currBookCnt; i++) {
		if (bookArr[i] != NULL) {
			outfile << bookArr[i]->getIsbn() << endl;
			outfile << bookArr[i]->getTitle() << endl;
			outfile << bookArr[i]->getAuthor() << endl;
			outfile << bookArr[i]->getPublisher() << endl;
			outfile << bookArr[i]->getDate() << endl;
			if (i == (currBookCnt - 1))
				outfile << bookArr[i]->getQty() << " " << bookArr[i]->getPrice() << " " << bookArr[i]->getCost();
			else
				outfile << bookArr[i]->getQty() << " " << bookArr[i]->getPrice() << " " << bookArr[i]->getCost() << endl;
		}
	}
	outfile.close();
}


// This member function will work for adding book.
// If the ISBN already exists, then propt user to edit the book instead of adding it.
void Inventory::addBook(string i, string t, string au, string p, string d, int q, double prc, double cst)
{
	Book * checkValid = searchByISBN(i);
	if (checkValid == NULL)
	{

		bookArr[currBookCnt] = new Book(i, t, au, p, d, q, prc, cst);
		currBookCnt++;
		if (currBookCnt == bookArrSize)
		{
			cout << "No more space" << endl;

		}

	}
	else
	{
		cout << "Book already exists. Please use edit book function.";
	}
}


// This member function will work for searching book by ISBN number.
Book* Inventory::searchByISBN(string isbn)
{

	for (int i = 0; i < currBookCnt; i++) {
		if (bookArr[i] != NULL) {
			if (isbn == bookArr[i]->getIsbn()) {
				return bookArr[i];
			}
		}
	}
	return NULL;
}

// This member function will work for searching book by tittle.
// upper-case and lower-case characters are also matched here
Book* Inventory::searchBytittle(string t)
{
	for (int i = 0; i < currBookCnt; i++) {
		if (bookArr[i] != NULL) {
			string getTitle = bookArr[i]->getTitle();
			if (getLowercase(t) == getLowercase(getTitle)) {
				return bookArr[i];
			}
		}
	}
	return NULL;
}

string Inventory::getLowercase(string &a)
{
	string lower;
	for (int x = 0; x < static_cast<int>(a.length()); x++)
	{
		lower += tolower(a[x]);
	}
	return  lower;
}


// This member function will work for searching ISBN Index .
// Used for internal purpose(delete)
int Inventory::getIdxByISBN(string t)
{
	for (int i = 0; i < currBookCnt; i++) {
		if (bookArr[i] != NULL) {
			if (t == bookArr[i]->getIsbn()) {
				return i;
			}
		}
	}
	return -1;
}


// This member function will work for deleting books.First it searches if book is present (by ISBN index number) then it deletes.
void Inventory::deleteBook(string i)
{
	Book* bookToBeDelete = searchByISBN(i);
	if (bookToBeDelete) {
		int idx = getIdxByISBN(i);
		delete bookToBeDelete;
		currBookCnt--;
		bookArr[idx] = NULL;
	}
}


// This member function will prints all the books' info from database.
void Inventory::reportofInventory() {

	for (int i = 0; i < currBookCnt; i++) {
		if (bookArr[i] != NULL) {
			cout << bookArr[i];
		}
	}
}
// This member function will work for getting total wholesale cost of all books.
double Inventory::inventory_Wholesale() {
	double total = 0;
	for (int i = 0; i < currBookCnt; i++) {
		if (bookArr[i] != NULL) {
			total += bookArr[i]->getCost()*(bookArr[i]->getQty());
		}
	}
	return total;

}

// This member function will work for getting total retail cost of all books.
double Inventory::inventory_Retail()
{
	double total = 0;
	for (int i = 0; i < currBookCnt; i++) {
		if (bookArr[i] != NULL) {
			total += bookArr[i]->getPrice()*(bookArr[i]->getQty());
		}
	}
	return total;
}
// This member function will update the number of books in the inventory.
// Used by casheir module for updating book qty after sale.
void Inventory::updateQtyByISBN(string i, int newQty)
{

	Book* bookToBeUpdated = searchByISBN(i);

	if (bookToBeUpdated) {

		bookToBeUpdated->setQty(newQty);

	}

}


// This member function will read the file content. Here we used Exception handling if it is a bad file this function will catch that.
// otherwise it will call 'addBook' member function for adding book details.
void Inventory::readfromfile()
{
	ifstream infile;
	infile.open("Book.txt");
	string read1, read2, read3, read4, read5;
	double read6, read7;
	int read8;
	for (int x = 0; infile.good(); x++)
	{
		try {
			if (infile.eof()) {
				throw "unexpected end of file";
			}
			getline(infile, read1);
			if (infile.eof()) {
				throw "unexpected end of file";
			}
			getline(infile, read2);
			if (infile.eof()) {
				throw "unexpected end of file";
			}
			getline(infile, read3);
			if (infile.eof()) {
				throw "unexpected end of file";
			}
			getline(infile, read4);
			if (infile.eof()) {
				throw "unexpected end of file";
			}
			getline(infile, read5);
			if (infile.eof()) {
				throw "unexpected end of file";
			}
		}
		catch (const char* e) {
			cout << "Bad inventory file : " << e << endl;
			cout << "Program will exit" << endl;
			system("pause");
			exit(1);
		}
		infile >> read8;
		infile >> read6;
		infile >> read7;

		addBook(read1, read2, read3, read4, read5, read8, read6, read7);
		read1.clear(); read2.clear(); read3.clear(); read4.clear(); read5.clear();
		infile.ignore();
	}
	infile.close();
}

// This member function for Menu details of inventory module. This menu is handling all user details for look up book,
//  Add a Book,  Edit a Book, Delete a book.
void Inventory::menu()
{
	string choice, s_choice;
	string i_isbn, i_title, i_author, i_publisher;
	string i_date = getDateNow();;
	int i_qty;
	double i_price;
	double i_cost;
	Book* b = NULL;


	do
	{
		system("CLS");
		cout << "Serendipity Booksellers\n";
		cout << right << setw(21) << "Inventory Database\n";

		cout << "1. Look up a book.\n";
		cout << "2. Add a Book.\n";
		cout << "3. Edit a Book's Record.\n";
		cout << "4. Delete a book.\n";
		cout << "5. Return to Main\n";

		cout << "Please enter your choice\n";
		cin >> choice;


		while (atoi(choice.c_str()) < 1 && atoi(choice.c_str()) > 5)
		{
			cout << "\nPlease enter number from 1-5";
			cin >> choice;
		}

		switch (atoi(choice.c_str()))

			//Lookup book by ISBN/tittle and printing all info about book.
		{
		case 1:
			do
			{

				cout << "1. Look up a book by isbn number.\n";
				cout << "2. Look up a book by tittle.\n";
				cout << "3. Return to Inventory Menu\n";

				cout << "Please enter your choice\n";
				cin >> s_choice;

				switch (atoi(s_choice.c_str())) {

				case 1:
					cout << "\nYou selected item 1" << endl;
					cout << "Enter book's isbn number: " << endl;
					cin >> i_isbn;

					b = searchByISBN(i_isbn);
					if (b == NULL) {
						cout << "Book not found" << endl;
					}
					else {
						cout << *b;
					}

					break;

				case 2:
					cout << "Enter book's tittle: " << endl;
					cin.ignore();
					getline(cin, i_title);

					b = searchBytittle(i_title);
					if (b == NULL) {
						cout << "Book not found" << endl;
					}
					else {
						cout << *b;
					}
					break;

				case 3:
					cout << "\nYou selected item 3" << endl;
					break;
				default:
					cout << "Invalid Input" << endl;
					break;
				}

			} while (atoi(s_choice.c_str()) != 3);
			break;

			//Adding a book to database and validating all user info
		case 2:

			cout << "Book's isbn number: " << endl;
			cin.ignore();
			getline(cin, i_isbn);
			while (i_isbn.length() != 17) {
				cout << "ISBN should be exactly 17 char long. Please enter correct ISBN :" << endl;
				getline(cin, i_isbn);
			}

			cout << "Book's tittle: " << endl;
			getline(cin, i_title);
			while (i_title.length() > 50) {
				cout << "Title should be less 50 chars long. Please enter correct Title :" << endl;
				getline(cin, i_title);
			}

			cout << "Book's author name: " << endl;;
			getline(cin, i_author);
			while (i_author.length() > 50) {
				cout << "Author should be less 50 chars long. Please enter correct Author :" << endl;
				getline(cin, i_author);
			}
			cout << "Book's publisher: " << endl;
			getline(cin, i_publisher);
			while (i_publisher.length() > 50) {
				cout << "Publisher should be less 50 chars long. Please enter correct Publisher :" << endl;
				getline(cin, i_publisher);
			}




			cout << "Book's qty: " << endl;
			cin >> i_qty;
			cout << "Book's price: " << endl;
			cin >> i_price;
			cout << "Book's cost: " << endl;
			cin >> i_cost;

			addBook(i_isbn, i_title, i_author, i_publisher, i_date, i_qty, i_price, i_cost);
			cout << "Added book sucessfully" << endl;
			system("pause");
			break;


			// Editing book info. At first its serching and printing a book details by ISBN number. Allowing all fields to edit
			// exept ISBN Nmber and date. Since Isbn number is books unique key and date will update automtacally from the system. 
			//As well as validating tittle , author and publisher field.
		case 3:
			cout << "\nYou selected item 3" << endl;
			cout << "Enter Book's isbn number for edit book: " << endl;
			cin.ignore();
			getline(cin, i_isbn);
			b = searchByISBN(i_isbn);
			if (b == NULL) {
				cout << "Book not found" << endl;
			}
			else {
				cout << *b;
				cout << "Enter book's new tittle: " << endl;
				getline(cin, i_title);
				while (i_title.length() > 50) {
					cout << "Title should be less 50 chars long. Please enter correct Title :" << endl;
					getline(cin, i_title);
				}
				b->setTitle(i_title);

				cout << "Enter book's new author name: " << endl;
				getline(cin, i_author);
				while (i_author.length() > 50) {
					cout << "Author should be less 50 chars long. Please enter correct Author :" << endl;
					getline(cin, i_author);
				}
				b->setAuthor(i_author);

				cout << "Enter book's new publisher: " << endl;
				getline(cin, i_publisher);
				while (i_publisher.length() > 50) {
					cout << "Publisher should be less 50 chars long. Please enter correct Publisher :" << endl;
					getline(cin, i_publisher);
				}
				b->setPublisher(i_publisher);

				cout << "Enter Book's new qty: " << endl;
				cin >> i_qty;
				b->setQty(i_qty);

				cout << "Enter Book's new price: " << endl;
				cin >> i_price;
				b->setPrice(i_price);

				cout << "Enter Book's new cost: " << endl;
				cin >> i_cost;
				b->setCost(i_cost);
			}
			system("pause");
			break;


			// Deleting a book by ISBN number if the book is found.
		case 4:
			cout << "\nYou selected item 4" << endl;

			cout << "Book's isbn number: " << endl;
			cin.ignore();
			getline(cin, i_isbn);
			b = searchByISBN(i_isbn);
			if (b == NULL) {
				cout << "Book not found" << endl;
			}
			else {
				deleteBook(i_isbn);
				cout << "Book deleted" << endl;
			}
			system("pause");
			break;
		case 5:
			cout << "\nYou selected item 5";
			break;
		default:
			cout << "Invalid Input" << endl;
			break;
		}
	} while (atoi(choice.c_str()) != 5);

}
// Getting current book number
int Inventory::getCurrBookcnt()
{
	return currBookCnt;
}


// Getting book details from Book array.
Book* Inventory::getBook(int x)
{
	return bookArr[x];
}

string Inventory::getDateNow()
{
	string i_date;
	time_t now = time(0);
	char str[100];
	ctime_s(str, 100, &now);
	struct tm st;
	gmtime_s(&st, &now);
	i_date = to_string(st.tm_mday) + "/" + to_string(st.tm_mon + 1) + "/" + to_string(st.tm_year + 1900);
	return i_date;
}