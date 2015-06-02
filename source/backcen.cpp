#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <stdbool.h>
#include <string.h>
int main()
{
        char centence[80]={0};
        char alpha[80]={0};
        size_t string_lenth=0;
        size_t count_words_letter=0;
        bool B=true;
        printf("输入一段文字，检测是否为回文\n");
        if (fgets(centence,80,stdin)==NULL) {
                printf("In put error!\n");
                exit(1);
        }
        string_lenth=strlen(centence);
        for (size_t i = 0; i < string_lenth; ++i)
        {
                if (isalpha(centence[i])!=0)
                {
                        alpha[count_words_letter]=centence[i];
                        ++count_words_letter;
                }
        }
        string_lenth=strlen(centence);
        for (size_t j = 0; j < count_words_letter; ++j)
        {
                if (!(alpha[j]==alpha[count_words_letter-j-1]))
                {
                        B=false;
                }
        }
        if (B)
        {
                printf("句子是回文！\n");
        }
        else
        {
                printf("句子不是回文！\n");
        }
        return 0;
}
