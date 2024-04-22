#include <stdio.h>
#include "printBits.h"

#define CLEAR(num, digit) ((num) &= ~(1 << (digit)))
#define SET(num, digit) ((num) |= (1 << (digit)))

void xor
	(unsigned *num, const int source, const int digit,
	 const unsigned char key) {
		if (source ^ key) {
			SET(*num, digit);
		} else {
			CLEAR(*num, digit);
		}
	}

	unsigned gen(const void *data, size_t size)
{
	unsigned code = 0;
	unsigned char *new_data = (unsigned char *)data;
	for (int byte = size - 1; byte >= 0; byte--) {
		for (int bit = 7; bit >= 0; bit--) {
			unsigned char key = (code >> 15) & 1;
			code <<= 1;
			xor(&code, (new_data[byte] >> bit) & 1, 0, key);
			xor(&code, (code >> 5) & 1, 5, key);
			xor(&code, (code >> 12) & 1, 12, key);
			printBits(&code, sizeof(code));
		}
	}
	return code & 65535;
}

int main()
{
	const unsigned correct = 174762;
	const unsigned wrong = 436906;
	const unsigned long long test = 1038892647605;
	/* printBits(&test, sizeof(test)); */
	printBits(&correct, sizeof(correct));
	unsigned result = gen(&test, sizeof(test));
	printBits(&result, sizeof(result));
	/* printBits(&wrong, sizeof(wrong)); */
	return 0;
}
