#include "derive.hpp"
#include <iostream>
using namespace std;

void Derive::hello()
{
		Base::hello();
		cout << "inheritance!" << endl;
}
