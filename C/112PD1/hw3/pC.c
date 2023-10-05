#include <stdio.h>

int main(){
	int a,b,c,prize = 0;
	scanf("%d-%d-%d",&a,&b,&c);
	if (a == b && b == c)
		prize += 300;
	if (a + b < c)
		prize += 150;
	if (a == c)
		prize += 100;
	if (a < b)
		prize += 50;
	printf("%d",prize);
	return 0;
}
