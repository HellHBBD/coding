#include <iostream>
using namespace std;

size_t getSize(int *ptr){ //array pass an address to function, declare a pointer variable
	return sizeof(ptr); //size_t is a data type compartable between 32bit and 64bit
}

int main(){
	int array[20];
	cout << "getSize(array) : " << getSize(array) << endl;
	cout << "sizeof(array) : " << sizeof(array) << endl;
	cout << "sizeof(*array) : " << sizeof(*array) << endl;
	cout << "array length : " << sizeof(array)/sizeof(*array) << endl;
	return 0;
}
