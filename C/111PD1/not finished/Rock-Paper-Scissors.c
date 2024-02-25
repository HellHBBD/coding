#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void eliminate_int(int *list, const int index, const int max)
{
	for (int i = index; i < max - 1; i++)
		list[i] = list[i + 1];
}

void eliminate_char(char *list, const int index, const int max)
{
	for (int i = index; i < max - 1; i++)
		list[i] = list[i + 1];
}

void compete(const char *shape, int *player, const int player1, const int player2, char *judge,
	     const int N, const int lN)
{
	char shape1 = shape[player1 - 1];
	char shape2 = shape[player2 - 1];
	switch (shape1) {
	case 'r':
		switch (shape2) {
		case 'r':
			if (judge[0] == 'b') {
				eliminate_int(player, player1, N);
				eliminate_char(judge, 0, lN);
			}
			if (judge[0] == 's') {
				eliminate_int(player, player2, N);
				eliminate_char(judge, 0, lN);
			}
			break;
		case 'p':
			eliminate_int(player, player1, N);
			break;
		case 's':
			eliminate_int(player, player2, N);
			break;
		}
		break;
	case 'p':
		switch (shape2) {
		case 'r':
			eliminate_int(player, player2, N);
			break;
		case 'p':
			if (judge[0] == 'b') {
				eliminate_int(player, player1, N);
				eliminate_char(judge, 0, lN);
			}
			if (judge[0] == 's') {
				eliminate_int(player, player2, N);
				eliminate_char(judge, 0, lN);
			}
			break;
		case 's':
			eliminate_int(player, player1, N);
			break;
		}
		break;
	case 's':
		switch (shape2) {
		case 'r':
			eliminate_int(player, player1, N);
			break;
		case 'p':
			eliminate_int(player, player2, N);
			break;
		case 's':
			if (judge[0] == 'b') {
				eliminate_int(player, player1, N);
				eliminate_char(judge, 0, lN);
			}
			if (judge[0] == 's') {
				eliminate_int(player, player2, N);
				eliminate_char(judge, 0, lN);
			}
			break;
		}
		break;
	}
}

int game(const char *shape, int *player, char *judge, const int N, const int lN)
{
	int player1 = player[0];
	int player2 = player[1];
	if (player2 < 1 || player2 > N)
		return player1;
	while (1) {
	}
}

void print(const char *shape, const char *judge, const int N, const int lN)
{
	puts("shape:");
	for (int i = 0; i < N; i++)
		printf("%d:%c\n", i + 1, shape[i]);
	puts("judge:");
	for (int i = 0; i < lN; i++)
		printf("%d:%c\n", i + 1, judge[i]);
}

int main()
{
	int N, lN;
	scanf("%d\n", &N);
	char *shape = malloc(sizeof(char) * N + 1);
	int *player = malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		player[i] = i + 1;
	gets(shape);
	frexp(N / 2, &lN);
	char *judge = malloc(sizeof(char) * lN + 1);
	gets(judge);
	print(shape, judge, N, lN);

	free(shape);
	free(judge);
	free(player);
	return 0;
}
