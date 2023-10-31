#include <stdio.h>

int pow(int a,int n){
	return (n == 1) ? a : a*pow(a,n-1);
}

int main(){
	int a,n;
	scanf("%d%d",&a,&n);
	printf("%d\n",pow(a,n));
	return 0;
}
