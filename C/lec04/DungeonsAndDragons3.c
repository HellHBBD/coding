#include <stdio.h>

int main(){
	unsigned long long NUMBER_1 = 0x38E38E38E38E3800LLU;
	unsigned long long NUMBER_2 = 0x2AAAAAAAAAAAAAAALLU;
	unsigned long long NUMBER_3 = 0x1C71C71C71C71C71LLU;
	unsigned long long divisor = 0x7CE66C50E2840000LLU;
	int d1,d2,d3;
	scanf("%d %d %d",&d1,&d2,&d3);
	NUMBER_1 = (d1*NUMBER_1)%divisor;
	NUMBER_2 = (d2*NUMBER_2)%divisor;
	NUMBER_3 = (d3*NUMBER_3)%divisor;
	long long sum = ((NUMBER_1 + NUMBER_2)%divisor + NUMBER_3)%divisor;
	printf("%lld",sum);
	return 0;
}
