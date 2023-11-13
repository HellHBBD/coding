#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1) {
	uint64_t fk, fk1, foo;
	if (k == 0) {
		*f2k = 1;
		*f2k1 = 1;
	} else if (k == 1) {
		*f2k = 1;
		*f2k1 = 2;
	} else if (k & 0x1) { //odd
		fib_fast_doubling(k / 2, &foo, &fk);
		fib_fast_doubling((k + 1) / 2, &fk1, &foo);
		*f2k = fk * (2 * fk1 - fk);
		*f2k1 = fk * fk + fk1 * fk1;
	} else { //even
		fib_fast_doubling(k / 2, &fk, &fk1);
		*f2k = fk * (2 * fk1 - fk);
		*f2k1 = fk * fk + fk1 * fk1;
	}
}

int main() {
	for (unsigned k = 1; k < 94; k++) {
		uint64_t f2k, f2k1;
		fib_fast_doubling(k / 2, &f2k, &f2k1);
		printf("%llu\n", (k & 0x1) ? f2k1 : f2k);
	}

	return 0;
}
