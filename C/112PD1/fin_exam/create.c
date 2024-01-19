#include "prototype.h"

struct LinkedList *create(char *target, int p1, int n, int m, int l, int p2) {
	struct LinkedList *result = malloc(sizeof(struct LinkedList));
	for (int i = 0; i < strlen(target) + 1; i++)
		result->name[i] = target[i];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++)
				for (int l = 0; l < 10; l++)
					result->passwd_public[i][j][k][l] = p1;
		}
	}
	result->passwd_private = malloc(sizeof(int **) * n);
	for (int i = 0; i < n; i++) {
		result->passwd_private[i] = malloc(sizeof(int *) * m);
		for (int j = 0; j < m; j++) {
			result->passwd_private[i][j] = malloc(sizeof(int) * l);
			for (int k = 0; k < l; k++)
				result->passwd_private[i][j][k] = p2;
		}
	}
	result->next = 0;
	result->back_head = 0;
	return result;
}
