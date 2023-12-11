#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define SWAP(a, b) (a == b ?: (a) ^= (b) ^= (a) ^= (b))

//initialize
const char matrix[8][8] = {'X', 'a', 'b', 'c', 'X', 'X', 'X', 'X',
						   'a', 'X', 'X', 'X', 'X', 'd', 'X', 'X',
						   'b', 'X', 'X', 'X', 'e', 'X', 'X', 'X',
						   'c', 'X', 'X', 'X', 'f', 'X', 'g', 'X',
						   'X', 'X', 'e', 'f', 'X', 'h', 'i', 'j',
						   'X', 'd', 'X', 'X', 'h', 'X', 'X', 'k',
						   'X', 'X', 'X', 'g', 'i', 'X', 'X', 'l',
						   'X', 'X', 'X', 'X', 'j', 'k', 'l', 'X'};
//                    a  b  c  d  e  f  g  h  i  j  k  l
const int length[] = {7, 3, 1, 7, 7, 6, 7, 6, 5, 2, 5, 4};

struct Edge {
		char name;
		int length;
		char vertex1;
		char vertex2;
};

struct Edge edges[] = {
  {.name = 'a', .length = 7, .vertex1 = 'A', .vertex2 = 'B'},
  {.name = 'b', .length = 3, .vertex1 = 'A', .vertex2 = 'C'},
  {.name = 'c', .length = 1, .vertex1 = 'A', .vertex2 = 'D'},
  {.name = 'd', .length = 7, .vertex1 = 'B', .vertex2 = 'F'},
  {.name = 'e', .length = 7, .vertex1 = 'C', .vertex2 = 'E'},
  {.name = 'f', .length = 6, .vertex1 = 'D', .vertex2 = 'E'},
  {.name = 'g', .length = 7, .vertex1 = 'D', .vertex2 = 'G'},
  {.name = 'h', .length = 6, .vertex1 = 'E', .vertex2 = 'F'},
  {.name = 'i', .length = 5, .vertex1 = 'E', .vertex2 = 'G'},
  {.name = 'j', .length = 2, .vertex1 = 'E', .vertex2 = 'H'},
  {.name = 'k', .length = 5, .vertex1 = 'F', .vertex2 = 'H'},
  {.name = 'l', .length = 4, .vertex1 = 'G', .vertex2 = 'H'}};

void swap(struct Edge *e1, struct Edge *e2) {
	struct Edge temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

void quickSort(struct Edge *edges, int left, int right, int *step) {
	if (left >= right)
		return;
	int pivot = right;
	int l = left - 1;
	int r = right;

	while (1) {
		while (edges[++l].length < edges[pivot].length)
			;
		while (edges[--r].length > edges[pivot].length)
			;
		if (l >= r)
			break;
		swap(&edges[l], &edges[r]);
	}
	swap(&edges[pivot], &edges[l]);
	printf("step %d:", (*step)++);
	for (int i = 0; i < 12; i++)
		printf("(%c, %d)", edges[i].name, edges[i].length);
	puts("");
	quickSort(edges, left, l - 1, step);
	quickSort(edges, r + 1, right, step);
}

int main() {

	//Q1
	puts("  A B C D E F G H");
	for (int i = 0; i < 8; i++) {
		printf("%c ", 'A' + i);
		for (int j = 0; j < 8; j++) {
			if (matrix[i][j] == 'X') {
				printf("X ");
				continue;
			}
			printf("%d ", length[matrix[i][j] - 'a']);
		}
		puts("");
	}
	puts("-------------------------");

	//Q2
	// char edges[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};
	int step = 0;
	printf("step %d:", step++);
	for (int i = 0; i < 12; i++)
		printf("(%c, %d)", edges[i].name, edges[i].length);
	puts("");
	quickSort(edges, 0, 11, &step);
	puts("-------------------------");

	//Q3
	char travered[8] = {0};
	for (int edgeCount = 0, index = 0; edgeCount < 7; index++) {
		printf("(%c, %d)", edges[index].name, edges[index].length);
		char vertex1 = edges[index].vertex1;
		char vertex2 = edges[index].vertex2;
		char *c;
		for (c = travered; *c != '\0'; c++)
			if (*c == vertex1)
				goto checkVertex2;
		*c = vertex1;
		goto nocycle;

	checkVertex2:
		for (c = travered; *c != '\0'; c++)
			if (*c == vertex2)
				goto cycle;
		*c = vertex2;
		goto nocycle;

	nocycle:
		edgeCount++;
		puts("");
		continue;
	cycle:
		puts(" is ignored");
	}
	return 0;
}
