#include <stdio.h>
typedef bool _Bool;

void printx(int n)
{
	for (int i = 0; i < n; i++)
		printf("x");
}

int main()
{
	char c;
	bool isNumber = true;
	int digit = 0;
	while (1) { //user input loop
		printf("(type '\\' to escape)\n");
		while (1) { //string loop
			c = getchar();
			if (c == '\\')
				break;
			if ((c >= 'a' && c <= 'z') ||
			    (c >= 'A' && c <= 'Z')) { //character
				printf("%c", c);
				isNumber = false;
				digit = 0;
			} else if (c >= '0' && c <= '9') { //number
				if (isNumber == true)
					digit++;
				else
					printf("%c", c);
			} else { //else
				if (digit == 0) {
					printf("%c", c);
					isNumber = true;
				} else {
					printx(digit);
					printf("%c", c);
					isNumber = true;
					digit = 0;
				}
				if (c == '\n')
					break;
			}
		}
		if (c == '\\')
			break;
	}
	return 0;
}
