#include <stdio.h>
#include <stdarg.h>

double average(double v1, double v2, ...);

int main(void) {
        printf("%f\n", average(1.23, 2.45, 2.52, 0.0));
        return 0;
}

double average(double v1, double v2, ...) {
        va_list parg;
        double sum = v1 + v2;
        double value = 0;
        int count = 2;

        va_start(parg, v2);

        while ((value = va_arg(parg, double)) != 0.0) {
                sum += value;
                count++;
        }
        return sum / count;
}
