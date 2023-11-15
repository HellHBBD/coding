#include <stdio.h>
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

int GCD_recursion(int p, int q) {
	/* int r; */
	int r = p % q;
	printf("%2d %2d %2d\n", p, q, r);
	/* if ((r = p % q) == 0) */
	if (r == 0)
		return q;
	else
		return GCD_recursion(q, r);
}

int GCD_loop(int p, int q) {
	while (p > 0 && q > 0) {
		int r = p % q;
		printf("%2d %2d %2d\n", p, q, r);
		if (r == 0)
			return q;
		p = q;
		q = r;
	}
}

int main() {
	printf("Please input two integer and get their GCD(greastest common divisor).\n");
	int n, m, gcd;
	scanf("%d%d", &n, &m);
	puts("recursion");
	printf("The GCD of the two numbers is %d.\n", GCD_recursion(m, n));
	puts("loop");
	printf("The GCD of the two numbers is %d.\n", GCD_loop(m, n));

	return 0;
}
