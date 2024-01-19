#include <stdio.h>
#include <stdlib.h>
#define NUM 9

void addPoint(int ***list, int *countPtr, int i, int j)
{
		if (*list == 0) {
				*list = malloc(sizeof(int *));
				(*list)[0] = malloc(sizeof(int) * 2);
				(*list)[0][0] = i;
				(*list)[0][1] = j;
				(*countPtr)++;
		} else {
				int count = *countPtr;
				for (int index = 0; index < count; index++)
						if ((*list)[index][0] == i && (*list)[index][1] == j)
								return;
				*list = realloc(*list, sizeof(int *) * count);
				(*list)[count] = malloc(sizeof(int) * 2);
				(*list)[count][0] = i;
				(*list)[count][1] = j;
				(*countPtr)++;
		}
}

void reset(int list[9][2])
{
		for (int i = 0; i < 9; i++) {
				list[i][0] = -1;
				list[i][1] = -1;
		}
}

void check_sudoku(int (*grid_p)[NUM])
{
		int **unsatisfied = 0;
		int unsatisfiedCount = 0;
		for (int i = 0; i < NUM; i++) {
				int checkList[9][2] = {-1};
				for (int j = 0; j < NUM; j++) {
						int index1 = i;
						int index2 = j;
						int number = grid_p[index1][index2];
						if (checkList[number][0] == -1) {
								checkList[number][0] = index1;
								checkList[number][1] = index2;
						} else {
								addPoint(&unsatisfied, &unsatisfiedCount, index1, index2);
						}
				}
				reset(checkList);
				for (int j = 0; j < NUM; j++) {
						int index1 = j;
						int index2 = i;
						int number = grid_p[index1][index2];
						if (checkList[number][0] == -1) {
								checkList[number][0] = index1;
								checkList[number][1] = index2;
						} else {
								addPoint(&unsatisfied, &unsatisfiedCount, index1, index2);
						}
				}
				reset(checkList);
				for (int j = 0; j < NUM; j++) {
						int index1 = i / 3 * 3 + j / 3;
						int index2 = i % 3 * 3 + j % 3;
						int number = grid_p[index1][index2];
						if (checkList[number][0] == -1) {
								checkList[number][0] = index1;
								checkList[number][1] = index2;
						} else {
								addPoint(&unsatisfied, &unsatisfiedCount, index1, index2);
						}
				}
				reset(checkList);
		}

		for (int i = 0; i < unsatisfiedCount; i++) //print all unsatisfied point
				printf("(%d,%d)\n", unsatisfied[i][0], unsatisfied[i][1]);
}

int main(void)
{
		int grid[NUM][NUM]; // sudoku puzzle
		for (int i = 0; i < NUM; ++i)
				for (int j = 0; j < NUM; ++j)
						scanf("%d", &grid[i][j]);
		check_sudoku(grid);
		return 0;
}
