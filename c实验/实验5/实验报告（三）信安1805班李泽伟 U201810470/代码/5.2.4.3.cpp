/*编写一个程序, 其功能要求是：输入n个学生的姓名和
C语言课程的成绩，将成绩按从高到低的次序排序，姓名
同时作相应调整，输出排序后学生的姓名和C语言课程的成
绩。然后，输入一个C语言课程成绩值，用二分查找进行
搜索。如果查找到有该成绩，输出该成绩同学的姓名和
C语言课程的成绩；否则输出提示“not found!”。*/ 

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
    /*数据输入*/ 
    for(t=0;t<N;t++)
      scanf("%s %d",&name[t],&b[t]);
    /* 冒泡排序*/ 
    for(i=0;i<N-1;i++)
     for(a=0;a<N-1;a++){
      if(b[a]>b[a+1])
      {
      	y=b[a];
        b[a] = b[a+1];
        b[a+1] =y;
        
        
       swap(name[a],name[a+1]); 

	  }}
	  /*输出*/
	  for(g=0;g<N;g++) printf("\n%s:%d",name[g],b[g]) ;
	  
	  /*二分法*/ 
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
