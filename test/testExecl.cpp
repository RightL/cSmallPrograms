#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("Now Gooooo:\n");
    execl("/home/right/C-SmallProgram/SourceCode/avagenum_func.o","average_func.o",NULL);
    printf("Endddddd:\n");
    return 0;
}

