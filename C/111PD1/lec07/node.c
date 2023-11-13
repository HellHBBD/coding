#include <stdio.h>
#include <stdlib.h>

struct node {
		int value;
		struct node *next;
};

void append(struct node **list, int value) {
	struct node *this = *list;
	if (*list == 0) {
		*list = malloc(sizeof(struct node));
		(*list)->value = value;
		(*list)->next = 0;
	} else {
		while (1) {
			if (this->next == 0)
				break;
			this = this->next;
		}
		this->next = malloc(sizeof(struct node));
		this = this->next;
		this->value = value;
		this->next = 0;
	}
}

void delete (struct node **list) {
	struct node *newNode = (*list)->next;
	free(*list);
	*list = newNode;
}

void printNode(struct node *list) {
	printf("[");
	while (1) {
		if (list == 0)
			break;
		if (list->next == 0) {
			printf("%d", list->value);
			break;
		}
		printf("%d,", list->value);
		list = list->next;
	}
	puts("]");
}

int main() {
	struct node *list = 0;
	append(&list, 2);
	append(&list, 3);
	append(&list, 5);
	delete (&list);
	printNode(list);

	struct node *this = list;
	struct node *next;
	if (this == 0)
		return 0;
	else
		next = this->next;
	while (1) {
		if (next == 0) {
			free(this);
			break;
		}
		free(this);
		this = next;
		next = this->next;
	}
	list = this = next = 0;
	return 0;
}
