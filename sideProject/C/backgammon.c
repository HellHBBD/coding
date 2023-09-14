#include <stdio.h>
#include <stdlib.h>

enum status{
	blank,circle,cross
};

int main(){
	int gamemode;
	while (1){
		puts("choose the gamemode:(1) 1P vs 2P (2) 1P vs COM (3)exit:");
		scanf("%d",&gamemode);
		if (gamemode >= 1 || gamemode <= 3){
			break;
		}
		puts("wrong gamemode!");
	}
	int row,column;
	while (1){
		puts("input checkerboard size:");
		scanf("%dx%d",&row,&column);
		if (row <= 20 && row >= 3 && column <= 20 && column >= 3){
			break;
		}
		puts("wrong size!");
	}
	enum status **checkerboard = malloc(row*sizeof(enum status*));
	for (int i = 0;i < row;i++){
		checkerboard[i] = malloc(column*sizeof(enum status));
		for (int j = 0;j < column;j++)
			checkerboard[i][j] = blank;
	}
	for (int i = 0;i < row;i++){
		free(checkerboard[i]);
	}
	free(checkerboard);
	return 0;
}
