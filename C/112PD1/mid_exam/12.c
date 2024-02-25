#include <stdio.h>

int main()
{
	int(*p)[4], *q[4] = { 0 }, **r; //q is array of pointer
	int array[] = { 2, 3, 5, 7 };
	p = &array; //p is pointer to array
	r = q; //r is equivalent to q
	return 0;
}
