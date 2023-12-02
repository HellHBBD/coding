#include <stdio.h>
#include <string.h>

union Number {
		float float_number;
		unsigned float_bits;
		double double_number;
		unsigned long long double_bits;
};

void printBits(const size_t size, const void *const ptr) {
	unsigned char *b = (unsigned char *)ptr;
	for (int byte = size - 1; byte >= 0; byte--) {
		for (int bit = 7; bit >= 0; bit--)
			printf("%u", (b[byte] >> bit) & 1);
		putchar(' ');
	}
	puts("");
}

void getNumber(union Number *number, char *format) {
	if (strcmp(format, "fn") == 0) {
		scanf("%f", &number->float_number);
	} else if (strcmp(format, "fb") == 0) {
		for (int i = sizeof(float) * 8; i >= 0; i--) {
			char c = getchar();
			if (c == '0')
				number->float_bits |= (1 << i);
			else if (c == '1')
				number->float_bits &= ~(1 << i);
		}
		getchar();
	} else if (strcmp(format, "dn") == 0) {
		scanf("%lf", &number->double_number);
	} else if (strcmp(format, "db") == 0) {
		for (int i = sizeof(double) * 8; i >= 0; i--) {
			char c = getchar();
			if (c == '0')
				number->double_bits |= (1 << i);
			else if (c == '1')
				number->double_bits &= ~(1 << i);
		}
		getchar();
	}
}

void printNumber(union Number number, char *format) {
	if (strcmp(format, "fn") == 0) {
		printf("%f\n", number.float_number);
	} else if (strcmp(format, "fb") == 0) {
		for (int i = sizeof(float) * 8; i >= 0; i--)
			if (number.float_bits & (1 << i))
				putchar('1');
			else
				putchar('0');
		puts("");
	} else if (strcmp(format, "dn") == 0) {
		printf("%e\n", number.double_number);
	} else if (strcmp(format, "db") == 0) {
		for (int i = sizeof(double) * 8; i >= 0; i--)
			if (number.double_bits & (1 << i))
				putchar('1');
			else
				putchar('0');
		puts("");
	}
}

int main() {
	union Number f1, f2;
	/* 1 */
	f1.double_number = 1.175494350822287507968736537222245677818665556772087521508751706278417259454727172851560500000000000000000000000000000000e-38f;
	/* printBits(sizeof(f1), &f1); */
	printNumber(f1, "dn");
	/* 2 */
	f2.float_number = 0.0;
	/* printBits(sizeof(f2), &f2); */
	printNumber(f2, "fb");
	f2.double_number = 0.0;
	/* printBits(sizeof(f2), &f2); */
	printNumber(f2, "db");
	/* 3 */
	f2.double_number = 1.175494350822287500e-38f;
	if (f1.double_number == f2.double_number)
		printf("  %.100e\n= %.100e\n", f1.double_number, f2.double_number);
	else
		printf("  %.100e\n!= %.100e\n", f1.double_number, f2.double_number);
	return 0;
}
