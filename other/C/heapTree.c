#include <stdio.h>
#include <stdlib.h>

struct heapTree{
	int length;
	int *array;
};

void print(struct heapTree *tree){
	/* int height = log2(length)+1; */
	for (int i = 0;i < tree->length;i++)
		printf("%3d",tree->array[i]);
	puts("");
}

int swap(int *a,int *b){
	if (*a <= *b)
		return -1;
	int temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

void initializedCheck(int *array,int index){
	if (index == 1)
		return;
	int noSwap = swap(&array[index-1],&array[index/2-1]);
	if (noSwap)
		return;
	initializedCheck(array,index/2);
}

void uninitializedCheck(int *array,int index){
	if (index == 1)
		return;
	int noSwap = swap(&array[index-1],&array[index/2-1]);
	if (noSwap)
		return;
	/* lookup(array,index/2); */
}

void push(struct heapTree *tree,int element){
	tree->length++;
	tree->array = realloc(tree->array,sizeof(int)*tree->length);
	tree->array[tree->length-1] = element;
	initializedCheck(tree->array,tree->length);
}

void pop(struct heapTree *tree){
	tree->length--;
	int reinsert = tree->array[tree->length];
	tree->array[0] = 0;
	tree->array = realloc(tree->array,sizeof(int)*tree->length);
}

struct heapTree *gen(int length){
	struct heapTree *tree = malloc(sizeof(struct heapTree));
	for (int i = 1;i <= length;i++)
		push(tree,i);
	return tree;
}

int main(){
	struct heapTree *tree = gen(11);
	print(tree);
	free(tree->array);
	tree->array = 0;
	free(tree);
	tree = 0;
	return 0;
}
