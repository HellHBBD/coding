#include <stdio.h>

int main(){
	long int n,s,total = 0;
	scanf("%ld",&n);
	for (long int i=0;i<n;i++){
		scanf("%ld",&s);
		total += s;
		if (total%s == 0)
			printf("%ld %ld\n",total,s);
	}
	return 0;
}
