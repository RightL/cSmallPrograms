#include <stdlib.h>
#include <stdio.h>
#include <cctype>
int main(void)
{
    char centence[80]={0};
    char words[20][30]={{0}};
    int count_words_num=0;
    int count_words_letter=0;
    printf("输入一些单词，用逗号分割：\n");
    if (fgets(centence,50,stdin)==NULL)
    {
        printf("In put error!\n");
        exit(1);
    }
    for (int i = 0; i < 80; ++i)
    {
        if (isalpha(centence[i])!=0)
        {
            words[count_words_num][count_words_letter]=centence[i];
            ++count_words_letter;
            continue;
        }
        if (centence[i]==',')
        {
            ++count_words_num;
            count_words_letter=0;
        }
    }
    count_words_num+=1;
    for (int j = 0; j < count_words_num; ++j)
    {
        printf("%s\n", words[j]);
    }
    return 0;
}

