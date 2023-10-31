#include <stdio.h>

int answer[8],used[8];

void permutation(int cnt){
	/* printf("%d call\n",cnt); */
	if (cnt == 8){
		for (int i = 0;i < 8;i++)
			printf("%d ",answer[i]);
		puts("");
		/* printf("%d return\n",cnt); */
		return;
	}
	for (int i = 1;i <= 8;i++){
		if (used[i-1] == 0){
			answer[cnt] = i;
			used[i-1] = i;
			permutation(cnt+1);
			used[i-1] = 0;
		}
	}
}

int main(){
	permutation(0);
	return 0;
}
