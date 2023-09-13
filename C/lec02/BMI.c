#include <stdio.h>
#include <math.h>

int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	printf("%.6f",y/powf(0.01*x,2));
	return 0;
}
