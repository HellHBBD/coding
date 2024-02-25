#include <stdio.h>
#include <string.h>

#define SIZE 25

int length(char pwd1[], char pwd2[])
{
	if (strlen(pwd1) < 6 || strlen(pwd1) > 16)
		return 1;
	if (strlen(pwd2) < 6 || strlen(pwd2) > 16)
		return 1;
	else
		return 0;
}

int compare(char pwd1[], char pwd2[])
{
	if (strcmp(pwd1, pwd2) == 0)
		return 0;
	else
		return 1;
}

int content(char pwd1[])
{
	typedef enum { true = 1, false = 0 } bool;

	bool hasUpper = false, hasLower = false, hasDigit = false;
	for (int i = 0; i < strlen(pwd1); i++) {
		int ascii = (int)pwd1[i];
		if (ascii >= (int)'A' && ascii <= (int)'Z')
			hasUpper = true;
		if (ascii >= (int)'a' && ascii <= (int)'z')
			hasLower = true;
		if (ascii >= (int)'0' && ascii <= (int)'9')
			hasDigit = true;
		if (hasUpper && hasLower && hasDigit)
			return 0;
	}
	if (hasUpper && hasLower && hasDigit)
		return 0;
	else
		return 1;
}

int main()
{
	char password1[SIZE];
	char password2[SIZE];

	// Enter the password
	scanf("%s", password1);
	// Enter the password again
	scanf("%s", password2);

	// Check Password
	// First: Check length
	if (length(password1, password2) == 1) {
		printf("Length does not match the requirements");
	} else {
		// Second: Check for consistency
		if (compare(password1, password2) == 1) {
			printf("Not the same password");
		} else {
			// Third: Check for compliance
			if (content(password1) == 1)
				printf("Do not satisfy the conditions");

			else
				printf("Everything is good");
		}
	}

	return 0;
}
