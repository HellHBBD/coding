#include <iostream>
#include <iomanip>
#include "salePerson.hpp"
using namespace std;

int main(){
	SalesPerson Paul;
	Paul.getSaleFromUser();
	Paul.printAnnualSales();
	return 0;
}
