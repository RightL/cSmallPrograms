#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *join_strings(char *strings[], size_t strCount);
char *read_string(char terminator);

int main(void) {
        char terminator = '*';
        char answer = 'y';
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

        return pStr;
}

char *read_string(char terminator) {

        return 0;
}
