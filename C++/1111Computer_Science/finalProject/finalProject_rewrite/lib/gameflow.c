#include <stdio.h>
#include <stdlib.h>

#include "gameflow.h"
#include "player.h"
#include "answer.h"

void game_init()
{
	printf("number length: ");
	scanf("%d", &length);
	CLEAN_BUFFER();
	answer = malloc(sizeof(char) * (length + 1));
	printf("player count: ");
	scanf("%d", &player_count);
	CLEAN_BUFFER();
	players = malloc(sizeof(struct Player *) * player_count);
	for (int i = 0; i < player_count; i++) {
		players[i] = malloc(sizeof(struct Player));
		player_init(players[i]);
	}
}

void game_turn()
{
	while (1) {
		for (int i = 0; i < player_count; i++) {
			printf("Player %d's turn\n", i);
			guess(players[i]);
			if (players[i]->A == length) {
				printf("Player %d win !!\n", i);
				return;
			}
			else {
				printf("%dA%dB\n", players[i]->A, players[i]->B);
			}
		}
	}
}

void game_exit()
{
	free(answer);
	for (int i = 0; i < player_count; i++) {
		player_delete(players[i]);
		free(players[i]);
	}
	free(players);
}
