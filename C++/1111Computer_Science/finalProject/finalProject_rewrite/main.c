#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <gameflow.h>
#include <answer.h>
#include <player.h>
#include <timer.h>

int length = 0;
char *answer = NULL;
int player_count = 0;
struct Player **players = NULL;
time_t start = 0;

int main()
{
	game_init();
	generate();
	printf("%s\n", answer);
	game_turn();
	game_exit();
	return 0;
}
