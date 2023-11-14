#include <stdio.h>
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

int main() {
	printf("Please input two integer and get their GCD(greastest common divisor).\n");
	int n, m, gcd;
	scanf("%d%d", &n, &m);

	while (m > 0 && n > 0) {
		// to make n be greater than m
		if (m > n)
			swap(m, n);

		n = n % m;
	}
	gcd = m;

	printf("The GCD of the two numbers is %d.\n", gcd);
	return 0;
}
