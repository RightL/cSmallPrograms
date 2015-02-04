#include <stdio.h>
#include <stdlib.h>

#define STEP 4

float* allocate_memory(float *data,size_t step);
float average_num(float *data);

static size_t count_num;
static size_t max_count_num;

int main(void)
{
    float *data=NULL;

    count_num=0;
    max_count_num=0;

    printf("Type some numbers:\nTYPE A LETTER TO THE END OF INPUT\n");
    //输入
    while(true)
    {
        if (count_num==max_count_num)
        {
            data=allocate_memory(data,STEP); 
            if (data==NULL)
            {
                printf("failed to allocate_memory\n");
                exit(1);
            }
        } 
        if (scanf("%f",data+count_num))
        {
            count_num++;
        }
        else
        {
            break;
        }
    }
    //if nothing input
    if (count_num==0)
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

//为输入的值分配内存
float* allocate_memory(float *data,size_t step)
{
    max_count_num+=step;
    //allocate_memory
    float *newdata=(float *)calloc(1,max_count_num*sizeof(float));
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
        free(data);
        data=NULL;
    }
    data=newdata;
    newdata=NULL; 

    return data;
}
//计算平均数
float average_num(float *data)
{
    float total=0;
    for (size_t i = 0; i < count_num; ++i)
    {
        total+=*(data+i);
    }
    return total/count_num;
}

