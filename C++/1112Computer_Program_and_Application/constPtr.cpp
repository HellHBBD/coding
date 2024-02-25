#include <iostream>
using namespace std;

void f(const int *xPtr)
{
	//*xPtr = 100; error: const can't be lvalue
}

int main()
{
	int x, y, z, x1, y1, z1;

	const int *xPtr = &x;
	xPtr = &x1;
	//*xPtr = 1; error: can't assign value

	int *const yPtr = &y;
	//yPtr = &y1; error: can't assign address
	*yPtr = 1;

	const int *const zPtr = &z;
	//zPtr = &z1; error: can't assign value
	//*zPtr = 1;  error: can't assign address

	return 0;
}
