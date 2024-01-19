#include <iostream>
using namespace std;

int main()
{
		int b[] = {2, 3, 5, 7};
		int *bPtr = b;
		cout << "total size of array:" << sizeof(b) << endl; //
		cout << *b << " " << *(b + 1) << endl;
		//cout << *(b+1.0); memory position can only operate with int
		cout << *bPtr << endl;
		bPtr++;
		cout << *bPtr << endl;
		//b++; b consider as a constant (not lvalue)
		int *cPtr = &b[3];
		cout << cPtr - bPtr << endl;
		cout << bPtr - cPtr << endl;
		//cout << bPtr / cPtr << endl; pointer has no / operator
		return 0;
}
