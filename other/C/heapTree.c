#include <stdio.h>
#include <time.h>
#include "heapTree.h"
#define SIZE 10

int max(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int min(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	srand(time(0));
	setCmp(min);
	struct heapTree tree = (struct heapTree){ .array = 0, .length = 0 };
	int array[SIZE];
	for (int i = 0; i < SIZE; i++)
		push(&tree, rand() % 100);
	levelOrder(&tree);
	puts("");
	/* preorder(&tree, 1); */
	/* puts(""); */
	/* inorder(&tree, 1); */
	/* puts(""); */
	/* postorder(&tree, 1); */
	/* puts(""); */
	for (int i = 0; i < SIZE; i++) {
		array[i] = pop(&tree);
		levelOrder(&tree);
		puts("");
	}
	puts("");
	for (int i = 0; i < SIZE; i++)
		printf("%2d ", array[i]);
	puts("");
	return 0;
}
