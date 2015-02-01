#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//用链表储存温度值
struct LinkedList
{
    struct LinkedList *pnext;
    float *daily_temperature;
    float average;
    int count_num;
};

float average_degree(float *InPutNumber);       /*进行平均温度计算*/

int main(void)
{
    struct LinkedList *first=NULL;
    struct LinkedList *current=NULL;
    struct LinkedList *previous=NULL;
    bool keep=true;                             /*是否继续输入*/

    printf("Type some tmptemperature:\n");
    printf("(must have six times a day)\n\n\n");
    while(true)
    {
        //输入温度值
        printf("The next day:\n");
        float tmptemperature[6]={0};
        for (int i = 0; i < 6; ++i)
        {
            //在第一天的第一个温度值输入一个字母或符号退出输入
            if (i==0)
            {
                keep=scanf("%f",&tmptemperature[i]);
                if (!keep)
                {
                    break;    
                }
            }
            else
            {
                scanf("%f",&tmptemperature[i]); 
            }
        }
        if (!keep)
        {
            break;
        }
        current=(struct LinkedList*)calloc(6,sizeof(struct LinkedList));
        if (first==NULL)
        {
            first=current;
        }
        if (previous!=NULL)
        {
            previous->pnext=current;
        }
        current->average=average_degree(tmptemperature);
        for (int j = 0; j < count_number; ++j)
        {
            *(current->daily_temperature+j)=tmptemperature[j];
        }
        current->count_num=count_number;
        current->pnext=NULL;
        previous=current;
    }

    current=first;
    while(current!=NULL)
    {
        for(int i = 0; i< current->count_num;++i)
        {
            printf("%f",*(current->daily_temperature+i));
        }
    }

    return 0;
}

float average_degree(float *tmptemperature)
{
    float average=0;
    for (int i = 0; i < 6; ++i)
    {
        average+=*(tmptemperature+i);
    }
    return average/6;
}
