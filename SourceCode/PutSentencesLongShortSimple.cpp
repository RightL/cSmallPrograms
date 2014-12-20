#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 100
#define MAX_SEN 30
int main(void)
{
    char *pstring[MAX_SEN]={NULL};
    bool keep=true;
    printf("输入几个句子（在新行输入回车退出输入）：\n");
    for (int i = 0; i < MAX_SEN; ++i)
    {
        pstring[i]=(char *)malloc(sizeof(char)*MAX_LEN);
        if (*(pstring[i])=='\n')
        {
            free(pstring[i]);
            break;
        }
        fgets(pstring[i],MAX_LEN,stdin);
    }
    while(keep)
    {
        
    }
    return 0;
}

