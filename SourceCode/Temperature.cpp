#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    struct LinkedList *pnext;
    float *daily_temperature;
    float average;
    int count_num;
};

float average_degree(float *InPutNumber);

int main(void)
{
    struct LinkedList *first=NULL;
    struct LinkedList *current=NULL;
    struct LinkedList *previous=NULL;
    int keep=1;

    printf("Type some tmptemperature:\n");

    while(true)
    {
        printf("The next day:\n");
        float tmptemperature[6]={0};
        int count_number=0;
        for (int i = 0; i < 6; ++i)
        {
            keep=scanf("%f",&tmptemperature[i]);
            if (keep)
            {
                count_number++;
            }
            else
            {
                break;
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

