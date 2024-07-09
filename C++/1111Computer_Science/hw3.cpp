#include <bits/stdc++.h>
using namespace std;

int main()
{
	int year;
	cout << "Input a four digits AD year: ";
	cin >> year;
	if (year < 1000 or year > 9999) {
		cout << "Wrong input!";
		return 0;
	}
	if (year % 400 == 0)
		cout << "Leap year";
	else if (year % 4 == 0 and year % 100 != 0)
		cout << "Leap year";
	else
		cout << "Common year";
	return 0;
}
