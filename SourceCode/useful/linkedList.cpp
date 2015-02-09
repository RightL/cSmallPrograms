#include "linkedList.h"

struct linkedList_t *first=NULL;
struct linkedList_t *current=NULL;
struct linkedList_t *previous=NULL;

//add_linkedList
#ifdef LINKEDLIST_TYPE_FLOAT
float* add_linkedList(float *data,unsigned int count_data)
{
    current=(struct linkedList_t*)calloc(1,sizeof(struct linkedList_t));
    if (current==NULL)
    {
        printf("failed to allocate memory\n");
        exit(1);
    }

    if (first==NULL)
        current=first;
    if (previous!=NULL)
        previous->pnext=current;

    current->data=data;
    current->count_data=count_data;

    current->pnext=NULL;
    previous=current;
}
#endif

