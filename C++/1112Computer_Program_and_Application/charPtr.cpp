#include <iostream>
using namespace std;

int main()
{
	int a[] = { 1, 2, 3 };
	char ch[] = "abc";
	cout << "a = " << a << endl; //print address
	cout << "ch = " << ch << endl; //print string
	cout << "&ch = " << &ch << endl; //print address
	cout << "(void*)ch = " << (void *)ch << endl; //cast as a void pointer (print address)
	cout << "*ch = " << *ch << endl; //print ch[0]

	cout << endl;

	char *cp = ch;
	cout << "cp = " << cp << endl; //print string
	cout << "(void*)cp = " << (void *)cp << endl; //cast as a void pointer (print address)

	cout << endl;

	char c = '$';
	char *p = &c;
	cout << "c = " << c << endl;
	cout << "p = " << p << endl; //default as a string (stop at \0)

	return 0;
}
