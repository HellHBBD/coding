#include <stdio.h>
#include <stdlib.h>

void a(short *array, unsigned long long *a, unsigned long long *b) {
	*a = *b = 0;
	for (int i = 0; i < 4; i++) {
		unsigned long long num1 = array[i];
		unsigned long long num2 = array[i + 4];
		for (int j = 0; j < (3 - i) * 16; j++) {
			num1 *= 2;
			num2 *= 2;
		}
		*a += num1;
		*b += num2;
	}
}

long int *fucn(short int *array) {
	long int temp1 = 0;
	long int temp2 = 0;
	int i;
	for (i = 0; i < 4; i++) {
		temp1 += array[i];
		if (i != 3)
			temp1 *= 65536;
	}
	for (i = 4; i < 8; i++) {
		temp2 += array[i];
		if (i != 3)
			temp2 *= 65536;
	}
	long int *result = malloc(sizeof(long int) * 2);
	result[0] = temp1;
	result[1] = temp2;
	return result;
}

int main() {
	short array[] = {0x1050, 0x0000, 0x0000, 0x0000, 0x0005, 0x0600, 0x300c, 0x326b};
	unsigned long long x, y;
	a(array, &x, &y);
	printf("%llu %llu\n", x, y);
	long int *result = fucn(array);
	printf("%lu %lu\n", result[0], result[1]);
	free(result);
	return 0;
}
