#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char read(FILE *, char **);
void command(char *, char *);

int main()
{
	FILE *file = fopen("config", "r");
	int line = 0;
	char signal;
	while (1) {
		char *name, *path;
		line++;
		signal = read(file, &name);
		if (name[0] == '#') {
			free(name);
			while ((signal = getc(file)) != '\n')
				;
			continue;
		}
		if (signal == '\n') {
			fprintf(stderr, "Error config at line %d\n", line);
			fprintf(stderr, "%s\\n <- expect space or tab\n", name);
			free(name);
			fclose(file);
			return 1;
		} else if (signal == EOF && *name == '\0') {
			fputs("Read config successfully!\n", stderr);
			free(name);
			fclose(file);
			return 0;
		} else if (signal == EOF) {
			fprintf(stderr, "Error config at line %d\n", line);
			fprintf(stderr, "%sEOF <- expect space or tab\n", name);
			free(name);
			fclose(file);
			return 1;
		}

		signal = read(file, &path);
		if (signal == ' ' || signal == '\t') {
			fprintf(stderr, "Error config at line %d\n", line);
			fprintf(stderr, "%s <- expect newline\n", path);
			free(name);
			free(path);
			fclose(file);
			return 1;
		}
		command(name, path);
		free(name);
		free(path);
	}
}

char read(FILE *file, char **result)
{
	*result = NULL;
	int length = 0;
	while (1) {
		char c = getc(file);
		switch (c) {
		case ' ':
		case '\t':
		case '\n':
		case EOF:
			*result = realloc(*result, sizeof(char) * (length + 1));
			(*result)[length] = '\0';
			return c;
		default:
			if (*result) {
				*result = realloc(*result, sizeof(char) * (length + 1));
				(*result)[length++] = c;
			} else {
				length++;
				*result = malloc(sizeof(char) * 2);
				(*result)[0] = c;
				(*result)[1] = '\0';
			}
		}
	}
}

void command(char *name, char *path)
{
	char *str = "gcc -o ";
	char *msg = malloc(sizeof(char) * (strlen(str) + strlen(path) + strlen(name) + 4));
	strcpy(msg, str);
	strcat(msg, path);
	strcat(msg, " ");
	strcat(msg, name);
	strcat(msg, ".c");
	/* puts(msg); */
	system(msg);
	free(msg);
}
