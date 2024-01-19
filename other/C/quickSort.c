#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void swap(int *a, int *b)
{
		int temp = *a;
		*a = *b;
		*b = temp;
}

void quickSort(int *array, int left, int right)
{
		if (left >= right)
				return;
		int pivot = array[(left + right) / 2];
		int l = left - 1;
		int r = right + 1;
		while (1) {
				while (array[++l] < pivot)
						;
				while (array[--r] > pivot)
						;
				if (l >= r)
						break;
				swap(&array[l], &array[r]);
		}
		quickSort(array, left, l - 1);
		quickSort(array, r + 1, right);
}

int main()
{
		srand(time(0));
		int a[SIZE];
		for (int i = 0; i < SIZE; i++)
				a[i] = rand() % (SIZE * 10);
		quickSort(a, 0, SIZE - 1);
		for (int i = 0; i < SIZE; i++)
				printf("%d ", a[i]);
		puts("");
		return 0;
}
