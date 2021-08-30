#pragma once
#include "Book.h"
#include "Menu.h"
using namespace std;




class Inventory :public Menu {

	//All privte member
private:
	Book * * bookArr;
	int bookArrSize;
	int currBookCnt;

	// Constructor destrutor witt all member function
public:
	Inventory();
	~Inventory();
	void addBook(string i, string t, string au, string p, string d, int q, double prc, double cst);
	Book* searchByISBN(string i);
	Book* searchBytittle(string t);
	int getIdxByISBN(string t);
	void deleteBook(string i);
	void reportofInventory();
	double inventory_Wholesale();
	double inventory_Retail();
	void readfromfile();
	void writeToFile();
	virtual void menu();
	int getCurrBookcnt();
	Book* getBook(int x);
	void updateQtyByISBN(string i, int newQty);
	string getLowercase(string &a);
	string getDateNow();
	friend ostream& operator << (ostream& os, const Book& obj);
};
