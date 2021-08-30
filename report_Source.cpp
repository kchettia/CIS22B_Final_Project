//Done by Krshant Chettiar
#define _CRT_SECURE_NO_WARNINGS
#include "Report.h"
#include "Book.h"
#include<iostream>
#include "Inventory.h"
#include<iomanip>
#include<cstring>
using namespace std;

// Default Constructor - gets Book object using the GetBook function from inventory 
Report::Report()
{

	numofbooks = copybook.getCurrBookcnt();
	copy = new Book *[numofbooks];
	for (int x = 0; x < numofbooks; x++)
		copy[x] = copybook.getBook(x);

}
// Destructor - Free up memory
Report::~Report()
{
	delete[] copy;
}
// Sort function, Uses selection sort. Depending on the User's choice, it will swap based on Title,Cost,Price,Quantity
// Swapping done using the compareNSwap function
void Report::sort(int c)
{
	for (int j = 0; j < numofbooks; j++)
	{
		for (int x = 0; x < numofbooks; x++)
		{

			switch (c)
			{
			case 1:compareNSwap(copy[x]->getTitle(), copy[j]->getTitle(), x, j);
				break;
			case 2:compareNSwap(copy[x]->getCost(), copy[j]->getCost(), x, j);
				break;
			case 3:compareNSwap(copy[x]->getPrice(), copy[j]->getPrice(), x, j);
				break;
			case 4:compareNSwap(copy[j]->getQty(), copy[x]->getQty(), x, j);
				break;
			case 5:compareNSwap(copy[j]->getCost(), copy[x]->getCost(), x, j);
				break;
			case 6:
				string date = copy[j]->getDate();
				string month = date.substr(0, 2);
				string day = date.substr(3, 2);
				string year = date.substr(6, 4);
				date = year + month + day;

				string date1 = copy[x]->getDate();
				string month1 = date1.substr(0, 2);
				string day1 = date1.substr(3, 2);
				string year1 = date1.substr(6, 4);
				date1 = year1 + month1 + day1;
				compareNSwap(date1, date, x, j);
				break;

			}

		}
	}


}
// Called from the sort function
// Compares one and two and swaps it around if one is greater than two
template <typename t>
void Report::compareNSwap(t one, t two, int x, int j)
{
	Book *temp;

	if (one > two)
	{
		temp = copy[x];
		copy[x] = copy[j];
		copy[j] = temp;
	}

}


// Prints report, varies depending on user's choice

void Report::printReport(string a, int choice)
{
	system("CLS");
	cout << "Serendipity Booksellers\n";
	cout << a << " Report\n";
	cout << "Date:" << copybook.getDateNow() << endl << endl;

	cout << left << setw(6) << "S/N" << setw(20) << "ISBN" << setw(53) << "Title"
		<< left << setw(25) << "Author" << setw(25) << "Publisher"
		<< left << setw(15) << "Date Added" << setw(12) << "Quantity" << setw(17) << "Retail Price" << setw(17) << "Wholesale Cost" << endl;
	for (int j = 0; j < 187; j++)
		cout << "-";
	cout << "\n";
	for (int x = 0; x < numofbooks; x++)
	{
		cout << left << setw(6) << x + 1 << setw(20) << copy[x]->getIsbn() << setw(53) << copy[x]->getTitle()
			<< left << setw(25) << copy[x]->getAuthor() << setw(25) << copy[x]->getPublisher()
			<< left << setw(18) << copy[x]->getDate() << setw(12) << copy[x]->getQty() << fixed << showpoint << setprecision(2) << setw(18) << copy[x]->getPrice() << fixed << showpoint << setprecision(2) << setw(17) << copy[x]->getCost() << endl;
	}
	switch (choice)
	{
	case 2:cout << "\nInventory Wholesale Value: $" << fixed << showpoint << setprecision(2) << copybook.inventory_Wholesale() << endl << endl;
		break;
	case 3:cout << "\nInventory Retail Value: $" << fixed << showpoint << setprecision(2) << copybook.inventory_Retail() << endl << endl;
		break;
	}
	system("pause");

}


// Menu calls different calls Sort and printReport function
// Depending on User's choice, it will pass different variables to functions
// If user chooses 7, returns to Main Menu

void Report::menu()
{
	string choice;

	do
	{
		system("CLS");

		cout << "Serendipity Booksellers\n";
		cout << "\tReport Module\n";
		cout << "1. Inventory List.\n";
		cout << "2. Inventory Wholesale Value.\n";
		cout << "3. Inventory Retail Value.\n";
		cout << "4. List by Quanitity.\n";
		cout << "5. List by Cost.\n";
		cout << "6. List by Age.\n";
		cout << "7. Return to Main\n";

		cout << "Please enter your choice\n";
		cin >> choice;


		switch (atoi(choice.c_str()))
		{
		case 1:
			cout << "\nYou selected item 1" << endl;
			sort(atoi(choice.c_str()));
			printReport("List By Inventory", atoi(choice.c_str()));
			break;
		case 2:
			cout << "\nYou selected item 2" << endl;
			sort(atoi(choice.c_str()));
			printReport("Inventory Wholesale Value", atoi(choice.c_str()));
			break;
		case 3:
			cout << "\nYou selected item 3" << endl;
			sort(atoi(choice.c_str()));
			printReport("Inventory Retail Value", atoi(choice.c_str()));
			break;
		case 4:
			cout << "\nYou selected item 4" << endl;
			sort(atoi(choice.c_str()));
			printReport("List By Quantity", atoi(choice.c_str()));
			break;
		case 5:
			cout << "\nYou selected item 5" << endl;
			sort(atoi(choice.c_str()));
			printReport("List by Cost", atoi(choice.c_str()));
			break;
		case 6:
			cout << "\nYou selected item 6" << endl;
			sort(atoi(choice.c_str()));
			printReport("List By Age", atoi(choice.c_str()));
			break;
		case 7:
			cout << "\nYou selected item 7" << endl;
			break;
		default:
			cout << "Invalid Input" << endl;
			break;
		}
	} while (atoi(choice.c_str()) != 7);

}

