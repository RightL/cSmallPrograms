#include <stdio.h>
#include <stdlib.h>

extern float* fl_allocate_memory(float *data,unsigned int step);

extern struct allocate_memory_count now_and_max; 

struct allocate_memory_count
{
    unsigned int  count_now;
    unsigned int   count_max;
};

