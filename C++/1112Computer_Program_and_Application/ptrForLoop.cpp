#include <iostream>
using namespace std;

int main() {
	char msg1[] = "hello";
	//char *msg2 = "hello"; //point to symbol table
	for (char *p = msg1; *p != '\0'; ++p)
		cout << *p;
	cout << endl;

	for (char *p = msg1; *p != '\0'; ++p)
		cout << *p;
	cout << endl;

	for (char *p = msg1; *p != '\0'; cout << *p, ++p)
		;
	cout << endl;

	for (char *p = msg1; *p != '\0'; cout << *p++)
		;
	cout << endl;
	return 0;
}
