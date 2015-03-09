#include <stdio.h>
#include <stdlib.h>
#include "useful/cp_allocate_memory.h"
#include "useful/average_num.h"

static const unsigned int step = 4;

int main(void)
{
    float *data = NULL;

    now_and_max.count_now = 0;
    now_and_max.count_max = 0;

    printf("Type some numbers:\nTYPE A LETTER TO THE END OF INPUT\n");
    //输入
    while(true)
    {
        if (now_and_max.count_now == now_and_max.count_max)
        {
            data=fl_allocate_memory(data,step);
            if (data == NULL)
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
    if (now_and_max.count_now == 0)
    {
        printf("What the hell ?\n");
        free(data);
        exit(0);
    }

    if (data == NULL)
    {
        printf("Some thing goes wrong \n");
        exit(1);
    }
    //计算平均数
    printf("\n\naverage : %f\n", fl_average_num(data,now_and_max.count_now));
    //free memory
    free(data);
    data = NULL;
    return 0;
}
