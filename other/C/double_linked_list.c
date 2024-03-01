#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"
#include "progress_bar.h"
#define MAX 9999

int main()
{
	struct List *list = malloc(sizeof(struct List));
	list->length = 0;
	list->head = 0;
	list->tail = 0;
	int start, end;
	for (int i = 0; i < MAX; i++)
		append(list, i);
	clear(list);
	free(list);
	return 0;
}
