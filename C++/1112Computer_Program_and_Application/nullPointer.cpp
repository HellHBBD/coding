#include <iostream>
using namespace std;

int main() {
	int *cp;
	cp = 0; //null pointer
	//cp = 1; -> error
	*cp = 0; //change the pointing value
	//lvalue = rvalue;
	//lvalue require a position to store
	//rvalue require an expression
	//<expression>; -> statment(no syntax error)
	return 0;
}
