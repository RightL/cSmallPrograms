#include "cp_allocate_memory.h"

struct allocate_memory_count now_and_max;

float* fl_allocate_memory(float *data,unsigned int step)
{
    now_and_max.count_max+=step;
    //allocate_memory
    float *newdata=(float *)calloc(1,now_and_max.count_max*sizeof(float));
    if (newdata==NULL)
    {
        printf("failed to allocate_memory\n");
        exit(1); 
    }
    //copy old data to new one
    if (data!=NULL)
    {
        for (unsigned int  i = 0; i < now_and_max.count_now; ++i)
            *(newdata+i)=*(data+i);  
        free(data);
        data=NULL;
    }
    data=newdata;
    newdata=NULL; 

    return data;
}
