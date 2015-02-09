#include <stdio.h>
#include <stdlib.h>

extern float* add_linkedList(float *data,unsigned int count_data);

//if the data type is float
#ifdef LINKEDLIST_TYPE_FLOAT
struct linkedList_t
{
    struct linkedList_t *pnext;
    unsigned int count_data;
    float *data; 
};
#endif

//if the data type is int
#ifdef LINKEDLIST_TYPE_INT
struct linkedList_t
{
    struct linkedList_t *pnext;
    unsigned int count_data;
    int *data; 
};
#endif

//一些存储链表地址的指针
extern struct linkedList_t *first;
extern struct linkedList_t *current;
extern struct linkedList_t *previous;
