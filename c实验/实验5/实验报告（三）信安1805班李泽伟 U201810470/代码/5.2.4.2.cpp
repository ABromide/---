//编写一个程序, 其功能要求是：输入一个整数，将它在内存中二进制表示的每一位
//转换成为对应的数字字符，存放到一个字符数组中，然后输出该整数的二进制表示。

#include<stdio.h>
int main(void)
{
int a[32]={0},t,i=0;
scanf("%d",&t);

while(t!=0){

  if(t%2==0)
    {a[i]=0;i++;t=t/2; 
}
  else{a[i]=1;i++;t=t-1;t=t/2;
	 }
}
while(i<=32) {printf("%d",a[32-i]);i++;} 
} 

