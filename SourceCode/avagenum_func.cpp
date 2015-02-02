#include <stdio.h>
#include <stdlib.h>

#define STEP 4

float* allocate_memory(float *data);
float average_num(float *data);

int main(void)
{
    float *data=NULL;
    size_t count_num=0;
    size_t max_count_num=0;

    printf("Type some numbers:\nTYPE A LETTER TO THE END OF INPUT\n\n");
    while(true)
    {
        if (count_num==max_count_num)
        {
            
        }
        data=allocate_memory(data); 
    }
    return 0;
}

//为输入的值分配内存
float* allocate_memory(float *data)
{
    return data;
}
//计算平均数
float average_num(float *data)
{
    float average_num=0;
    return average_num;
}
