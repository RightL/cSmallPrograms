#include <stdio.h>
#include <string.h>
#include "../source/useful/charlimits.h"
int main(void)
{
	long b = 0;
	double a = 121.0;
	double x= 1.24563;
	long double y = (long double)x;
	long double h = y*100000;
	long z = (long)h;
	printf("%ld\n", z);
	if (z == (long)h ) {
		printf("YES\n");
	}
	void *p = &a;
	double *temp = (double*)p;
	printf("%lf\n", *temp);
	if ((b = numLen(&a, "double")) == -1) {
		printf("FAILED\n");
	}
	printf("%ld\n", b);
	return 0;
}
