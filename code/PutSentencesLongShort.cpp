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
struct Node *createnode(char string[MAX_LEN],int string_lenth);
int main(void)
{
    char tmpstring[MAX_LEN]={0};        /*mabey we shouldn't initialize it '*/
    int tmpstring_lenth;
    struct Node *pRoot=NULL;
    while(true)
    {
        tmpstring_lenth=0;
        printf("输入一个句子(在新行键入回车退出输入)\n");
        fgets(tmpstring,MAX_LEN,stdin);
        if (tmpstring[0]=='\n')
        {
            break;    
        }
        tmpstring_lenth=strlen(tmpstring);
        pRoot=createnode(tmpstring,tmpstring_lenth);
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
    pNode->string_lenth=string_lenth;
    return pNode;
}
struct Node *addnode(char string[],struct Node *pNode,int string_lenth)
{
    if (pNode==NULL)
    {
        return createnode(string,string_lenth);
    }    
    if ()
    {
        
    }
}


