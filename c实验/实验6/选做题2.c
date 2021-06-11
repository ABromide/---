#include "stdio.h"
#include "string.h"
int main(void)
{
    char *(*p[2])(const char *,const char *);
    char a[]={"computer"},b[]={"HUST"},c[20],*result=c;
    int i,k=0;
    scanf("%d",&i);
    switch(i)
    {
        case(0):p[i]=strcpy;break;
        case(1):p[i]=strcat;break;
    }
    getchar();

    result=p[i](a,b);
    printf("%s",result);
}
