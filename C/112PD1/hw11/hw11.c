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
char *input_file, *insert_file, *delete_file, *search_file;

void input() {
	FILE *init = fopen(input_file, "r");
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
			printf("The total number of prefixes in the input file is : %d.\n", count);
			fclose(init);
			return;
		}
		if (current) {
			current->next = malloc(sizeof(struct prefix));
			count++;
			current = current->next;
			memcpy(&current->ip, temp, 4);
			current->len = temp[4];
			current->next = 0;
		} else {
			head = malloc(sizeof(struct prefix));
			current = head;
			count++;
			memcpy(&current->ip, temp, 4);
			current->len = temp[4];
			current->next = 0;
		}
	}
}

void length_distribution(int i) {
	int count = 0;
	for (struct prefix *current = head; current; current = current->next)
		if (current->len == i)
			count++;
	printf("The number of prefixes with prefix length %d = %d.\n", i, count);
}

void segment(int d) {
	int size = (1 << d);
	group = malloc(sizeof(struct prefix *) * size + 1);
	/* memset(group, 0, sizeof(struct prefix *) * size+1); */
	for (int i = 0; i < size; i++) {
		group[i] = malloc(sizeof(struct prefix));
		group[i]->ip = (i << (32 - d));
		group[i]->len = d;
		group[i]->next = 0;
	}
	group[size] = malloc(sizeof(struct prefix));
	group[size]->ip = 0;
	group[size]->len = 0;
	group[size]->next = 0;

	int i;
	for (struct prefix *current = head; current;) {
		head = current->next;
		i = 0;
		if (current->len < d)
			i = size;

		else
			while (firstBits(group[i]->ip, d) != firstBits(current->ip, d))
				i++;

		struct prefix *currentPrefix = group[i];
		while (currentPrefix->next && currentPrefix->next->ip < current->ip)
			currentPrefix = currentPrefix->next;
		current->next = currentPrefix->next;
		currentPrefix->next = current;
		current = head;
	}

	/* i = 0; */
	/* while (group[i++] != 0) */
	/* 	; */
	/* group[i] = group[size - 1]; */
	/* group[size - 1] = 0; */
}

void prefix_insert() {
}

void prefix_delete() {
}

void search() {
}

/* | 00001001 | ---> | 9.1.0.0 | */
void print() {
	int size = (1 << d);
	for (int i = 0; i < size; i++) {
		printf("| ");
		for (int j = 0; j < d; j++)
			printf("%d", group[i]->ip >> (31 - j) & 1);
		printf(" |");
		for (struct prefix *printNode = group[i]->next; printNode; printNode = printNode->next){
			printf(" ---> | %d.%d.%d.%d |", printNode->ip >> 24 & 255, printNode->ip >> 16 & 255, printNode->ip >> 8 & 255, printNode->ip & 255);
			/* unsigned char *bytes = (unsigned char *)printNode->ip; */
			/* printf(" ---> | %d.%d.%d.%d |", bytes[0], bytes[1], bytes[2], bytes[3]); */
		}
		puts("");
	}
	puts("--------special group--------");
	for (struct prefix *printNode = group[size]; printNode; printNode = printNode->next){
		printf("%d.%d.%d.%d\n", printNode->ip >> 24 & 255, printNode->ip >> 16 & 255, printNode->ip >> 8 & 255, printNode->ip & 255);
		/* unsigned char *bytes = (unsigned char *)printNode->ip; */
		/* printf("%d.%d.%d.%d\n", bytes[0], bytes[1], bytes[2], bytes[3]); */
	}
	puts("-----------------------------");
}

void clear() {
	for (struct prefix *deleteNode = head; deleteNode; deleteNode = head) {
		head = head->next;
		free(deleteNode);
	}
	head = 0;
	int size = (1 << d);
	for (int i = 0; i < size+1 && group; i++) {
		for (struct prefix *deleteNode = group[i]; deleteNode; deleteNode = group[i]) {
			group[i] = group[i]->next;
			free(deleteNode);
		}
	}
	free(group);
}

unsigned long long begin, end;

int main(int arvc, char **argv) {
	/* input_file = argv[1]; */
	/* insert_file = argv[2]; */
	/* delete_file = argv[3]; */
	/* search_file = argv[4]; */
	/* d = atoi(argv[5]); */
	input_file = "routing_table.txt";
	insert_file = "inserted_prefixes.txt";
	delete_file = "deleted_prefixes.txt";
	search_file = "trace_file.txt";
	d = 24;
	/* begin = rdtsc(); */
	input();
	/* end = rdtsc(); */
	/* printf("Execute cycles %llu \n", (end - begin)); */

	for (int i = 0; i <= 32; i++)
		length_distribution(i);

	segment(d);
	print();

	clear();
	return 0;
}
