#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *join_strings(char *strings[], size_t strCount);
char *read_string(char term_end);

static const char terminator = '*';
static const char answer = 'y';


int main(void) {
        char *pStrings[] = {NULL};
        char *pStr = NULL;
        size_t strCount = 0;

        printf("Type something\n");

        for (size_t i = 0; i < strCount; i++)
                free(pStrings[i]);
        free(pStr);
        return 0;
}

char *join_strings(char *strings[], size_t strCount) {
        char *pStr = NULL;
        size_t strLen = 0;

        for (size_t i = 0; i < strCount; i++)
                strLen += strlen(strings[i]);
        pStr = (char *)malloc(sizeof(char) * strLen);
        if (pStr == NULL) {
                printf("Memery allocation failure\n");
                exit(-1);
        }

        for (size_t i = 0; i < strCount; i++) {
                strcat(pStr, strings[i]);
        }

        return pStr;
}

char *read_string(char term_end) {

        return 0;
}
