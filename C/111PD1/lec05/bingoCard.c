#include <stdio.h>

void printArray(int array[8][8])
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("%3d ", array[i][j]);
		printf("\n");
	}
}

int main()
{
	int card[8][8], host, hCount, vCount, dCount1, dCount2, total;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			scanf("%d", &card[i][j]);

	for (int i = 0; i < 64; i++) {
		scanf("%d", &host);
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
				if (card[i][j] == host)
					card[i][j] = 0;
		}
	}

	dCount1 = 0;
	dCount2 = 0;
	for (int i = 0; i < 8; i++) {
		hCount = 0;
		vCount = 0;
		for (int j = 0; j < 8; j++) {
			if (hCount == 0)
				hCount += card[i][j];
			if (vCount == 0)
				vCount += card[j][i];
			if (dCount1 == 0 && i == j)
				dCount1 += card[i][j];
			if (dCount2 == 0 && i + j == 7)
				dCount2 += card[i][j];
		}
		if (hCount == 0)
			total++;
		if (vCount == 0)
			total++;
	}
	if (dCount1 == 0)
		total++;
	if (dCount2 == 0)
		total++;

	printf("%d", total);
	return 0;
}
