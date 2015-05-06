#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 20

char *to_string(size_t count, double first, ...);
char *ftoa(double x);

int main(void)
{
	char *string =
	    to_string(6, 3.14, 23.23, 234.34, 14.11, 99.9, 11.1);
	printf("%s\n", string);
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
	}

	va_end(parg);
	return string;
}

char *ftoa(double x)
{
	char *str;

	return str;
}
