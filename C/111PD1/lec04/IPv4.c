#include <stdio.h>

int main() {
	int num;
	scanf("%2x", &num);
	printf("%d", num);
	for (int i = 0; i < 3; i++) {
		scanf("%2x", &num);
		printf(".%d", num);
	}
	return 0;
}
