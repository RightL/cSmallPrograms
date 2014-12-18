#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char *pstring[10]={NULL};
    pstring[0]=(char *)malloc(sizeof(char)*20);
    if(pstring[0]==NULL)
    {
        exit(1);
    }
    fgets(pstring[0],20,stdin);
    printf("%s\n", pstring[0]);
    free(pstring[0]);
    return 0;
}




