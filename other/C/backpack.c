#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define abs(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

void printBits(size_t const size, void const *const ptr)
{
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

void Cgen(const int n, const int r, int select, int *array, int *index)
{
	if (r == 1) {
		for (int i = 0; i < n; i++) {
			select |= (1 << i);
			array[*index] = select;
			(*index)++;
			select &= ~(1 << i);
		}
		return;
	}
	for (int a = r - 1; a < n; a++) {
		select |= (1 << a);
		Cgen(a, r - 1, select, array, index);
		select &= ~(1 << a);
	}
}

int main()
{
	int array[20] = {};
	int index = 0;
	Cgen(5, 3, 0, array, &index);
	for (int i = 0; i < 10; i++)
		printBits(sizeof(int), &array[i]);
	return 0;
}
