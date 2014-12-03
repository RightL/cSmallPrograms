#include <stdio.h>
#include <cctype>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Lnum
{
    struct Lnum *pnext;
    float f_number; 
}
int main(void)
{
    double t_f_number;
    size_t count_number;
    char in_put[10]={0};
    while(true)
    {
        fgets(in_put,10,stdin);
        t_f_number=atof(in_put);
    }
    return 0;
}

