#include <stdio.h>

int pureRecursive(int n) {
	if (n <= 2)
		return n;
	else
		return pureRecursive(n - 1) + pureRecursive(n - 2) + pureRecursive(n - 3);
}

int iterative(int n) {
	if (n <= 2)
		return n;
	int i0 = 0, i1 = 1, i2 = 2, j;
	for (int i = 3; i <= n; i++) {
		j = i0 + i1 + i2;
		i0 = i1;
		i1 = i2;
		i2 = j;
	}
	return j;
}

int *temp = malloc(sizeof(int) * 3), max = 2;
temp[0] = 0;
temp[1] = 1;
temp[2] = 2;

int tempRecursive(int n) {
}

int main() {
	for (int i = 0; i < 10; i++)
		printf("%d ", pureRecursive(i));
	puts("");
	for (int i = 0; i < 10; i++)
		printf("%d ", iterative(i));
	puts("");
	return 0;
}
