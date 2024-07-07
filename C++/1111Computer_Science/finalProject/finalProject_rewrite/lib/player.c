#include <stdlib.h>

#include <player.h>

void player_init(struct Player *player)
{
	player->string = malloc(sizeof(char) * (length + 1));
	player->A = 0;
	player->B = 0;
}

void player_delete(struct Player *player) {
	free(player->string);
	player->string = NULL;
	player->A = 0;
	player->B = 0;
}
