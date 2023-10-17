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

struct Node *index(struct List *,int);

void reverse();

struct List *copy();

void print(struct List *);

int main(){
	struct List *list = malloc(sizeof(struct List));
	list->length = 0;
	list->head = 0;
	list->tail = 0;
	append(list,2);
	append(list,3);
	append(list,5);
	struct Node *test = index(list,0);
	printf("%d\n",test->value);
	test = index(list,1);
	printf("%d\n",test->value);
	test = index(list,2);
	printf("%d\n",test->value);
	free(list);
	return 0;
}

void append(struct List *list,T value){
	struct Node *new_node = malloc(sizeof(struct Node));
	if (list->length){
		new_node->previous = list->tail; //backward
		list->tail = new_node;
		new_node->previous->next = new_node; //forward
		new_node->next = 0;
		new_node->value = value; //assign
	}
	else{ //empty
		list->head = list->tail = new_node;
		new_node->next = new_node->previous = 0;
		new_node->value = value;
	}
	list->length ++;
}

void insert(struct List *list,int index,T value){
}

struct Node *index(struct List *list,int index){
	struct Node *result = 0;
	if (2*index <= list->length-1){
		result = list->head;
		for (int i = 0;i != index;i++)
			result = result->next;
	}
	else{
		result = list->tail;
		for (int i = list->length-1;i != index;i--)
			result = result->previous;
	}
	return result;
}

void print(struct List *list){
	for (struct Node *node = list->head;node != 0;node = node->next)
		printf("%d ",node->value);
	puts("");
}