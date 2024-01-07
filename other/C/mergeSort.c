#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void merge(int *array, int length) {
	int sublen = length / 2;
	int *merge_array = malloc(sizeof(int) * length);
	for (int i = 0, a = 0, b = sublen; i < length; i++)
		if (a == sublen)
			merge_array[i] = array[b++];
		else if (b == length)
			merge_array[i] = array[a++];
		else if (array[a] > array[b])
			merge_array[i] = array[b++];
		else
			merge_array[i] = array[a++];
	for (int i = 0; i < length; i++)
		array[i] = merge_array[i];
	free(merge_array);
}

void mergeSort(int *array, int length) {
	if (length == 1)
		return;
	int sublen = length / 2;
	mergeSort(array, sublen);
	mergeSort(array + sublen, length - sublen);
	merge(array, length);
}

int main() {
	srand(time(0));
	int a[SIZE];
	for (int i = 0; i < SIZE; i++)
		a[i] = rand() % (SIZE * 10);
	mergeSort(a, SIZE);
	for (int i = 0; i < SIZE; i++)
		printf("%d ", a[i]);
	puts("");
	return 0;
}
