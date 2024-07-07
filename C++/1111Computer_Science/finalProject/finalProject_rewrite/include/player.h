#ifndef PLAYER_H
#define PLAYER_H

#define CLEAN_BUFFER()                          \
	{                                       \
		char c;                         \
		while ((c = getchar()) != '\n') \
			;                       \
	}

extern int length;
extern int player_count;
extern struct Player **players;

struct Player {
	char *string;
	int A;
	int B;
};

void player_init(struct Player *);
void player_delete(struct Player *);

#endif
