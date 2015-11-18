#include <stdio.h>
#define off 0
#define on 1
int main() 
{
printf("asdfkasldkfjhalsdkfjhasdlkfjahsdlfkjadshlfkjahsldfkjashldfkjadshlfkjasflasjkdf");
    int array[100] = {off};
printf("asdfkasldkfjhalsdkfjhasdlkfjahsdlfkjadshlfkjahsldfkjashldfkjadshlfkjasflasjkdf");
    int i,j;
    int number = 0;
    for(i=0;i<100;++i){
        for(j=0;j<100;++j){
            if(array[j]%i){
                array[j] = !array[j];
            }
        }
    }
    for(i=0;i<100;++i){
        if(array[i]){
            ++number;
        }
    }
    printf("%d",number);
    return 0;
}
