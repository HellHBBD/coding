#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *table;
unsigned long long solved;

int f(int n){
	if (solved & (1 << n))
		return table[n];
	int size = log2(solved);
	if (n > size){
		table = realloc(table,sizeof(int)*(n+1));
	}
	solved |= (1 << n);
	table[n] = f(n-1) + f(n-2);
	return table[n];
}

int main(){
	//init
	table = malloc(sizeof(int)*2);
	table[0] = 0;
	table[1] = 1;
	solved = 3;
	for (int i = 0;i < 20;i++)
		printf("%d ",f(i));
	puts("");
	free(table);
	return 0;
}
