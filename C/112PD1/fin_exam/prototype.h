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

struct LinkedList *create(char *, int, int, int, int, int);
struct LinkedList *find(struct LinkedList *, char[20]);
int insert(struct LinkedList *, char *, struct LinkedList *);
int update_public(struct LinkedList *, char[20], int, int, int, int, int *);
int update_private(struct LinkedList *, char[20], int, int, int, int);
void update_public_target(int (*)[10][10][10][10], int, int, int, int, int);
int update_name(struct LinkedList *, char[20], char[20]);
int LowerToUpper(struct LinkedList *, char[20]);
void sort_name(char[40]);
