#include <stdio.h>
#include <stdlib.h>

void insert(int a,int b,int *array,int length){
	int from = -1;
	int to = -1;
	for (int i = 0;i < length;i++){
		if (array[i] == a)
			from = i;
		if (array[i] == b)
			to = i;
		if (from != -1 && to != -1)
			break;
	}
	int step = (from > to ? -1 : 1);
	int temp = a;
	for (int i = from;i != to-1;i += step){
		array[i] = array[i+step];
	}
	array[to-1] = temp;
}

int main(){
	int n;
	scanf("%d",&n);
	int *array = malloc(sizeof(int)*n);
	for (int i = 0;i < n;i++)
		array[i] = i+1;
	while (1){
		int command;
		scanf("%d",&command);
		if (command == 3)
			break;
		else if (command == 1){
			int a,b;
			scanf("%d %d",&a,&b);
			insert(a,b,array,n);
		}
		else if (command == 2){
			int index;
			scanf("%d",&index);
			printf("%d\n",array[index-1]);
		}
	}
	free(array);
	return 0;
}
