#include "hw8-1.h"
#include <stdlib.h>

void init(int ***mp)
{
	for (int i = 65; i <= 95; i++) {
		mp[i] = malloc(95 * sizeof(int *));
		for (int j = 65; j <= 95; j++) {
			mp[i][j] = malloc(95 * sizeof(int));
			for (int k = 65; k <= 95; k++)
				mp[i][j][k] = 1;
		}
	}
}

void modify(int *a, int val)
{
	*a = val;
}

int query(int ****mp, char a[4], char b[4])
{
	int check = (*mp)[a[0]][a[1]][a[2]] + (*mp)[b[0]][b[1]][b[2]];
	return (check % 2 == 0) ? 0 : 1;
}
