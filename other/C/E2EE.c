#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { true = 1, false = 0 } bool;

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

char *encrypt(const char *msg, const char key, bool *black_list)
{
	int length = strlen(msg);
	char *result = malloc(sizeof(char) * (length + 1));
	for (int i = 0; i < length; i++) {
		char c = msg[i] ^ key;
		if (black_list[i])
			result[i] = msg[i];
		else
			result[i] = c;
	}
	result[length] = '\0';
	return result;
}

int main()
{
	printf("input message:");
	char *message = read_line();
	char Akey, Bkey;
	printf("A's key:");
	Akey = getchar();
	getchar();
	printf("B's key:");
	Bkey = getchar();
	bool black_list[strlen(message)];
	for (int i = 0; i < strlen(message); i++)
		if (message[i] ^ Akey || message[i] ^ Bkey)
			black_list[i] = false;
		else
			black_list[i] = true;
	message = encrypt(message, Akey, black_list);
	printf("A send to B, C get \"%s\"\n", message);
	message = encrypt(message, Bkey, black_list);
	printf("B send back to A, C get \"%s\"\n", message);
	message = encrypt(message, Akey, black_list);
	printf("A send to B again, C get \"%s\"\n", message);
	message = encrypt(message, Bkey, black_list);
	printf("after sending, B get \"%s\"\n", message);
	free(message);
	return 0;
}
