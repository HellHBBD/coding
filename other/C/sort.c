#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 10

void printArray(void *base, size_t memberCount)
{
	int *array = (int *)base;
	int count = 0;
	for (int i = 0; i < memberCount; i++) {
		count++;
		if (count == 20) {
			printf("%5d\n", array[i]);
			count = 0;
		} else {
			printf("%5d ", array[i]);
		}
	}
	puts("");
}

int int_asc(const void *a, const void *b)
{ //ascending
	return (*(int *)a - *(int *)b);
}

int int_des(const void *b, const void *a)
{ //descending
	return (*(int *)a - *(int *)b);
}

void swap(void *a, void *b, size_t size)
{
	void *temp = malloc(size);
	memcpy(temp, a, size);
	memcpy(a, b, size);
	memcpy(b, temp, size);
	free(temp);
}

void selectionSort(void *base, size_t memberCount, size_t memberSize,
		   int (*compare)(const void *, const void *))
{
	char *array = (char *)base;
	for (int swapIndex = 0; swapIndex < memberCount - 1; swapIndex++) {
		int minIndex = swapIndex;
		for (int findIndex = swapIndex; findIndex < memberCount;
		     findIndex++)
			if (compare(array + findIndex * memberSize,
				    array + minIndex * memberSize) < 0)
				minIndex = findIndex;
		swap(array + swapIndex * memberSize,
		     array + minIndex * memberSize, memberSize);
	}
}

void insertionSort(void *base, size_t memberCount, size_t memberSize,
		   int (*compare)(const void *, const void *))
{
	char *array = (char *)base;
	for (int selectIndex = 1; selectIndex < memberCount; selectIndex++) {
		for (int currentIndex = selectIndex - 1; currentIndex >= 0;
		     currentIndex--) {
			if (compare(array + selectIndex * memberSize,
				    array + currentIndex * memberSize) > 0)
				break;
			swap(array + selectIndex * memberSize,
			     array + currentIndex * memberSize, memberSize);
		}
	}
}

/* void bubbleSort(void *base, size_t memberCount, size_t memberSize, int (*compare)(const void *, const void *)) { */
/* 	int *array = (int *)base; // */
/* 	for (int surface = memberCount; surface > 0; surface--) { */
/* 		for (int bubble = 0; bubble < surface - 1; bubble++) */
/* 			if (compare(&array[bubble], &array[bubble + 1]) > 0) */
/* 				swap(&array[bubble], &array[bubble + 1]); */
/* 	} */
/* } */

/* void shellSort(void *base, size_t memberCount, size_t memberSize, int (*compare)(const void *, const void *)) { */
/* 	int *array = (int *)base; // */
/* } */

/* void shakerSort(void *base, size_t memberCount, size_t memberSize, int (*compare)(const void *, const void *)) { */
/* 	int *array = (int *)base; // */
/* } */

/* void quickSort(void *base, size_t memberCount, size_t memberSize, int (*compare)(const void *, const void *)) { */
/* 	int *array = (int *)base; // */
/* } */

/* void mergeSort(void *base, size_t memberCount, size_t memberSize, int (*compare)(const void *, const void *)) { */
/* 	int *array = (int *)base; // */
/* } */

/* void heapSort(void *base, size_t memberCount, size_t memberSize, int (*compare)(const void *, const void *)) { */
/* 	int *array = (int *)base; // */
/* } */

/* void radixSort(void *base, size_t memberCount, size_t memberSize, int (*compare)(const void *, const void *)) { */
/* 	int *array = (int *)base; // */
/* } */

enum Algorithm {
	selection,
	insertion,
	buble,
	shell,
	shaker,
	quick,
	merge,
	heap,
	radix
};

void sort(enum Algorithm algorithm, void *base, size_t length, size_t size,
	  int (*cmp)(const void *, const void *))
{
	if (algorithm == selection)
		selectionSort(base, length, size, cmp);
	else if (algorithm == insertion)
		insertionSort(base, length, size, cmp);
	/* else if (algorithm == buble) */
	/* else if (algorithm == shell) */
	/* else if (algorithm == shaker) */
	/* else if (algorithm == quick) */
	/* else if (algorithm == merge) */
	/* else if (algorithm == heap) */
	/* else if (algorithm == radix) */
}

int main()
{
	/* srand(time(0)); */
	int array[SIZE] = { 23, 75, 63, 76, 30, 63, 65, 46, 37, 88 };
	/* for (int i = 0; i < SIZE; i++) */
	/* 	array[i] = rand() % 100; */
	printArray(array, SIZE);
	puts("");
	sort(insertion, array, SIZE, sizeof(int), int_asc);
	puts("");
	printArray(array, SIZE);
	return 0;
}
