//1.���ô�СΪn��ָ������ָ����gets���������n�У�
//ÿ�в�����80���ַ���
//2.��дһ������������ÿһ���������Ķ���ո��ַ�ѹ
//��Ϊһ���ո��ַ���
//3.�ڵ��ú��������ѹ���ո��ĸ��У����в������
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

