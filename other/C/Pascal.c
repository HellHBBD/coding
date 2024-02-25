#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10

int result[64];
unsigned long long existIndex = 1;

int Pascal(int n, int r)
{
	/* int arraySize = log2(existIndex) + 1; */
	int requireSize = (1 + n + 1) * (n + 1) / 2;
	/* if (requireSize > arraySize) */
	/* 	result = realloc(result, sizeof(int) * requireSize); */
	int index = requireSize - n + r - 1;
	if (existIndex & ((unsigned long long)1 << index)) {
		return result[index];
	} else if (r == 0 || n == r) {
		result[index] = 1;
		existIndex |= ((unsigned long long)1 << index);
		return 1;
	} else {
		result[index] = Pascal(n - 1, r - 1) + Pascal(n - 1, r);
		existIndex |= ((unsigned long long)1 << index);
		return result[index];
	}
}

int main()
{
	/* result = malloc(sizeof(int)); */
	result[0] = 1;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < N - i; j++)
			printf("   ");
		for (int j = 0; j <= i; j++)
			printf("%3d   ", Pascal(i, j));
		puts("");
	}
	return 0;
}
