//用带参数的宏替换函数max，来实现求最大数的功能。
#include "stdio.h" 
#define MAX (a>b)?(a>c?a:c):(b>c?b:c)
#define SUM (d+e)
int main(void)
{
  int a, b, c;
  float d, e;
  printf("Enter three integers:");
  scanf("%d %d %d",&a,&b,&c); 
  printf("\nthe maximum of them is %d\n",MAX);

    printf("Enter two floating point numbers:");
    scanf("%f %f",&d,&e);
    printf("\nthe sum of them is  %f\n",SUM);
    return 0; 
}

 
