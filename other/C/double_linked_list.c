#include <stdio.h>
#include <stdlib.h>
#define T int

struct Node{
	T value;
	struct Node *next;
	struct Node *previous;
};

struct List{
	int length;
	struct Node *head;
	struct Node *tail;
};

void append(struct List *,T);

void insert(struct List *,int,T);

void rm();

void pop();

void clear();

struct List *find();

struct Node *index();

void reverse();

struct List *copy();

void print(struct List *);

int main(){
	struct List *list = malloc(sizeof(struct List));
	list->head = 0;
	list->tail = 0;
	append(list,2);
	append(list,3);
	append(list,5);
	print(list);
	free(list);
	return 0;
}

void append(struct List *list,T value){
	struct Node *new_node = malloc(sizeof(struct Node));
	if (list->head && list->tail){
		new_node->previous = list->tail; //backward
		list->tail = new_node;
		new_node->previous->next = new_node; //forward
		new_node->next = 0;
		new_node->value = value; //assign
	}
	else{
		list->head = list->tail = new_node;
		new_node->next = new_node->previous = 0;
		new_node->value = value;
	}
	list->length ++;
}

void insert(struct List *list,int index,T value){
}

void print(struct List *list){
	for (struct Node *node = list->head;node != 0;node = node->next)
		printf("%d ",node->value);
	puts("");
}
