#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *join_strings(char *strings[], size_t strCount);
char *read_string(char term_end);

#define BUFFER_SIZE 50
#define MAX_STR 100

static const char terminator = '*';


int main(void)
{
	char *pStrings[MAX_STR] = { NULL };
	char *pStr = NULL;
	char answer = 'y';
	size_t strCount = 0;

	printf("Type something\n");

	while (strCount < MAX_STR && tolower(answer) == 'y') {
		pStrings[strCount++] = read_string(terminator);
		printf("Do you wanna enter another ? (Y/n): ");
		scanf("%c", &answer);
		fflush(stdin);
	}

	pStr = join_strings(pStrings, strCount);
	printf("\nHere are the strings as a single string:\n%s\n", pStr);

	for (size_t i = 0; i < strCount; i++)
		free(pStrings[i]);
	free(pStr);
	return 0;
}

char *join_strings(char *strings[], size_t strCount)
{
	char *pStr = NULL;
	size_t total_lenth = 0;
	size_t lenth = 0;

	for (size_t i = 0; i < strCount; i++) {
		total_lenth += strlen(strings[i]);
		if (strings[i][lenth - 1] != '\n') {
			total_lenth++;
		}
	}

	pStr = (char *) malloc(sizeof(char) * total_lenth);
	if (pStr == NULL) {
		printf("Memery allocation failure\n");
		exit(-1);
	}

	for (size_t i = 0; i < strCount; i++) {
		strcat(pStr, strings[i]);
		lenth = strlen(strings[i]);
		if (strings[i][lenth - 1] != '\n') {
			strings[i][lenth] = '\n';
			strings[i][lenth + 1] = '\0';
		}
	}

	return pStr;
}

char *read_string(char term_end)
{
	char *pStr = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (pStr == NULL) {
		printf("Memery allocation failure\n");
		exit(-1);
	}

	size_t i = 0;
	while (term_end != (pStr[i++] = (char) getchar())) {
		if ((i % BUFFER_SIZE) == 0) {
			pStr = (char *) realloc(pStr, i + BUFFER_SIZE);
			if (pStr == NULL) {
				printf("Memery allocation failure\n");
				exit(-1);
			}
		}
	}
	pStr[i - 1] = '\0';

	return pStr;
}
