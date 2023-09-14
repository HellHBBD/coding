#include <stdio.h>

int main(){
	for (int i=0;i<128;i++)
		printf("\'%c\' %d\n",(char)i,i);
}
