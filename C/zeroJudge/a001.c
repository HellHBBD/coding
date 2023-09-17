#include <stdio.h>
#include <stdlib.h>

int getString(char *string){
	char c;
	string = 0;
	int length = 0;
	while ((c = getchar()) != '\n'){
		string = realloc(string,sizeof(char)*(length+1));
		string[length++] = c;
	}
	string = realloc(string,sizeof(char)*(length+1));
	string[length++] = '\0';
}

int main(){
	char *string;
	getString(string);
	printf("hello, %s",string);
	free(string);
	return 0;
}
