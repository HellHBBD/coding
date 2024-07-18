#ifndef ANSWER_H
#define ANSWER_H

#include "player.h"

extern int length;
extern char *answer;

void reset();
void generate();
void guess(struct Player *);

#endif
