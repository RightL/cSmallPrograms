#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    struct LinkedList *pnext;
    float daily_demperature[6];
    float average;
};

float average_degree(float *InPutNumber);

int main(void)
{
    struct LinkedList *first=NULL;
    struct LinkedList *current=NULL;
    struct LinkedList *previous=NULL;
    int count_number=0;
    int keep=1;

    printf("Type some degrees:\n");
    
    while(true)
    {
        printf("The next day:\n");
        float InPutNumber[6]={0};
        for (int i = 0; i < 6; ++i)
        {
            keep=scanf("%f",&InPutNumber[i]);
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
        current->average=average_degree(InPutNumber);
        for (int j = 0; j < count_number; ++j)
        {
            current->daily_demperature[j]=InPutNumber[j];
        }
        current->pnext=NULL;
        previous=current;
    }
    
    current=first;
    while(current!=NULL)
    {
        
    }
    return 0;
}

float average_degree(float *InPutNumber)
{
    float average=0;
    for (int i = 0; i < 6; ++i)
    {
        average+=*(InPutNumber+i);
    }
    return average/6;    
}

