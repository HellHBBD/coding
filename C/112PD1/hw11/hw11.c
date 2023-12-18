#include "clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define firstBits(n, d) ((n) >> (32 - (d)))

struct prefix {
		unsigned ip;
		unsigned char len;
		struct prefix *next;
};

struct prefix *head = 0;
struct prefix **group = 0;
int d = 0;

void input(const char *file) {
	FILE *init = fopen(file, "r");
	unsigned char temp[5];
	int count = 0;
	struct prefix *current = 0;
	while (1) {
		memset(temp, 0, 5);
		int scanCount = fscanf(init, "%hhu.%hhu.%hhu.%hhu/%hhu", temp, temp + 1, temp + 2, temp + 3, temp + 4);
		if (scanCount == 4) {
			/* temp[4] = (temp[0] ? 8 : 0) + (temp[1] ? 8 : 0) + (temp[2] ? 8 : 0) + (temp[3] ? 8 : 0); */
			temp[4] = temp[3] ? 32 : temp[2] ? 24
								   : temp[1] ? 16
								   : temp[0] ? 8
											 : 0;
		} else if (scanCount == -1) {
			printf("%d\n", count);
			fclose(init);
			return;
		}
		if (current) {
			current->next = malloc(sizeof(struct prefix));
			count++;
			current = current->next;
			memcpy(&current->ip, temp, 4);
			current->len = temp[4];
		} else {
			head = malloc(sizeof(struct prefix));
			current = head;
			count++;
			memcpy(&current->ip, temp, 4);
			current->len = temp[4];
		}
	}
}

void length_distribution(int i) {
	int count = 0;
	for (struct prefix *current = head; current; current = current->next)
		if (current->len == i)
			count++;
	printf("%d\n", count);
}

void segment(int d) {
	int size = (1 << d);
	group = malloc(sizeof(struct prefix *) * size);
	memset(group, 0, sizeof(struct prefix *) * size);
	int i;
	for (struct prefix *current = head; current;) {
		head = current->next;
		i = 0;
		if (current->len < d)
			i = size - 1;
		else
			while (group[i] != 0 && firstBits(group[i]->ip, d) != firstBits(current->ip, d))
				i++;
		current->next = group[i];
		group[i] = current;
		current = head;
	}
	i = 0;
	while (group[i++] != 0)
		;
	group[i] = group[size - 1];
	group[size - 1] = 0;
}

void prefix_insert() {
}

void prefix_delete() {
}

void search() {
}

void print() {
	int size = (1 << d);
	for (int i = 0; i < size && group; i++) {
		for (struct prefix *deleteNode = group[i]; deleteNode; deleteNode = deleteNode->next)
			printf("%d ", firstBits(deleteNode->ip, d));
		puts("");
	}
}

void clear() {
	for (struct prefix *deleteNode = head; deleteNode; deleteNode = head) {
		head = head->next;
		free(deleteNode);
	}
	head = 0;
	int size = (1 << d);
	for (int i = 0; i < size && group; i++) {
		for (struct prefix *deleteNode = group[i]; deleteNode; deleteNode = group[i]) {
			group[i] = group[i]->next;
			free(deleteNode);
		}
	}
	free(group);
}

unsigned long long begin, end;

int main() {
	/* begin = rdtsc(); */
	input("routing_table.txt");
	/* end = rdtsc(); */
	/* printf("Execute cycles %llu \n", (end - begin)); */

	/* int i; */
	/* scanf("%d", &i); */
	/* length_distribution(i); */

	scanf("%d", &d);
	segment(d);

	/* print(); */
	clear();
	return 0;
}
