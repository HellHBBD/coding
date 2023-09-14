#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix,int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			printf("%4d ",matrix[i][j]);
		}
		puts("");
	}
}

int calculate(int **matrix,int i,int j,int n){
	int result = 0;
	for (int x=0;x<n;x++){
		result += (matrix[i][x] * matrix[x][j]);
	}
	return result;
}

int main(){
	int n,**matrix1,**matrix2;
	printf("Please enter a number n to build a matrix1 A: ");
	scanf("%d",&n);
	matrix1 = malloc(sizeof(int*)*n); //construct
	for (int i=0;i<n;i++){
		matrix1[i] = malloc(sizeof(int)*n);
		for (int j=0;j<n;j++){
			matrix1[i][j] = i*n+j+1;
		}
	} //construct
	printMatrix(matrix1,n);

	puts("Matrix A multiplied by itself:");
	matrix2 = malloc(sizeof(int*)*n); //construct
	for (int i=0;i<n;i++){
		matrix2[i] = malloc(sizeof(int)*n);
		for (int j=0;j<n;j++){
			matrix2[i][j] = calculate(matrix1,i,j,n);
		}
	} //construct
	printMatrix(matrix2,n);

	for (int i=0;i<n;i++){ //free
		for (int j=0;j<n;j++){
			free(matrix1[i]);
			free(matrix2[i]);
		}
	} //free
	free(matrix1);
	free(matrix2);
	return 0;
}
