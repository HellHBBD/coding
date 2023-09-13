#include <stdio.h>

int main(){
	int N,T,B,A;
	scanf("%d",&N);
	int score[N];
	for (int i=0;i<N;i++){
		scanf("%d",&score[i]);
	}
	scanf("%d",&T);
	int interval[T][3];
	for (int i=0;i<T;i++){
		for (int j=0;j<3;j++)
			interval[i][j] = 0;
	}

	for (int i=0;i<T;i++){
		scanf("%d %d",&B,&A);
		for (int j=0;j<N;j++){
			if (score[j] < B)
				interval[i][0] ++;
			else if (score[j] < A)
				interval[i][1] ++;
			else
				interval[i][2] ++;
		}
	}
	for (int i=0;i<T;i++){
		for (int j=0;j<3;j++)
			printf("%d ",interval[i][j]);
		printf("\n");
	}
	return 0;
}
