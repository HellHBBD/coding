#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void findIndex(char letter, int *a, int *b) {
	const char *table[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	*a = *b = -1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (letter == table[i][j]) {
				*b = j + 1;
				break;
			}
		}
		if (*b != -1) {
			*a = i + 2;
			break;
		}
	}
}

void convert(char *arr[], int count) {
	for (int i = 0; i < count; i++) {
		char result[900] = {0};
		//int length = 0;
		for (int j = 0; j < strlen(arr[i]); j++) {
			if (arr[i][j] == '\n')
				strcat(result, "\n");
			else if (arr[i][j] == ' ')
				strcat(result, " ");
			else {
				char letter[5];
				int a, b;
				findIndex(arr[i][j], &a, &b);
				sprintf(letter, "(%d)%d", a, b);
				strcat(result, letter);
			}
		}
		for (int j = 0; j < strlen(result); j++)
			arr[i][j] = result[j];
	}
}

int main() {
	char line[BUFFER_LEN];
	char buffer[LINE_LEN][BUFFER_LEN];
	char *arr[LINE_LEN];

	int count = 0;
	while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
		arr[count] = buffer[count];
		strncpy(buffer[count++], line, BUFFER_LEN - 1);
	}
	convert(arr, count);
	for (int i = 0; i < count; i++)
		printf("%s", arr[i]);
}
