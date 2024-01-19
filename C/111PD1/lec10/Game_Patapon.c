#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line()
{
		char c, *result = 0;
		int charCount = 0;
		while (1) {
				c = getchar();
				if (c == '\n') {
						result = realloc(result, charCount + 1);
						result[charCount] = '\0';
						return result;
				}
				charCount++;
				result = realloc(result, charCount);
				result[charCount - 1] = c;
		}
}

int main()
{
		int distance, health;
		scanf("%d %d\n", &distance, &health);
		char *input = read_line();
		char *command;
		char *forward = "PATA PATA PATA PON";
		char *attack = "PON PON PATA PON";
		char *backward = "CHAKA CHAKA PATA PON";
		int legalCommand = 0, monsterAttack = 0;
		command = strtok(input, ",.");
		while (1) {
				if (command == NULL) {
						printf("NO %d", health);
						break;
				} else if (strcmp(command, forward) == 0) {
						legalCommand++;
						distance--;
						if (distance == 0) {
								printf("NO %d", health);
								break;
						}
				} else if (strcmp(command, attack) == 0) {
						legalCommand++;
						if (distance <= 3) {
								health--;
								if (health == 0) {
										printf("YES %d", legalCommand);
										break;
								}
						}
				} else if (strcmp(command, backward) == 0) {
						legalCommand++;
						distance++;
				}
				monsterAttack++;
				if (monsterAttack == 10) {
						if (strcmp(command, backward) != 0) {
								printf("NO %d", health);
								break;
						}
				}
				command = strtok(NULL, ",.");
		}
		free(input);
		return 0;
}
