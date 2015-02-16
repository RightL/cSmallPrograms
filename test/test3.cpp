#include <stdio.h>
int main(void)
{
    for (int i = 0; i < 10; ++i)
    {
        static int a=0;
        int b=0;
        ++a;
        ++b;
        printf("%d:",a);
        printf("%d\n",b);
    }
    return 0;
}
