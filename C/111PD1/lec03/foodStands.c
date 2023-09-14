#include <stdio.h>

int dis(int a,int b){
	if (a > b)
		return a-b;
	return b-a;
}

int main(){
	int input,start = -1,end,max,distance;
	while (1){
		scanf("%d",&input);
		if (start == -1){
			start = input;
			max = input;
			continue;
		}
		if (input == -1)
			break;
		if (dis(start,input) > dis(start,max))
			max = input;
		end = input;
	}

	distance = dis(start,end);
	if (dis(start,max) > distance)
		distance = dis(start,max);
	if (dis(end,max) > distance)
		distance = dis(end,max);
	//printf("start:%d\nend:%d\nmax:%d\ndistance:%d",start,end,max,distance);
	printf("%d",distance);
	return 0;
}
