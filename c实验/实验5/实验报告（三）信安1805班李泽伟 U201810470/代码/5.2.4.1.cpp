//��дһ������,�Ӽ��̶�ȡ����
//����һ��34������и�ֵ������ת�þ���Ȼ�����ԭ�����ת�þ���


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
