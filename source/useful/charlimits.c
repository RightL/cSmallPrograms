#include "charlimits.h"

long numLen(void *x, const char numtype[])
{
	long len = 0;

	for (size_t i = 0; i < intcount; i++)
		if (!strcmp(numtype, Int[i]))
			goto methodInt;
	for (size_t i = 0; i < floatcount; i++)
		if (!strcmp(numtype, Float[i]))
			goto methodFloat;

	methodInt:{
		long long *tmp=NULL;
		tmp=(long long*)x;
		while (*tmp != 0) {
			*tmp = *tmp / 10;
			++len;
		}

		return len;
	}
	methodFloat:{
		return len;
	}


	printf("Type No found.\n");
	return -1;
}
