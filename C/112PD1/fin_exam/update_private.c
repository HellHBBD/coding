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

int update_private(struct LinkedList *head, char target[20], int idx1, int idx2, int idx3, int val)
{
		struct LinkedList *person = find(head, target);
		if (person == 0)
				return -1;
		person->passwd_private[idx1][idx2][idx3] = val;
		return 0;
}
