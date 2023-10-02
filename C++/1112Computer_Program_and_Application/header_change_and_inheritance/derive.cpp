#include <iostream>
#include "derive.hpp"
using namespace std;

void Derive::hello(){
	Base::hello();
	cout << "inheritance!" << endl;
}
