#ifndef SALEP_H
#define SALEP_H
#include <iomanip>
#include <iostream>
using namespace std;

class SalesPerson
{ // define class
		public:
		static const int monthsPerYear = 12; //all objects own one variable
		SalesPerson();
		void getSaleFromUser();
		void setSales(int, double);
		void printAnnualSales();

		private:
		double totalAnnualSales();
		double sales[monthsPerYear];
};

SalesPerson::SalesPerson()
{
		for (int i = 0; i < monthsPerYear; i++)
				sales[i] = 0.0;
}

void SalesPerson::getSaleFromUser()
{
		double salesFigure;
		for (int i = 1; i < monthsPerYear + 1; i++) {
				cout << "month " << i << ":" << endl;
				cin >> salesFigure;
				setSales(i, salesFigure);
		}
}

void SalesPerson::setSales(int month, double data)
{
		if (data >= 0)
				sales[month - 1] = data;
		else
				cout << "invalid data" << endl;
}

double SalesPerson::totalAnnualSales()
{
		double total = 0.0;
		for (int i = 0; i < 12; i++)
				total += sales[i];
		return total;
}

void SalesPerson::printAnnualSales()
{
		cout << setprecision(2) << "Average: " << totalAnnualSales() / monthsPerYear << endl;
}

#endif
