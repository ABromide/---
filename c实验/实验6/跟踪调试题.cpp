#include "stdio.h"
char *strcpy(char *,char *);
int main(void)
{
    char a[60],b[60]="there is a boat on the lake.";
    printf("%s\n",strcpy(a,b));

}
char *strcpy(char *s,char *t)
{
	char *r=s;
    while((*r++=*t++)!='\0');
    return (s);
}
