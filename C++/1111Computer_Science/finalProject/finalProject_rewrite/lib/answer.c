#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <answer.h>

void reset()
{
	memset(answer, length + 1, sizeof(char));
}

void generate()
{
	unsigned exist = 0;
	for (int i = 0; i < length; i++) {
		int number = 0;
		do {
			number = rand() % 10;
		} while ((exist >> number) & 1);
		exist |= (1 << number);
		answer[i] = number + '0';
	}
}

void guess(struct Player *gs)
{
	printf("Guess number: ");
	fgets(gs->string, length + 1, stdin);
	CLEAN_BUFFER();
	gs->A = 0;
	gs->B = 0;
	char *string = gs->string;
	for (int i = 0; i < length; i++) {
		if (string[i] == answer[i]) {
			gs->A++;
		} else {
			for (int j = 0; j < length; j++) {
				if (string[i] == answer[j]) {
					gs->B++;
					break;
				}
			}
		}
	}
}
