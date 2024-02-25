#include <stdio.h>
typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28

int main()
{
	char cmdChar;
	int count = 0;
	int Strength = INIT_STRENGTH;
	int Obedience = INIT_OBEDIENCE;
	while (1) {
		scanf("%c", &cmdChar);
		if (cmdChar == '\n')
			break;
		if (cmdChar == 'e') {
			Strength += STRENGTH_EAT;
			Obedience -= OBEDIENCE_EAT;
		} else if (cmdChar == 't') {
			Obedience += OBEDIENCE_TRAIN;
			Strength -= STRENGTH_TRAIN;
		}
		if (Obedience >= LEARN_OBEDIENCE && Strength <= LEARN_STRENGTH) {
			count += 1;
			Obedience = INIT_OBEDIENCE;
		}
	}
	if (count >= 5)
		printf("Yes");
	else
		printf("No");
	return 0;
}
