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
unsigned long long begin, end;

void input()
{
	FILE *init = fopen(input_file, "r");
	unsigned char temp[5];
	int count = 0;
	struct prefix *current = 0;
	while (1) {
		memset(temp, 0, 5);
		int scanCount = fscanf(init, "%hhu.%hhu.%hhu.%hhu/%hhu", temp + 3, temp + 2,
				       temp + 1, temp, temp + 4);
		if (scanCount == 4) {
			temp[4] = temp[3] ? 32 : temp[2] ? 24 : temp[1] ? 16 : temp[0] ? 8 : 0;
		} else if (scanCount == -1) {
			/* printf("The total number of prefixes in the input file is : %d.\n", count); */
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

void length_distribution(int i)
{
	int count = 0;
	for (struct prefix *current = head; current; current = current->next)
		if (current->len == i)
			count++;
	printf("The number of prefixes with prefix length %d = %d.\n", i, count);
}

void segment(int d)
{
	int size = (1 << d);
	group = malloc(sizeof(struct prefix *) * size + 1);
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
}

void prefix_insert()
{
	FILE *insert = fopen(insert_file, "r");
	unsigned char temp[5];
	int count = 0;
	int size = (1 << d);
	while (1) {
		memset(temp, 0, 5);
		begin = rdtsc();
		int scanCount = fscanf(insert, "%hhu.%hhu.%hhu.%hhu/%hhu", temp + 3, temp + 2,
				       temp + 1, temp, temp + 4);
		if (scanCount == 4) {
			temp[4] = temp[3] ? 32 : temp[2] ? 24 : temp[1] ? 16 : temp[0] ? 8 : 0;
		} else if (scanCount == -1) {
			fclose(insert);
			return;
		}
		struct prefix *current = malloc(sizeof(struct prefix));
		memcpy(&current->ip, temp, 4);
		current->len = temp[4];
		current->next = 0;

		int i = 0;
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

		end = rdtsc();
		/* printf("%llu\n", (end - begin)); */
	}
}

void prefix_delete()
{
	FILE *delete = fopen(delete_file, "r");
	unsigned char temp[5];
	int count = 0;
	int size = (1 << d);
	while (1) {
		count++;
		memset(temp, 0, 5);
		begin = rdtsc();
		int scanCount = fscanf(delete, "%hhu.%hhu.%hhu.%hhu/%hhu", temp + 3, temp + 2,
				       temp + 1, temp, temp + 4);
		if (scanCount == 4) {
			temp[4] = temp[3] ? 32 : temp[2] ? 24 : temp[1] ? 16 : temp[0] ? 8 : 0;
		} else if (scanCount == -1) {
			fclose(delete);
			return;
		}
		if (count == 146)
			count = 513;
		unsigned ip;
		memcpy(&ip, temp, 4);
		unsigned char len = temp[4];
		int i = 0;
		if (len < d)
			i = size;
		else
			while (firstBits(group[i]->ip, d) != firstBits(ip, d))
				i++;

		struct prefix *previous;
		struct prefix *current = group[i]->next;
		while (current && current->ip != ip) {
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		free(current);
		current = 0;

		end = rdtsc();
		/* printf("%llu\n", (end - begin)); */
	}
}

void search()
{
	FILE *search = fopen(search_file, "r");
	unsigned char temp[5];
	int size = (1 << d);
	while (1) {
		memset(temp, 0, 5);
		begin = rdtsc();
		int scanCount = fscanf(search, "%hhu.%hhu.%hhu.%hhu/%hhu", temp + 3, temp + 2,
				       temp + 1, temp, temp + 4);
		if (scanCount == 4) {
			temp[4] = temp[3] ? 32 : temp[2] ? 24 : temp[1] ? 16 : temp[0] ? 8 : 0;
		} else if (scanCount == -1) {
			fclose(search);
			return;
		}
		unsigned ip;
		memcpy(&ip, temp, 4);
		unsigned char len = temp[4];
		int i = 0;
		if (len < d)
			i = size;
		else
			while (firstBits(group[i]->ip, d) != firstBits(ip, d))
				i++;

		struct prefix *current = group[i]->next;
		while (current && current->ip != ip)
			current = current->next;
		/* if (current) */
		/* 	puts("successful"); */
		/* else */
		/* 	puts("failed"); */

		end = rdtsc();
		printf("%llu\n", (end - begin));
	}
}

/* void print() { */
/* 	int size = (1 << d); */
/* 	for (int i = 0; i < size; i++) { */
/* 		printf("| "); */
/* 		for (int j = 0; j < d; j++) */
/* 			printf("%d", group[i]->ip >> (31 - j) & 1); */
/* 		printf(" |"); */
/* 		for (struct prefix *printNode = group[i]->next; printNode; printNode = printNode->next){ */
/* 			printf(" ---> | %d.%d.%d.%d |", printNode->ip >> 24 & 255, printNode->ip >> 16 & 255, printNode->ip >> 8 & 255, printNode->ip & 255); */
/* 			#<{(| unsigned char *bytes = (unsigned char *)printNode->ip; |)}># */
/* 			#<{(| printf(" ---> | %d.%d.%d.%d |", bytes[0], bytes[1], bytes[2], bytes[3]); |)}># */
/* 		} */
/* 		puts(""); */
/* 	} */
/* 	puts("--------special group--------"); */
/* 	for (struct prefix *printNode = group[size]->next; printNode; printNode = printNode->next){ */
/* 		printf("%d.%d.%d.%d\n", printNode->ip >> 24 & 255, printNode->ip >> 16 & 255, printNode->ip >> 8 & 255, printNode->ip & 255); */
/* 		#<{(| unsigned char *bytes = (unsigned char *)printNode->ip; |)}># */
/* 		#<{(| printf("%d.%d.%d.%d\n", bytes[0], bytes[1], bytes[2], bytes[3]); |)}># */
/* 	} */
/* 	puts("-----------------------------"); */
/* } */

void print()
{
	int size = (1 << d);
	for (int i = 0; i < size; i++) {
		int count = 0;
		for (struct prefix *printNode = group[i]->next; printNode;
		     printNode = printNode->next)
			count++;
		printf("The number of prefixes in group %d = %d\n", i, count);
	}
}

void clear()
{
	for (struct prefix *deleteNode = head; deleteNode; deleteNode = head) {
		head = head->next;
		free(deleteNode);
	}
	head = 0;
	int size = (1 << d);
	for (int i = 0; i < size + 1 && group; i++) {
		for (struct prefix *deleteNode = group[i]; deleteNode; deleteNode = group[i]) {
			/* printf("%d.%d.%d.%d/%d\n", deleteNode->ip >> 24 & 255, deleteNode->ip >> 16 & 255, deleteNode->ip >> 8 & 255, deleteNode->ip & 255, deleteNode->len); */
			group[i] = group[i]->next;
			free(deleteNode);
		}
	}
	free(group);
}

int main(int arvc, char **argv)
{
	/* input_file = argv[1]; */
	/* insert_file = argv[2]; */
	/* delete_file = argv[3]; */
	/* search_file = argv[4]; */
	/* d = atoi(argv[5]); */
	input_file = "data/routing_table.txt";
	insert_file = "data/inserted_prefixes.txt";
	delete_file = "data/deleted_prefixes.txt";
	search_file = "data/trace_file.txt";
	d = 8;

	input();

	/* for (int i = 0; i <= 32; i++) */
	/* 	length_distribution(i); */

	segment(d);
	/* print(); */

	prefix_insert();
	/* print(); */
	/* prefix_delete(); */
	search();

	clear();
	return 0;
}
