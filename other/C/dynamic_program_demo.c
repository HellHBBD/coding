#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "printBits.h"

int *table;
unsigned long long solved;

int f(int n)
{
	if (solved & (1 << n)) //test if n bit is 1
		return table[n];
	if (n > log2(solved)) //determine if n is bigger than max size
		table = realloc(table, sizeof(int) * (n + 1));
	solved |= (1 << n); //set n bit as 1
	table[n] = f(n - 1) + f(n - 2); //recursive and store the result
	return table[n];
}

int main()
{
	//init
	table = malloc(sizeof(int) * 2);
	table[0] = 0;
	table[1] = 1;
	solved = 3;

	//test
	for (int i = 0; i < 20; i++)
		printf("%-5d\n", f(i));
	puts("");

	free(table);
	return 0;
}
