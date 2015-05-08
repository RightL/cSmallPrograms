#include <stdio.h>
#include <string.h>
int func_a(const char a[]);
int main(int argc, char const *argv[])
{
	func_a("double");
        const char b[] = "asddf";
        printf("%s\n", b);
	return 0;
}

int func_a(const char a[])
{
        if (!strcmp(a,"double")) {
                printf("YES\n");
        }
	return 0;
}
