#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

int main(){
	Location result;
	char input[100];
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
	return 0;
}
