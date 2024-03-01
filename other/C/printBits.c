#include <stdio.h>
#include "printBits.h"

int main()
{
	int x = 1234567800;
	printBits(sizeof(x), &x);
	return 0;
}
