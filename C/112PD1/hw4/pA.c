#include <stdio.h>

int main(){
    int days,starting_day;
    printf("Enter number of days in month: ");
    scanf("%d",&days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d",&starting_day);
    
	int count = starting_day;
	for (int i = 0;i < starting_day-1;i++)
		printf("   ");
	for (int i = 0;i < days;i++,count++){
		printf("%2d ",i+1);
		if (count%7 == 0)
			puts("");
	}
    return 0;
}
