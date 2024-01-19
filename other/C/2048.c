#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 4
#define CLEAR() printf("\033[2J") //clear screen
#define SAVE() printf("\033[2s")  //save cursor position
#define SET(x, y) printf("\033[%d;%dH", x, y)

int score = 0;
int array[SIZE][SIZE] = {0};

char getCommand()
{
		char command = getchar();
		char c;
		while ((c = getchar()) != '\n')
				;
		return command;
}

void print()
{
		CLEAR();
		SET(0, 0);
		printf("Score: %d\n", score);
		puts("|-----|-----|-----|-----|");
		for (int i = 0; i < SIZE; i++) {
				printf("|");
				for (int j = 0; j < SIZE; j++)
						if (array[i][j] == 0)
								printf("     |");
						else
								printf("%5d|", array[i][j]);
				puts("");
				puts("|-----|-----|-----|-----|");
		}
		printf("command: ");
}

int main()
{
		CLEAR();
		while (1) {
				print();
				char command = getCommand();
				switch (command) {
				case 'w':
						break;
				case 'a':
						break;
				case 's':
						break;
				case 'd':
						break;
				case 'q':
						CLEAR();
						SET(0, 0);
						return 0;
				}
		}
}
