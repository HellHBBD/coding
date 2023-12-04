#include <stdio.h>

struct byte {
		unsigned char b1 : 1;
		unsigned char b2 : 1;
		unsigned char b3 : 1;
		unsigned char b4 : 1;
		unsigned char b5 : 1;
		unsigned char b6 : 1;
		unsigned char b7 : 1;
		unsigned char b8 : 1;
};

union Number {
		float f;
		unsigned bits;
		struct byte bitField[4];
};

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
	unsigned number = *(unsigned *)ptr;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 7; j >= 0; j--)
			printf("%u", (number >> (8 * i + j)) & 1);
		putchar(' ');
	}
	puts("");
}

void bitToFloat_union(const void *const ptr, const size_t size) {
	union Number number = {.bits = *(unsigned *)ptr};
	printf("%f\n", number.f);
}

void floatToBit_union(const void *const ptr, const size_t size) {
	union Number number = {.f = *(float *)ptr};
	for (int i = size - 1; i >= 0; i--) {
		for (int j = 7; j >= 0; j--)
			printf("%u", (number.bits >> (8 * i + j)) & 1);
		putchar(' ');
	}
	puts("");
}

void bitToFloat_bitField(const void *const ptr, const size_t size) {
	union Number number;
	for (int i = size - 1; i >= 0; i--) {
		number.bitField[i].b8 = (*(unsigned *)ptr >> (8 * i + 7)) & 1;
		number.bitField[i].b7 = (*(unsigned *)ptr >> (8 * i + 6)) & 1;
		number.bitField[i].b6 = (*(unsigned *)ptr >> (8 * i + 5)) & 1;
		number.bitField[i].b5 = (*(unsigned *)ptr >> (8 * i + 4)) & 1;
		number.bitField[i].b4 = (*(unsigned *)ptr >> (8 * i + 3)) & 1;
		number.bitField[i].b3 = (*(unsigned *)ptr >> (8 * i + 2)) & 1;
		number.bitField[i].b2 = (*(unsigned *)ptr >> (8 * i + 1)) & 1;
		number.bitField[i].b1 = (*(unsigned *)ptr >> (8 * i + 0)) & 1;
	}
	printf("%f\n", number.f);
}

void floatToBit_bitField(const void *const ptr, const size_t size) {
	union Number number = {.f = *(float *)ptr};
	for (int i = size - 1; i >= 0; i--) {
		printf("%u", number.bitField[i].b8);
		printf("%u", number.bitField[i].b7);
		printf("%u", number.bitField[i].b6);
		printf("%u", number.bitField[i].b5);
		printf("%u", number.bitField[i].b4);
		printf("%u", number.bitField[i].b3);
		printf("%u", number.bitField[i].b2);
		printf("%u", number.bitField[i].b1);
		putchar(' ');
	}
	puts("");
}

int main() {
	float pi_f;
	scanf("%f\n", &pi_f);
	printf("print binary format of float number (int_ptr):   ");
	floatToBit_ptr(&pi_f, sizeof(pi_f));
	printf("print binary format of float number (union):     ");
	floatToBit_union(&pi_f, sizeof(pi_f));
	printf("print binary format of float number (bit field): ");
	floatToBit_bitField(&pi_f, sizeof(pi_f));
	unsigned pi_b;
	scanBit(&pi_b, sizeof(pi_b));
	printf("print float format of binary number (int_ptr):   ");
	bitToFloat_ptr(&pi_b, sizeof(pi_b));
	printf("print float format of binary number (union):     ");
	bitToFloat_union(&pi_b, sizeof(pi_b));
	printf("print float format of binary number (bit field): ");
	bitToFloat_bitField(&pi_b, sizeof(pi_b));
	return 0;
}
