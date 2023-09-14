#include <stdio.h>
#include <math.h>

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	double result = sqrt(a*c) + pow(a,b) + log10(a*b*c);
	result = round(result*1000) / 1000.0;
	printf("%.3lf",result);
}
