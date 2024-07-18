#ifndef GAMEFLOW_H
#define GAMEFLOW_H

#include "answer.h"
#include "player.h"

extern int length;
extern char *answer;
extern int player_count;
extern struct Player **players;

void game_init();
void game_turn();
void game_exit();

#endif
