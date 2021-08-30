#pragma once
#include "Report.h"
#include "Book.h"
#include "Inventory.h"
#ifndef REPORT_H
#define REPORT_H


class Report :public Inventory
{
private:
	Book * * copy;
	int numofbooks;
	Inventory copybook;

public:
	Report();
	~Report();
	void menu();
	template <typename t>
	void compareNSwap(t, t, int, int);
	void sort(int);
	void printReport(std::string, int);
};



#endif
