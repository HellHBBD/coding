#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
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
	result->protocol = malloc(sizeof(char));
	*result->protocol = '\0';
	result->host = malloc(sizeof(char));
	*result->host = '\0';
	result->pathname = malloc(sizeof(char));
	*result->pathname = '\0';
	result->search = malloc(sizeof(char));
	*result->search = '\0';
	result->hash = malloc(sizeof(char));
	*result->hash = '\0';
	result->port = 0;
	int i;
	for (i = 0;url[i] != '\n';i++){ //protocol
		if (url[i] == ':'){
			i += 3;
			break;
		}
		addChar(&result->protocol,url[i]);
	}
	for (;url[i] != '\n';i++){ //host
		if (url[i] == ':' || url[i] == '/')
			break;
		addChar(&result->host,url[i]);
	}
	if (url[i] == ':'){ //port
		i++;
		sscanf(&url[i],"%d",&result->port);
		for (;url[i] != '\n';i++){
			if (url[i] == '/'){
				i++;
				break;
			}
		}
	}
	for (;url[i] != '\n';i++){ //pathname
		if (url[i] == '?' || url[i] == '#')
			break;
		addChar(&result->pathname,url[i]);
	}
	if (url[i] == '?'){ //search
		i++;
		for (;url[i] != '\n';i++){
			if (url[i] == '#'){
				i++;
				break;
			}
			addChar(&result->search,url[i]);
		}
	}
	for (;url[i] != '\n';i++){
		addChar(&result->hash,url[i]);
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
