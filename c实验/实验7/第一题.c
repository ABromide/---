#include<stdio.h>
int main(void)
{
    char u[]="UVWXYZ";
    char v[]="xyz";
   struct T{
	int x;
	char c;
	char *t;}a[]={{11,'A',u},{100, 'B',v}},*p=a;
	//printf("%c",(++p)->x);
	//p++;printf("%c",p->c);
	//printf("%c",*p++->t);printf("%c",*p->t);
	//printf("%c",*(++p)->t);
	//printf("%c",*++p->t);
	printf("%c",++*p->t);
//
}

