#include <stdio.h>
#include "Cgen.h"
#include "printBits.h"

int main()
{
	int array[20] = {};
	int index = 0;
	Cgen(5, 3, 0, array, &index);
	for (int i = 0; i < 10; i++)
		printBits(sizeof(int), &array[i]);
	return 0;
}
