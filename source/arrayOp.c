#include <stdio.h>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double array_op(double array[], size_t size,
		double (*pfun) (double, double));


int main(void)
{
	double array[] = { 1, 2, 3, 4, 5, 6, 7 };
	size_t lenth = sizeof(array) / sizeof(double);
	printf("%f\n", array_op(array, lenth, subtract));
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

double multiply(double a, double b)
{
	return a * b;
}

double array_op(double array[], size_t size,
		double (*pfun) (double, double))
{
	double result = array[size - 1];
	for (size_t i = size - 1; i > 0; i--)
		result = pfun(array[i - 1], result);
	return result;
}
