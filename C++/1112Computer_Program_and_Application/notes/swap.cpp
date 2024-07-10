#include <iostream>
using namespace std;

void swap_ptr(int *a, int *b)
{ //declare pointer and point to the memory
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void swap_ref(int &a, int &b)
{ //pass memory position directly
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void mul_ptr(int *a, int n)
{
	*a *= n;
}

void mul_ref(int &a, int n)
{
	a *= n;
}

int main()
{
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	swap_ptr(&a, &b);
	swap_ref(x, y);
	cout << a << " " << b << endl;
	cout << x << " " << y << endl;
	mul_ptr(&a, b);
	mul_ref(x, y);
	cout << a << " " << b << endl;
	cout << x << " " << y << endl;
	return 0;
}
