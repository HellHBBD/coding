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

void Homework6_4(){
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
