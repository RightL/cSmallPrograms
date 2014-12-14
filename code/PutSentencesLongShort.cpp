#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_LEN 100
struct Node
{
    char item[MAX_LEN];
    int count;
    int string_lenth;
    struct Node *pLeft;
    struct Node *pRight;
};
struct Node *createnode(char string[MAX_LEN]);
int main(void)
{
    char tmpstring[MAX_LEN]={0};        /*mabey we shouldn't initialize it '*/
    struct Node *pRoot=NULL;
    while(true)
    {
        printf("输入一个句子(在新行键入回车退出输入)\n");
        fgets(tmpstring,MAX_LEN,stdin);
        if (tmpstring[0]=='\n')
        {
            break;    
        }
        pRoot=createnode(tmpstring);
        fflush(stdin);
    }
    return 0;
}
struct Node *createnode(char string[MAX_LEN],int string_lenth)
{
    struct Node *pNode=(struct Node *)malloc(sizeof(struct Node));
    for (int i = 0; i < (int)strlen(string); ++i)
    {
        pNode->item[i]=string[i];       
    }
    pNode->count=1;
    pNode->pLeft=pNode->pRight=NULL;
    return pNode;
}
struct Node *addnode(char string[],struct Node *pNode)
{
    if (pNode==NULL)
    {
        return createnode(string);
    }    
    if ()
    {
        
    }
}


