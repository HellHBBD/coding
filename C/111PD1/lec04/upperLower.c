#include <stdio.h>

char upper(char c)
{
	return c - 32;
}

char lower(char c)
{
	return c + 32;
}

int main()
{
	printf("%c", upper('a'));
	return 0;
}
