#include <stdio.h>
#include <stdbool.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))

int maxFactor(int a,int b,int c){
	int factor;
	int m = min(a,min(b,c));
	for (int i = 1;i <= m;i++)
		if (a%i == 0 && b%i == 0 && c%i == 0)
			factor = i;
	return factor;
}

int main(){
	puts("//////////Welcome to NCKU-PD1-Kirby-Shop\\\\\\\\\\\\\\\\\\\\");
	bool open = false;
	bool enter_again = false;
	int KirbyA = 0;
	int KirbyB = 0;
	int KirbyC = 0;
	int option,Kirby,money = 0;
	char flush;
	while (1){
		puts("Options: (1)Openning (2)List (3)Adding (4)Exit");
		scanf("%d",&option);
		//printf("%d\n",option);
		if (option < 1 || option > 4){
			puts("Error: Please try again!");
			continue;
		}
		if (option == 1){ //openning
			if (open)
				puts("Your Kirby shop has already opened :(");
			else{
				puts("Your shop is openning!");
				open = true;
			}
		}
		else if (option == 2){ //list
			puts("===================================");
			printf("Kirby-A: %d\n",KirbyA);
			printf("Kirby-B: %d\n",KirbyB);
			printf("Kirby-C: %d\n",KirbyC);
			printf("Kirby: %d, Money: %d\n",Kirby,money);
			puts("===================================");
		}
		else if (option == 3){ //adding
			if (open){
				printf("Please enter three numbers: ");
				int a,b,c;
				while (1){
					int getNumber = scanf("%d%d%d",&a,&b,&c);
					flush = getchar();
					//printf("%d %d %d%c",a,b,c,d);
					if (getNumber == 3 && flush == '\n' && a == -1 && b == -1 && c == -1 && enter_again){
						enter_again = false;
						break;
					}
					else if (getNumber == 3 && flush == '\n' && a > 0 && b > 0 && c > 0){
						enter_again = false;
						break;
					}
					else{
						while (1){
							if (flush == '\n')
								break;
							flush = getchar();
						}
						printf("Error: Please try again or enter '-1 -1 -1' to make a new options: ");
						enter_again = true;
					}
				}
				if (a == -1 && b == -1 && c == -1)
					continue;
				int factor = maxFactor(a,b,c);
				int price = a+b+c-factor*2;
				printf("Divide these Kirbys into %d boxes, with the number of Kirby in each box being %d, %d, and %d\nPrice: %d\n",factor,a/factor,b/factor,c/factor,price);
				KirbyA += a;
				KirbyB += b;
				KirbyC += c;
				Kirby = KirbyA+KirbyB+KirbyC;
				money += price;
			}
			else{
				puts("Your Kirby shop has not opened");
				continue;
			}
		}
		else if (option == 4){ //exit
			break;
		}
	}
	return 0;
}
