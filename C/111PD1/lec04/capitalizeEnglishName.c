#include <ctype.h>
#include <stdio.h>

int main()
{
	char charInput, charBuffer = ' ';
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		while (1) {
			charInput = getchar();
			if (charInput == ',' || charInput == ';' ||
			    charInput == '.') {
				printf("\n");
				charBuffer = ' ';
				break;
			}
			if (charBuffer == ' ')
				printf("%c", toupper(charInput));
			else
				printf("%c", tolower(charInput));
			charBuffer = charInput;
		}
	}
	return 0;
}
