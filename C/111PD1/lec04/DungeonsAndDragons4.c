#include <math.h>
#include <stdio.h>

void printBits(size_t const size, void const *const ptr) {
	unsigned char *b = (unsigned char *)ptr;
	unsigned char byte;
	int i, j;

	for (i = size - 1; i >= 0; i--) {
		for (j = 7; j >= 0; j--) {
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}

int getBit(int number, int start, int end) {
	int result = 0;
	for (int i = start; i < end + 1; i++)
		if (number & 1 << i)
			result |= 1 << (i - start);
		else
			result &= ~(1 << (i - start));
	return result;
}

int main() {
	unsigned int temp;
	scanf("%u", &temp);
	int byte[4];
	byte[0] = getBit(temp, 24, 31);
	byte[1] = getBit(temp, 16, 23);
	byte[2] = getBit(temp, 8, 15);
	byte[3] = getBit(temp, 0, 7);
	int d1, d2, d3, d4;
	scanf("%d %d %d %d", &d1, &d2, &d3, &d4);
	int b1 = byte[d1 - 1];
	int b2 = byte[d2 - 1];
	int b3 = byte[d3 - 1];
	int b4 = byte[d4 - 1];
	temp = 0;
	int step = b1 ^ b2;
	temp |= step << 24;
	step = b2 & b3;
	temp |= step << 16;
	step = b1 | b3;
	temp |= step << 8;
	step = getBit(~b4, 0, 7);
	temp |= step;
	int rotate = d1 + d2 + d3 + d4;
	step = getBit(temp, 0, rotate - 1);
	temp >>= rotate;
	temp |= step << (32 - rotate);
	int lower = getBit(temp, 0, 15);
	int upper = getBit(temp, 16, 31);
	temp = upper ^ lower;
	printf("%d", temp);
	return 0;
}
