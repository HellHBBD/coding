#include <stdio.h>

int y(int x){
	return 6*x+10;
}

int z(int x){
	return 2023-5*x;
}

int f(int x){
	return y(z(x))+7*x;
}

int main(){
	int x;
	scanf("%d",&x);
	printf("%d\n",f(x));
	return 0;
}
