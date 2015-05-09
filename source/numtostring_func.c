#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRLEN 20

static char *to_string(size_t count, double first, ...);
static char *ftoa(double x);

int main(void)
{
	char *string = to_string(6, 3.14, 23.23, 234.34, -14.11, 99.9, 11.1);

	return 0;
}

char *to_string(size_t count, double first, ...)
{
	char *string = NULL;
	double current_num = 0;
	double num = 0;
	va_list parg;
	va_start(parg, first);

	for (size_t i = 0; i < count; i++) {
		current_num = va_arg(parg, double);
		if (!ftoa(current_num)){
			printf("Memery allocation failure\n");
			return NULL;
		}
	}


	va_end(parg);
	return string;
}

char *ftoa(double x)
{
	char *str = NULL;
	size_t dotIndex = 0;
	int intx = 0;
	bool isnegative = x < 0;

	if (isnegative)
		x = -x;
	if (!(str = malloc(sizeof(char) * MAX_STRLEN))) {
		printf("Memery allocation failure\n");
		return NULL;
	}

	while (x != (double) intx) {
		intx = (int) (x *= 10);
		++dotIndex;
	}

	size_t i = 0;
	do {
		if (i == dotIndex && i != 0){
			str[i++] = '.';
			continue;
		}
		int tmpnum = intx % 10;
		intx = intx / 10;
		str[i++] = (char) ('0' + tmpnum);
	} while (intx != 0);

	if (isnegative) {
		str[i] = '-';
		str[i + 1] = '\0';
	} else {
		str[i] = '\0';
	}

	return str;
}
