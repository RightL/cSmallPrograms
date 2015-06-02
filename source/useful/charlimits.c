#include "charlimits.h"

int numLen(void *x, const char numtype[])
{
	int len = 0;

	for (size_t i = 0; i < intcount; i++)
		if (!strcmp(numtype, Int[i]))
			goto methodInt;
	for (size_t i = 0; i < floatcount; i++)
		if (!strcmp(numtype, Float[i]))
			goto methodFloat;
	printf("Type No found.\n");
	return -1;

	methodInt:{
		long long tmp = *((long long*)x) < 0 ?
				*((long long*)x) : -*((long long*)x) * 10;
		while (tmp != 0) {
			tmp = tmp / 10;
			++len;
		}
		return len;
	}
	methodFloat:{
		double tmp = *((double*)x) > 0 ?
				*((double*)x) : -*((double*)x) * 10;
		long intx = (long)tmp;
		while (tmp != (double)intx) {
			intx = (long) (tmp *= 10);
			printf("%ld,%lf\n",intx,tmp);
		}
		while (intx != 0) {
			intx = intx / 10;
			++len;
		}
		return len;
	}
}
