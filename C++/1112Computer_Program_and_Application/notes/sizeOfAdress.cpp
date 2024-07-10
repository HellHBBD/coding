#include <iostream>
using namespace std;

int main()
{
	int b = 3;
	int *bPtr = &b;
	void *cPtr;
	cout << "cPtr : " << cPtr << endl;
	cout << "&cPtr : " << &cPtr << endl;
	cout << "sizeof(cPtr) : " << sizeof(cPtr) << endl;
	//*cPtr may cause error
	cPtr = bPtr; //void pointer can be assigned
	cout << "assign bPtr to cPtr" << endl;
	cout << "cPtr : " << cPtr << endl;
	cout << "&cPtr : " << &cPtr << endl;
	cout << "sizeof(cPtr) : " << sizeof(cPtr) << endl;
	//*cPtr still cause error
	return 0;
}
