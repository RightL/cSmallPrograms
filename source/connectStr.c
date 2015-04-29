#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *join_strings(char *strings[], size_t strCount);
char *read_string(char term_end);

#define BUFFER_SIZE 50

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
        size_t total_lenth = 0;
        size_t lenth = 0;

        for (size_t i = 0; i < strCount; i++) {
                total_lenth += strlen(strings[i]);
                if (strings[i][lenth - 1] != '\n') {
                        total_lenth++;
                }
        }

        pStr = (char *)malloc(sizeof(char) * total_lenth);
        if (pStr == NULL) {
                printf("Memery allocation failure\n");
                exit(-1);
        }

        for (size_t i = 0; i < strCount; i++) {
                strcat(pStr, strings[i]);
                lenth = strlen(strings[i]);
                if (strings[i][lenth - 1] != '\n') {
                        strings[i][lenth] = '\n';
                        strings[i][lenth + 1] ='\0';
                }
        }

        return pStr;
}

char *read_string(char term_end) {
        char *str = NULL;
        size_t i = 0;

        do {
                str = (char *)malloc(sizeof(char) * BUFFER_SIZE);
                i++;
        } while(term_end != (*(str + i) = (char)getchar()));


        return 0;
}
