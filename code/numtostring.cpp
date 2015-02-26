#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LEN 10               /*The int32_t has 10*/

char* numtostring(int number);

int main(void)
{
	int32_t number=0;

	printf("\n: %s\n", numtostring(number));

	return 0;
}

char* numtostring(int32_t number)
{
	char *pstring=NULL;

	bool isnegative = number < 0;
	if (isnegative)
		number = -number;                   /*make it mositive*/
	do{
		int8_t tmpnum = number%10;
	} while(number != 0);

	return pstring;
}
