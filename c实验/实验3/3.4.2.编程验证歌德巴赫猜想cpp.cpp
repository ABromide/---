#include "stdio.h"
#include <math.h>
int split_a(int); 
int split_b(int,int);
int main(void)
{
	int even,i,t,flag=1;
	int prime1=2,prime2;
	while(flag)
	{ 
	        printf("please input a munber(>4).");//���� 
			scanf("%d",&even);
			if(even<4) 
			{printf("the number is too small,please input against.");
			continue;}//����ѭ��
			
			//�������ֺ��жϣ� 
			split_a(even);
			
		    printf("%d=%d+%d\n",even,split_a(even),split_b(even,split_a(even)));
		    
		    if(even==0) flag=0;//������0ʱֹͣѭ�� 
	}
	
}


int split_a(int n)//a
{
	int a,t; 
	int k=sqrt((double)a);
	
	
	 
	    for(a=2;a<=(n/2);a++)
	   { //����a<4ʱ��ֱ������b�ǲ������� 
	        if(a<4){
			split_b(n,a); 
			while(split_b(n,a)!=0) return a;}
            
            //��������ģ����ж�a�ǲ������� 
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



