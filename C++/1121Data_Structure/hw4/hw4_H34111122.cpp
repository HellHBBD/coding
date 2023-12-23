#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#define SWAP(a, b) ((a) ^= (b) ^= (a) ^= (b))

class Edge {
	public:
		char name;
		char endNode;
		int length;
		Edge *next;

		Edge(char endNode, int length, char name) {
			this->endNode = endNode;
			this->length = length;
			this->name = name;
			next = 0;
		}
};

class PriorityQueue {
	public:
		PriorityQueue();
		~PriorityQueue();
		void push(char);
		char pop();

		int length;
		char *array;
};

Edge *list[8] = {0};

int d[8];

void read_file() {
	FILE *file = fopen("Graph.txt", "r");
	char start, end, name;
	int length;
	while (fscanf(file, "%*d, %*d, '%c', '%c', %d, '%c'", &start, &end, &length, &name) != EOF) {
		Edge *current = list[start - 'A'];
		if (current) {
			for (; current->next && current->next->endNode < end; current = current->next)
				;
			current->next = new Edge(end, length, name);
		} else {
			list[start - 'A'] = new Edge(end, length, name);
		}
	}
	fclose(file);
}

int cmp(const char a, const char b) {
	int d1 = d[a - 'A'];
	int d2 = d[b - 'A'];
	if (d1 == -1 && d2 == -1)
		return 0;
	else if (d1 == -1)
		return 1;
	else if (d2 == -1)
		return -1;
	else
		return d[a - 'A'] - d[b - 'A'];
}

void Dijkstra() {
	PriorityQueue priority_queue;
	for (int i = 0; i < 8; i++)
		priority_queue.push('A' + i);
	char source;
	printf("starting node: ");
	scanf("%c",&source);
	d[source - 'A'] = 0;
	while (priority_queue.length) {
		char node = priority_queue.pop();
		for (Edge *edge = list[node - 'A']; edge; edge = edge->next)
			if (d[edge->endNode - 'A'] == -1 || d[edge->endNode - 'A'] > d[node - 'A'] + edge->length)
				d[edge->endNode - 'A'] = d[node - 'A'] + edge->length;
		printf("%c|", node);
		// printf("%c|", source);
		for (int i = 0; i < 8; i++)
			if (d[i] == -1)
				printf("  X");
			else
				printf(" %2d", d[i]);
		puts("");
	}
}

void free_list() {
	for (int i = 0; i < 8; i++) {
		for (Edge *deleteEdge = list[i]; deleteEdge; deleteEdge = list[i]) {
			list[i] = list[i]->next;
			delete deleteEdge;
		}
	}
}

int main() {
	read_file();
	//Q1
	for (int i = 0; i < 8; i++) {
		printf("%c:", 'A' + i);
		for (Edge *current = list[i]; current; current = current->next)
			printf(" %c(%d)", current->endNode, current->length);
		puts("");
	}
	//Q2
	for (int i = 0; i < 8; i++)
		d[i] = -1;
	Dijkstra();
	free_list();
	return 0;
}

PriorityQueue::PriorityQueue() {
	length = 0;
	array = 0;
}

PriorityQueue::~PriorityQueue() {
	if (array)
		free(array);
	length = 0;
	array = 0;
}

void PriorityQueue::push(char element) {
	array = (char *)realloc(array, sizeof(char) * (length + 1));
	array[length] = element;
	length++;
}

char PriorityQueue::pop() {
	for (int i = 1; i < length; i++)
		if (cmp(array[i - 1], array[i]) <= 0)
			SWAP(array[i - 1], array[i]);
	length--;
	char min = array[length];
	array = (char *)realloc(array, sizeof(char) * length);
	return min;
}
