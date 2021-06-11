//一个长整型变量占4个字节，其中每个字节又分成高4位和低4位。试从该长整型变量的高字节开始，
//依次取出每个字节的高4位和低4位并以数字字符的形式进行显示。
#include "stdio.h"
int main(void)
{
    long int a;
    char num[32]={"00000000000000000000000000000000"};
    char *p=num;
    int i=1,k=0;
    //input
    printf("input a number:");
    scanf("%ld",&a);
    //
     while(a!=0)
        {
    if(a%2==1) {num[k]='1';k++;a=(a)/2;}
    else if(a%2==0) {num[k]='0';k++;a=a/2;}
            }
    //output
    while(i<33)
    {
        if((i)%8==0) {printf("%c",num[32-i]);printf("\n");i=i+1;}
        else if((i)%4==0) {printf("%c",num[32-i]);printf(" ");i=i+1;}
        else {printf("%c",num[32-i]);i=i+1;}
    }
}


