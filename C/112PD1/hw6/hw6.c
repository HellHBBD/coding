#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void Homework6_1(){
	int N;
	scanf("%d",&N);
	int array[N];
	for (int i = 0;i < N;i++)
		scanf("%d",&array[i]);
	printf("%d",array[N-1]);
	for (int i = N-2;i >= 0;i--)
		printf(" %d",array[i]);
}

void Homework6_2(){
	int N;
	scanf("%d",&N);
	int array[N-1];
	for (int i = 0;i < N;i++)
		scanf("%d",&array[i]);
	bool exist[N];
	for (int i = 0;i < N-1;i++)
		exist[array[i]-1] = true;
	for (int i = 0;i < N;i++){
		if (!exist[i]){
			printf("%d",i+1);
			break;
		}
	}
}

void Homework6_3(){
	int N;
	scanf("%d",&N);
	int array[N];
	long brray[N];
	scanf("%d",&array[0]);
	brray[0] = array[0];
	for (int i = 1;i < N;i++){
		scanf("%d",&array[i]);
		brray[i] = brray[i-1] + array[i];
	}
	int queryTime;
	scanf("%d",&queryTime);
	for (int i = 0;i < queryTime;i++){
		long left,right;
		scanf("%ld%ld",&left,&right);
		if (left == 1)
			left = 0;
		else
			left = brray[left-2];
		right = brray[right-1];
		if (i == queryTime-1)
			printf("%ld",right-left);
		else
			printf("%ld\n",right-left);
	}
}

void swap(int *a,int *b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void Homework6_4(){
	int m,n;
	scanf("%d%d",&n,&m);
	int array[n][m];
	for (int i = 0;i < n;i++){
		for (int j = 0;j < m;j++){
			scanf("%d",&array[i][j]);
		}
	}
	/* int swapList[5][4]; */
	/* for (int i = 0;i < 5;i++){ */
	/* 	scanf("%d%d%d%d",&swapList[i][0],&swapList[i][1],&swapList[i][2],&swapList[i][3]); */
	/* } */
	for (int i = 0;i < 5;i++){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		swap(&array[x1-1][y1-1],&array[x2-1][y2-1]);
	}
	printf("%d",array[0][0]);
	for (int j = 1;j < m;j++){
		printf(" %d",array[0][j]);
	}
	for (int i = 1;i < n;i++){
		puts("");
		printf("%d",array[i][0]);
		for (int j = 1;j < m;j++){
			printf(" %d",array[i][j]);
		}
	}
}

int main(){
	int option;
	scanf("%d",&option);
	if (option == 1)
		Homework6_1();
	else if (option == 2)
		Homework6_2();
	else if (option == 3)
		Homework6_3();
	else if (option == 4)
		Homework6_4();
	return 0;
}
