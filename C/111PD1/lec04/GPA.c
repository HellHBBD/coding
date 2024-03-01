#include <stdio.h>

int gradeExchange(char letter)
{
	if (letter == 'A')
		return 4;
	if (letter == 'B')
		return 3;
	if (letter == 'C')
		return 2;
	if (letter == 'F')
		return 0;
}

int main()
{
	char input;
	int credit = 0, totalCredit = 0;
	float GPA = 0.0, grade = 0.0;
	while (1) {
		input = getchar();
		if (input == '\n') {
			GPA += (credit * grade);
			break;
		}
		if (input >= '0' && input <= '9') {
			GPA += (credit * grade);
			credit = input - '0';
			totalCredit += credit;
		}
		if (input >= 'A' && input <= 'F')
			grade = gradeExchange(input);
		if (input == '+')
			grade += 0.3;
		if (input == '-')
			grade -= 0.3;
	}
	GPA /= (float)totalCredit;
	printf("%.2f", GPA);
	return 0;
}
