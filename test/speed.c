#include "stdio.h"
int main(int argc, char const *argv[]) {
        for (long long int i = 0; i < 100000000; i++) {
                printf("%lld\n", i);
        }
        return 0;
}
