#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int is 10*/
#define MAX_STRING_LEN 10

char *numtostring(int number);

int main(void)
{
	printf("\nType a number: ");
	int number=0;
	char *numstr = NULL;

	scanf("%d", &number);

	numstr = numtostring(number);
	if (!numstr) {
		printf("Unexpected error\n");
		return -1;
	}

	printf("The string is : ");
	for (int i = static_cast<int>(strlen(numstr)); i >= 0; i--) {
		printf("%c", *(numstr + i));
	}
	printf("\n");

	free(numstr);
	return 0;
}

char *numtostring(int number)
{
	// '\0' + '-' = 2
	char numstr[MAX_STRING_LEN + 2] = {0};

	bool isnegative = number < 0;
	if (isnegative)
		number = -number;

	unsigned int i = 0;
	do {
		/*Will never happen
		if (i > MAX_STRING_LEN - 2) {
			printf("Too long number:%d\n", i);
			return NULL;
		}
		*/

		int tmpnum = number % 10;
		number = number / 10;
		numstr[i] = static_cast<char>('0' + tmpnum);

		++i;
	} while(number != 0);

	if (isnegative) {
		numstr[i] = '-';
		numstr[i + 1] = '\0';
	} else {
		numstr[i] = '\0';
	}

	size_t numstr_len = strlen(numstr) + 1;
	char *pnumstr = reinterpret_cast<char *>(malloc(numstr_len));
	if (!pnumstr) {
		printf("Memery allocation failure\n");
		return NULL;
	}

	strcpy(pnumstr, numstr);
	return pnumstr;
}
