#ifndef HEAPTREE_H
#define HEAPTREE_H

#include <stdio.h>
#include <stdlib.h>
#define SWAP(a, b) ((a) ^= (b) ^= (a) ^= (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int (*cmp)(const void *, const void *) = 0;

struct heapTree {
	int length;
	int *array;
};

void setCmp(int (*)(const void *, const void *));
void levelOrder(struct heapTree *);
void preorder(struct heapTree *, int);
void inorder(struct heapTree *, int);
void postorder(struct heapTree *, int);
void levitate(struct heapTree *, int);
void sink(struct heapTree *, int);
void push(struct heapTree *, int);
int pop(struct heapTree *);
struct heapTree *gen(int);
void heapSort(int *, int);

void setCmp(int (*f)(const void *, const void *))
{
	cmp = f;
}

void levelOrder(struct heapTree *tree)
{
	/* int height = log2(length)+1; */
	/* if (queue == 0) */
	/* 	queue = malloc(sizeof(struct Queue)); */
	for (int i = 0; i < tree->length; i++)
		printf("%2d ", tree->array[i]);
}

void preorder(struct heapTree *tree, int index)
{
	if (index > tree->length)
		return;
	printf("%2d ", tree->array[index - 1]);
	preorder(tree, index * 2);
	preorder(tree, index * 2 + 1);
}

void inorder(struct heapTree *tree, int index)
{
	if (index > tree->length)
		return;
	inorder(tree, index * 2);
	printf("%2d ", tree->array[index - 1]);
	inorder(tree, index * 2 + 1);
}

void postorder(struct heapTree *tree, int index)
{
	if (index > tree->length)
		return;
	postorder(tree, index * 2);
	postorder(tree, index * 2 + 1);
	printf("%2d ", tree->array[index - 1]);
}

void sink(struct heapTree *tree, int index)
{
	if (index > tree->length)
		return;
	int *superNode = &tree->array[index - 1];
	int *leftSubNode =
		2 * index > tree->length ? 0 : &tree->array[2 * index - 1];
	int *rightSubNode =
		2 * index + 1 > tree->length ? 0 : &tree->array[2 * index];
	if (leftSubNode != 0 && cmp(superNode, leftSubNode) < 0) {
		SWAP(*superNode, *leftSubNode);
		sink(tree, 2 * index);
	}
	if (rightSubNode != 0 && cmp(superNode, rightSubNode) < 0) {
		SWAP(*superNode, *rightSubNode);
		sink(tree, 2 * index + 1);
	}
}

void levitate(struct heapTree *tree, int index)
{
	if (index == 1 ||
	    cmp(&tree->array[index / 2 - 1], &tree->array[index - 1]) >= 0)
		return;
	SWAP(tree->array[index / 2 - 1], tree->array[index - 1]);
	levitate(tree, index / 2); //check father
}

void push(struct heapTree *tree, int element)
{
	tree->length++;
	tree->array = realloc(tree->array, sizeof(int) * tree->length);
	tree->array[tree->length - 1] = element;
	levitate(tree, tree->length);
}

int pop(struct heapTree *tree)
{
	int index = tree->length, max = tree->array[0];
	tree->array[0] = tree->array[index - 1];
	tree->length--;
	tree->array = realloc(tree->array, sizeof(int) * tree->length);
	sink(tree, 1); //check from root
	return max;
}

struct heapTree *gen(int length)
{
	struct heapTree *tree = malloc(sizeof(struct heapTree));
	tree->array = 0;
	tree->length = 0;
	for (int i = 1; i <= length; i++)
		push(tree, i);
	return tree;
}

void heapSort(int *array, int size)
{
	struct heapTree tree = (struct heapTree){ .array = 0, .length = 0 };
	for (int i = 0; i < size; i++)
		push(&tree, array[i]);
	for (int i = 0; i < size; i++)
		array[i] = pop(&tree);
}

#endif
