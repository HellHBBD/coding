#include <stdio.h>
#include <stdlib.h>

int isSafe(int x,int y,int height,int width,int **matrix,int **visited){
	/* Your own expression */
}

void DFS(int **matrix,int x,int y,int height,int width,int **visited,int *count){
	/* Your own expression */
}

int findLargestConnectedZone(int height,int width,int **matrix){
	/* Your own expression */
}

int main() {
	int height,width;
	printf("Enter the height and width of the matrix: ");
	scanf("%d %d",&height,&width);

	// Allocate memory for the matrix
	int **matrix = (int**)malloc(height*sizeof(int*));
	for (int i = 0;i < height;++i){
		matrix[i] = (int*)malloc(width*sizeof(int));
	}

	printf("Enter the matrix values:\n");
	for (int i = 0;i < height;++i){
		for (int j = 0;j < width;++j){
			scanf("%d",&matrix[i][j]);
		}
	}

	int largestZone = findLargestConnectedZone(height,width,matrix);

	printf("%d\n",largestZone);

	// Free the allocated memory
	for (int i = 0;i < height;++i){
		free(matrix[i]);
	}
	free(matrix);

	return 0;
}

