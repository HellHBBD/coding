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

void count(const struct list *table, int item, int *total)
{
		if (table[item - 1].length == 0)
				(*total)++;
		else
				for (int i = 0; i < table[item - 1].length; i++)
						count(table, table[item - 1].array[i], total);
}

int main()
{
		int itemCount;
		scanf("%d", &itemCount);
		struct list *table = malloc(sizeof(struct list) * itemCount);
		for (int i = 0; i < itemCount; i++) {
				scanf("%d", &table[i].length);
				table[i].array = malloc(sizeof(int) * table[i].length);
				for (int j = 0; j < table[i].length; j++)
						scanf("%d", &table[i].array[j]);
		}

		int total = 0;
		for (int i = 0; i < itemCount; i++)
				count(table, i + 1, &total);
		printf("%d", total);

		for (int i = 0; i < itemCount; i++) { //free table
				free(table[i].array);
				table[i].array = 0;
		}
		free(table);
		table = 0; //free table
		return 0;
}
