#include <stdio.h>

unsigned setFloat(unsigned sign, unsigned exponent, unsigned fraction) {
	unsigned result = 0;
	result = (sign << 31) | (exponent << 23) | (fraction);
	return result;
}

int main() {
	/* 1 */
	puts("1.");
	unsigned ptr = setFloat(0, 0b00000001, 0b00000000000000000000000);
	printf("%e\n", *(float *)&ptr);
	ptr = setFloat(0, 0b00000000, 0b00000000000000000000001);
	printf("%e\n", *(float *)&ptr);
	float f = 1.40129846432e-45;
	printf("%e\n", f);
	/* 2 */
	puts("\n2.");
	ptr = setFloat(0, 0b00000000, 0b00000000000000000000000);
	printf("%e\n", *(float *)&ptr);
	/* 3 */
	puts("\n3.");
	double f1 = 1.175494350822287507968736537222245677818665556772087521508751706278417259454727172851560500000000000000000000000000000000e-38f;
	double f2 = 1.175494350822287500e-38f;
	if (f1 == f2)
		printf("%.100e = %.100e", f1, f2);
	else
		printf("%.100e != %.100e", f1, f2);
	puts("");
	return 0;
}
