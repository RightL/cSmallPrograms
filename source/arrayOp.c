#include <stdio.h>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a , double b);
double array_op(double array[], size_t size, double (*pfun)(double, double));


int main(void)
{
        return 0;
}

double add(double a, double b)
{
        return a + b;
}

double subtract(double a, double b)
{
        return a - b;
}

double multiply(double a , double b)
{
        return a * b;
}

double array_op(double array[], size_t size, double (*pfun)(double, double))
{
        return size;
}
