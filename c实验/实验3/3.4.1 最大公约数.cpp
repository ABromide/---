//������û���������������������
//���������Լ���������֮��Ҫ
//���õݹ麯��ʵ�������Լ����
//��ͬʱ�Ե�����ʽִ�иó��򣬹�
//��ݹ���̡� 

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
