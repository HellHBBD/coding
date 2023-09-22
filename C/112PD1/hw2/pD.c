#include <stdio.h>

int main(){
	int a,b,N;
	scanf("%d,%d,%d",&a,&b,&N);
	int result = (a << b) + (a | b) - (N >> b)*(a ^ b) - (a & b);
	printf("%d\n",result);
	return 0;
}
