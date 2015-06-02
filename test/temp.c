#include <stdio.h>
#include <dlfcn.h>
int main(void)
{
        dlopen("dlfunc.so", RTLD_NOW);
        
        return 0;
}
