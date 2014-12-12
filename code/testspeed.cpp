#include <stdio.h>
#include <cctype>
#include <time.h>
#include <math.h>
int main(void)
{
    time_t calendar_start=time(NULL);
    clock_t cpu_start=clock();
    int count=0;
    const int iterations=1000000;
    char answer='y';
    printf("Initial clock time = %lu Initial calendar time = %lu\n", cpu_start,calendar_start);
    while(tolower(answer)=='y')
    {
        for (int i = 0; i < iterations; ++i)
        {
            double x=sqrt(3.14159265);
        }
        printf("\n%ld Spuare roots completed.\n", iterations*(++count));
        printf("\nDo you want to run some more? (Y/n)  ");
        scanf("%c",&answer);
    }
    clock_t cpu_end=clock();
    time_t calendar_end=time(NULL);
    printf("\nFinal clock time : %lu Final calendar time : %lu\n",cpu_end,calendar_end );
    printf("\nCPU time for %ld iterations is %.21f seconds\n", count*iterations,((double)(cpu_end-cpu_start))/CLOCKS_PER_SEC);
    printf("\nElapsed calendar time to execute the program is %8.21f\n", difftime(calendar_end,calendar_start));
    return 0;
}

