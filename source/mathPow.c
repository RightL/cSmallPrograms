#include "useful/power.h"
#include <stdio.h>

int main(void)
{
	double value = 0;
	int _power = 0;
	printf("Type the value: ");
	scanf("%lf", &value);
	printf("Type the power: ");
	scanf("%d", &_power);
	printf("The %d power of %lf is %lf\n", _power, value,
	       power(value, _power));
	return 0;
}
