#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char *s)
{
	char *stack = malloc(sizeof(char) * strlen(s));
	int size = 0;
	for (char *c = s; *c; c++) {
		switch (*c) {
		case ')':
			if (size-- == 0 || stack[size] != '(')
				return false;
			break;
		case ']':
			if (size-- == 0 || stack[size] != '[')
				return false;
			break;
		case '}':
			if (size-- == 0 || stack[size] != '{')
				return false;
			break;
		default:
			stack[size++] = *c;
		}
	}
	free(stack);
	if (size)
		return false;
	else
		return true;
}

int main()
{
	printf("%d\n", isValid("(){}[)"));
	return 0;
}
