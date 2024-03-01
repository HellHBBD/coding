#ifndef PRINTBITS_H
#define PRINTBITS_H

#include <stdio.h>

void printBits(const size_t size, const void *const ptr)
{
	unsigned char *b = (unsigned char *)ptr;
	for (int byte = size - 1; byte >= 0; byte--) {
		for (int bit = 7; bit >= 0; bit--)
			printf("%u", (b[byte] >> bit) & 1);
		putchar(' ');
	}
	puts("");
}

#endif
