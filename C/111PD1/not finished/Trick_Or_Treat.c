#include <stdio.h>
#include <stdlib.h>

int array[1500];

int maxChandy(int size) {
	if (size == 1)
		return array[0];
	else if (size == 2)
		return array[1];
	else if (size == 3)
		return array[0] + array[2];
	int max = 0;
	for (int i = 2; i < size; i++) {
		int total = array[size - 1] + maxChandy(size - i);
		max = (total > max) ? total : max;
	}
	return max;
}

int main() {
	int size = 0;
	scanf("%d", &size);
	for (int i = 0; i < size; ++i)
		scanf("%d", &array[i]);
	printf("%d\n", maxChandy(size));
	return 0;
}
