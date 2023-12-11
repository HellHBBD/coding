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
		char vertex1;
		char vertex2;
		int length;
};

#define len(edge) (length[(edge) - 'a'])

void swap(struct Edge *e1, struct Edge *e2) {
	struct Edge temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

void quickSort(char *edges, int left, int right, int *step) {
	if (left >= right)
		return;
	int pivot = right;
	int l = left - 1;
	int r = right;

	while (1) {
		while (len(edges[++l]) < len(edges[pivot]))
			;
		while (len(edges[--r]) > len(edges[pivot]))
			;
		if (l >= r)
			break;
		SWAP(edges[l], edges[r]);
	}
	SWAP(edges[pivot], edges[l]);
	printf("step %d:", (*step)++);
	for (int i = 0; i < 12; i++)
		printf("(%c, %d)", edges[i], len(edges[i]));
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
			printf("%d ", len(matrix[i][j]));
		}
		puts("");
	}
	puts("-------------------------");

	//Q2
	char edges[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};
	int step = 0;
	printf("step %d:", step++);
	for (int i = 0; i < 12; i++)
		printf("(%c, %d)", edges[i], len(edges[i]));
	puts("");
	quickSort(edges, 0, 11, &step);
	puts("-------------------------");

	//Q3
	char travered[8] = {0};
	for (int edgeCount = 0, index = 0; edgeCount < 7; index++) {
		printf("(%c, %d)", edges[index], len(edges[index]));
		for (char *c = travered; *c != '\0'; c++)
			if (*c == edges[index])
				goto cycle;
		travered[edgeCount] = edges[index];
		edgeCount++;
		puts("");
		continue;
	cycle:
		puts(" is ignored");
	}
	return 0;
}
