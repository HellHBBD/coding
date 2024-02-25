#include <stdio.h>

int main()
{
	char c;
	while ((c = getchar()) != '\n')
		putchar(c - 7);
	return 0;
}
