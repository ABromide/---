/*编写一个程序，证明对于在符号
常量BEGIN和END之间的偶数这一
猜测成立。例如，如果BEGIN为10，END为20，程序的输出应为：
GOLDBACH'S CONJECTURE:
Every even number n>=4 is the sum of two primes.
10=3+7
12=5+7
……
20=3+17*/ 

/*1.输入ab。  2.int数组把数组赋值  3.i<(a-b+1);i++  4.素数的判定*/ 
#include "stdio.h"
#include <math.h>
#define MAX 20 
int split_a(int); 
int split_b(int,int);
int main(void)
{
	int a[MAX],start,end;
	int p,h;
	scanf("%d %d",&start,&end) ;
	printf("GOLDBACH'S CONJECTURE:\n");
	printf("Every even number n>=4 is the sum of two primes.\n");
	//确定开始的数是否为偶数 
	if(start%2==0)
	{
	    for(h=0;h<(end-start+2)/2;h++) a[h]=start+2*h; 
	}
	else
	{
	   start=start+1;
		for(h=0;h<(end-start+2)/2;h++) a[h]=start+2*h; 
	}
	
	//计算素数 
	for(p=0;p<(end-start+2)/2;p++)
	{split_a(a[p]); 
	printf("%d=%d+%d\n",a[p],split_a(a[p]),split_b(a[p],split_a(a[p])));}
} 



//素数分割函数 声明了a,t,b,i，k，k2; 
int split_a(int n)//a
{
	int a,t; 
	int k=sqrt((double)a);
	
	
	 
	    for(a=2;a<=(n/2);a++)
	   { //首先a<4时，直接来看b是不是质数 
	        if(a<4){
			split_b(n,a); 
			while(split_b(n,a)!=0) return a;}
            
            //如果大于四，先判断a是不是质数 
	        else {
			
		        for(t=2;t<k;t++)
				if(a%t==0) break; 
				
		           
		                        
		        if(t>k) split_b(n,a);
		        while(split_b(n,a)!=0) return a;
		  }
		  
		  
    	} 
	}
	  
  int split_b(int n,int an)//b
	   {
	   	int b=n-an;int i;
	   	int k2=sqrt((double)b);
	   	  for(i=2;i<=k2;i++)
	   	   if(b%i==0) break; 
	   	   
	   	   if(i>k2) return b;
	   	   else return 0;
	   }

