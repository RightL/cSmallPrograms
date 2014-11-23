#include <stdio.h>
#include <stdlib.h>
int main()
{
    int number=0;
    printf("输入一个四位数：");
    scanf("%d",&number);
    int A,B,C,D;
    char tho[9][10]={{"一千"},{"两千"},{"三千"},{"四千"},{"五千"},{"六千"},{"七千"},{"八千"},{"九千"}};
    char hun[10][10]={{"零"},{"一百"},{"两百"},{"三百"},{"四百"},{"五百"},{"六百"},{"七百"},{"八百"},{"九百"}};
    char ten[10][10]={{"零"},{"一十"},{"二十"},{"三十"},{"四十"},{"五十"},{"六十"},{"七十"},{"八十"},{"九十"}};
    char sin[9][10]={{"一"},{"二"},{"三"},{"四"},{"五"},{"六"},{"七"},{"八"},{"九"}};
    A=(int)number/1000;
    printf("%d\n",A);
    B=(int)(number-1000*A)/100;
    printf("%d\n",B);
    C=(int)(number-1000*A-100*B)/10;
    printf("%d\n",C);
    D=(int)(number-1000*A-100*B-10*C);
    printf("%d\n",D);
    printf("读作：");
    printf("%s", tho[A-1]);
    if ((B!=C)&&(B==0||C==0)&&(C!=D))
    {
        printf("%s",hun[B]);    
        printf("%s",ten[C]);
        printf("%s",sin[D-1]);
    }
    else if((C==D)&&(C==0)&&(C!=B))
    {
    	printf("%s",hun[B]);
    	printf("%s",sin[D-1]);
    }
    else if(B==0&&B==C&&C!=D)
    {
    	printf("%s",hun[0]);
    	printf("%s",sin[D-1]);
    }
    else if(B==0&&B==C&&C==D)
    {
    	printf("");
    }
    else
    {
         printf("%s",hun[B]);
         printf("%s",ten[C]);   
         printf("%s",sin[D-1]);
    }
    
    return 0;
}