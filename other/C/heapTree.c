#include <stdio.h>
#include <stdlib.h>

struct heapTree {
		int length;
		int *array;
};

void print(struct heapTree *tree) {
	/* int height = log2(length)+1; */
	for (int i = 0; i < tree->length; i++)
		printf("%3d", tree->array[i]);
	puts("");
}

int max(const int a, const int b) {
	return a - b;
}

int min(const int a, const int b) {
	return b - a;
}

int swap(int *array, int index1, int index2) {
	if (max(array[index1 - 1], array[index2 - 1]) <= 0)
		return -1;
	int temp = array[index1 - 1];
	array[index1 - 1] = array[index2 - 1];
	array[index2 - 1] = temp;
	return index2;
}

void initializedCheck(int *array, int index) { //done
	if (index == 1)
		return;
	int noSwap = swap(array, index - 1, index / 2 - 1);
	if (noSwap)
		return;
	initializedCheck(array, index / 2);
}

void uninitializedCheck(int *array, int index) {
	if (index == 1)
		return;
	int noSwap = swap(array, index - 1, index / 2 - 1);
	if (noSwap)
		return;
	/* lookup(array,index/2); */
}

void push(struct heapTree *tree, int element) { //done
	tree->length++;
	tree->array = realloc(tree->array, sizeof(int) * tree->length);
	tree->array[tree->length - 1] = element;
	initializedCheck(tree->array, tree->length);
}

int pop(struct heapTree *tree) {
	int max = tree->array[0];
	tree->array[0] = tree->array[tree->length - 1];
	tree->length--;
	tree->array = realloc(tree->array, sizeof(int) * tree->length);
	uninitializedCheck(tree->array, 1);
}

struct heapTree *gen(int length) { //done
	struct heapTree *tree = malloc(sizeof(struct heapTree));
	tree->array = 0;
	tree->length = 0;
	for (int i = 1; i <= length; i++)
		push(tree, i);
	return tree;
}

int main() {
	struct heapTree *tree = gen(11);
	print(tree);
	free(tree->array);
	tree->array = 0;
	free(tree);
	tree = 0;
	return 0;
}
