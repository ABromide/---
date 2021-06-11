//编程让用户输入两个整数，计算两
//个数的最大公约数并且输出之（要
//求用递归函数实现求最大公约数）
//。同时以单步方式执行该程序，观
//察递归过程。 

#include "stdio.h"
int Recursion(int,int);
int main(void)
{
  int n,m;
  scanf("%d %d",&n,&m);	
  while(n%2==0&&m%2==0) {n=n/2;m=m/2;}
  Recursion(n,m);
  return 0;
}
int Recursion(int a,int b)
{
	if(a%b==0)  printf("Recursion=%d\n\n",b);
	if(b%a==0)  printf("Recursion=%d\n\n",a);
    if(b%a!=0&&a%b!=0)
{
	while(a!=b)
	{
	
	if(a>b) 
	{
		a=a-b;
		printf("a=%d,b=%d\n",a,b);
	}
	if(a<b) 
	{
		b=b-a;
		printf("a=%d,b=%d\n",a,b);
	}
    }
	 printf("Recursion=%d\n\n",b);
	return 0;
}
	
}
