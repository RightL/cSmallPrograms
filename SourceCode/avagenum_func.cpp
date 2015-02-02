#include <stdio.h>
#include <stdlib.h>

#define STEP 4

float* allocate_memory(float *data);
float average_num(float *data,size_t count_num);

size_t count_num=0;
size_t max_count_num=0;

int main(void)
{
    float *data=NULL;

    printf("Type some numbers:\nTYPE A LETTER TO THE END OF INPUT\n\n");
    while(true)
    {
        if (count_num==max_count_num)
        {
            data=allocate_memory(data); 
        } 
    }
    return 0;
}

//为输入的值分配内存
float* allocate_memory(float *data)
{
    float *newdata=NULL;
    max_count_num+=STEP;
    //allocate_memory
    newdata=(float*)calloc(1,max_count_num*sizeof(float)); 
    if (newdata==NULL)
    {
        printf("failed to allocate_memory\n");
        exit(1); 
    }
    //copy old data to new one
    if (data!=NULL)
    {
        for (size_t i = 0; i < count_num; ++i)
        {
            *(newdata+i)=*(data+i);  
        }
    }
    data=newdata;
    free(newdata);
    newdata=NULL; 

    return data;
}
//计算平均数
float average_num(float *data,size_t count_num)
{
    float total=0;
    return total/count_num;
}

