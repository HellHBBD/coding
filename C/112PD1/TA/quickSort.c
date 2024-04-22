#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))
#define SIZE 10

/* void swap(int *a, int *b) { */
/* 	int temp = *a; */
/* 	*a = *b; */
/* 	*b = *a; */
/* } */

void print(int *array)
{
	for (int i = 0; i < SIZE; i++)
		printf("%d ", array[i]);
	puts("");
}

void quickSort(int array[], int leftest, int rightest)
{
	if (leftest < rightest) {
		int key = array[(leftest + rightest) / 2];
		int left_index = leftest - 1;
		int right_index = rightest + 1;

		while (1) {
			while (array[++left_index] < key)
				;
			/* find left */
			while (array[--right_index] > key)
				;
			/* find right */
			if (left_index >= right_index)
				break;
			swap(array[left_index], array[right_index]);
		}
		quickSort(array, leftest, left_index - 1); //recursive at left
		quickSort(array, right_index + 1,
			  rightest); //recursive at right
	}
}

int main(void)
{
	srand(time(0));
	int array[SIZE];
	for (int i = 0; i < SIZE; i++)
		array[i] = rand() % 10;

	quickSort(array, 0, SIZE - 1);

	for (int i = 0; i < SIZE; i++)
		printf("%d ", array[i]);
	puts("");
	return 0;
}
