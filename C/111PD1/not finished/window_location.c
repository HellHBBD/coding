#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

void addChar(char **string,char c){
	int length;
	if (*string == 0){
		length = 0;
	}
	else
		length = strlen(*string);
	*string = realloc(*string,sizeof(char)*(length+2));
	(*string)[length] = c;
	(*string)[length+1] = '\0';
}

Location *parse_url(char *url){
	Location *result = malloc(sizeof(Location));
	result->protocol = 0;
	result->host = 0;
	result->pathname = 0;
	result->search = 0;
	result->hash = 0;
	result->port = 0;
	int i;
	for (i = 0;i < strlen(url);i++){ //protocol
		if (url[i] == ':'){
			i += 3;
			break;
		}
		addChar(&result->protocol,url[i]);
	}
	for (;i < strlen(url);i++){
	}
	return result;
}

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}
