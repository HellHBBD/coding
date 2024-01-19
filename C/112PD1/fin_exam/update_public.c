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

int check(int index) {
	if (index >= 10 || index < 0)
		return 1;
	return 0;
}

int update_public(struct LinkedList *head, char target[20], int idx1, int idx2, int idx3, int idx4, int *val) {
	if (check(idx1) || check(idx2) || check(idx3) || check(idx4))
		return -2;
	struct LinkedList *person = find(head, target);
	if (person == 0)
		return -1;
	*val += person->passwd_public[idx1][idx2][idx3][idx4];
	person->passwd_public[idx1][idx2][idx3][idx4] = *val - person->passwd_public[idx1][idx2][idx3][idx4];
	return 0;
}
