#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline()
{
	char *result = malloc(sizeof(char) * 1);
	result[0] = '\0';
	char c;
	while ((c = getchar()) != '\n') {
		int length = strlen(result);
		result = realloc(result, sizeof(char) * (length + 1));
		result[length] = c;
		result[length + 1] = '\0';
	}
	return result;
}

int find(char *filename)
{
	const char *str1 = "sudo cat /etc/NetworkManger/system-connections/";
	const char *str2 = ".nmconnection > temp";
	char *cmd = malloc(sizeof(char) * (strlen(str1) + strlen(filename) + strlen(str2) + 1));
	strcpy(cmd, str1);
	strcat(cmd, filename);
	strcat(cmd, str2);
	puts(cmd);
}

int main(int argc, char **argv)
{
	char *wifi_name;
	if (argc == 1) {
		printf("wifi name: ");
		wifi_name = readline();
	} else {
		wifi_name = malloc(sizeof(char) * (strlen(argv[1]) + 1));
		strcpy(wifi_name, argv[1]);
	}
	/* find(wifi_name); */
	const char *str1 = "/etc/NetworkManager/system-connections/";
	const char *str2 = ".nmconnection";
	char *filepath =
		malloc(sizeof(char) * (strlen(str1) + strlen(wifi_name) + strlen(str2) + 1));
	strcpy(filepath, str1);
	strcat(filepath, wifi_name);
	strcat(filepath, str2);
	FILE *file = fopen(filepath, "r");
	char psk[100];
	fscanf(file, "%s\n", test);
	puts(test);
	fclose(file);
	free(wifi_name);
	return 0;
}
