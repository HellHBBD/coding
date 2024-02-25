#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line()
{
	char *line = 0, c;
	int length = 0;
	while (1) {
		c = getchar();
		if (c == '\n') {
			line = realloc(line, sizeof(char) * (length + 1));
			line[length] = '\0';
			break;
		}
		line = realloc(line, sizeof(char) * (length + 1));
		line[length] = c;
		length++;
	}
	return line;
}

char *encrypt(const char *msg, const char key)
{
	int length = strlen(msg);
	char *result = malloc(sizeof(char) * (length + 1));
	for (int i = 0; i < length; i++) {
		char c = msg[i] ^ key;
		if (isprint(c))
			result[i] = c;
		else
			result[i] = msg[i];
	}
	result[length] = '\0';
	return result;
}

int main()
{
	printf("message:");
	char *message = read_line();
	//printf("key:");
	//char key = getchar();
	//char *result = encrypt(message,key);
	for (int i = 0; i < 128; i++) {
		char c = (char)i;
		char *result = encrypt(message, c);
		if (isprint(c))
			printf("%d \'%c\' %s\n", i, c, result);
		else
			printf("%d %s\n", i, result);
		free(result);
	}
	free(message);
	return 0;
}
