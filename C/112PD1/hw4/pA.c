#include <stdio.h>

int main(){
    int days,starting_day;
    printf("Enter number of days in month: ");
    scanf("%d",&days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d",&starting_day);
    
	int count = 0;
	for (int i = -starting_day+1;i < days;i++,count++){
		if (count%7 == 0)
			puts("");
		if (i < 0){
			printf("   ");
			continue;
		}
		printf("%2d ",i+1);
	}
    return 0;
}
