//编写一个程序,从键盘读取数据
//，对一个34矩阵进行赋值，求其转置矩阵，然后输出原矩阵和转置矩阵。


#include<stdio.h>
int main(void)
{
	int a[3][4],b[4][3],j,i;

	for(i=0;i<3;i++)
	  for(j=0;j<4;j++)
     	scanf("%d",&a[i][j]);
     	
   
	for(i=0;i<3;i++)
     {
	 for(j=0;j<4;j++)
	   printf("%6d",a[i][j]);
	 printf("\n");}
    	

	
		for(i=0;i<4;i++)//hang
	      for(j=0;j<3;j++)
	      b[i][j]=a[j][i];
	      
	    for(i=0;i<4;i++)//hang
     {
	 for(j=0;j<3;j++)
	   printf("%6d",b[i][j]);
	 printf("\n");
	 }
	}
