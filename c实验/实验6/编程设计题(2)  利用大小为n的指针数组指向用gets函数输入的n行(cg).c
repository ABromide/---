#include<stdio.h>
#define N 2
char *nospace(char *p[],int n);
int main()
{
	int i;
	char *p[N],*s[N],str[N][80];
	for(i=0;i<N;i++)
	{
		gets(str[i]);
		p[i]=str[i];
	}
    for(i=0;i<N;i++)
    {
		s[i]=nospace(p,i);
		puts(s[i]);
	}
	return 0;
}
char *nospace(char *p[],int n)
{
	char *s=p[n];
	int j,k=0;
	for(j=0;p[n][j]!='\0';j++)
	{
		if(p[n][j]==' '&&p[n][j+1]!=' ')
			{s[k]=p[n][j];k++;}
		if(p[n][j]!=' ')
			{s[k]=p[n][j];k++;}
	}
	s[k]='\0';
	return(s);
}
