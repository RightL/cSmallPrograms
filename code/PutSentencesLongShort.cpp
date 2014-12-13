#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LEN 100
struct Node
{
    char item[MAX_LEN];
    int count;
    struct Node *pLeft;
    struct Node *pRight;
};
int main(void)
{
    char tmpstring[MAX_LEN]={0};        /*mabey we shouldn't initialize it '*/
    while(true)
    {
        printf("输入一个句子(键入两个回车结束输入)\n");
        fgets(tmpstring,MAX_LEN,stdin);
    }
    return 0;
}
struct Node *createnode(char string[])
{
    struct Node *pNode=(struct Node *)malloc(sizeof(struct Node));
    for (int i = 0; i < (int)strlen(string); ++i)
    {
        pNode->item[i]=string[i];       /*The count number i mabey not correct*/
    }
    return pNode;
}

