#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
        const char delim[] = ",";
        char a[] = ",,,,,,,,adfasdf\0";
        char *pWord[] = {NULL};
        pWord[0] = strtok(a, delim);
        printf("%zu\n", strlen(pWord[0]));
        printf("%s\n", pWord[0]);
        return 0;
}
