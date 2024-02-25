#include <stdio.h>

long double factorialAndReciprocal(int n)
{
	long double result = 1;
	for (int i = 1; i <= n; i++)
		result /= i;
	return result;
}

int main()
{
	int n;
	scanf("%d", &n);
	long double e = 1;
	for (int i = 1; i <= n; i++)
		e += factorialAndReciprocal(i);
	printf("%.18Lf", e);
	return 0;
}
