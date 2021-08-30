//Done by Maggie Wang
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include"Book.h"
#include "Cashier.h"
#include "Inventory.h"
#include "Report.h"
#include "Menu.h"
#include <windows.h>
#include<iomanip>
using namespace std;



int main()
{
	Menu *test;
	string choice;

	system("mode CON: COLS=200 LINES=60");

	do
	{
		system("CLS");
		cout << "Serendipity Booksellers\n";
		cout << setw(18) << right << "Main Menu\n\n";

		cout << "1. Cashier Module\n";
		cout << "2. Inventory Database Module\n";
		cout << "3. Report Module\n";
		cout << "4. Exit \n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (atoi(choice.c_str()))
		{
		case 1:
			test = new Cashier;
			test->menu();
			delete test;

			break;
		case 2:
			test = new Inventory;
			test->menu();
			delete test;
			break;
		case 3:
			test = new Report;
			test->menu();
			delete test;
			break;

		}

	} while (atoi(choice.c_str()) != 4);


	system("pause");
	return 0;
}