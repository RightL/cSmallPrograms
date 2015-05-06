#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <cctype>

#define MAX 50

int main(void)
{
	char string[MAX] = { 0 };
	char *pstring = NULL;
	pstring = string;
	printf("Type a sentense :\n");
	fgets(pstring, MAX, stdin);
	int count = 0;

	int string_lenth;
	string_lenth = (int) strlen(pstring);
	while (true) {
		if (count == string_lenth) {
			break;
		}
		if (isspace(*(pstring + count))
		    || ispunct(*(pstring + count))) {
			for (int j = count; j <= string_lenth; ++j) {
				*(pstring + j) = *(pstring + j + 1);
				*(pstring + j + 1) = 0;
			}
		} else {
			count++;
		}
	}
	printf("删除空格和标点后的句子是：\n%s", pstring);
	return 0;
}
