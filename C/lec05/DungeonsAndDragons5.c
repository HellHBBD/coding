#include <stdio.h>

int main(){
	int disc[6] = {};
	int d1,d2;
	for (int i=0;i<75;i++){
		scanf("%d %d",&d1,&d2);
		if (d2%2 == 0)
			disc[d1-1] -= 1;
		else
			disc[d1-1] += 1;
		if (disc[d1-1] == 10)
			disc[d1-1] = 0;
		if (disc[d1-1] == -1)
			disc[d1-1] = 9;
	}
	for (int i=0;i<6;i++)
		printf("%d ",disc[i]);
	return 0;
}
