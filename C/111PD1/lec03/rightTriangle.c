#include <stdio.h>

int main()
{
	int i, j;
	scanf("%d %d", &i, &j);
	switch (i) {
	case 1: {
		for (int k = 1; k <= j; k++) {
			for (int l = 0; l <= j - k; l++)
				printf("*");
			printf("\n");
		}
		break;
	}
	case 2: {
		for (int k = 1; k <= j; k++) {
			for (int l = 1; l <= k; l++)
				printf("*");
			printf("\n");
		}
		break;
	}
	case 3: {
		for (int k = 1; k <= j; k++) {
			for (int l = 1; l < k; l++)
				printf(" ");
			for (int l = 0; l <= j - k; l++)
				printf("*");
			printf("\n");
		}
		break;
	}
	case 4: {
		for (int k = 1; k <= j; k++) {
			for (int l = 1; l <= j - k; l++)
				printf(" ");
			for (int l = 1; l <= k; l++)
				printf("*");
			printf("\n");
		}
		break;
	}
	}
}
