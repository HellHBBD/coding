#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
		int data;
		struct Node *next;
};

void swap(void *a, void *b, size_t size)
{
		void *temp = malloc(size);
		memcpy(temp, a, size);
		memcpy(a, b, size);
		memcpy(b, temp, size);
		free(temp);
}

int main()
{
		int a = 3, b = 5;
		printf("before swap: %d %d\n", a, b);
		swap(&a, &b, sizeof(int));
		printf("after swap: %d %d\n\n", a, b);
		double c = 3.14159, d = 2.71828;
		printf("before swap: %lf %lf\n", c, d);
		swap(&c, &d, sizeof(double));
		printf("after swap: %lf %lf\n\n", c, d);
		struct Node node1, node2;
		node1 = (struct Node){.data = 1, .next = &node2};
		node2 = (struct Node){.data = 7, .next = &node1};
		printf("before swap: %d %p\n", node1.data, node1.next);
		printf("before swap: %d %p\n", node2.data, node2.next);
		swap(&node1, &node2, sizeof(struct Node));
		printf("after swap: %d %p\n", node1.data, node1.next);
		printf("after swap: %d %p\n\n", node2.data, node2.next);
		return 0;
}
