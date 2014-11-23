#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
int main(void)
{
    char centence[50]={0};
    char words[20][20]={0};
    int count_words_num=0;
    int count_words_letter=0;
    for (int i = 0; i < 50; ++i)
    {
        if (isalpha(centence[i]))
        {
            words[count_words_num][count_words_letter]=centence[i];
            count_words_letter++;
        }
        if (centence[i]==',')
        {
            count_words_num++;
        }
    }
    for (int i = 0; i < count_words_num; ++i)
    {
        printf("%s\n", words[i]);
    }
    return 0;
}

