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

void find(char *wifi)
{
	const char *str1 = "sudo cat /etc/NetworkManager/system-connections/";
	const char *str2 =
		".nmconnection | grep 'psk=' | awk -F '=' '{print $2}'";
	char *cmd = malloc(sizeof(char) *
			   (strlen(str1) + strlen(wifi) + strlen(str2) + 1));
	strcpy(cmd, str1);
	strcat(cmd, wifi);
	strcat(cmd, str2);
	/* puts(cmd); */
	system(cmd);
	free(cmd);
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
	find(wifi_name);
	free(wifi_name);
	return 0;
}
