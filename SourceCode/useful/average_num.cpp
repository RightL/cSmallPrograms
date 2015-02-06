#include "average_num.h"

float fl_average_num(float* numberList,unsigned int count_average_num)
{
    if (numberList==NULL)
    {
        printf("Nothing in numberList\n");
        exit(0);
    }

    float total=0;

    for (unsigned int  i = 0; i < count_average_num; ++i)
        total+=*(numberList+i);    

    return total/count_average_num;
}
