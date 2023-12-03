#include <stdio.h>

void scanBit(unsigned *bits, const size_t size) {
	char c;
	int bit = size * 8;
	while ((c = getchar()) != '\n') {
		bit--;
		if (c - '0' && bit >= 0)
			*bits |= (1 << bit);
		else
			*bits &= ~(1 << bit);
	}
}

void bitToFloat_ptr(const void *const ptr, const size_t size) {
	printf("%f\n", *(float *)ptr);
}

void floatToBit_ptr(const void *const ptr, const size_t size) {
	unsigned *number = (unsigned *)ptr;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 7; j >= 0; j--)
			printf("%u", (*number >> (8 * i + j)) & 1);
		putchar(' ');
	}
	puts("");
}

int main() {
	float pi_f;
	scanf("%f\n", &pi_f);
	floatToBit_ptr(&pi_f, sizeof(pi_f));
	unsigned pi_b;
	scanBit(&pi_b, sizeof(pi_b));
	bitToFloat_ptr(&pi_b, sizeof(pi_b));
	return 0;
}
