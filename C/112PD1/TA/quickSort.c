#include <stdio.h>
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))
#define SIZE 10

/* void swap(int *a, int *b) { */
/* 	int temp = *a; */
/* 	*a = *b; */
/* 	*b = *a; */
/* } */

void QSORT(int *array, int left, int right) {

	if (left >= right)
		return;

	int l = left + 1;
	int r = right;
	int key = array[left];

	///to-do///

	QSORT(array);
	QSORT(array);
}

int main(void) {

	int array[SIZE];

	for (int i = 0; i < SIZE; i++)
		scanf("%d", &array[i]);

	QSORT(array, 0, SIZE - 1);

	for (int i = 0; i < SIZE; i++)
		printf("%d ", array[i]);
	return 0;
}
