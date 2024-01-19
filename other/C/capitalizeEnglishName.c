#include <stdio.h>
#define toupper(c) ((c) - 'a' + 'A')
#define tolower(c) ((c) - 'A' + 'a')

int main()
{
		char charInput, charBuffer = ' ';
		int n;
		scanf("%d\n", &n);
		while (1) {
				charInput = getchar();
				if (charInput == '\n')
						break;
				if (charInput == ',' || charInput == ';' || charInput == '.') {
						printf("\n");
						charBuffer = ' ';
						continue;
				}
				if (charBuffer == ' ')
						printf("%c", toupper(charInput));
				else
						printf("%c", tolower(charInput));
				charBuffer = charInput;
		}
		return 0;
}
