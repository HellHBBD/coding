#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//initialize
const char matrix[8][8] = {
  'X', 'a', 'b', 'c', 'X', 'X', 'X', 'X',
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

struct Node {
		char vertex;
		Node *next;
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
		while (l < r && edges[++l].length <= edges[pivot].length)
			;
		while (r > l && edges[--r].length >= edges[pivot].length)
			;
		if (l >= r)
			break;
		swap(edges + l, edges + r);
	}
	swap(edges + pivot, edges + l);
	printf("step %d:", (*step)++);
	for (int i = 0; i < 12; i++)
		printf("(%c, %d)", edges[i].name, edges[i].length);
	puts("");
	quickSort(edges, left, l - 1, step);
	quickSort(edges, r + 1, right, step);
}

void findVertex(Node *traversed[4], char vertex, int *index, Node **tail) {
	for (int i = 0; i < 4; i++) {
		for (Node *currentNode = traversed[i]; currentNode; currentNode = currentNode->next) {
			if (currentNode->vertex == vertex) {
				*index = i;
				*tail = currentNode;
				while (*tail)
					if ((*tail)->next)
						*tail = (*tail)->next;
					else
						return;
			}
		}
	}
}

void print(Node *list[4]) {
	for (int i = 0; i < 4; i++) {
		for (Node *node = list[i]; node; node = node->next)
			printf("%c ", node->vertex);
		puts("0");
	}
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
	int step = 0;
	printf("step %d:", step++);
	for (int i = 0; i < 12; i++)
		printf("(%c, %d)", edges[i].name, edges[i].length);
	puts("");
	quickSort(edges, 0, 11, &step);
	puts("-------------------------");

	//Q3
	Node *traversed[4] = {0};
	int index1 = -1, index2 = -1;
	for (int edgeCount = 0, index = 0; edgeCount < 7; index++) {
		Node *tail1 = 0, *tail2 = 0;
		printf("(%c, %d)", edges[index].name, edges[index].length);
		char vertex1 = edges[index].vertex1;
		char vertex2 = edges[index].vertex2;
		if (tail1 == 0)
			findVertex(traversed, vertex1, &index1, &tail1);
		if (tail2 == 0)
			findVertex(traversed, vertex2, &index2, &tail2);
		if (tail1) {
			if (index1 == index2) {
				puts("is ignore");
				// print(traversed);
				continue;
			}

			else if (tail2) {
				tail1->next = traversed[index2];
				traversed[index2] = 0;
			} else {
				Node *new_node = new Node;
				tail1->next = new_node;
				new_node->vertex = vertex2;
				new_node->next = 0;
			}
		} else {
			if (tail2) {
				Node *new_node = new Node;
				tail2->next = new_node;
				new_node->vertex = vertex1;
				new_node->next = 0;
			} else {
				for (int i = 0; i < 4; i++) {
					if (traversed[i] == 0) {
						traversed[i] = new Node;
						traversed[i]->vertex = vertex1;
						traversed[i]->next = new Node;
						traversed[i]->next->vertex = vertex2;
						traversed[i]->next->next = 0;
						break;
					}
				}
			}
		}
		puts("");
		edgeCount++;
		// print(traversed);
	}

	return 0;
}
