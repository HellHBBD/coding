#include <stdio.h>

void decoding() {
	int line;
	scanf("%d%*c", &line);
	for (int i = 0; i < line; i++) {
		char c;
		while ((c = getchar()) != '\n' && c != EOF) {
			int n;
			scanf("%d", &n);
			for (int j = 0; j < n; j++)
				putchar(c);
		}
		puts("");
	}
}

void encoding() {
	int line;
	scanf("%d%*c", &line);
	for (int i = 0; i < line; i++) {
		char current = getchar(), c;
		int count = 1;
		while (1) {
			c = getchar();
			if (c == '\n') {
				putchar(current);
				printf("%d", count);
				break;
			}
			if (c == current)
				count++;
			else {
				putchar(current);
				printf("%d", count);
				current = c;
				count = 1;
			}
		}
		puts("");
	}
}

int main() {
	int option;
	puts("(1)encoding (2)decoding");
	scanf("%d", &option);
	switch (option) {
		case 1:
			encoding();
			break;
		case 2:
			decoding();
			break;
	}
	return 0;
}
