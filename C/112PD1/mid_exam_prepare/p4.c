#include <stdio.h>
#define MAX 100

int pureRecursive(int n)
{
	if (n <= 2)
		return n;
	else
		return pureRecursive(n - 1) + pureRecursive(n - 2) +
		       pureRecursive(n - 3);
}

int iterative(int n)
{
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

int temp[MAX], record = 7;

int tempRecursive(int n)
{
	if (record & (1 << n))
		;
	else {
		temp[n] = tempRecursive(n - 1) + tempRecursive(n - 2) +
			  tempRecursive(n - 3);
		record |= (1 << n);
	}
	return temp[n];
}

int main()
{
	for (int i = 0; i < 10; i++)
		printf("%d ", pureRecursive(i));
	puts("");
	for (int i = 0; i < 10; i++)
		printf("%d ", iterative(i));
	puts("");
	temp[0] = 0;
	temp[1] = 1;
	temp[2] = 2;
	for (int i = 0; i < 10; i++)
		printf("%d ", tempRecursive(i));
	puts("");
	return 0;
}
