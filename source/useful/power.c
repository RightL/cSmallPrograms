#include "power.h"

double power(double x, int n) {
        if (n == 1)
                return x;
        x *= power(x, --n);
        return x;
}
