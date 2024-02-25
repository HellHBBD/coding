#include <stdio.h>
#define MAX 200
#define max(a, b) ((a) > (b) ? (a) : (b))

int main()
{
	int combine[MAX];
	long long int a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld%lld\n", a, b);
	int i = 0;
	while (b != 0) {
		int digit = b % 10;
		combine[i] = digit;
		b /= 10;
		i++;
	}
	while (a != 0) {
		int digit = a % 10;
		combine[i] = digit;
		a /= 10;
		i++;
	}
	int even = 0;
	int odd = 0;
	for (int j = 0; j < i; j++)
		if (j % 2 == 0)
			odd += combine[j];
		else
			even += combine[j];
	if ((even - odd) % 11 == 0)
		printf("Yes");
	else
		printf("No");
	return 0;
}
