#include <iostream>
using namespace std;

int main(){
	int a = 5;
	int b;
	cout << (b = ++a); //assign expression return the value of lvalue
	return 0;
}
