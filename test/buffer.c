#include <stdio.h>

int main(void) {
        int a;
        char b;
        scanf("%d", &a);
        fflush(stdin);
        scanf("%c", &b);
        printf("%d\n", a);
        printf("%c\n", b);
        return 0;
}
