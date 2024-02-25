#include <stdio.h>

int reverse(int n)
{
	int tens = (n % 100) / 10;
	int units = n % 10;
	return n / 100 * 100 + tens + units * 10;
}

int main()
{
	int N;
	scanf("%d", &N);
	printf("%d", 2023 * reverse(N));
	return 0;
}
