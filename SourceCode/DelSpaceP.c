#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char string[50];
    char *pstring=NULL;
    pstring=string;
    fgets(pstring,50,stdin);
    int count=0;
    for(int i = 0; i < 50; ++i)
    {
        count=i;
        while(isspace(*(pstring+i))||ispunct(*(pstring+i)))
        {
            *(pstring+count)=*(pstring+(count+1));
        }
    } 
    printf("删除空格和标点后的句子是：\n%s",pstring);
    return 0;
}

