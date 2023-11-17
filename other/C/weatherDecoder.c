#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getline() {
	char *line = 0, c;
	while ((c = getchar()) != '\n') {
		if (line == 0)
			line = malloc(sizeof(char) * 2);
		else
			line = realloc(line, sizeof(char) * (strlen(line) + 2));
		line[strlen(line)] = c;
		line[strlen(line) + 1] = '\0';
	}
	return line;
}

int main() {
	char *line = getline();
	char *ptr = line;
	while (1) {
		if (ptr[0] == '0') {
			printf("Fine ");
			if (ptr[1] == '\0')
				break;
			ptr++;
		} else if (ptr[1] == '0') {
			printf("Cloudy ");
			if (ptr[2] == '\0')
				break;
			ptr += 2;
		} else if (ptr[2] == '0') {
			printf("Rainy ");
			if (ptr[3] == '\0')
				break;
			ptr += 3;
		} else {
			printf("Snow ");
			if (ptr[3] == '\0')
				break;
			ptr += 3;
		}
	}
	free(line);
	return 0;
}
