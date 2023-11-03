#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *table;
unsigned long long solved;

int f(int n){
	if (solved & (1 << n))
		return table[n-1];
	solved |= (1 << n);
	int size = log2(solved) + 1;
	table = realloc(table,sizeof(int)*size);
	table[n-1] = f(n-1) + f(n-2);
	return table[n-1];
}

int main(){
	//init
	table = malloc(sizeof(int)*2);
	table[0] = 0;
	table[1] = 1;
	solved = 3;
	printf("%d\n",f(5));
	free(table);
	return 0;
}
