#include <stdio.h>
#include <cctype>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Lnum
{
    struct Lnum *pnext;
    float f_number; 
};
int main(void)
{
    struct Lnum *first=NULL;
    struct Lnum *current=NULL;
    struct Lnum *previous=NULL;
    int count_number=0;
    float InPutNumber;
    while(true)
    {
        printf("输入一个数字（输入字母退出输入）：");
        if (scanf("%f",&InPutNumber))
        {
           count_number++; 
        }  
        else 
        {
           break;
        }
        current=(struct Lnum*)malloc(sizeof(struct Lnum));
        if (first==NULL)
        {
            first=current;
        }
        if (previous!=NULL)
        {
            previous->pnext=current;
        }
        current->f_number=InPutNumber;
        InPutNumber=0;
        current->pnext=NULL;
        previous=current;
    }
    current=first;
    while(current!=NULL)
    {
        break;
    }
    return 0;
}

