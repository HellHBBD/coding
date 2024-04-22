#include "BasePlusCommissionEmployee.hpp"
#include "HourlyEmployee.hpp"
#include "SalariedEmployee.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout << fixed << setprecision(2);

	// create vector of four base-class pointers
	vector<Employee *> employees(4);

	// initialize vector with Employees
	employees[0] = new SalariedEmployee("John", "Smith", "111-11-1111", 800,
					    8, 15, 2004);
	employees[1] = new HourlyEmployee("Karen", "Price", "222-22-2222",
					  16.75, 40, 12, 27, 1992);
	employees[2] = new CommissionEmployee("Sue", "Jones", "333-33-3333",
					      10000, .06, 0, 99, 8045);
	employees[3] = new BasePlusCommissionEmployee(
		"Bob", "Lewis", "444-44-4444", 5000, .04, 300, 1, 3, 1993);

	cout << "*********************************************************************"
	     << endl;
	employees[0]->print();
	cout << "\nearned $" << employees[0]->earnings() << "\n\n";
	Employee::setCurrentDate(8, 15, 2004);
	cout << "The current date is now " << Employee::getCurrentDate() << "."
	     << endl;
	cout << "\nearned $" << employees[0]->earnings() << "\n\n";
	delete employees[0];
	cout << "*********************************************************************"
	     << endl;
	employees[1]->print();
	cout << "\nearned $" << employees[1]->earnings() << "\n\n";
	Employee::setCurrentDate(12, 27, 1992);
	cout << "The current date is now " << Employee::getCurrentDate() << "."
	     << endl;
	cout << "\nearned $" << employees[1]->earnings() << "\n\n";
	delete employees[1];
	cout << "*********************************************************************"
	     << endl;
	employees[2]->print();
	cout << "\nearned $" << employees[2]->earnings() << "\n\n";
	Employee::setCurrentDate(1, 1, 1900);
	cout << "The current date is now " << Employee::getCurrentDate() << "."
	     << endl;
	cout << "\nearned $" << employees[2]->earnings() << "\n\n";
	delete employees[2];
	cout << "*********************************************************************"
	     << endl;
	employees[3]->print();
	cout << "\nearned $" << employees[3]->earnings() << "\n\n";
	Employee::setCurrentDate(1, 3, 1993);
	cout << "The current date is now " << Employee::getCurrentDate() << "."
	     << endl;
	cout << "\nearned $" << employees[3]->earnings() << "\n\n";
	delete employees[3];
	cout << "*********************************************************************"
	     << endl;
	return 0;
}
