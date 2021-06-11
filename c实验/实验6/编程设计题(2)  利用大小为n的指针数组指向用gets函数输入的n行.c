//1.利用大小为n的指针数组指向用gets函数输入的n行，
//每行不超过80个字符。
//2.编写一个函数，它将每一行中连续的多个空格字符压
//缩为一个空格字符。
//3.在调用函数中输出压缩空格后的各行，空行不予输出
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define N 1
char reduce_place(char *);
int main(void)
{
    char *p[N],str[N][80];
    int i=0,k=0;

	for(i=0;i<N;i++)  {gets(str[i]);  p[i]=str[i];}
	for(i=0;i<N;i++)
    {
        reduce_place(p[i]);
         printf("%s\n",p[i]);
    }
}

char reduce_place(char*p)
{   int n,i;
    for(n=0,i=0;*(p+n)!='\0';n++,i++)
    {
        if(p[n]==' ')
        {
            for(;p[n]==' ';n++);
            p[i++]=' ';
            *(p+i)=*(p+n);
        }
        else *(p+i)=*(p+n);
    }
    *(p+i)=*(p+n);

}

