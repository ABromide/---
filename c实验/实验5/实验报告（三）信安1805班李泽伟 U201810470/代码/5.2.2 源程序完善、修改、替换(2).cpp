
#include<stdio.h>
#define M 10
#define N 3
int main(void)
{
    int a[M]={0}, b[M];
    int i, j, k;
     for(i=M,j=0;i>0;i--)
     {
         for(k=1;k<=N;k++)
	     {
             if(++j>M-1) j=0;
             if(j==0&&a[9]==1||(j!=0&&a[j-1]==1))k--;
         }
         b[M-i]=j?j:M;
         a[j-1]=1;
     }
     for(i=0;i<M;i++)
     printf("%6d", b[i]);
     return 0;
}
