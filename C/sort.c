#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void printArray(void *base,size_t memberCount){
	int *array = (int *)base;
	int count = 0;
	for (int i = 0;i < memberCount;i++){
		count++;
		if (count == 20){
			printf("%5d\n",array[i]);
			count = 0;
		}
		else{
			printf("%5d ",array[i]);
		}
	}
	puts("");
}

int compare(const void *a,const void *b){
	return (*(int*)a-*(int*)b); //increase
}

void swap(int *a,int *b){ //
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void selectionSort(void *base,size_t memberCount,size_t memberSize,int (*compare)(const void *,const void *)){
	int *array = (int *)base; //
	for (int swapIndex = 0;swapIndex < memberCount-1;swapIndex++){
		int minIndex = swapIndex;
		for (int findIndex = swapIndex;findIndex < memberCount;findIndex++){
			if (compare(&array[findIndex],&array[minIndex]) < 0)
				minIndex = findIndex;
		}
		if (swapIndex != minIndex)
			swap(&array[swapIndex],&array[minIndex]);
	}
}

void insertionSort(void *base,size_t memberCount,size_t memberSize,int (*compare)(const void *,const void *)){
	int *array = (int *)base; //
	for (int selectIndex = 1;selectIndex < memberCount;selectIndex++){
		for (int currentIndex = selectIndex-1;currentIndex >= 0;currentIndex--){
			if (compare(&array[selectIndex],&array[currentIndex]) > 0)
				break;
			swap(&array[selectIndex],&array[currentIndex]);
		}
	}
}

void bubbleSort(void *base,size_t memberCount,size_t memberSize,int (*compare)(const void *,const void *)){
	int *array = (int *)base; //
	for (int surface = memberCount;surface > 0;surface--){
		for (int bubble = 0;bubble < surface-1;bubble++){
			if (compare(&array[bubble],&array[bubble+1]) > 0){
				swap(&array[bubble],&array[bubble+1]);
			}
		}
	}
}

void shellSort(void *base,size_t memberCount,size_t memberSize,int (*compare)(const void *,const void *)){
	int *array = (int *)base; //
}

void shakerSort(void *base,size_t memberCount,size_t memberSize,int (*compare)(const void *,const void *)){
	int *array = (int *)base; //
}

void quickSort(void *base,size_t memberCount,size_t memberSize,int (*compare)(const void *,const void *)){
	int *array = (int *)base; //
}

void mergeSort(void *base,size_t memberCount,size_t memberSize,int (*compare)(const void *,const void *)){
	int *array = (int *)base; //
}

void heapSort(void *base,size_t memberCount,size_t memberSize,int (*compare)(const void *,const void *)){
	int *array = (int *)base; //
}

void radixSort(void *base,size_t memberCount,size_t memberSize,int (*compare)(const void *,const void *)){
	int *array = (int *)base; //
}

int main(){
	//srand(time(0));
	int *array = malloc(sizeof(int)*SIZE);
	for (int i = 0;i < SIZE;i++)
		array[i] = rand();
	printArray(array,SIZE);
	puts("");
	insertionSort(array,SIZE,sizeof(int),compare);
	puts("");
	printArray(array,SIZE);
	free(array);
	return 0;
}
