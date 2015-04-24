#include "power.h"

double power(double x, int n)
{
        if (n == 0)
                return 1;
        if (n > 0)
                x *= power(x, --n);
        else if (n < 0)
                x = (1 / x) * power(x, ++n);
        return x;
}
