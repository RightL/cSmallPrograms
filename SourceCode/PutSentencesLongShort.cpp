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
struct Node *addnode(char string[],struct Node *pNode,int string_lenth);
void freenodes(struct Node *pNode);
void listnodes(struct Node *pNode);
int main(void)
{
    int tmpstring_lenth;
    struct Node *pRoot=NULL;
    printf("输入一个句子(在新行键入回车退出输入)\n");
    while(true)
    {
        tmpstring_lenth=0;
        char tmpstring[MAX_LEN]={0};
        fgets(tmpstring,MAX_LEN,stdin);
        if (tmpstring[0]=='\n')
        {
            break;    
        }
        tmpstring_lenth=(int)strlen(tmpstring);
        if(pRoot==NULL)
        {
            pRoot=createnode(tmpstring,tmpstring_lenth);
        }
        else
        {
            addnode(tmpstring,pRoot,tmpstring_lenth);
        }
        
        fflush(stdin);
    }
    printf("句子从小到大输出为：\n");
    listnodes(pRoot);
    freenodes(pRoot);
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
    if (string_lenth==pNode->string_lenth)
    {
        ++pNode->count;
        return pNode;
    }
    if (string_lenth<pNode->string_lenth)
    {
        if (pNode->pLeft==NULL)
        {
            pNode->pLeft=createnode(string,string_lenth);
            return pNode->pLeft;
        }
        else
        {
            return addnode(string,pNode->pLeft,string_lenth);
        }
    }
    else
    {
        if (pNode->pRight==NULL)
        {
            pNode->pRight=createnode(string,string_lenth);
            return pNode->pRight;
        }
        else
        {
            return addnode(string,pNode->pRight,string_lenth);
        }
    }
}

void listnodes(struct Node *pNode)
{
    if(pNode->pLeft!=NULL)
        listnodes(pNode->pLeft);
    for (int j = 0; j < pNode->count; ++j)
    {
        printf("%s", pNode->item);
    }
    if (pNode->pRight!=NULL)
    {
        listnodes(pNode->pRight);
    }
}
void freenodes(struct Node *pNode)
{
    if(pNode==NULL)
        return;
    if (pNode->pLeft!=NULL)
    {
        freenodes(pNode->pLeft);
    }
    if (pNode->pRight!=NULL)
    {
        freenodes(pNode->pRight);
    }
    free(pNode);
}


