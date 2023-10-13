#include <stdio.h>

int main(){
	int days,starting_day;
	printf("Enter number of days in month: ");
	scanf("%d",&days);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d",&starting_day);
	int count = 0;
	for (int i = 0;i < days;){
		if (starting_day-1){
			printf("   ");
			starting_day--;
			count++;
			continue;
		}
		printf("%2d ",i+1);
		i++;
		count++;
		if (count%7 == 0)
			puts("");
	}
	return 0;
}
