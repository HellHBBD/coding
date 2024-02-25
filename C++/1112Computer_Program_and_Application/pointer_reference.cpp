#include <iostream>
using namespace std;

int main()
{
	int c = 1;
	int *cp = &c; //pointer must assign by an address
	int &cr = c; //reference variable
	int &crr = cr;
	cout << c << " " << cr << " " << crr << endl;
	cout << &c << " " << &cr << " " << &crr << endl; //reference represent the same address
	cout << *cp << " stored at " << cp << endl;
	*cp = 2; // change value by pointer
	cout << c << " " << cr << " " << crr << endl;
	cout << &c << " " << &cr << " " << &crr << endl;
	cout << *cp << " stored at " << cp << endl;
	return 0;
}
