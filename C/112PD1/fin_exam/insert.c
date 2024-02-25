/* #include "prototype.h" */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkedList {
	char name[20];
	int passwd_public[10][10][10][10];
	int ***passwd_private;
	struct LinkedList *back_head;
	struct LinkedList *next;
};

int insert(struct LinkedList *head, char *target, struct LinkedList *insert_people)
{
	struct LinkedList *target_people = find(head, target);
	if (target_people == 0)
		return -1;
	for (; target_people->back_head; target_people = target_people->back_head)
		;
	target_people->back_head = insert_people;
	return 0;
}
