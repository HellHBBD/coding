#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct prefix {
		unsigned ip;
		unsigned char len;
		struct prefix *next;
};

struct prefix *input(char *file) {
	FILE *init = fopen(file, "r");
	unsigned char temp[5];
	int count = 0;
	struct prefix *head = 0, *current = 0;
	while (1) {
		int scanCount = fscanf(init, "%hhu.%hhu.%hhu.%hhu/%hhu", temp, temp + 1, temp + 2, temp + 3, temp + 4);
		if (scanCount == 4) {
			temp[4] = (temp[0] ? 8 : 0) + (temp[1] ? 8 : 0) + (temp[2] ? 8 : 0) + (temp[3] ? 8 : 0);
		} else if (scanCount == 0) {
			printf("%d\n", count);
			fclose(init);
			return head;
		}
		if (current) {
			current->next = malloc(sizeof(struct prefix));
			count++;
			current = current->next;
			memcpy(&current->ip, temp, 4);
			current->len = temp[4];
		} else {
			head = malloc(sizeof(struct prefix));
			current = head;
			count++;
			memcpy(&current->ip, temp, 4);
			current->len = temp[4];
		}
	}
}

int main() {
	struct prefix *head = input("test.txt");
	return 0;
}
