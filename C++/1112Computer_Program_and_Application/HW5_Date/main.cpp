#include "Date.hpp"
#include <iostream>
using namespace std;

int main()
{
		Date d1(2, 26, 1900), d2(2, 26, 2004), d3(12, 29, 2023);
		for (int i = 0; i < 5; i++) {
				d1.print('\n');
				d1.nextDay();
		}
		cout << endl;

		for (int i = 0; i < 5; i++) {
				d2.print('\n');
				d2.nextDay();
		}
		cout << endl;

		for (int i = 0; i < 5; i++) {
				d3.print('\n');
				d3.nextDay();
		}
		cout << endl;

		Date d4(0, 0, 0), d5(100, 100, 100);
		return 0;
}
