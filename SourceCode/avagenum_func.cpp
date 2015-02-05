#include <stdio.h>
#include <stdlib.h>
#include "useful/cp_allocate_memory.h"

static const unsigned int step=4;

float average_num(float *data);

int main(void)
{
    float *data=NULL;

    now_and_max.count_now=0;
    now_and_max.count_max=0;

    printf("Type some numbers:\nTYPE A LETTER TO THE END OF INPUT\n");
    //输入
    while(true)
    {
        if (now_and_max.count_now==now_and_max.count_max)
        {
            data=fl_allocate_memory(data,step);
            if (data==NULL)
            {
                printf("failed to allocate_memory\n");
                exit(1);
            }
        } 
        
        if (scanf("%f",data+now_and_max.count_now))
            now_and_max.count_now++;
        else
            break;
    }
    //if nothing input
    if (now_and_max.count_now==0)
    {
        printf("What the hell ?\n");        
        free(data);
        exit(0);
    }

    if (data==NULL)
    {
        printf("Some thing goes wrong \n");
        exit(1);
    }
    //计算平均数
    printf("\n\naverage : %f\n", average_num(data));
    //free memory
    free(data);
    data=NULL;
    return 0;
}

//计算平均数
float average_num(float *data)
{
    float total=0;
    for (unsigned int  i = 0; i < now_and_max.count_now; ++i)
        total+=*(data+i);
    return total/now_and_max.count_now;
}

