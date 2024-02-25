#include <stdio.h>
#include <stdlib.h>

struct list {
	int length;
	int *array;
};

void printList(struct list *table, int count)
{
	for (int i = 0; i < count; i++) {
		printf("%d: ", i + 1);
		for (int j = 0; j < table[i].length; j++)
			printf("%d ", table->array[j]);
		puts("");
	}
}

struct node {
	int value;
	struct node *next;
};

void append(struct node **list, int value)
{
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

void delete (struct node **list)
{
	struct node *newNode = (*list)->next;
	free(*list);
	*list = newNode;
}

void printNode(struct node *list)
{
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

int main()
{
	int itemCount;
	scanf("%d", &itemCount);
	struct list *table = malloc(sizeof(struct list) * itemCount);
	struct node *materialList, *this, *next;
	materialList = this = next = 0;
	for (int i = 0; i < itemCount; i++) {
		scanf("%d", &table[i].length);
		append(&materialList, i + 1);
		table[i].array = malloc(sizeof(int) * table[i].length);
		for (int j = 0; j < table[i].length; j++)
			scanf("%d", &table[i].array[j]);
	}

	this = materialList; //decompose
	int totalCount = 0; //count
	while (1) {
		if (this == 0)
			break;
		int index = this->value - 1;
		if (table[index].length == 0) {
			totalCount++;
			delete (&this);
			materialList = this;
			continue;
		} else {
			for (int i = 0; i < table[index].length; i++)
				append(&this, table[index].array[i]);
			delete (&this);
			materialList = this;
		}
	} //decompose
	this = 0;
	printf("%d", totalCount); //count

	for (int i = 0; i < itemCount; i++) { //free table
		free(table[i].array);
		table[i].array = 0;
	}
	free(table);
	table = 0; //free table
	return 0;
}
