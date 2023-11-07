#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void areAnagrams(char str1[],char str2[]){
	/* Your own expression */
	if (strlen(str1) != strlen(str2)){
		puts("No, the strings are not anagrams.");
		return;
	}
	int length = strlen(str1);
	for (int i = 0;i < length;i++){
		bool notIn1 = true,notIn2 = true;
		for (int j = 0;j < length;j++){
			if (str1[i] == str2[j])
				notIn1 = false;
			if (str2[i] == str1[j])
				notIn2 = false;
		}
		if (notIn1 || notIn2){
			puts("No, the strings are not anagrams.");
			return;
		}
	}
	puts("Yes, the strings are anagrams.");
}

int main(){
	char str1[100], str2[100];
	scanf("%s", str1);
	scanf("%s", str2);
	areAnagrams(str1, str2);
	return 0;
}
