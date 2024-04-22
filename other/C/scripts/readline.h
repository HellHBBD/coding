#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline()
{
	char *result = malloc(sizeof(char) * 1);
	result[0] = '\0';
	char c;
	while ((c = getchar()) != '\n') {
		int length = strlen(result);
		result = realloc(result, sizeof(char) * (length + 1));
		result[length] = c;
		result[length + 1] = '\0';
	}
	return result;
}
