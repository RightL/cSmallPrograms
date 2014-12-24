#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 100
#define MAX_SEN 30
int main(void)
{
    char *pstring[MAX_SEN]={NULL};
    printf("Type a sentence:\n");
    int i;
    for (i = 0; i < MAX_SEN; ++i)
    {
        pstring[i]=(char *)malloc(sizeof(char)*MAX_LEN);
        if (pstring[i]==NULL)
        {
            printf("malloc \n");
            exit(1);
        }
        fgets(pstring[i],MAX_LEN,stdin);
        if (*(pstring[i]+0)=='\n')
        {
            free(pstring[i]);
            break;
        }
        fflush(stdin);
    }
    for (int p = 0;  p < i; p++)
    {
        printf("%s", pstring[p]);
    }
    printf("Put sentence from Short to Long:\n");
    int all=0;
    while(all<i)
    {
        int min_index=0;
        for (int b = 0; b < i; ++b)
        {
            if (pstring[min_index]==NULL)
            {
                min_index++;
            }
            else
            {
                break;
            }
        }
        for (int q = 1; q < i; ++q)
        {
            if (pstring[q]==NULL||pstring[min_index]==NULL)
            {
                continue;
            }
            if (strlen(pstring[q])<strlen(pstring[min_index]))
            {
                min_index=q;
            }
        }
        printf("%s",pstring[min_index]);
        free(pstring[min_index]);
        pstring[min_index]=NULL;
        ++all;
    }
    return 0;
}

