#include <stdio.h>
#include <stdlib.h>

char *join_strings(char *strings[]);
char *read_string(char terminator);

int main(void) {
        char terminator = '*';
        char answer = 'y';
        char *pStrings[] = {NULL};
        return 0;
}

char *join_strings(char *strings[], size_t strLenth) {
        char *pStr = NULL;
        if (pStr = (char *)malloc(sizeof(char) * strLenth)) {
                printf("Memery allocation failure\n");
                exit(-1);
        }
        
        return pStr;
}

char *read_string(char terminator) {

        return 0;
}
