/*��дһ������, �书��Ҫ���ǣ�����n��ѧ����������
C���Կγ̵ĳɼ������ɼ����Ӹߵ��͵Ĵ�����������
ͬʱ����Ӧ��������������ѧ����������C���Կγ̵ĳ�
����Ȼ������һ��C���Կγ̳ɼ�ֵ���ö��ֲ��ҽ���
������������ҵ��иóɼ�������óɼ�ͬѧ��������
C���Կγ̵ĳɼ������������ʾ��not found!����*/ 

#include<stdio.h>
    void swap(char *a,char *b) ;
int main(void) 

{
	char name[20][20],temp;
    int b[20],N;
	int i,a,t;
	int y,key;
	int g=0;
	

    scanf("%d",&N);
    /*��������*/ 
    for(t=0;t<N;t++)
      scanf("%s %d",&name[t],&b[t]);
    /* ð������*/ 
    for(i=0;i<N-1;i++)
     for(a=0;a<N-1;a++){
      if(b[a]>b[a+1])
      {
      	y=b[a];
        b[a] = b[a+1];
        b[a+1] =y;
        
        
       swap(name[a],name[a+1]); 

	  }}
	  /*���*/
	  for(g=0;g<N;g++) printf("\n%s:%d",name[g],b[g]) ;
	  
	  /*���ַ�*/ 
	  scanf("%d",&key) ;
	  int low,high,mid;
      low=0;     
      high=N-1;   
      while(low<=high)
    {
        mid=(low+high)/2;  
        if(key<b[mid])
            high=mid;
        if(key>b[mid])
            low=mid;
        else key=b[mid];
             
    }
    printf("%s: %4d\n",name[mid],b[mid]);
    return 0;
	  
      
}


void swap(char *a,char*b)
{
	int temp;
	    temp = *a;
       *a = *b;
	   *b = temp;
}
