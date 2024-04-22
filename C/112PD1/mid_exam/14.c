#include <stdio.h>
int W = 32;

void Direct_convert(unsigned Rmin, unsigned Rmax, unsigned L[], unsigned U[],
		    unsigned *n)
{
	int d = 0, i;
	while (Rmin <= Rmax) {
		for (i = 0; i < W; i++)
			if ((Rmin % (1 << (i + 1)) != 0) ||
			    (Rmin + (1 << (i + 1)) - 1) > Rmax)
				break;
		L[d] = Rmin;
		U[d] = Rmin + (1 << i) - 1;
		d = d + 1;
		Rmin = Rmin + (1 << i);
	}
	*n = d;
}

int main()
{
	unsigned L1[10] = { 0 };
	unsigned U1[10] = { 0 };
	unsigned L2[10] = { 0 };
	unsigned U2[10] = { 0 };
	unsigned n = 0;
	Direct_convert(333, 333, L1, U1, &n);
	puts("  L   U");
	for (int i = 0; i < n; i++)
		printf("%3u %3u\n", L1[i], U1[i]);
	puts("");
	n = 0;
	Direct_convert(3, 128, L2, U2, &n);
	puts("  L   U");
	for (int i = 0; i < n; i++)
		printf("%3u %3u\n", L2[i], U2[i]);
	return 0;
}
