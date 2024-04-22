#include <iostream>
using namespace std;

int main()
{
	int a = 7;
	int *aPtr = &a;
	float b = 5.3;
	float *bPtr = &b;
	cout << "a has value " << *aPtr << " at " << aPtr << endl;
	cout << "the size of aPtr is " << sizeof(aPtr) << " bit"
	     << endl; //the position of memory store as 8 bit
	cout << "b has value " << *bPtr << " at " << bPtr << endl;
	cout << "the size of bPtr is " << sizeof(bPtr) << " bit"
	     << endl; //any type is the same
	return 0;
}
