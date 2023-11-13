#include <stdio.h>

int main() {
	int student, group;
	scanf("%d %d", &student, &group);
	printf("%d %d", student / group, student % group);
	return 0;
}
