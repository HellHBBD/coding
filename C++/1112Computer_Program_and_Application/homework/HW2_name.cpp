#include <stdio.h>

void clearString(char string[])
{
	char *p = string;
	for (int i = 0; i < 20; i++) {
		*p = '\0';
		p++;
	}
}

int main()
{
	char firstName[20], middleName = '\0', lastName[20];
	clearString(firstName);
	clearString(lastName);
	char *firstPointer = firstName, *lastPointer = lastName;
	char c;
	while (1) {
		c = getchar();
		if (c == ' ')
			break;
		*firstPointer = c;
		firstPointer++;
	}
	while (1) {
		c = getchar();
		if (c == ' ') {
			lastPointer = lastName;
			middleName = *lastPointer;
			clearString(lastName);
			continue;
		}
		if (c == '\n')
			break;
		*lastPointer = c;
		lastPointer++;
	}
	if (middleName == '\0')
		printf("%s, %s", lastName, firstName);
	else
		printf("%s, %s %c.", lastName, firstName, middleName);
	return 0;
}
