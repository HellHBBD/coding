#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
		int data;
		struct LinkedList *next;
};

void Insert(struct LinkedList **head, int newData) {
	struct LinkedList *newNode = malloc(sizeof(struct LinkedList));
	newNode->data = newData;
	newNode->next = *head;
	*head = newNode;
}

void Reverse(struct LinkedList **head) {
	struct LinkedList *prev = *head;
	struct LinkedList *curr = prev->next;
	struct LinkedList *next = curr->next;
	prev->next = 0;
	curr->next = prev;
	while (next) {
		prev = curr;
		curr = next;
		next = next->next;
		curr->next = prev;
	}
	*head = curr;
}

void printLinkedList(struct LinkedList *head) {
	while (head != NULL) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int main() {
	struct LinkedList *head = NULL;

	Insert(&head, 2);
	Insert(&head, 3);
	Insert(&head, 7);
	Insert(&head, 1);
	Insert(&head, 9);
	Insert(&head, 10);

	printf("before:\n");
	printLinkedList(head);

	printf("after:\n");
	Reverse(&head);
	printLinkedList(head);
}
