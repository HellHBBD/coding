#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#define T int

struct Node {
	T value;
	struct Node *next;
	struct Node *previous;
};

struct List {
	int length;
	struct Node *head;
	struct Node *tail;
};

void append(struct List *list, T value)
{
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->value = value; //assign
	if (list->length) {
		new_node->previous = list->tail; //backward
		list->tail = new_node;
		new_node->previous->next = new_node; //forward
		new_node->next = 0;
	} else { //empty
		list->head = list->tail = new_node;
		new_node->next = new_node->previous = 0;
	}
	list->length++;
}

struct Node *search(struct List *list, int index)
{
	struct Node *result = 0;
	if (2 * index <= list->length - 1) {
		result = list->head;
		for (int i = 0; i != index; i++)
			result = result->next;
	} else {
		result = list->tail;
		for (int i = list->length - 1; i != index; i--)
			result = result->previous;
	}
	return result;
}

void insert(struct List *list, int index, T value)
{
	struct Node *after_node = search(list, index);
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->value = value; //assign
	if (after_node->previous == 0) { //head
		new_node->previous = 0; //backward
		after_node->previous = new_node;
		list->head = new_node; //forward
		new_node->next = after_node;
	} else {
		new_node->previous = after_node->previous; //backward
		after_node->previous = new_node;
		new_node->previous->next = new_node; //forward
		new_node->next = after_node;
	}
	list->length++;
}

void clear(struct List *list)
{
	struct Node *forward = list->head;
	struct Node *backward = list->tail;
	while (1) {
		if (forward == backward) {
			free(forward);
			forward = 0;
			break;
		}
		if (forward->next == backward) {
			free(forward);
			free(backward);
			forward = backward = 0;
			break;
		}
		forward = forward->next;
		backward = backward->previous;
		free(forward->previous);
		free(backward->next);
		forward->previous = backward->next = 0;
	}
	list->length = 0;
	list->head = list->tail = 0;
}

void reverse(struct List *list)
{
}

void print(struct List *list)
{
	for (struct Node *node = list->head; node != 0; node = node->next)
		printf("%d ", node->value);
	puts("");
}

#endif
