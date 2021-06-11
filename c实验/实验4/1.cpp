#include "stdio.h"
#define SUM (a+b)
#define DIF (a-b)
#define SWAP(a,b)  (t=b,b=a,a=t)//加了变量t 
int main(void)//main——main（void） 
{
    int b,t,a;//a
    printf("Input two integers a, b:");
    scanf("%d,%d",&a,&b);
    printf("\nSUM=%d\n the difference between square of a and square of b is:%d",SUM, SUM*DIF);
    SWAP(a,b);
    printf("\nNow a=%d,b=%d\n",a,b);//P——p 
    return 0;// 
}

