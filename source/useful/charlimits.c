#include "charlimits.h"

unsigned long doubleLen(int x) {
        unsigned long len = 0;

        while(x != 0) {
                x = x / 10;
                ++len;
        }

        return len;
}
